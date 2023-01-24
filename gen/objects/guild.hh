#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/guild#guild-object-guild-structure
class Guild{
public:
    Guild(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> icon = uninitialized,
        nullable_omittable_field<std::string> icon_hash = omitted,
        nullable_field<std::string> splash = uninitialized,
        nullable_field<std::string> discovery_splash = uninitialized,
        omittable_field<bool> owner = omitted,
        field<Snowflake> owner_id = uninitialized,
        omittable_field<std::string> permissions = omitted,
        nullable_omittable_field<std::string> region = omitted,
        nullable_field<Snowflake> afk_channel_id = uninitialized,
        field<int> afk_timeout = uninitialized,
        omittable_field<bool> widget_enabled = omitted,
        nullable_omittable_field<Snowflake> widget_channel_id = omitted,
        field<int> verification_level = uninitialized,
        field<int> default_message_notifications = uninitialized,
        field<int> explicit_content_filter = uninitialized,
        field<std::vector<Role> > roles = uninitialized,
        field<std::vector<Emoji> > emojis = uninitialized,
        field<std::vector<GuildFeature> > features = uninitialized,
        field<int> mfa_level = uninitialized,
        nullable_field<Snowflake> application_id = uninitialized,
        nullable_field<Snowflake> system_channel_id = uninitialized,
        field<int> system_channel_flags = uninitialized,
        nullable_field<Snowflake> rules_channel_id = uninitialized,
        nullable_omittable_field<int> max_presences = omitted,
        omittable_field<int> max_members = omitted,
        nullable_field<std::string> vanity_url_code = uninitialized,
        nullable_field<std::string> description = uninitialized,
        nullable_field<std::string> banner = uninitialized,
        field<int> premium_tier = uninitialized,
        omittable_field<int> premium_subscription_count = omitted,
        field<std::string> preferred_locale = uninitialized,
        nullable_field<Snowflake> public_updates_channel_id = uninitialized,
        omittable_field<int> max_video_channel_users = omitted,
        omittable_field<int> approximate_member_count = omitted,
        omittable_field<int> approximate_presence_count = omitted,
        omittable_field<WelcomeScreen> welcome_screen = omitted,
        field<int> nsfw_level = uninitialized,
        omittable_field<std::vector<Sticker> > stickers = omitted,
        field<bool> premium_progress_bar_enabled = uninitialized
    ):
        id(id),
        name(name),
        icon(icon),
        icon_hash(icon_hash),
        splash(splash),
        discovery_splash(discovery_splash),
        owner(owner),
        owner_id(owner_id),
        permissions(permissions),
        region(region),
        afk_channel_id(afk_channel_id),
        afk_timeout(afk_timeout),
        widget_enabled(widget_enabled),
        widget_channel_id(widget_channel_id),
        verification_level(verification_level),
        default_message_notifications(default_message_notifications),
        explicit_content_filter(explicit_content_filter),
        roles(roles),
        emojis(emojis),
        features(features),
        mfa_level(mfa_level),
        application_id(application_id),
        system_channel_id(system_channel_id),
        system_channel_flags(system_channel_flags),
        rules_channel_id(rules_channel_id),
        max_presences(max_presences),
        max_members(max_members),
        vanity_url_code(vanity_url_code),
        description(description),
        banner(banner),
        premium_tier(premium_tier),
        premium_subscription_count(premium_subscription_count),
        preferred_locale(preferred_locale),
        public_updates_channel_id(public_updates_channel_id),
        max_video_channel_users(max_video_channel_users),
        approximate_member_count(approximate_member_count),
        approximate_presence_count(approximate_presence_count),
        welcome_screen(welcome_screen),
        nsfw_level(nsfw_level),
        stickers(stickers),
        premium_progress_bar_enabled(premium_progress_bar_enabled)
    {}
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    nullable_omittable_field<std::string> icon_hash;
    nullable_field<std::string> splash;
    nullable_field<std::string> discovery_splash;
    omittable_field<bool> owner;
    field<Snowflake> owner_id;
    omittable_field<std::string> permissions;
    nullable_omittable_field<std::string> region;
    nullable_field<Snowflake> afk_channel_id;
    field<int> afk_timeout;
    omittable_field<bool> widget_enabled;
    nullable_omittable_field<Snowflake> widget_channel_id;
    field<int> verification_level;
    field<int> default_message_notifications;
    field<int> explicit_content_filter;
    field<std::vector<Role> > roles;
    field<std::vector<Emoji> > emojis;
    field<std::vector<GuildFeature> > features;
    field<int> mfa_level;
    nullable_field<Snowflake> application_id;
    nullable_field<Snowflake> system_channel_id;
    field<int> system_channel_flags;
    nullable_field<Snowflake> rules_channel_id;
    nullable_omittable_field<int> max_presences;
    omittable_field<int> max_members;
    nullable_field<std::string> vanity_url_code;
    nullable_field<std::string> description;
    nullable_field<std::string> banner;
    field<int> premium_tier;
    omittable_field<int> premium_subscription_count;
    field<std::string> preferred_locale;
    nullable_field<Snowflake> public_updates_channel_id;
    omittable_field<int> max_video_channel_users;
    omittable_field<int> approximate_member_count;
    omittable_field<int> approximate_presence_count;
    omittable_field<WelcomeScreen> welcome_screen;
    field<int> nsfw_level;
    omittable_field<std::vector<Sticker> > stickers;
    field<bool> premium_progress_bar_enabled;

