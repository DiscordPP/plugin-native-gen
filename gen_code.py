import re
from contextlib import nullcontext
import json
import sys
from copy import copy
from pathlib import Path
from typing import Any, Dict, List

PARSED_PATH = Path('discord-api-parser/discord-api-json')
OVERRIDE_PATH = Path('overrides')
TARGET_PATH = Path('gen')

RESERVED: List[str] = [
    'alignas', 'alignof', 'and', 'and_eq', 'asm', 'atomic_cancel', 'atomic_commit', 'atomic_noexcept', 'auto', 'bitand',
    'bitor', 'bool', 'break', 'case', 'catch', 'char', 'char8_t', 'char16_t', 'char32_t', 'class', 'compl', 'concept',
    'const', 'consteval', 'constexpr', 'constinit', 'const_cast', 'continue', 'co_await', 'co_return', 'co_yield',
    'decltype', 'default', 'delete', 'do', 'double', 'dynamic_cast', 'else', 'enum', 'explicit', 'export', 'extern',
    'false', 'float', 'for', 'friend', 'goto', 'if', 'inline', 'int', 'long', 'mutable', 'namespace', 'new', 'noexcept',
    'not', 'not_eq', 'nullptr', 'operator', 'or', 'or_eq', 'private', 'protected', 'public', 'reflexpr', 'register',
    'reinterpret_cast', 'requires', 'return', 'short', 'signed', 'sizeof', 'static', 'static_assert', 'static_cast',
    'struct', 'switch', 'synchronized', 'template', 'this', 'thread_local', 'throw', 'true', 'try', 'typedef', 'typeid',
    'typename', 'union', 'unsigned', 'using', 'virtual', 'void', 'volatile', 'wchar_t', 'while', 'xor', 'xor_eq'
]

TYPES: Dict[str, str] = {
    'snowflake': 'Snowflake',
    'string': 'std::string',
    'boolean': 'bool',
    'integer': 'int',
    'int': 'int',
    'double': 'double',
    'iso8601 timestamp': 'Timestamp',
    'dictionary with keys in available locales': 'std::map<Locale, std::string>',
    'integer for integer options, double for number options': 'std::variant<int, double>',
    'mixed': 'json',
    'null': 'std::nullptr_t',
    'member': 'GuildMember'
}

NL = '\n'

DELAY_OBJECTS = ['receiving-and-responding']

DELAY_OBJECTS_FWD = ['gateway']


# https://svn.blender.org/svnroot/bf-blender/trunk/blender/build_files/scons/tools/bcolors.py
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def make_pascal_case(src):
    return ''.join(src.title().split(' ')).replace('-', '')


def warn_reserved(s):
    if s in RESERVED:
        print(f'{bcolors.WARNING}WARNING: {s} is a reserved word{bcolors.ENDC}')


def parse_type(src: str):
    if src.startswith('++'):
        return src[2:] + (' ' if src.endswith('>') else '')
    src = src.lower().strip()
    opening = src.find('(')
    if opening >= 0:
        return parse_type(src[:opening] + src[src.find(')') + 1:])
    if src in TYPES:
        return TYPES[src]
    if ' or ' in src:
        return f'std::variant<{", ".join([parse_type(s) for s in re.split(", or |, | or ", src)])}> '
    if src.startswith('a '):
        return parse_type(src.removeprefix("a "))
    if src.startswith('array of ') or src.startswith('list of '):
        return f'std::vector<{parse_type(src.removeprefix("array of ").removeprefix("list of ").removesuffix("s"))}> '
    if src.startswith('map of '):
        inner = [i.removesuffix('s') for i in src.removeprefix("map of ").split(" to ", 1)]
        return f'std::map<{parse_type(inner[0].removesuffix("s"))}, {parse_type(inner[1].removesuffix("s"))}> '
    if src.startswith('one of '):
        return parse_type(src.removeprefix('one of '))
    if src.endswith('id'):
        return parse_type("snowflake")
    front_split = src.split(' ', 1)
    if len(front_split) == 2:
        if front_split[0] in ['partial']:
            return parse_type(front_split[1])
    back_split = src.rsplit(' ', 1)
    if len(back_split) == 2:
        if back_split[1] in ['object', 'string', 'value']:
            return parse_type(back_split[0])
    fallback = make_pascal_case(src)
    print(f'{bcolors.OKCYAN}INFO: unknown type `{src}`, falling back to `{fallback}`{bcolors.ENDC}')
    return fallback


