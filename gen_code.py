import json
import re
from contextlib import nullcontext
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
    'float': 'float',
    'double': 'double',
    'iso8601 timestamp': 'Timestamp',
    'dictionary with keys in available locales': 'std::map<Locale, std::string>',
    'integer for integer options, double for number options': 'std::variant<int, double>',
    'mixed': 'json',
    'null': 'std::nullptr_t',
    'member': 'GuildMember',
    'array of two integers': 'std::Array<int, 2>',

    # Generated: may not be correct
    'action type': 'ActionType',
    'action': 'Action',
    'activity': 'Activity',
    'allowed mention type': 'AllowedMentionType',
    'allowed mention': 'AllowedMention',
    'allowed mentions': 'AllowedMentions',
    'application command interaction data option': 'ApplicationCommandInteractionDataOption',
    'application command option choice': 'ApplicationCommandOptionChoice',
    'application command option type': 'ApplicationCommandOptionType',
    'application command option': 'ApplicationCommandOption',
    'application command permission type': 'ApplicationCommandPermissionType',
    'application command type': 'ApplicationCommandType',
    'application commands': 'ApplicationCommands',
    'application': 'Application',
    'attachment': 'Attachment',
    'audit log change': 'AuditLogChange',
    'audit log entry': 'AuditLogEntry',
    'audit log event': 'AuditLogEvent',
    'auto moderation action': 'AutoModerationAction',
    'auto moderation rule': 'AutoModerationRule',
    'binary': 'Binary',
    'button': 'Button',
    'channel mention': 'ChannelMention',
    'channel type': 'ChannelType',
    'channel': 'Channel',
    'choice': 'Choice',
    'client status': 'ClientStatus',
    'component': 'Component',
    'default reaction': 'DefaultReaction',
    'embed author': 'EmbedAuthor',
    'embed field': 'EmbedField',
    'embed footer': 'EmbedFooter',
    'embed image': 'EmbedImage',
    'embed provider': 'EmbedProvider',
    'embed thumbnail': 'EmbedThumbnail',
    'embed video': 'EmbedVideo',
    'embed': 'Embed',
    'emoji': 'Emoji',
    'event status': 'EventStatus',
    'file contents': 'FileContents',
    'guild feature': 'GuildFeature',
    'guild member': 'GuildMember',
    'guild scheduled event': 'GuildScheduledEvent',
    'guild': 'Guild',
    'install params': 'InstallParams',
    'integration': 'Integration',
    'interaction callback data': 'InteractionCallbackData',
    'interaction callback type': 'InteractionCallbackType',
    'interaction type': 'InteractionType',
    'invite stage instance': 'InviteStageInstance',
    'keyword preset type': 'KeywordPresetType',
    'message activity': 'MessageActivity',
    'message component': 'MessageComponent',
    'message interaction': 'MessageInteraction',
    'message reference': 'MessageReference',
    'message': 'Message',
    'oauth2 scope': 'Oauth2Scope',
    'overwrite': 'Overwrite',
    'presence update': 'PresenceUpdate',
    'presence': 'Presence',
    'privacy level': 'PrivacyLevel',
    'reaction': 'Reaction',
    'resolved data': 'ResolvedData',
    'role tags': 'RoleTags',
    'role': 'Role',
    'scheduled entity type': 'ScheduledEntityType',
    'select option': 'SelectOption',
    'session start limit': 'SessionStartLimit',
    'stage instance': 'StageInstance',
    'sticker pack': 'StickerPack',
    'sticker': 'Sticker',
    'tag': 'Tag',
    'team member': 'TeamMember',
    'team': 'Team',
    'thread member': 'ThreadMember',
    'thread members': 'ThreadMembers',
    'thread metadata': 'ThreadMetadata',
    'trigger type': 'TriggerType',
    'unavailable guild': 'UnavailableGuild',
    'user objects, with an additional partial member field': 'UserObjects,WithAnAdditionalPartialMemberField',
    'user': 'User',
    'voice state': 'VoiceState',
    'webhook': 'Webhook',
    'welcome screen channel': 'WelcomeScreenChannel',
    'welcome screen': 'WelcomeScreen'
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
    # print(f"'{src}': '{fallback}',")
    return fallback


def run():
    object_includes = []
    object_final_includes = []
    object_fwd_includes = []
    object_fwd_final_includes = []
    for filepath in Path(PARSED_PATH).rglob("*.enum.json"):
        if "game_sdk" in str(filepath):
            continue
        print(filepath)
    print()
    for filepath in Path(PARSED_PATH).rglob("*.object.json"):
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
                metadata = {}
                for field_name, field in fields.items():
                    if field_name == "parser-data":
                        metadata = field
                        continue
                    if '(' in field.get("name", field_name):
                        field["name"] = field.get("name", field_name).split('(', 1)[0].rstrip()
                    if '(' in field_name:
                        field["field_name"] = field_name.split('(', 1)[0].rstrip()
                    warn_reserved(field.get("name", field_name))
                    field["type"] = parse_type(
                        # Some fields in /topics/gateway have the type in the description
                        field["comments"]["Description"] if field["type"] == "array"
                        else field["type"].replace('_', ' ')
                    )
                    field["container_type"] = \
                        f'{"nullable_" if field["nullable"] else ""}' + \
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
    f'        {field["container_type"]} {field.get("name", field_name)} = {"omitted" if field["optional"] else "uninitialized"}'
    for field_name, field in fields.items()
])}
    ): 
{f',{NL}'.join([
    f'        {field.get("name", field_name)}({field.get("name", field_name)})'
    for field_name, field in fields.items()
])}
    {{}}
    
{NL.join([
    '    ' +
    f'{field["container_type"]} {field.get("name", field_name)};'
    for field_name, field in fields.items()
])}

    friend void to_json(nlohmann::json &j, const {name} &t) {{
        //ToJsonExtra
{NL.join([
    field.get("to_json") or
    f'        if(!t.{field.get("name", field_name)}.is_omitted()) ' +
    f'{{j["{field.get("field_name", field_name)}"] = t.{field.get("name", field_name)};}}'
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
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-action-object
using Action = json;
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-action-object-action-types
using ActionType = int;
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
    print()
    for filepath in Path(PARSED_PATH).rglob("*.endpoint.json"):
        if "game_sdk" in str(filepath):
            continue
        print(filepath)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    run()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