    friend void to_json(nlohmann::json &j, const Guild &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.icon_hash.is_omitted()) {j["icon_hash"] = t.icon_hash;}
        if(!t.splash.is_omitted()) {j["splash"] = t.splash;}
        if(!t.discovery_splash.is_omitted()) {j["discovery_splash"] = t.discovery_splash;}
        if(!t.owner.is_omitted()) {j["owner"] = t.owner;}
        if(!t.owner_id.is_omitted()) {j["owner_id"] = t.owner_id;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
        if(!t.region.is_omitted()) {j["region"] = t.region;}
        if(!t.afk_channel_id.is_omitted()) {j["afk_channel_id"] = t.afk_channel_id;}
        if(!t.afk_timeout.is_omitted()) {j["afk_timeout"] = t.afk_timeout;}
        if(!t.widget_enabled.is_omitted()) {j["widget_enabled"] = t.widget_enabled;}
        if(!t.widget_channel_id.is_omitted()) {j["widget_channel_id"] = t.widget_channel_id;}
        if(!t.verification_level.is_omitted()) {j["verification_level"] = t.verification_level;}
        if(!t.default_message_notifications.is_omitted()) {j["default_message_notifications"] = t.default_message_notifications;}
        if(!t.explicit_content_filter.is_omitted()) {j["explicit_content_filter"] = t.explicit_content_filter;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.emojis.is_omitted()) {j["emojis"] = t.emojis;}
        if(!t.features.is_omitted()) {j["features"] = t.features;}
        if(!t.mfa_level.is_omitted()) {j["mfa_level"] = t.mfa_level;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.system_channel_id.is_omitted()) {j["system_channel_id"] = t.system_channel_id;}
        if(!t.system_channel_flags.is_omitted()) {j["system_channel_flags"] = t.system_channel_flags;}
        if(!t.rules_channel_id.is_omitted()) {j["rules_channel_id"] = t.rules_channel_id;}
        if(!t.max_presences.is_omitted()) {j["max_presences"] = t.max_presences;}
        if(!t.max_members.is_omitted()) {j["max_members"] = t.max_members;}
        if(!t.vanity_url_code.is_omitted()) {j["vanity_url_code"] = t.vanity_url_code;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.banner.is_omitted()) {j["banner"] = t.banner;}
        if(!t.premium_tier.is_omitted()) {j["premium_tier"] = t.premium_tier;}
        if(!t.premium_subscription_count.is_omitted()) {j["premium_subscription_count"] = t.premium_subscription_count;}
        if(!t.preferred_locale.is_omitted()) {j["preferred_locale"] = t.preferred_locale;}
        if(!t.public_updates_channel_id.is_omitted()) {j["public_updates_channel_id"] = t.public_updates_channel_id;}
        if(!t.max_video_channel_users.is_omitted()) {j["max_video_channel_users"] = t.max_video_channel_users;}
        if(!t.approximate_member_count.is_omitted()) {j["approximate_member_count"] = t.approximate_member_count;}
        if(!t.approximate_presence_count.is_omitted()) {j["approximate_presence_count"] = t.approximate_presence_count;}
        if(!t.welcome_screen.is_omitted()) {j["welcome_screen"] = t.welcome_screen;}
        if(!t.nsfw_level.is_omitted()) {j["nsfw_level"] = t.nsfw_level;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
        if(!t.premium_progress_bar_enabled.is_omitted()) {j["premium_progress_bar_enabled"] = t.premium_progress_bar_enabled;}
    }
    friend void from_json(const nlohmann::json &j, Guild &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(icon)){j.at(icon).get_to(t.icon);}
        if(j.contains(icon_hash)){j.at(icon_hash).get_to(t.icon_hash);}
        if(j.contains(splash)){j.at(splash).get_to(t.splash);}
        if(j.contains(discovery_splash)){j.at(discovery_splash).get_to(t.discovery_splash);}
        if(j.contains(owner)){j.at(owner).get_to(t.owner);}
        if(j.contains(owner_id)){j.at(owner_id).get_to(t.owner_id);}
        if(j.contains(permissions)){j.at(permissions).get_to(t.permissions);}
        if(j.contains(region)){j.at(region).get_to(t.region);}
        if(j.contains(afk_channel_id)){j.at(afk_channel_id).get_to(t.afk_channel_id);}
        if(j.contains(afk_timeout)){j.at(afk_timeout).get_to(t.afk_timeout);}
        if(j.contains(widget_enabled)){j.at(widget_enabled).get_to(t.widget_enabled);}
        if(j.contains(widget_channel_id)){j.at(widget_channel_id).get_to(t.widget_channel_id);}
        if(j.contains(verification_level)){j.at(verification_level).get_to(t.verification_level);}
        if(j.contains(default_message_notifications)){j.at(default_message_notifications).get_to(t.default_message_notifications);}
        if(j.contains(explicit_content_filter)){j.at(explicit_content_filter).get_to(t.explicit_content_filter);}
        if(j.contains(roles)){j.at(roles).get_to(t.roles);}
        if(j.contains(emojis)){j.at(emojis).get_to(t.emojis);}
        if(j.contains(features)){j.at(features).get_to(t.features);}
        if(j.contains(mfa_level)){j.at(mfa_level).get_to(t.mfa_level);}
        if(j.contains(application_id)){j.at(application_id).get_to(t.application_id);}
        if(j.contains(system_channel_id)){j.at(system_channel_id).get_to(t.system_channel_id);}
        if(j.contains(system_channel_flags)){j.at(system_channel_flags).get_to(t.system_channel_flags);}
        if(j.contains(rules_channel_id)){j.at(rules_channel_id).get_to(t.rules_channel_id);}
        if(j.contains(max_presences)){j.at(max_presences).get_to(t.max_presences);}
        if(j.contains(max_members)){j.at(max_members).get_to(t.max_members);}
        if(j.contains(vanity_url_code)){j.at(vanity_url_code).get_to(t.vanity_url_code);}
        if(j.contains(description)){j.at(description).get_to(t.description);}
        if(j.contains(banner)){j.at(banner).get_to(t.banner);}
        if(j.contains(premium_tier)){j.at(premium_tier).get_to(t.premium_tier);}
        if(j.contains(premium_subscription_count)){j.at(premium_subscription_count).get_to(t.premium_subscription_count);}
        if(j.contains(preferred_locale)){j.at(preferred_locale).get_to(t.preferred_locale);}
        if(j.contains(public_updates_channel_id)){j.at(public_updates_channel_id).get_to(t.public_updates_channel_id);}
        if(j.contains(max_video_channel_users)){j.at(max_video_channel_users).get_to(t.max_video_channel_users);}
        if(j.contains(approximate_member_count)){j.at(approximate_member_count).get_to(t.approximate_member_count);}
        if(j.contains(approximate_presence_count)){j.at(approximate_presence_count).get_to(t.approximate_presence_count);}
        if(j.contains(welcome_screen)){j.at(welcome_screen).get_to(t.welcome_screen);}
        if(j.contains(nsfw_level)){j.at(nsfw_level).get_to(t.nsfw_level);}
        if(j.contains(stickers)){j.at(stickers).get_to(t.stickers);}
        if(j.contains(premium_progress_bar_enabled)){j.at(premium_progress_bar_enabled).get_to(t.premium_progress_bar_enabled);}
    }
};

