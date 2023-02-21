import collections
import copy
import itertools
import json
import re
from contextlib import nullcontext
from pathlib import Path
from typing import Any, Dict, List, OrderedDict, TypeVar

import git

PARSER_PATH = Path('discord-api-parser')
SRC_PATH = PARSER_PATH.joinpath('discord-api-docs')
PARSED_PATH = PARSER_PATH.joinpath('discord-api-json')
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
    'array of two integers': 'std::array<int, 2>',

    # Generated: may not be correct
    'action type': 'ActionType',
    'action': 'Action',
    'activity': 'Activity',
    'allowed mention type': 'AllowedMentionType',
    'allowed mention': 'AllowedMentions',
    'allowed mentions': 'AllowedMentions',
    'application command interaction data option': 'ApplicationCommandInteractionDataOption',
    'application command option choice': 'ApplicationCommandOptionChoice',
    'application command option type': 'ApplicationCommandOptionType',
    'application command option': 'ApplicationCommandOption',
    'application command permission type': 'ApplicationCommandPermissionType',
    'applicationroleconnectionmetadatatype': 'ApplicationRoleConnectionMetadataType',
    'application command type': 'ApplicationCommandType',
    'application commands': 'ApplicationCommand',
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
    'oauth2 scope': 'OAuth2Scope',
    'overwrite': 'Overwrite',
    'presence update': 'PresenceUpdate',
    'presence': 'Presence',
    'privacy level': 'PrivacyLevel',
    'reaction': 'Reaction',
    'resolved data': 'ResolvedData',
    'role': 'Role',
    'role subscription data': 'RoleSubscriptionData',
    'role tags': 'RoleTags',
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
    'thread members': 'ThreadMember',
    'thread metadata': 'ThreadMetadata',
    'trigger type': 'TriggerType',
    'unavailable guild': 'Guild',
    'user objects, with an additional partial member field': 'UserObjects,WithAnAdditionalPartialMemberField',
    'user': 'User',
    'voice state': 'VoiceState',
    'webhook': 'Webhook',
    'welcome screen channel': 'WelcomeScreenChannel',
    'welcome screen': 'WelcomeScreen'
}

NL = '\n'
DQ = '\"'

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




