#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/interactions/message-components#button-object-button-structure
class Button: public Component{
  public:
    Button(
        field<int> style = uninitialized,
        omittable_field<std::string> label = omitted,
        omittable_field<Emoji> emoji = omitted,
        omittable_field<std::string> custom_id = omitted,
        omittable_field<std::string> url = omitted,
        omittable_field<bool> disabled = omitted
    ):
        Component(
            2
        ),
        style(style),
        label(label),
        emoji(emoji),
        custom_id(custom_id),
        url(url),
        disabled(disabled)
    {}
    
    field<int> style;
    omittable_field<std::string> label;
    omittable_field<Emoji> emoji;
    omittable_field<std::string> custom_id;
    omittable_field<std::string> url;
    omittable_field<bool> disabled;

    friend void to_json(nlohmann::json &j, const Button &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.style.is_omitted()) {j["style"] = t.style;}
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.disabled.is_omitted()) {j["disabled"] = t.disabled;}
    }
    friend void from_json(const nlohmann::json &j, Button &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("style")){j.at("style").get_to(t.style);}
        if(j.contains("label")){j.at("label").get_to(t.label);}
        if(j.contains("emoji")){j.at("emoji").get_to(t.emoji);}
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("disabled")){j.at("disabled").get_to(t.disabled);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#select-menu-object-select-menu-structure
class SelectMenu: public Component{
  public:
    SelectMenu(
        field<int> type = uninitialized,
        field<std::string> custom_id = uninitialized,
        omittable_field<std::vector<SelectOption> > options = omitted,
        omittable_field<std::vector<ChannelType> > channel_types = omitted,
        omittable_field<std::string> placeholder = omitted,
        omittable_field<int> min_values = omitted,
        omittable_field<int> max_values = omitted,
        omittable_field<bool> disabled = omitted
    ):
        Component(
            type
        ),
        custom_id(custom_id),
        options(options),
        channel_types(channel_types),
        placeholder(placeholder),
        min_values(min_values),
        max_values(max_values),
        disabled(disabled)
    {}
    
    field<std::string> custom_id;
    omittable_field<std::vector<SelectOption> > options;
    omittable_field<std::vector<ChannelType> > channel_types;
    omittable_field<std::string> placeholder;
    omittable_field<int> min_values;
    omittable_field<int> max_values;
    omittable_field<bool> disabled;

    friend void to_json(nlohmann::json &j, const SelectMenu &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.channel_types.is_omitted()) {j["channel_types"] = t.channel_types;}
        if(!t.placeholder.is_omitted()) {j["placeholder"] = t.placeholder;}
        if(!t.min_values.is_omitted()) {j["min_values"] = t.min_values;}
        if(!t.max_values.is_omitted()) {j["max_values"] = t.max_values;}
        if(!t.disabled.is_omitted()) {j["disabled"] = t.disabled;}
    }
    friend void from_json(const nlohmann::json &j, SelectMenu &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("options")){j.at("options").get_to(t.options);}
        if(j.contains("channel_types")){j.at("channel_types").get_to(t.channel_types);}
        if(j.contains("placeholder")){j.at("placeholder").get_to(t.placeholder);}
        if(j.contains("min_values")){j.at("min_values").get_to(t.min_values);}
        if(j.contains("max_values")){j.at("max_values").get_to(t.max_values);}
        if(j.contains("disabled")){j.at("disabled").get_to(t.disabled);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#text-inputs-text-input-structure
class TextInput: public Component{
  public:
    TextInput(
        field<std::string> custom_id = uninitialized,
        field<int> style = uninitialized,
        field<std::string> label = uninitialized,
        omittable_field<int> min_length = omitted,
        omittable_field<int> max_length = omitted,
        omittable_field<bool> required = omitted,
        omittable_field<std::string> value = omitted,
        omittable_field<std::string> placeholder = omitted
    ):
        Component(
            4
        ),
        custom_id(custom_id),
        style(style),
        label(label),
        min_length(min_length),
        max_length(max_length),
        required(required),
        value(value),
        placeholder(placeholder)
    {}
    
    field<std::string> custom_id;
    field<int> style;
    field<std::string> label;
    omittable_field<int> min_length;
    omittable_field<int> max_length;
    omittable_field<bool> required;
    omittable_field<std::string> value;
    omittable_field<std::string> placeholder;

    friend void to_json(nlohmann::json &j, const TextInput &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.style.is_omitted()) {j["style"] = t.style;}
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.min_length.is_omitted()) {j["min_length"] = t.min_length;}
        if(!t.max_length.is_omitted()) {j["max_length"] = t.max_length;}
        if(!t.required.is_omitted()) {j["required"] = t.required;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.placeholder.is_omitted()) {j["placeholder"] = t.placeholder;}
    }
    friend void from_json(const nlohmann::json &j, TextInput &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("style")){j.at("style").get_to(t.style);}
        if(j.contains("label")){j.at("label").get_to(t.label);}
        if(j.contains("min_length")){j.at("min_length").get_to(t.min_length);}
        if(j.contains("max_length")){j.at("max_length").get_to(t.max_length);}
        if(j.contains("required")){j.at("required").get_to(t.required);}
        if(j.contains("value")){j.at("value").get_to(t.value);}
        if(j.contains("placeholder")){j.at("placeholder").get_to(t.placeholder);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#action-rows
class ActionRow: public Component{
  public:
    ActionRow(
        field<std::vector<Component> > components = uninitialized
    ):
        Component(
            1
        ),
        components(components)
    {}
    
    field<std::vector<Component> > components;

    friend void to_json(nlohmann::json &j, const ActionRow &t) {
        if(!t.components.is_omitted()) {j["components"] = t.components;}
    }
    friend void from_json(const nlohmann::json &j, ActionRow &t) {
        if(j.contains("components")){j.at("components").get_to(t.components);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#thread-member-update-thread-member-update-event-extra-fields
class ThreadMemberUpdateEvent: public ThreadMember{
  public:
    ThreadMemberUpdateEvent(
        omittable_field<Snowflake> id = omitted,
        omittable_field<Snowflake> user_id = omitted,
        field<Timestamp> join_timestamp = uninitialized,
        field<int> flags = uninitialized,
        omittable_field<GuildMember> member = omitted,
        field<Snowflake> guild_id = uninitialized
    ):
        ThreadMember(
            id,
            user_id,
            join_timestamp,
            flags,
            member
        ),
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const ThreadMemberUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, ThreadMemberUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-create-guild-create-extra-fields
class GuildCreateEvent: public Guild{
  public:
    GuildCreateEvent(
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
        field<bool> premium_progress_bar_enabled = uninitialized,
        omittable_field<bool> unavailable = omitted,
        field<Timestamp> joined_at = uninitialized,
        field<bool> large = uninitialized,
        field<int> member_count = uninitialized,
        field<std::vector<VoiceState> > voice_states = uninitialized,
        field<std::vector<GuildMember> > members = uninitialized,
        field<std::vector<Channel> > channels = uninitialized,
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<PresenceUpdate> > presences = uninitialized,
        field<std::vector<StageInstance> > stage_instances = uninitialized,
        field<std::vector<GuildScheduledEvent> > guild_scheduled_events = uninitialized
    ):
        Guild(
            id,
            name,
            icon,
            icon_hash,
            splash,
            discovery_splash,
            owner,
            owner_id,
            permissions,
            region,
            afk_channel_id,
            afk_timeout,
            widget_enabled,
            widget_channel_id,
            verification_level,
            default_message_notifications,
            explicit_content_filter,
            roles,
            emojis,
            features,
            mfa_level,
            application_id,
            system_channel_id,
            system_channel_flags,
            rules_channel_id,
            max_presences,
            max_members,
            vanity_url_code,
            description,
            banner,
            premium_tier,
            premium_subscription_count,
            preferred_locale,
            public_updates_channel_id,
            max_video_channel_users,
            approximate_member_count,
            approximate_presence_count,
            welcome_screen,
            nsfw_level,
            stickers,
            premium_progress_bar_enabled,
            unavailable
        ),
        joined_at(joined_at),
        large(large),
        member_count(member_count),
        voice_states(voice_states),
        members(members),
        channels(channels),
        threads(threads),
        presences(presences),
        stage_instances(stage_instances),
        guild_scheduled_events(guild_scheduled_events)
    {}
    
    field<Timestamp> joined_at;
    field<bool> large;
    field<int> member_count;
    field<std::vector<VoiceState> > voice_states;
    field<std::vector<GuildMember> > members;
    field<std::vector<Channel> > channels;
    field<std::vector<Channel> > threads;
    field<std::vector<PresenceUpdate> > presences;
    field<std::vector<StageInstance> > stage_instances;
    field<std::vector<GuildScheduledEvent> > guild_scheduled_events;

    friend void to_json(nlohmann::json &j, const GuildCreateEvent &t) {
        if(!t.joined_at.is_omitted()) {j["joined_at"] = t.joined_at;}
        if(!t.large.is_omitted()) {j["large"] = t.large;}
        if(!t.unavailable.is_omitted()) {j["unavailable"] = t.unavailable;}
        if(!t.member_count.is_omitted()) {j["member_count"] = t.member_count;}
        if(!t.voice_states.is_omitted()) {j["voice_states"] = t.voice_states;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.channels.is_omitted()) {j["channels"] = t.channels;}
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.presences.is_omitted()) {j["presences"] = t.presences;}
        if(!t.stage_instances.is_omitted()) {j["stage_instances"] = t.stage_instances;}
        if(!t.guild_scheduled_events.is_omitted()) {j["guild_scheduled_events"] = t.guild_scheduled_events;}
    }
    friend void from_json(const nlohmann::json &j, GuildCreateEvent &t) {
        if(j.contains("joined_at")){j.at("joined_at").get_to(t.joined_at);}
        if(j.contains("large")){j.at("large").get_to(t.large);}
        if(j.contains("unavailable")){j.at("unavailable").get_to(t.unavailable);}
        if(j.contains("member_count")){j.at("member_count").get_to(t.member_count);}
        if(j.contains("voice_states")){j.at("voice_states").get_to(t.voice_states);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("channels")){j.at("channels").get_to(t.channels);}
        if(j.contains("threads")){j.at("threads").get_to(t.threads);}
        if(j.contains("presences")){j.at("presences").get_to(t.presences);}
        if(j.contains("stage_instances")){j.at("stage_instances").get_to(t.stage_instances);}
        if(j.contains("guild_scheduled_events")){j.at("guild_scheduled_events").get_to(t.guild_scheduled_events);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-member-add-guild-member-add-extra-fields
class GuildMemberAddEvent: public GuildMember{
  public:
    GuildMemberAddEvent(
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
        nullable_omittable_field<Timestamp> communication_disabled_until = omitted,
        field<Snowflake> guild_id = uninitialized
    ):
        GuildMember(
            user,
            nick,
            avatar,
            roles,
            joined_at,
            premium_since,
            deaf,
            mute,
            flags,
            pending,
            permissions,
            communication_disabled_until
        ),
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildMemberAddEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildMemberAddEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#message-create-message-create-extra-fields
class MessageCreateEvent: public Message{
  public:
    MessageCreateEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<User> author = uninitialized,
        field<std::string> content = uninitialized,
        field<Timestamp> timestamp = uninitialized,
        nullable_field<Timestamp> edited_timestamp = uninitialized,
        field<bool> tts = uninitialized,
        field<bool> mention_everyone = uninitialized,
        field<std::vector<User> > mentions = uninitialized,
        field<std::vector<Snowflake> > mention_roles = uninitialized,
        omittable_field<std::vector<ChannelMention> > mention_channels = omitted,
        field<std::vector<Attachment> > attachments = uninitialized,
        field<std::vector<Embed> > embeds = uninitialized,
        omittable_field<std::vector<Reaction> > reactions = omitted,
        omittable_field<std::variant<int, std::string> > nonce = omitted,
        field<bool> pinned = uninitialized,
        omittable_field<Snowflake> webhook_id = omitted,
        field<int> type = uninitialized,
        omittable_field<MessageActivity> activity = omitted,
        omittable_field<Application> application = omitted,
        omittable_field<Snowflake> application_id = omitted,
        omittable_field<MessageReference> message_reference = omitted,
        omittable_field<int> flags = omitted,
        nullable_omittable_field<Message> referenced_message = omitted,
        omittable_field<MessageInteraction> interaction = omitted,
        omittable_field<Channel> thread = omitted,
        omittable_field<std::vector<Component> > components = omitted,
        omittable_field<std::vector<StickerItem> > sticker_items = omitted,
        omittable_field<std::vector<Sticker> > stickers = omitted,
        omittable_field<int> position = omitted,
        omittable_field<RoleSubscriptionData> role_subscription_data = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<GuildMember> member = omitted
    ):
        Message(
            id,
            channel_id,
            author,
            content,
            timestamp,
            edited_timestamp,
            tts,
            mention_everyone,
            mentions,
            mention_roles,
            mention_channels,
            attachments,
            embeds,
            reactions,
            nonce,
            pinned,
            webhook_id,
            type,
            activity,
            application,
            application_id,
            message_reference,
            flags,
            referenced_message,
            interaction,
            thread,
            components,
            sticker_items,
            stickers,
            position,
            role_subscription_data
        ),
        guild_id(guild_id),
        member(member)
    {}
    
    omittable_field<Snowflake> guild_id;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const MessageCreateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.mentions.is_omitted()) {j["mentions"] = t.mentions;}
    }
    friend void from_json(const nlohmann::json &j, MessageCreateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
        if(j.contains("mentions")){j.at("mentions").get_to(t.mentions);}
    }
};