// https://discord.com/developers/docs/resources/guild#guild-preview-object-guild-preview-structure
class GuildPreview{
public:
    GuildPreview(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> icon = uninitialized,
        nullable_field<std::string> splash = uninitialized,
        nullable_field<std::string> discovery_splash = uninitialized,
        field<std::vector<Emoji> > emojis = uninitialized,
        field<std::vector<GuildFeature> > features = uninitialized,
        field<int> approximate_member_count = uninitialized,
        field<int> approximate_presence_count = uninitialized,
        nullable_field<std::string> description = uninitialized,
        field<std::vector<Sticker> > stickers = uninitialized
    ):
        id(id),
        name(name),
        icon(icon),
        splash(splash),
        discovery_splash(discovery_splash),
        emojis(emojis),
        features(features),
        approximate_member_count(approximate_member_count),
        approximate_presence_count(approximate_presence_count),
        description(description),
        stickers(stickers)
    {}
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    nullable_field<std::string> splash;
    nullable_field<std::string> discovery_splash;
    field<std::vector<Emoji> > emojis;
    field<std::vector<GuildFeature> > features;
    field<int> approximate_member_count;
    field<int> approximate_presence_count;
    nullable_field<std::string> description;
    field<std::vector<Sticker> > stickers;

    friend void to_json(nlohmann::json &j, const GuildPreview &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.splash.is_omitted()) {j["splash"] = t.splash;}
        if(!t.discovery_splash.is_omitted()) {j["discovery_splash"] = t.discovery_splash;}
        if(!t.emojis.is_omitted()) {j["emojis"] = t.emojis;}
        if(!t.features.is_omitted()) {j["features"] = t.features;}
        if(!t.approximate_member_count.is_omitted()) {j["approximate_member_count"] = t.approximate_member_count;}
        if(!t.approximate_presence_count.is_omitted()) {j["approximate_presence_count"] = t.approximate_presence_count;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
    }
    friend void from_json(const nlohmann::json &j, GuildPreview &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(icon)){j.at(icon).get_to(t.icon);}
        if(j.contains(splash)){j.at(splash).get_to(t.splash);}
        if(j.contains(discovery_splash)){j.at(discovery_splash).get_to(t.discovery_splash);}
        if(j.contains(emojis)){j.at(emojis).get_to(t.emojis);}
        if(j.contains(features)){j.at(features).get_to(t.features);}
        if(j.contains(approximate_member_count)){j.at(approximate_member_count).get_to(t.approximate_member_count);}
        if(j.contains(approximate_presence_count)){j.at(approximate_presence_count).get_to(t.approximate_presence_count);}
        if(j.contains(description)){j.at(description).get_to(t.description);}
        if(j.contains(stickers)){j.at(stickers).get_to(t.stickers);}
    }
};

