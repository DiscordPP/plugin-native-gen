#pragma once

#include <fmt/format.h>
#include <fmt/ranges.h>
#include <iomanip>

namespace discordpp {

namespace util {
// https://stackoverflow.com/a/17708801
inline std::string url_encode(const std::string &value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n;
         ++i) {
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char)c);
        escaped << std::nouppercase;
    }

    return escaped.str();
}
} // namespace util

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
#include "objects_fwd/application-commands_fwd.hh"
#include "objects_fwd/message-components_fwd.hh"
#include "objects_fwd/receiving-and-responding_fwd.hh"
#include "objects_fwd/application_fwd.hh"
#include "objects_fwd/audit-log_fwd.hh"
#include "objects_fwd/auto-moderation_fwd.hh"
#include "objects_fwd/channel_fwd.hh"
#include "objects_fwd/emoji_fwd.hh"
#include "objects_fwd/guild_fwd.hh"
#include "objects_fwd/guild-scheduled-event_fwd.hh"
#include "objects_fwd/guild-template_fwd.hh"
#include "objects_fwd/invite_fwd.hh"
#include "objects_fwd/stage-instance_fwd.hh"
#include "objects_fwd/sticker_fwd.hh"
#include "objects_fwd/user_fwd.hh"
#include "objects_fwd/voice_fwd.hh"
#include "objects_fwd/webhook_fwd.hh"
#include "objects_fwd/gateway-events_fwd.hh"
#include "objects_fwd/oauth2_fwd.hh"
#include "objects_fwd/permissions_fwd.hh"
#include "objects_fwd/rate-limits_fwd.hh"
#include "objects_fwd/teams_fwd.hh"
/* This space intentionally left blank */
#include "objects_fwd/gateway_fwd.hh"
/* This space intentionally left blank */
#include "objects/application-commands.hh"
#include "objects/message-components.hh"
#include "objects/application.hh"
#include "objects/audit-log.hh"
#include "objects/auto-moderation.hh"
#include "objects/channel.hh"
#include "objects/emoji.hh"
#include "objects/guild.hh"
#include "objects/guild-scheduled-event.hh"
#include "objects/guild-template.hh"
#include "objects/invite.hh"
#include "objects/stage-instance.hh"
#include "objects/sticker.hh"
#include "objects/user.hh"
#include "objects/voice.hh"
#include "objects/webhook.hh"
#include "objects/gateway.hh"
#include "objects/gateway-events.hh"
#include "objects/oauth2.hh"
#include "objects/permissions.hh"
#include "objects/rate-limits.hh"
#include "objects/teams.hh"
/* This space intentionally left blank */
#include "objects/receiving-and-responding.hh"
#undef OBJECT_BREAKOUTS

using ApplicationCommandPermission = GuildApplicationCommandPermissions;

template <class BASE> class PluginNative : public BASE, virtual BotStruct {
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
};

} // namespace discordpp