# https://github.com/pydantic/pydantic/blob/b8a695788e957285f10a5ddff12b726a85b1122e/pydantic/utils.py#L212-L223
# MIT License: https://github.com/pydantic/pydantic/blob/b8a695788e957285f10a5ddff12b726a85b1122e/LICENSE
KeyType = TypeVar('KeyType')
def deep_update(mapping: Dict[KeyType, Any], *updating_mappings: Dict[KeyType, Any]) -> Dict[KeyType, Any]:
    updated_mapping = mapping.copy()
    for updating_mapping in updating_mappings:
        for k, v in updating_mapping.items():
            if k in updated_mapping and isinstance(updated_mapping[k], dict) and isinstance(v, dict):
                updated_mapping[k] = deep_update(updated_mapping[k], v)
            else:
                updated_mapping[k] = v
    return updated_mapping


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
    target = Path(TARGET_PATH)
    target.mkdir(parents=True, exist_ok=True)
    target.joinpath('endpoints').mkdir(exist_ok=True)
    # target.joinpath('objects').mkdir(exist_ok=True)
    # target.joinpath('objects_fwd').mkdir(exist_ok=True)

    repo = git.Repo()
    parser_repo = git.Repo(PARSER_PATH)
    src_repo = git.Repo(SRC_PATH)
    json_repo = git.Repo(PARSED_PATH)

    # @formatter:off
    comment_header = f'''\
// Generated by Discord++'s Plugin Native Gen: last commit {repo.head.object.hexsha[:7]} on {repo.head.object.committed_datetime}
// https://github.com/DiscordPP/plugin-native-gen

// Based on JSON of Discord's API: commit {json_repo.head.object.hexsha[:7]} on {json_repo.head.object.committed_datetime}
// https://github.com/DiscordPP/discord-api-json

// Parsed by Discord++'s parser: commit {parser_repo.head.object.hexsha[:7]} on {parser_repo.head.object.committed_datetime}
// https://github.com/DiscordPP/discord-api-parser

// From Discord's official API docs: commit {src_repo.head.object.hexsha[:7]} on {src_repo.head.object.committed_datetime}
// https://github.com/discord/discord-api-docs
'''
    render_objects = f'''\
{comment_header}

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "field.hh"
'''
    render_objects_fwd = f'''\
{comment_header}

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

'''
    # @formatter:on
    all_objects: OrderedDict[str, Dict[str, Dict[str, Dict[str, Any]]]] = collections.OrderedDict()
    all_objects['children'] = {}
    for filepath in Path(PARSED_PATH).rglob("*.object.json"):
        stem = filepath.stem.split('.')[0].lower().replace('_', '-')
        overridepath = Path(str(filepath).replace(str(PARSED_PATH), str(OVERRIDE_PATH)))
        with \
                filepath.open(mode="r") as file, \
                (overridepath.open(mode="r") if overridepath.is_file() else nullcontext()) as override_file:
            objects: Dict[str, Dict[str, Dict[str, Any]]] = json.loads(file.read())
            if override_file:
                overrides: Dict[str, Dict[str, Dict[str, Any]]] = json.loads(override_file.read())
                for name, fields in overrides.items():
                    if name in objects:
                        for field_name, field in fields.items():
                            if field_name in objects[name]:
                                objects[name][field_name].update(field)
                            else:
                                objects[name][field_name] = field
                    else:
                        objects[name] = fields
            all_objects[stem] = {}
            for name, object in objects.items():
                all_objects['children' if False and 'parent' in object['parser-data'] else stem][name] = object
    # all_objects.move_to_end('children')
    all_objects_index = 0
    while all_objects_index < len(all_objects.items()):
        stem, objects = list(all_objects.items())[all_objects_index]
        all_objects_index += 1
        i = 0
        while i < len(objects):
            name, fields = list(objects.items())[i]
            metadata = fields.get("parser-data")
            if metadata:
                if metadata.get("skip"):
                    objects.pop(name)
                    continue
                delay = metadata.get("delay", 0)
                depth = int(stem.split('-')[1]) if stem.startswith('delay') else 0
                if name == "Resolved Data":
                    pass
                if depth == 0:
                    if "parent" in metadata:
                        delay += 1
                    if stem == "receiving-and-responding":
                        delay += 1
                if delay:
                    print(f'Delay {name}')
                    metadata["delay"] = delay - 1
                    all_objects[f'delay-{depth + 1}'] = all_objects.get(f'delay-{depth + 1}', {})
                    all_objects[f'delay-{depth + 1}'][name] = objects.pop(name)
                    continue
            i += 1
        for name, fields in copy.deepcopy(objects).items():
            name = make_pascal_case(name)
            print("Processing", name, "in", stem)
            metadata = fields.pop("parser-data")
            if 'name' in metadata:
                name = metadata['name']
                print(f"Actually named {name}")
            parent = {}
            parent_name = ''
            parent_metadata = {}
            if 'parent' in metadata:
                i = 0
                while not parent and i < len(all_objects):
                    if metadata['parent'] in all_objects[list(all_objects.keys())[i]]:
                        parent = copy.deepcopy(all_objects[list(all_objects.keys())[i]][metadata['parent']])
                        parent_metadata = parent.pop("parser-data")
                        parent_name = parent_metadata.get('name') or \
                                      make_pascal_case(metadata['parent'])
                    i += 1
            for field_name, field in itertools.chain(fields.items(), parent.items()):
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
            render_parts = {
                "predeclare": ''.join(f'{NL}class {class_name};' for class_name in metadata.get('predeclare', [])),
                "constructor": {
                    "parameters": ',\n        '.join([
                        f'{field["container_type"]} {field.get("name", field_name)} = {"omitted" if field["optional"] else "uninitialized"}'
                        for field_name, field
                        in itertools.chain(parent.items() if parent else [], filter(lambda item: not parent or item[0] not in parent, fields.items()))
                        if not 'static' in metadata or field_name not in metadata['static']
                    ]),
                    "initialisation": (
                        f',\n'.join(
                            ([
                                 '        ' + parent_name + '(\n' + f",{NL}".join([
                                     "            " + str(metadata["static"][field.get("name", field_name)]
                                     if "static" in metadata and field_name in metadata["static"]
                                     else field.get("name", field_name)) for field_name, field in parent.items()
                                 ]) + '\n        )'
                            ] if parent else []) + [
                            f'        {field.get("name", field_name)}({metadata["static"][field.get("name", field_name)] if "static" in metadata and field_name in metadata["static"] else field.get("name", field_name)})'
                            for field_name, field in fields.items() if not parent or field_name not in parent
                        ])
                    )
                },
                "variables": '\n'.join([
                    '    '
                    f'{field["container_type"]} {field.get("name", field_name)};'
                    for field_name, field in fields.items() if not parent or field_name not in parent
                ]),
                "to_json": {
                    "parent": f'\n        to_json(j, (const {parent_name}&)t);' if parent else '',
                    "assignments": '\n'.join([field.get("to_json",
                        f'        if(!t.{field.get("name", field_name)}.is_omitted()) '
                        f'{{j["{field.get("field_name", field_name)}"] = t.{field.get("name", field_name)};}}'
                    ) for field_name, field in fields.items()])
                },
                "from_json": {
                    "parent": f'\n        from_json(j, ({parent_name}&)t);' if parent else '',
                    "assignments": '\n'.join([field.get("from_json",
                        f'        if(j.contains(\"{field.get("field_name", field_name)}\")){{'
                        f'j.at(\"{field.get("field_name", field_name)}\").get_to(t.{field.get("name", field_name)});}}'
                    ) for field_name, field in fields.items()])
                },
                "alts": ''.join(f'{NL}using {alt} = {name};' for alt in metadata.get('alts', []))
            }
            # @formatter:off
            render_objects += f'''{render_parts["predeclare"]}
// {metadata.get('docs_url')}
class {name}{f': public {parent_name}' if parent else ''}{{
  public:
    {name}(
        {render_parts["constructor"]["parameters"]}
    ):
{render_parts["constructor"]["initialisation"]}
    {{}}
    {name}(const json &j) {{ from_json(j, *this); }}
    
{render_parts["variables"]}

    friend void to_json(nlohmann::json &j, const {name} &t) {{{render_parts["to_json"]["parent"]}
{render_parts["to_json"]["assignments"]}
    }}
    friend void from_json(const nlohmann::json &j, {name} &t) {{{render_parts["from_json"]["parent"]}
{render_parts["from_json"]["assignments"]}
    }}
}};{render_parts["alts"]}
'''
            render_objects_fwd += f'''\
class {name};
'''
            # @formatter:on
            print()
    target.joinpath('objects.hh').write_text(render_objects)
    target.joinpath('objects-fwd.hh').write_text(render_objects_fwd)
    # print(object_fwd_includes, object_fwd_final_includes, object_includes, object_final_includes)

    print()
    for filepath in []:  # Path(PARSED_PATH).rglob("*.endpoint.json"):
        print(filepath)
        overridepath = Path(str(filepath).replace(str(PARSED_PATH), str(OVERRIDE_PATH)))
        with \
                filepath.open(mode="r") as file:  # , \
            # (overridepath.open(mode="r") if overridepath.is_file() else nullcontext()) as override_file:
            endpoints: Dict[str, Dict[str, Any]] = json.loads(file.read())
            # @formatter:off
            render = '''\
#ifndef ENDPOINT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

'''
            # @formatter:on

    # @formatter:off
    render_enums = f"""\
{comment_header}

#pragma once

namespace discordpp {{
"""
    # @formatter:on
    for filepath in Path(PARSED_PATH).rglob("*.enum.json"):
        if "Opcodes_and_Status_Codes" in str(filepath):
            continue
        print(filepath)
        render_enums += f'\n// {filepath.stem.replace("_", " ").removesuffix(".enum")} //\n\n'
        overridepath = Path(str(filepath).replace(str(PARSED_PATH), str(OVERRIDE_PATH)))
        with \
                filepath.open(mode="r") as file, \
                (overridepath.open(mode="r") if overridepath.is_file() else nullcontext()) as override_file:
            enums: Dict[str, Dict[str, str | Dict[str, str]]] = json.loads(file.read())
            if override_file:
                enums = deep_update(enums, json.loads(override_file.read()))
            for name, opt in enums.items():
                metadata = opt.pop("parser-data", None)
                if metadata:
                    if metadata['skip']:
                        print('Skipping', name)
                        continue

                value_eg = list(opt.values())[0].get('value')
                pretty_name = name.replace(" ", "")  # .removesuffix('s')
                if pretty_name.endswith('s') and  not any(pretty_name.endswith(suffix) for suffix in [
                    'Status', 'Flags'
                ]):
                    pretty_name = pretty_name[:-1]
                is_int = bool(value_eg and (value_eg.isdigit() or '<<' in value_eg or '0x' in value_eg))
                is_large = bool(value_eg and ('<<' in value_eg or '0x' in value_eg))
                render_parts = {
                    'name': f'enum class {pretty_name}{" : long int" if is_large else " : int" if is_int else ""}',
                    'values': "\n    ".join(
                        key.replace(' ', '_').replace('.', '_') + (" = " + re.sub(r' \(.+\)', '', value['value']) if is_int else "") + ','
                        for key, value in opt.items()
                    )
                }
                render_parts['values'] = render_parts['values'][:-1]
                if not is_int:
                    render_parts['serialize_values'] =  "\n        ".join(
                        f"{{{pretty_name}::{key.replace(' ', '_').replace('.', '_')}, \"{value.get('value', key).removeprefix(DQ).removesuffix(DQ)}\"}},"
                        for key, value in opt.items()
                    )
                    render_parts['serialize_values'] = render_parts['serialize_values'][:-1]
                # @formatter:off
                render_enums += f"""\
{render_parts['name']} {{
    {render_parts['values']}
}};
"""
                # @formatter:on
                if not is_int:
                    # @formatter:off
                    render_enums += f"""\
NLOHMANN_JSON_SERIALIZE_ENUM(
    {pretty_name},
    {{
        {render_parts['serialize_values']}
    }}
);
"""
                    # @formatter:on
                render_enums += '\n'
    # @formatter:off
    render_enums += """\
} // namespace discordpp
"""
    # @formatter:on
    TARGET_PATH.joinpath('enum.hh').write_text(render_enums)

    # @formatter:off
    TARGET_PATH.joinpath('plugin-native.hh').write_text(f'''\
{comment_header}

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

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-response-object-interaction-callback-data-structure
using InteractionCallbackData = json;

#define OBJECT_BREAKOUTS
/* This space intentionally left blank */
#include "objects-fwd.hh"
/* This space intentionally left blank */
#include "objects.hh"
/* This space intentionally left blank */
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


if __name__ == '__main__':
    run()