// https://discord.com/developers/docs/resources/guild#guild-widget-settings-object-guild-widget-settings-structure
class GuildWidgetSettings{
public:
    GuildWidgetSettings(
        field<bool> enabled = uninitialized,
        nullable_field<Snowflake> channel_id = uninitialized
    ):
        enabled(enabled),
        channel_id(channel_id)
    {}
    
    field<bool> enabled;
    nullable_field<Snowflake> channel_id;

    friend void to_json(nlohmann::json &j, const GuildWidgetSettings &t) {
        if(!t.enabled.is_omitted()) {j["enabled"] = t.enabled;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildWidgetSettings &t {
        if(j.contains(enabled)){j.at(enabled).get_to(t.enabled);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
    }
};

// https://discord.com/developers/docs/resources/guild#guild-widget-object-guild-widget-structure
class GuildWidget{
public:
    GuildWidget(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> instant_invite = uninitialized,
        field<std::vector<Channel> > channels = uninitialized,
        field<std::vector<User> > members = uninitialized,
        field<int> presence_count = uninitialized
    ):
        id(id),
        name(name),
        instant_invite(instant_invite),
        channels(channels),
        members(members),
        presence_count(presence_count)
    {}
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> instant_invite;
    field<std::vector<Channel> > channels;
    field<std::vector<User> > members;
    field<int> presence_count;

    friend void to_json(nlohmann::json &j, const GuildWidget &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.instant_invite.is_omitted()) {j["instant_invite"] = t.instant_invite;}
        if(!t.channels.is_omitted()) {j["channels"] = t.channels;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.presence_count.is_omitted()) {j["presence_count"] = t.presence_count;}
    }
    friend void from_json(const nlohmann::json &j, GuildWidget &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(instant_invite)){j.at(instant_invite).get_to(t.instant_invite);}
        if(j.contains(channels)){j.at(channels).get_to(t.channels);}
        if(j.contains(members)){j.at(members).get_to(t.members);}
        if(j.contains(presence_count)){j.at(presence_count).get_to(t.presence_count);}
    }
};

// https://discord.com/developers/docs/resources/guild#guild-member-object-guild-member-structure
class GuildMember{
public:
    GuildMember(
        omittable_field<User> user = omitted,
        nullable_omittable_field<std::string> nick = omitted,
        nullable_omittable_field<std::string> avatar = omitted,
        field<std::vector<Snowflake> > roles = uninitialized,
        field<Timestamp> joined_at = uninitialized,
        nullable_omittable_field<Timestamp> premium_since = omitted,
        field<bool> deaf = uninitialized,
        field<bool> mute = uninitialized,
        field<int> flags = uninitialized,
        omittable_field<bool> pending = omitted,
        omittable_field<std::string> permissions = omitted,
        nullable_omittable_field<Timestamp> communication_disabled_until = omitted
    ):
        user(user),
        nick(nick),
        avatar(avatar),
        roles(roles),
        joined_at(joined_at),
        premium_since(premium_since),
        deaf(deaf),
        mute(mute),
        flags(flags),
        pending(pending),
        permissions(permissions),
        communication_disabled_until(communication_disabled_until)
    {}
    