def run():
    object_includes = []
    object_final_includes = []
    object_fwd_includes = []
    object_fwd_final_includes = []
    for filepath in Path(PARSED_PATH).rglob("*.object.json"):  # TODO use *
        if "game_sdk" in str(filepath):
            continue
        target = Path(TARGET_PATH)
        target.mkdir(parents=True, exist_ok=True)
        target.joinpath('endpoints').mkdir(exist_ok=True)
        target.joinpath('objects').mkdir(exist_ok=True)
        target.joinpath('objects_fwd').mkdir(exist_ok=True)
        overridepath = Path(str(filepath).replace(str(PARSED_PATH), str(OVERRIDE_PATH)))
        with \
                filepath.open(mode="r") as file, \
                (overridepath.open(mode="r") if overridepath.is_file() else nullcontext()) as override_file:
            objects: Dict[str, Dict[str, Dict[str, Any]]] = json.loads(file.read())
            if override_file:
                overrides: Dict[str, Dict[str, Dict[str, Any]]] = json.loads(override_file.read())
                for name, fields in overrides.items():
                    for field_name, field in fields.items():
                        objects[name][field_name].update(field)
            # @formatter:off
            render = '''\
#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

'''
            render_fwd = '''\
#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

'''
            # @formatter:on
            i = 0
            while i < len(objects):
                name, fields = list(objects.items())[i]
                metadata = fields.get("parser-data")
                if metadata:
                    requeue = metadata.get("requeue")
                    if requeue:
                        metadata["requeue"] -= 1
                        print(objects.keys())
                        objects[name] = objects.pop(name)
                        print(objects.keys())
                        continue
                i += 1
            for name, fields in objects.items():
                name = make_pascal_case(name)
                print("Processing", name, "in", str(filepath).replace(str(PARSED_PATH), ""))
                # TODO Load exceptions from some file
                metadata = {}
                for field_name, field in fields.items():
                    if field_name == "parser-data":
                        metadata = field
                        continue
                    warn_reserved(field.get("name") or field_name)
                    field["type"] = parse_type(field["type"])
                    field["container_type"] = f'{"nullable_" if field["nullable"] else ""}' + \
                        f'{"omittable_" if field["optional"] else ""}' + \
                        f'field<{field["type"]}>'
                    # print('                                 ', field["type"])
                    # print('                             : ', parse_type(field["type"]))
                fields.pop("parser-data")
                # @formatter:off
                render += f'''\
// {metadata.get("docs_url")}
class {name}{{
  public:
    {name}(
{f',{NL}'.join([
    f'        {field["container_type"]} {field.get("name") or field_name} = {"omitted" if field["optional"] else "uninitialized"}'
    for field_name, field in fields.items()
])}
    ): 
{f',{NL}'.join([
    f'        {field.get("name") or field_name}({field.get("name") or field_name})'
    for field_name, field in fields.items()
])}
    {{}}
    
{NL.join([
    '    ' +
    f'{field["container_type"]} {field.get("name") or field_name};'
    for field_name, field in fields.items()
])}

    friend void to_json(nlohmann::json &j, const {name} &t) {{
        //ToJsonExtra
{NL.join([
    field.get("to_json") or
    f'        if(!t.{field.get("name") or field_name}.is_omitted()) ' +
    f'{{j["{field_name}"] = t.{field.get("name") or field_name};}}'
    for field_name, field in fields.items()
])}
    }}
}};
'''
                render_fwd += f'''\
class {name};
'''
                # @formatter:on
                print()
            stem = filepath.stem.split('.')[0].lower().replace('_', '-')
            target.joinpath('objects', stem + '.hh').write_text(render)
            target.joinpath('objects_fwd', stem + '_fwd.hh').write_text(render_fwd)
            (
                object_includes
                if stem not in DELAY_OBJECTS else
                object_final_includes
            ).append(f'objects/{stem}.hh')
            (
                object_fwd_includes
                if stem not in DELAY_OBJECTS_FWD else
                object_fwd_final_includes
            ).append(f'objects_fwd/{stem}_fwd.hh')
    # print(object_fwd_includes, object_fwd_final_includes, object_includes, object_final_includes)
    # @formatter:off
    TARGET_PATH.joinpath('plugin-native.hh').write_text(f'''\
#pragma once

#include <fmt/format.h>
#include <fmt/ranges.h>
#include <iomanip>

namespace discordpp {{

namespace util {{
// https://stackoverflow.com/a/17708801
inline std::string url_encode(const std::string &value) {{
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n;
         ++i) {{
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {{
            escaped << c;
            continue;
        }}

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char)c);
        escaped << std::nouppercase;
    }}

    return escaped.str();
}}
}} // namespace util

// https://discord.com/developers/docs/reference#iso8601-datetime
using Timestamp = std::string;
// https://discord.com/developers/docs/reference#image-data
using ImageData = std::string;
// https://discord.com/developers/docs/reference#locales
using Locale = std::string;
// https://discord.com/developers/docs/topics/teams#data-models-team-object
using Team = json;
// https://discord.com/developers/docs/resources/audit-log#audit-log-entry-object-optional-audit-entry-info
using OptionalAuditEntryInfo = json;
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-rule-object-trigger-metadata
using TriggerMetadata = json;
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-action-object
using Action = json;
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-action-object-action-types
using ActionType = int;
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-action-object-action-metadata
using ActionMetadata = json;
// https://discord.com/developers/docs/interactions/message-components#component-object
using Component = json;
// https://discord.com/developers/docs/resources/guild#integration-account-object
using Action = json;
// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-object-guild-scheduled-event-privacy-level
using PrivacyLevel = int;
// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-object-guild-scheduled-event-status
using EventStatus = int;
// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-object-guild-scheduled-event-entity-types
using ScheduledEntityType = int;
// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-object-guild-scheduled-event-entity-metadata
using GuildScheduledEventEntityMetadata = json;
// https://discord.com/developers/docs/topics/gateway#identify-identify-connection-properties
using IdentifyConnectionProperties = json;
// https://discord.com/developers/docs/topics/gateway#activity-object
using ActivityTimestamps = json;
using ActivityParty = json;
using ActivityAssets = json;
using ActivitySecrets = json;
// Missing? https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-response-object-interaction-callback-data-structure
using InteractionCallbackData = json;

#define OBJECT_BREAKOUTS
/* This space intentionally left blank */
{f'{NL}/* This space intentionally left blank */{NL}'.join([
    NL.join([f'#include "{include}"' for include in includes])
    for includes in
    [object_fwd_includes, object_fwd_final_includes, object_includes, object_final_includes]
])}
#undef OBJECT_BREAKOUTS

using ApplicationCommandPermission = GuildApplicationCommandPermissions;

template <class BASE> class PluginNative : public BASE, virtual BotStruct {{
#define ENDPOINT_BREAKOUTS
#define Bot PluginNative

#include "endpoints/application-commands.hh"
#include "endpoints/audit-log.hh"
#include "endpoints/channel.hh"
#include "endpoints/emoji.hh"
#include "endpoints/guild-template.hh"
#include "endpoints/guild-scheduled-event.hh"
#include "endpoints/guild.hh"
#include "endpoints/invite.hh"
#include "endpoints/receiving-and-responding.hh"
#include "endpoints/stage-instance.hh"
#include "endpoints/sticker.hh"
#include "endpoints/webhook.hh"

#undef Bot
#undef ENDPOINT_BREAKOUTS
}};

}} // namespace discordpp
''')
    # @formatter:on


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    run()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