    omittable_field<User> user;
    nullable_omittable_field<std::string> nick;
    nullable_omittable_field<std::string> avatar;
    field<std::vector<Snowflake> > roles;
    field<Timestamp> joined_at;
    nullable_omittable_field<Timestamp> premium_since;
    field<bool> deaf;
    field<bool> mute;
    field<int> flags;
    omittable_field<bool> pending;
    omittable_field<std::string> permissions;
    nullable_omittable_field<Timestamp> communication_disabled_until;

    friend void to_json(nlohmann::json &j, const GuildMember &t) {
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.nick.is_omitted()) {j["nick"] = t.nick;}
        if(!t.avatar.is_omitted()) {j["avatar"] = t.avatar;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.joined_at.is_omitted()) {j["joined_at"] = t.joined_at;}
        if(!t.premium_since.is_omitted()) {j["premium_since"] = t.premium_since;}
        if(!t.deaf.is_omitted()) {j["deaf"] = t.deaf;}
        if(!t.mute.is_omitted()) {j["mute"] = t.mute;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.pending.is_omitted()) {j["pending"] = t.pending;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
        if(!t.communication_disabled_until.is_omitted()) {j["communication_disabled_until"] = t.communication_disabled_until;}
    }
    friend void from_json(const nlohmann::json &j, GuildMember &t {
        if(j.contains(user)){j.at(user).get_to(t.user);}
        if(j.contains(nick)){j.at(nick).get_to(t.nick);}
        if(j.contains(avatar)){j.at(avatar).get_to(t.avatar);}
        if(j.contains(roles)){j.at(roles).get_to(t.roles);}
        if(j.contains(joined_at)){j.at(joined_at).get_to(t.joined_at);}
        if(j.contains(premium_since)){j.at(premium_since).get_to(t.premium_since);}
        if(j.contains(deaf)){j.at(deaf).get_to(t.deaf);}
        if(j.contains(mute)){j.at(mute).get_to(t.mute);}
        if(j.contains(flags)){j.at(flags).get_to(t.flags);}
        if(j.contains(pending)){j.at(pending).get_to(t.pending);}
        if(j.contains(permissions)){j.at(permissions).get_to(t.permissions);}
        if(j.contains(communication_disabled_until)){j.at(communication_disabled_until).get_to(t.communication_disabled_until);}
    }
};

// https://discord.com/developers/docs/resources/guild#integration-object-integration-structure
class Integration{
public:
    Integration(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<std::string> type = uninitialized,
        field<bool> enabled = uninitialized,
        omittable_field<bool> syncing = omitted,
        omittable_field<Snowflake> role_id = omitted,
        omittable_field<bool> enable_emoticons = omitted,
        omittable_field<IntegrationExpireBehavior> expire_behavior = omitted,
        omittable_field<int> expire_grace_period = omitted,
        omittable_field<User> user = omitted,
        field<IntegrationAccount> account = uninitialized,
        omittable_field<Timestamp> synced_at = omitted,
        omittable_field<int> subscriber_count = omitted,
        omittable_field<bool> revoked = omitted,
        omittable_field<Application> application = omitted,
        omittable_field<std::vector<Oauth2Scope> > scopes = omitted
    ):
        id(id),
        name(name),
        type(type),
        enabled(enabled),
        syncing(syncing),
        role_id(role_id),
        enable_emoticons(enable_emoticons),
        expire_behavior(expire_behavior),
        expire_grace_period(expire_grace_period),
        user(user),
        account(account),
        synced_at(synced_at),
        subscriber_count(subscriber_count),
        revoked(revoked),
        application(application),
        scopes(scopes)
    {}
    
    field<Snowflake> id;
    field<std::string> name;
    field<std::string> type;
    field<bool> enabled;
    omittable_field<bool> syncing;
    omittable_field<Snowflake> role_id;
    omittable_field<bool> enable_emoticons;
    omittable_field<IntegrationExpireBehavior> expire_behavior;
    omittable_field<int> expire_grace_period;
    omittable_field<User> user;
    field<IntegrationAccount> account;
    omittable_field<Timestamp> synced_at;
    omittable_field<int> subscriber_count;
    omittable_field<bool> revoked;
    omittable_field<Application> application;
    omittable_field<std::vector<Oauth2Scope> > scopes;

    friend void to_json(nlohmann::json &j, const Integration &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.enabled.is_omitted()) {j["enabled"] = t.enabled;}
        if(!t.syncing.is_omitted()) {j["syncing"] = t.syncing;}
        if(!t.role_id.is_omitted()) {j["role_id"] = t.role_id;}
        if(!t.enable_emoticons.is_omitted()) {j["enable_emoticons"] = t.enable_emoticons;}
        if(!t.expire_behavior.is_omitted()) {j["expire_behavior"] = t.expire_behavior;}
        if(!t.expire_grace_period.is_omitted()) {j["expire_grace_period"] = t.expire_grace_period;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.account.is_omitted()) {j["account"] = t.account;}
        if(!t.synced_at.is_omitted()) {j["synced_at"] = t.synced_at;}
        if(!t.subscriber_count.is_omitted()) {j["subscriber_count"] = t.subscriber_count;}
        if(!t.revoked.is_omitted()) {j["revoked"] = t.revoked;}
        if(!t.application.is_omitted()) {j["application"] = t.application;}
        if(!t.scopes.is_omitted()) {j["scopes"] = t.scopes;}
    }
    friend void from_json(const nlohmann::json &j, Integration &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(type)){j.at(type).get_to(t.type);}
        if(j.contains(enabled)){j.at(enabled).get_to(t.enabled);}
        if(j.contains(syncing)){j.at(syncing).get_to(t.syncing);}
        if(j.contains(role_id)){j.at(role_id).get_to(t.role_id);}
        if(j.contains(enable_emoticons)){j.at(enable_emoticons).get_to(t.enable_emoticons);}
        if(j.contains(expire_behavior)){j.at(expire_behavior).get_to(t.expire_behavior);}
        if(j.contains(expire_grace_period)){j.at(expire_grace_period).get_to(t.expire_grace_period);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
        if(j.contains(account)){j.at(account).get_to(t.account);}
        if(j.contains(synced_at)){j.at(synced_at).get_to(t.synced_at);}
        if(j.contains(subscriber_count)){j.at(subscriber_count).get_to(t.subscriber_count);}
        if(j.contains(revoked)){j.at(revoked).get_to(t.revoked);}
        if(j.contains(application)){j.at(application).get_to(t.application);}
        if(j.contains(scopes)){j.at(scopes).get_to(t.scopes);}
    }
};

// https://discord.com/developers/docs/resources/guild#integration-account-object-integration-account-structure
class IntegrationAccount{
public:
    IntegrationAccount(
        field<std::string> id = uninitialized,
        field<std::string> name = uninitialized
    ):
        id(id),
        name(name)
    {}
    
    field<std::string> id;
    field<std::string> name;

    friend void to_json(nlohmann::json &j, const IntegrationAccount &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationAccount &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
    }
};

// https://discord.com/developers/docs/resources/guild#integration-application-object-integration-application-structure
class IntegrationApplication{
public:
    IntegrationApplication(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> icon = uninitialized,
        field<std::string> description = uninitialized,
        omittable_field<User> bot = omitted
    ):
        id(id),
        name(name),
        icon(icon),
        description(description),
        bot(bot)
    {}
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    field<std::string> description;
    omittable_field<User> bot;

    friend void to_json(nlohmann::json &j, const IntegrationApplication &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.bot.is_omitted()) {j["bot"] = t.bot;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationApplication &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(icon)){j.at(icon).get_to(t.icon);}
        if(j.contains(description)){j.at(description).get_to(t.description);}
        if(j.contains(bot)){j.at(bot).get_to(t.bot);}
    }
};

// https://discord.com/developers/docs/resources/guild#ban-object-ban-structure
class Ban{
public:
    Ban(
        nullable_field<std::string> reason = uninitialized,
        field<User> user = uninitialized
    ):
        reason(reason),
        user(user)
    {}
    
    nullable_field<std::string> reason;
    field<User> user;

    friend void to_json(nlohmann::json &j, const Ban &t) {
        if(!t.reason.is_omitted()) {j["reason"] = t.reason;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, Ban &t {
        if(j.contains(reason)){j.at(reason).get_to(t.reason);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
    }
};

// https://discord.com/developers/docs/resources/guild#welcome-screen-object-welcome-screen-structure
class WelcomeScreen{
public:
    WelcomeScreen(
        nullable_field<std::string> description = uninitialized,
        field<std::vector<WelcomeScreenChannel> > welcome_channels = uninitialized
    ):
        description(description),
        welcome_channels(welcome_channels)
    {}
    
    nullable_field<std::string> description;
    field<std::vector<WelcomeScreenChannel> > welcome_channels;

    friend void to_json(nlohmann::json &j, const WelcomeScreen &t) {
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.welcome_channels.is_omitted()) {j["welcome_channels"] = t.welcome_channels;}
    }
    friend void from_json(const nlohmann::json &j, WelcomeScreen &t {
        if(j.contains(description)){j.at(description).get_to(t.description);}
        if(j.contains(welcome_channels)){j.at(welcome_channels).get_to(t.welcome_channels);}
    }
};

// https://discord.com/developers/docs/resources/guild#welcome-screen-object-welcome-screen-channel-structure
class WelcomeScreenChannel{
public:
    WelcomeScreenChannel(
        field<Snowflake> channel_id = uninitialized,
        field<std::string> description = uninitialized,
        nullable_field<Snowflake> emoji_id = uninitialized,
        nullable_field<std::string> emoji_name = uninitialized
    ):
        channel_id(channel_id),
        description(description),
        emoji_id(emoji_id),
        emoji_name(emoji_name)
    {}
    
    field<Snowflake> channel_id;
    field<std::string> description;
    nullable_field<Snowflake> emoji_id;
    nullable_field<std::string> emoji_name;

    friend void to_json(nlohmann::json &j, const WelcomeScreenChannel &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.emoji_id.is_omitted()) {j["emoji_id"] = t.emoji_id;}
        if(!t.emoji_name.is_omitted()) {j["emoji_name"] = t.emoji_name;}
    }
    friend void from_json(const nlohmann::json &j, WelcomeScreenChannel &t {
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(description)){j.at(description).get_to(t.description);}
        if(j.contains(emoji_id)){j.at(emoji_id).get_to(t.emoji_id);}
        if(j.contains(emoji_name)){j.at(emoji_name).get_to(t.emoji_name);}
    }
};

// https://discord.com/developers/docs/resources/guild#list-active-guild-threads-response-body
class ListActiveGuildThreadsResponse{
public:
    ListActiveGuildThreadsResponse(
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<ThreadMembers> > members = uninitialized
    ):
        threads(threads),
        members(members)
    {}
    
    field<std::vector<Channel> > threads;
    field<std::vector<ThreadMembers> > members;

    friend void to_json(nlohmann::json &j, const ListActiveGuildThreadsResponse &t) {
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
    }
    friend void from_json(const nlohmann::json &j, ListActiveGuildThreadsResponse &t {
        if(j.contains(threads)){j.at(threads).get_to(t.threads);}
        if(j.contains(members)){j.at(members).get_to(t.members);}
    }
};
