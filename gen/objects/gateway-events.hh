#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/topics/gateway-events#payload-structure
class Payload{
  public:
    Payload(
        field<int> op = uninitialized,
        nullable_field<json> d = uninitialized,
        nullable_field<int> s = uninitialized,
        nullable_field<std::string> t = uninitialized
    ): 
        op(op),
        d(d),
        s(s),
        t(t)
    {}
    
    field<int> op;
    nullable_field<json> d;
    nullable_field<int> s;
    nullable_field<std::string> t;

    friend void to_json(nlohmann::json &j, const Payload &t) {
        //ToJsonExtra
        if(!t.op.is_omitted()) {j["op"] = t.op;}
        if(!t.d.is_omitted()) {j["d"] = t.d;}
        if(!t.s.is_omitted()) {j["s"] = t.s;}
        if(!t.t.is_omitted()) {j["t"] = t.t;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#identify-identify-structure
class Identify{
  public:
    Identify(
        field<std::string> token = uninitialized,
        field<IdentifyConnectionProperties> properties = uninitialized,
        omittable_field<bool> compress = omitted,
        omittable_field<int> large_threshold = omitted,
        omittable_field<std::array<int, 2> > shard = omitted,
        omittable_field<GatewayPresenceUpdate> presence = omitted,
        field<int> intents = uninitialized
    ): 
        token(token),
        properties(properties),
        compress(compress),
        large_threshold(large_threshold),
        shard(shard),
        presence(presence),
        intents(intents)
    {}
    
    field<std::string> token;
    field<IdentifyConnectionProperties> properties;
    omittable_field<bool> compress;
    omittable_field<int> large_threshold;
    omittable_field<std::array<int, 2> > shard;
    omittable_field<GatewayPresenceUpdate> presence;
    field<int> intents;

    friend void to_json(nlohmann::json &j, const Identify &t) {
        //ToJsonExtra
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.properties.is_omitted()) {j["properties"] = t.properties;}
        if(!t.compress.is_omitted()) {j["compress"] = t.compress;}
        if(!t.large_threshold.is_omitted()) {j["large_threshold"] = t.large_threshold;}
        if(!t.shard.is_omitted()) {j["shard"] = t.shard;}
        if(!t.presence.is_omitted()) {j["presence"] = t.presence;}
        if(!t.intents.is_omitted()) {j["intents"] = t.intents;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#identify-identify-connection-properties
class IdentifyConnectionProperties{
  public:
    IdentifyConnectionProperties(
        field<std::string> os = uninitialized,
        field<std::string> browser = uninitialized,
        field<std::string> device = uninitialized
    ): 
        os(os),
        browser(browser),
        device(device)
    {}
    
    field<std::string> os;
    field<std::string> browser;
    field<std::string> device;

    friend void to_json(nlohmann::json &j, const IdentifyConnectionProperties &t) {
        //ToJsonExtra
        if(!t.os.is_omitted()) {j["os"] = t.os;}
        if(!t.browser.is_omitted()) {j["browser"] = t.browser;}
        if(!t.device.is_omitted()) {j["device"] = t.device;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#resume-resume-structure
class Resume{
  public:
    Resume(
        field<std::string> token = uninitialized,
        field<std::string> session_id = uninitialized,
        field<int> seq = uninitialized
    ): 
        token(token),
        session_id(session_id),
        seq(seq)
    {}
    
    field<std::string> token;
    field<std::string> session_id;
    field<int> seq;

    friend void to_json(nlohmann::json &j, const Resume &t) {
        //ToJsonExtra
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.session_id.is_omitted()) {j["session_id"] = t.session_id;}
        if(!t.seq.is_omitted()) {j["seq"] = t.seq;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#request-guild-members-guild-request-members-structure
class GuildRequestMembers{
  public:
    GuildRequestMembers(
        field<Snowflake> guild_id = uninitialized,
        omittable_field<std::string> query = omitted,
        field<int> limit = uninitialized,
        omittable_field<bool> presences = omitted,
        omittable_field<std::variant<Snowflake, std::vector<Snowflake> > > user_ids = omitted,
        omittable_field<std::string> nonce = omitted
    ): 
        guild_id(guild_id),
        query(query),
        limit(limit),
        presences(presences),
        user_ids(user_ids),
        nonce(nonce)
    {}
    
    field<Snowflake> guild_id;
    omittable_field<std::string> query;
    field<int> limit;
    omittable_field<bool> presences;
    omittable_field<std::variant<Snowflake, std::vector<Snowflake> > > user_ids;
    omittable_field<std::string> nonce;

    friend void to_json(nlohmann::json &j, const GuildRequestMembers &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.query.is_omitted()) {j["query"] = t.query;}
        if(!t.limit.is_omitted()) {j["limit"] = t.limit;}
        if(!t.presences.is_omitted()) {j["presences"] = t.presences;}
        if(!t.user_ids.is_omitted()) {j["user_ids"] = t.user_ids;}
        if(!t.nonce.is_omitted()) {j["nonce"] = t.nonce;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#update-voice-state-gateway-voice-state-update-structure
class GatewayVoiceStateUpdate{
  public:
    GatewayVoiceStateUpdate(
        field<Snowflake> guild_id = uninitialized,
        nullable_field<Snowflake> channel_id = uninitialized,
        field<bool> self_mute = uninitialized,
        field<bool> self_deaf = uninitialized
    ): 
        guild_id(guild_id),
        channel_id(channel_id),
        self_mute(self_mute),
        self_deaf(self_deaf)
    {}
    
    field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    field<bool> self_mute;
    field<bool> self_deaf;

    friend void to_json(nlohmann::json &j, const GatewayVoiceStateUpdate &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.self_mute.is_omitted()) {j["self_mute"] = t.self_mute;}
        if(!t.self_deaf.is_omitted()) {j["self_deaf"] = t.self_deaf;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#update-presence-gateway-presence-update-structure
class GatewayPresenceUpdate{
  public:
    GatewayPresenceUpdate(
        nullable_field<int> since = uninitialized,
        field<std::vector<Activity> > activities = uninitialized,
        field<std::string> status = uninitialized,
        field<bool> afk = uninitialized
    ): 
        since(since),
        activities(activities),
        status(status),
        afk(afk)
    {}
    
    nullable_field<int> since;
    field<std::vector<Activity> > activities;
    field<std::string> status;
    field<bool> afk;

    friend void to_json(nlohmann::json &j, const GatewayPresenceUpdate &t) {
        //ToJsonExtra
        if(!t.since.is_omitted()) {j["since"] = t.since;}
        if(!t.activities.is_omitted()) {j["activities"] = t.activities;}
        if(!t.status.is_omitted()) {j["status"] = t.status;}
        if(!t.afk.is_omitted()) {j["afk"] = t.afk;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#hello-hello-structure
class Hello{
  public:
    Hello(
        field<int> heartbeat_interval = uninitialized
    ): 
        heartbeat_interval(heartbeat_interval)
    {}
    
    field<int> heartbeat_interval;

    friend void to_json(nlohmann::json &j, const Hello &t) {
        //ToJsonExtra
        if(!t.heartbeat_interval.is_omitted()) {j["heartbeat_interval"] = t.heartbeat_interval;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#ready-ready-event-fields
class ReadyEvent{
  public:
    ReadyEvent(
        field<int> v = uninitialized,
        field<User> user = uninitialized,
        field<std::vector<UnavailableGuild> > guilds = uninitialized,
        field<std::string> session_id = uninitialized,
        field<std::string> resume_gateway_url = uninitialized,
        omittable_field<std::Array<int, 2>> shard = omitted,
        field<Application> application = uninitialized
    ): 
        v(v),
        user(user),
        guilds(guilds),
        session_id(session_id),
        resume_gateway_url(resume_gateway_url),
        shard(shard),
        application(application)
    {}
    
    field<int> v;
    field<User> user;
    field<std::vector<UnavailableGuild> > guilds;
    field<std::string> session_id;
    field<std::string> resume_gateway_url;
    omittable_field<std::Array<int, 2>> shard;
    field<Application> application;

    friend void to_json(nlohmann::json &j, const ReadyEvent &t) {
        //ToJsonExtra
        if(!t.v.is_omitted()) {j["v"] = t.v;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.guilds.is_omitted()) {j["guilds"] = t.guilds;}
        if(!t.session_id.is_omitted()) {j["session_id"] = t.session_id;}
        if(!t.resume_gateway_url.is_omitted()) {j["resume_gateway_url"] = t.resume_gateway_url;}
        if(!t.shard.is_omitted()) {j["shard"] = t.shard;}
        if(!t.application.is_omitted()) {j["application"] = t.application;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#auto-moderation-action-execution-auto-moderation-action-execution-event-fields
class AutoModerationActionExecutionEvent{
  public:
    AutoModerationActionExecutionEvent(
        field<Snowflake> guild_id = uninitialized,
        field<AutoModerationAction> action = uninitialized,
        field<Snowflake> rule_id = uninitialized,
        field<TriggerType> rule_trigger_type = uninitialized,
        field<Snowflake> user_id = uninitialized,
        omittable_field<Snowflake> channel_id = omitted,
        omittable_field<Snowflake> message_id = omitted,
        omittable_field<Snowflake> alert_system_message_id = omitted,
        field<std::string> content = uninitialized,
        nullable_field<std::string> matched_keyword = uninitialized,
        nullable_field<std::string> matched_content = uninitialized
    ): 
        guild_id(guild_id),
        action(action),
        rule_id(rule_id),
        rule_trigger_type(rule_trigger_type),
        user_id(user_id),
        channel_id(channel_id),
        message_id(message_id),
        alert_system_message_id(alert_system_message_id),
        content(content),
        matched_keyword(matched_keyword),
        matched_content(matched_content)
    {}
    
    field<Snowflake> guild_id;
    field<AutoModerationAction> action;
    field<Snowflake> rule_id;
    field<TriggerType> rule_trigger_type;
    field<Snowflake> user_id;
    omittable_field<Snowflake> channel_id;
    omittable_field<Snowflake> message_id;
    omittable_field<Snowflake> alert_system_message_id;
    field<std::string> content;
    nullable_field<std::string> matched_keyword;
    nullable_field<std::string> matched_content;

    friend void to_json(nlohmann::json &j, const AutoModerationActionExecutionEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.action.is_omitted()) {j["action"] = t.action;}
        if(!t.rule_id.is_omitted()) {j["rule_id"] = t.rule_id;}
        if(!t.rule_trigger_type.is_omitted()) {j["rule_trigger_type"] = t.rule_trigger_type;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.alert_system_message_id.is_omitted()) {j["alert_system_message_id"] = t.alert_system_message_id;}
        if(!t.content.is_omitted()) {j["content"] = t.content;}
        if(!t.matched_keyword.is_omitted()) {j["matched_keyword"] = t.matched_keyword;}
        if(!t.matched_content.is_omitted()) {j["matched_content"] = t.matched_content;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#thread-list-sync-thread-list-sync-event-fields
class ThreadListSyncEvent{
  public:
    ThreadListSyncEvent(
        field<Snowflake> guild_id = uninitialized,
        omittable_field<std::vector<Snowflake> > channel_ids = omitted,
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<ThreadMember> > members = uninitialized
    ): 
        guild_id(guild_id),
        channel_ids(channel_ids),
        threads(threads),
        members(members)
    {}
    
    field<Snowflake> guild_id;
    omittable_field<std::vector<Snowflake> > channel_ids;
    field<std::vector<Channel> > threads;
    field<std::vector<ThreadMember> > members;

    friend void to_json(nlohmann::json &j, const ThreadListSyncEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_ids.is_omitted()) {j["channel_ids"] = t.channel_ids;}
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#thread-member-update-thread-member-update-event-extra-fields
class ThreadMemberUpdateEventExtra{
  public:
    ThreadMemberUpdateEventExtra(
        field<Snowflake> guild_id = uninitialized
    ): 
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const ThreadMemberUpdateEventExtra &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#thread-members-update-thread-members-update-event-fields
class ThreadMembersUpdateEvent{
  public:
    ThreadMembersUpdateEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<int> member_count = uninitialized,
        omittable_field<std::vector<ThreadMember> > added_members = omitted,
        omittable_field<std::vector<Snowflake> > removed_member_ids = omitted
    ): 
        id(id),
        guild_id(guild_id),
        member_count(member_count),
        added_members(added_members),
        removed_member_ids(removed_member_ids)
    {}
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<int> member_count;
    omittable_field<std::vector<ThreadMember> > added_members;
    omittable_field<std::vector<Snowflake> > removed_member_ids;

    friend void to_json(nlohmann::json &j, const ThreadMembersUpdateEvent &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member_count.is_omitted()) {j["member_count"] = t.member_count;}
        if(!t.added_members.is_omitted()) {j["added_members"] = t.added_members;}
        if(!t.removed_member_ids.is_omitted()) {j["removed_member_ids"] = t.removed_member_ids;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#channel-pins-update-channel-pins-update-event-fields
class ChannelPinsUpdateEvent{
  public:
    ChannelPinsUpdateEvent(
        omittable_field<Snowflake> guild_id = omitted,
        field<Snowflake> channel_id = uninitialized,
        nullable_omittable_field<Timestamp> last_pin_timestamp = omitted
    ): 
        guild_id(guild_id),
        channel_id(channel_id),
        last_pin_timestamp(last_pin_timestamp)
    {}
    
    omittable_field<Snowflake> guild_id;
    field<Snowflake> channel_id;
    nullable_omittable_field<Timestamp> last_pin_timestamp;

    friend void to_json(nlohmann::json &j, const ChannelPinsUpdateEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.last_pin_timestamp.is_omitted()) {j["last_pin_timestamp"] = t.last_pin_timestamp;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-create-guild-create-extra-fields
class GuildCreateExtra{
  public:
    GuildCreateExtra(
        field<Timestamp> joined_at = uninitialized,
        field<bool> large = uninitialized,
        omittable_field<bool> unavailable = omitted,
        field<int> member_count = uninitialized,
        field<std::vector<VoiceState> > voice_states = uninitialized,
        field<std::vector<GuildMember> > members = uninitialized,
        field<std::vector<Channel> > channels = uninitialized,
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<PresenceUpdate> > presences = uninitialized,
        field<std::vector<StageInstance> > stage_instances = uninitialized,
        field<std::vector<GuildScheduledEvent> > guild_scheduled_events = uninitialized
    ): 
        joined_at(joined_at),
        large(large),
        unavailable(unavailable),
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
    omittable_field<bool> unavailable;
    field<int> member_count;
    field<std::vector<VoiceState> > voice_states;
    field<std::vector<GuildMember> > members;
    field<std::vector<Channel> > channels;
    field<std::vector<Channel> > threads;
    field<std::vector<PresenceUpdate> > presences;
    field<std::vector<StageInstance> > stage_instances;
    field<std::vector<GuildScheduledEvent> > guild_scheduled_events;

    friend void to_json(nlohmann::json &j, const GuildCreateExtra &t) {
        //ToJsonExtra
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
};
// https://discord.com/developers/docs/topics/gateway-events#guild-ban-add-guild-ban-add-event-fields
class GuildBanAddEvent{
  public:
    GuildBanAddEvent(
        field<Snowflake> guild_id = uninitialized,
        field<User> user = uninitialized
    ): 
        guild_id(guild_id),
        user(user)
    {}
    
    field<Snowflake> guild_id;
    field<User> user;

    friend void to_json(nlohmann::json &j, const GuildBanAddEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-ban-remove-guild-ban-remove-event-fields
class GuildBanRemoveEvent{
  public:
    GuildBanRemoveEvent(
        field<Snowflake> guild_id = uninitialized,
        field<User> user = uninitialized
    ): 
        guild_id(guild_id),
        user(user)
    {}
    
    field<Snowflake> guild_id;
    field<User> user;

    friend void to_json(nlohmann::json &j, const GuildBanRemoveEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-emojis-update-guild-emojis-update-event-fields
class GuildEmojisUpdateEvent{
  public:
    GuildEmojisUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<Emoji> > emojis = uninitialized
    ): 
        guild_id(guild_id),
        emojis(emojis)
    {}
    
    field<Snowflake> guild_id;
    field<std::vector<Emoji> > emojis;

    friend void to_json(nlohmann::json &j, const GuildEmojisUpdateEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.emojis.is_omitted()) {j["emojis"] = t.emojis;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-stickers-update-guild-stickers-update-event-fields
class GuildStickersUpdateEvent{
  public:
    GuildStickersUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<Sticker> > stickers = uninitialized
    ): 
        guild_id(guild_id),
        stickers(stickers)
    {}
    
    field<Snowflake> guild_id;
    field<std::vector<Sticker> > stickers;

    friend void to_json(nlohmann::json &j, const GuildStickersUpdateEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-integrations-update-guild-integrations-update-event-fields
class GuildIntegrationsUpdateEvent{
  public:
    GuildIntegrationsUpdateEvent(
        field<Snowflake> guild_id = uninitialized
    ): 
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildIntegrationsUpdateEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-member-add-guild-member-add-extra-fields
class GuildMemberAddExtra{
  public:
    GuildMemberAddExtra(
        field<Snowflake> guild_id = uninitialized
    ): 
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildMemberAddExtra &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-member-remove-guild-member-remove-event-fields
class GuildMemberRemoveEvent{
  public:
    GuildMemberRemoveEvent(
        field<Snowflake> guild_id = uninitialized,
        field<User> user = uninitialized
    ): 
        guild_id(guild_id),
        user(user)
    {}
    
    field<Snowflake> guild_id;
    field<User> user;

    friend void to_json(nlohmann::json &j, const GuildMemberRemoveEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-member-update-guild-member-update-event-fields
class GuildMemberUpdateEvent{
  public:
    GuildMemberUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<Snowflake> > roles = uninitialized,
        field<User> user = uninitialized,
        nullable_omittable_field<std::string> nick = omitted,
        nullable_field<std::string> avatar = uninitialized,
        nullable_field<Timestamp> joined_at = uninitialized,
        nullable_omittable_field<Timestamp> premium_since = omitted,
        omittable_field<bool> deaf = omitted,
        omittable_field<bool> mute = omitted,
        omittable_field<bool> pending = omitted,
        nullable_omittable_field<Timestamp> communication_disabled_until = omitted
    ): 
        guild_id(guild_id),
        roles(roles),
        user(user),
        nick(nick),
        avatar(avatar),
        joined_at(joined_at),
        premium_since(premium_since),
        deaf(deaf),
        mute(mute),
        pending(pending),
        communication_disabled_until(communication_disabled_until)
    {}
    
    field<Snowflake> guild_id;
    field<std::vector<Snowflake> > roles;
    field<User> user;
    nullable_omittable_field<std::string> nick;
    nullable_field<std::string> avatar;
    nullable_field<Timestamp> joined_at;
    nullable_omittable_field<Timestamp> premium_since;
    omittable_field<bool> deaf;
    omittable_field<bool> mute;
    omittable_field<bool> pending;
    nullable_omittable_field<Timestamp> communication_disabled_until;

    friend void to_json(nlohmann::json &j, const GuildMemberUpdateEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.nick.is_omitted()) {j["nick"] = t.nick;}
        if(!t.avatar.is_omitted()) {j["avatar"] = t.avatar;}
        if(!t.joined_at.is_omitted()) {j["joined_at"] = t.joined_at;}
        if(!t.premium_since.is_omitted()) {j["premium_since"] = t.premium_since;}
        if(!t.deaf.is_omitted()) {j["deaf"] = t.deaf;}
        if(!t.mute.is_omitted()) {j["mute"] = t.mute;}
        if(!t.pending.is_omitted()) {j["pending"] = t.pending;}
        if(!t.communication_disabled_until.is_omitted()) {j["communication_disabled_until"] = t.communication_disabled_until;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-members-chunk-guild-members-chunk-event-fields
class GuildMembersChunkEvent{
  public:
    GuildMembersChunkEvent(
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<GuildMember> > members = uninitialized,
        field<int> chunk_index = uninitialized,
        field<int> chunk_count = uninitialized,
        omittable_field<std::vector<Snowflake> > not_found = omitted,
        omittable_field<std::vector<Presence> > presences = omitted,
        omittable_field<std::string> nonce = omitted
    ): 
        guild_id(guild_id),
        members(members),
        chunk_index(chunk_index),
        chunk_count(chunk_count),
        not_found(not_found),
        presences(presences),
        nonce(nonce)
    {}
    
    field<Snowflake> guild_id;
    field<std::vector<GuildMember> > members;
    field<int> chunk_index;
    field<int> chunk_count;
    omittable_field<std::vector<Snowflake> > not_found;
    omittable_field<std::vector<Presence> > presences;
    omittable_field<std::string> nonce;

    friend void to_json(nlohmann::json &j, const GuildMembersChunkEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.chunk_index.is_omitted()) {j["chunk_index"] = t.chunk_index;}
        if(!t.chunk_count.is_omitted()) {j["chunk_count"] = t.chunk_count;}
        if(!t.not_found.is_omitted()) {j["not_found"] = t.not_found;}
        if(!t.presences.is_omitted()) {j["presences"] = t.presences;}
        if(!t.nonce.is_omitted()) {j["nonce"] = t.nonce;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-role-create-guild-role-create-event-fields
class GuildRoleCreateEvent{
  public:
    GuildRoleCreateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<Role> role = uninitialized
    ): 
        guild_id(guild_id),
        role(role)
    {}
    
    field<Snowflake> guild_id;
    field<Role> role;

    friend void to_json(nlohmann::json &j, const GuildRoleCreateEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role.is_omitted()) {j["role"] = t.role;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-role-update-guild-role-update-event-fields
class GuildRoleUpdateEvent{
  public:
    GuildRoleUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<Role> role = uninitialized
    ): 
        guild_id(guild_id),
        role(role)
    {}
    
    field<Snowflake> guild_id;
    field<Role> role;

    friend void to_json(nlohmann::json &j, const GuildRoleUpdateEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role.is_omitted()) {j["role"] = t.role;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-role-delete-guild-role-delete-event-fields
class GuildRoleDeleteEvent{
  public:
    GuildRoleDeleteEvent(
        field<Snowflake> guild_id = uninitialized,
        field<Snowflake> role_id = uninitialized
    ): 
        guild_id(guild_id),
        role_id(role_id)
    {}
    
    field<Snowflake> guild_id;
    field<Snowflake> role_id;

    friend void to_json(nlohmann::json &j, const GuildRoleDeleteEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role_id.is_omitted()) {j["role_id"] = t.role_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-scheduled-event-user-add-guild-scheduled-event-user-add-event-fields
class GuildScheduledEventUserAddEvent{
  public:
    GuildScheduledEventUserAddEvent(
        field<Snowflake> guild_scheduled_event_id = uninitialized,
        field<Snowflake> user_id = uninitialized,
        field<Snowflake> guild_id = uninitialized
    ): 
        guild_scheduled_event_id(guild_scheduled_event_id),
        user_id(user_id),
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_scheduled_event_id;
    field<Snowflake> user_id;
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildScheduledEventUserAddEvent &t) {
        //ToJsonExtra
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#guild-scheduled-event-user-remove-guild-scheduled-event-user-remove-event-fields
class GuildScheduledEventUserRemoveEvent{
  public:
    GuildScheduledEventUserRemoveEvent(
        field<Snowflake> guild_scheduled_event_id = uninitialized,
        field<Snowflake> user_id = uninitialized,
        field<Snowflake> guild_id = uninitialized
    ): 
        guild_scheduled_event_id(guild_scheduled_event_id),
        user_id(user_id),
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_scheduled_event_id;
    field<Snowflake> user_id;
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildScheduledEventUserRemoveEvent &t) {
        //ToJsonExtra
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#integration-create-integration-create-event-additional-fields
class IntegrationCreateEventAdditional{
  public:
    IntegrationCreateEventAdditional(
        field<Snowflake> guild_id = uninitialized
    ): 
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const IntegrationCreateEventAdditional &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#integration-update-integration-update-event-additional-fields
class IntegrationUpdateEventAdditional{
  public:
    IntegrationUpdateEventAdditional(
        field<Snowflake> guild_id = uninitialized
    ): 
        guild_id(guild_id)
    {}
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const IntegrationUpdateEventAdditional &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#integration-delete-integration-delete-event-fields
class IntegrationDeleteEvent{
  public:
    IntegrationDeleteEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        omittable_field<Snowflake> application_id = omitted
    ): 
        id(id),
        guild_id(guild_id),
        application_id(application_id)
    {}
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    omittable_field<Snowflake> application_id;

    friend void to_json(nlohmann::json &j, const IntegrationDeleteEvent &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#invite-create-invite-create-event-fields
class InviteCreateEvent{
  public:
    InviteCreateEvent(
        field<Snowflake> channel_id = uninitialized,
        field<std::string> code = uninitialized,
        field<Timestamp> created_at = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<User> inviter = omitted,
        field<int> max_age = uninitialized,
        field<int> max_uses = uninitialized,
        omittable_field<int> target_type = omitted,
        omittable_field<User> target_user = omitted,
        omittable_field<Application> target_application = omitted,
        field<bool> temporary = uninitialized,
        field<int> uses = uninitialized
    ): 
        channel_id(channel_id),
        code(code),
        created_at(created_at),
        guild_id(guild_id),
        inviter(inviter),
        max_age(max_age),
        max_uses(max_uses),
        target_type(target_type),
        target_user(target_user),
        target_application(target_application),
        temporary(temporary),
        uses(uses)
    {}
    
    field<Snowflake> channel_id;
    field<std::string> code;
    field<Timestamp> created_at;
    omittable_field<Snowflake> guild_id;
    omittable_field<User> inviter;
    field<int> max_age;
    field<int> max_uses;
    omittable_field<int> target_type;
    omittable_field<User> target_user;
    omittable_field<Application> target_application;
    field<bool> temporary;
    field<int> uses;

    friend void to_json(nlohmann::json &j, const InviteCreateEvent &t) {
        //ToJsonExtra
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.code.is_omitted()) {j["code"] = t.code;}
        if(!t.created_at.is_omitted()) {j["created_at"] = t.created_at;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.inviter.is_omitted()) {j["inviter"] = t.inviter;}
        if(!t.max_age.is_omitted()) {j["max_age"] = t.max_age;}
        if(!t.max_uses.is_omitted()) {j["max_uses"] = t.max_uses;}
        if(!t.target_type.is_omitted()) {j["target_type"] = t.target_type;}
        if(!t.target_user.is_omitted()) {j["target_user"] = t.target_user;}
        if(!t.target_application.is_omitted()) {j["target_application"] = t.target_application;}
        if(!t.temporary.is_omitted()) {j["temporary"] = t.temporary;}
        if(!t.uses.is_omitted()) {j["uses"] = t.uses;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#invite-delete-invite-delete-event-fields
class InviteDeleteEvent{
  public:
    InviteDeleteEvent(
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<std::string> code = uninitialized
    ): 
        channel_id(channel_id),
        guild_id(guild_id),
        code(code)
    {}
    
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    field<std::string> code;

    friend void to_json(nlohmann::json &j, const InviteDeleteEvent &t) {
        //ToJsonExtra
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.code.is_omitted()) {j["code"] = t.code;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#message-create-message-create-extra-fields
class MessageCreateExtra{
  public:
    MessageCreateExtra(
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<GuildMember> member = omitted,
        field<std::vector<UserObjects,WithAnAdditionalPartialMemberField> > mentions = uninitialized
    ): 
        guild_id(guild_id),
        member(member),
        mentions(mentions)
    {}
    
    omittable_field<Snowflake> guild_id;
    omittable_field<GuildMember> member;
    field<std::vector<UserObjects,WithAnAdditionalPartialMemberField> > mentions;

    friend void to_json(nlohmann::json &j, const MessageCreateExtra &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.mentions.is_omitted()) {j["mentions"] = t.mentions;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#message-delete-message-delete-event-fields
class MessageDeleteEvent{
  public:
    MessageDeleteEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted
    ): 
        id(id),
        channel_id(channel_id),
        guild_id(guild_id)
    {}
    
    field<Snowflake> id;
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const MessageDeleteEvent &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#message-delete-bulk-message-delete-bulk-event-fields
class MessageDeleteBulkEvent{
  public:
    MessageDeleteBulkEvent(
        field<std::vector<Snowflake> > ids = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted
    ): 
        ids(ids),
        channel_id(channel_id),
        guild_id(guild_id)
    {}
    
    field<std::vector<Snowflake> > ids;
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const MessageDeleteBulkEvent &t) {
        //ToJsonExtra
        if(!t.ids.is_omitted()) {j["ids"] = t.ids;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#message-reaction-add-message-reaction-add-event-fields
class MessageReactionAddEvent{
  public:
    MessageReactionAddEvent(
        field<Snowflake> user_id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<Snowflake> message_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<GuildMember> member = omitted,
        field<Emoji> emoji = uninitialized
    ): 
        user_id(user_id),
        channel_id(channel_id),
        message_id(message_id),
        guild_id(guild_id),
        member(member),
        emoji(emoji)
    {}
    
    field<Snowflake> user_id;
    field<Snowflake> channel_id;
    field<Snowflake> message_id;
    omittable_field<Snowflake> guild_id;
    omittable_field<GuildMember> member;
    field<Emoji> emoji;

    friend void to_json(nlohmann::json &j, const MessageReactionAddEvent &t) {
        //ToJsonExtra
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#message-reaction-remove-message-reaction-remove-event-fields
class MessageReactionRemoveEvent{
  public:
    MessageReactionRemoveEvent(
        field<Snowflake> user_id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<Snowflake> message_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<Emoji> emoji = uninitialized
    ): 
        user_id(user_id),
        channel_id(channel_id),
        message_id(message_id),
        guild_id(guild_id),
        emoji(emoji)
    {}
    
    field<Snowflake> user_id;
    field<Snowflake> channel_id;
    field<Snowflake> message_id;
    omittable_field<Snowflake> guild_id;
    field<Emoji> emoji;

    friend void to_json(nlohmann::json &j, const MessageReactionRemoveEvent &t) {
        //ToJsonExtra
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#message-reaction-remove-all-message-reaction-remove-all-event-fields
class MessageReactionRemoveAllEvent{
  public:
    MessageReactionRemoveAllEvent(
        field<Snowflake> channel_id = uninitialized,
        field<Snowflake> message_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted
    ): 
        channel_id(channel_id),
        message_id(message_id),
        guild_id(guild_id)
    {}
    
    field<Snowflake> channel_id;
    field<Snowflake> message_id;
    omittable_field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const MessageReactionRemoveAllEvent &t) {
        //ToJsonExtra
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#message-reaction-remove-emoji-message-reaction-remove-emoji-event-fields
class MessageReactionRemoveEmojiEvent{
  public:
    MessageReactionRemoveEmojiEvent(
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<Snowflake> message_id = uninitialized,
        field<Emoji> emoji = uninitialized
    ): 
        channel_id(channel_id),
        guild_id(guild_id),
        message_id(message_id),
        emoji(emoji)
    {}
    
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    field<Snowflake> message_id;
    field<Emoji> emoji;

    friend void to_json(nlohmann::json &j, const MessageReactionRemoveEmojiEvent &t) {
        //ToJsonExtra
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#presence-update-presence-update-event-fields
class PresenceUpdateEvent{
  public:
    PresenceUpdateEvent(
        field<User> user = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<std::string> status = uninitialized,
        field<std::vector<Activity> > activities = uninitialized,
        field<ClientStatus> client_status = uninitialized
    ): 
        user(user),
        guild_id(guild_id),
        status(status),
        activities(activities),
        client_status(client_status)
    {}
    
    field<User> user;
    field<Snowflake> guild_id;
    field<std::string> status;
    field<std::vector<Activity> > activities;
    field<ClientStatus> client_status;

    friend void to_json(nlohmann::json &j, const PresenceUpdateEvent &t) {
        //ToJsonExtra
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.status.is_omitted()) {j["status"] = t.status;}
        if(!t.activities.is_omitted()) {j["activities"] = t.activities;}
        if(!t.client_status.is_omitted()) {j["client_status"] = t.client_status;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#presence-client-status-object
class ClientStatus{
  public:
    ClientStatus(
        omittable_field<std::string> desktop = omitted,
        omittable_field<std::string> mobile = omitted,
        omittable_field<std::string> web = omitted
    ): 
        desktop(desktop),
        mobile(mobile),
        web(web)
    {}
    
    omittable_field<std::string> desktop;
    omittable_field<std::string> mobile;
    omittable_field<std::string> web;

    friend void to_json(nlohmann::json &j, const ClientStatus &t) {
        //ToJsonExtra
        if(!t.desktop.is_omitted()) {j["desktop"] = t.desktop;}
        if(!t.mobile.is_omitted()) {j["mobile"] = t.mobile;}
        if(!t.web.is_omitted()) {j["web"] = t.web;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-structure
class Activity{
  public:
    Activity(
        field<std::string> name = uninitialized,
        field<int> type = uninitialized,
        nullable_omittable_field<std::string> url = omitted,
        field<int> created_at = uninitialized,
        omittable_field<ActivityTimestamps> timestamps = omitted,
        omittable_field<Snowflake> application_id = omitted,
        nullable_omittable_field<std::string> details = omitted,
        nullable_omittable_field<std::string> state = omitted,
        nullable_omittable_field<Emoji> emoji = omitted,
        omittable_field<ActivityParty> party = omitted,
        omittable_field<ActivityAssets> assets = omitted,
        omittable_field<ActivitySecrets> secrets = omitted,
        omittable_field<bool> instance = omitted,
        omittable_field<int> flags = omitted,
        omittable_field<std::vector<Button> > buttons = omitted
    ): 
        name(name),
        type(type),
        url(url),
        created_at(created_at),
        timestamps(timestamps),
        application_id(application_id),
        details(details),
        state(state),
        emoji(emoji),
        party(party),
        assets(assets),
        secrets(secrets),
        instance(instance),
        flags(flags),
        buttons(buttons)
    {}
    
    field<std::string> name;
    field<int> type;
    nullable_omittable_field<std::string> url;
    field<int> created_at;
    omittable_field<ActivityTimestamps> timestamps;
    omittable_field<Snowflake> application_id;
    nullable_omittable_field<std::string> details;
    nullable_omittable_field<std::string> state;
    nullable_omittable_field<Emoji> emoji;
    omittable_field<ActivityParty> party;
    omittable_field<ActivityAssets> assets;
    omittable_field<ActivitySecrets> secrets;
    omittable_field<bool> instance;
    omittable_field<int> flags;
    omittable_field<std::vector<Button> > buttons;

    friend void to_json(nlohmann::json &j, const Activity &t) {
        //ToJsonExtra
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.created_at.is_omitted()) {j["created_at"] = t.created_at;}
        if(!t.timestamps.is_omitted()) {j["timestamps"] = t.timestamps;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.details.is_omitted()) {j["details"] = t.details;}
        if(!t.state.is_omitted()) {j["state"] = t.state;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
        if(!t.party.is_omitted()) {j["party"] = t.party;}
        if(!t.assets.is_omitted()) {j["assets"] = t.assets;}
        if(!t.secrets.is_omitted()) {j["secrets"] = t.secrets;}
        if(!t.instance.is_omitted()) {j["instance"] = t.instance;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.buttons.is_omitted()) {j["buttons"] = t.buttons;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-timestamps
class ActivityTimestamps{
  public:
    ActivityTimestamps(
        omittable_field<int> start = omitted,
        omittable_field<int> end = omitted
    ): 
        start(start),
        end(end)
    {}
    
    omittable_field<int> start;
    omittable_field<int> end;

    friend void to_json(nlohmann::json &j, const ActivityTimestamps &t) {
        //ToJsonExtra
        if(!t.start.is_omitted()) {j["start"] = t.start;}
        if(!t.end.is_omitted()) {j["end"] = t.end;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-emoji
class ActivityEmoji{
  public:
    ActivityEmoji(
        field<std::string> name = uninitialized,
        omittable_field<Snowflake> id = omitted,
        omittable_field<bool> animated = omitted
    ): 
        name(name),
        id(id),
        animated(animated)
    {}
    
    field<std::string> name;
    omittable_field<Snowflake> id;
    omittable_field<bool> animated;

    friend void to_json(nlohmann::json &j, const ActivityEmoji &t) {
        //ToJsonExtra
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.animated.is_omitted()) {j["animated"] = t.animated;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-party
class ActivityParty{
  public:
    ActivityParty(
        omittable_field<std::string> id = omitted,
        omittable_field<std::Array<int, 2>> size = omitted
    ): 
        id(id),
        size(size)
    {}
    
    omittable_field<std::string> id;
    omittable_field<std::Array<int, 2>> size;

    friend void to_json(nlohmann::json &j, const ActivityParty &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.size.is_omitted()) {j["size"] = t.size;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-assets
class ActivityAssets{
  public:
    ActivityAssets(
        omittable_field<std::string> large_image = omitted,
        omittable_field<std::string> large_text = omitted,
        omittable_field<std::string> small_image = omitted,
        omittable_field<std::string> small_text = omitted
    ): 
        large_image(large_image),
        large_text(large_text),
        small_image(small_image),
        small_text(small_text)
    {}
    
    omittable_field<std::string> large_image;
    omittable_field<std::string> large_text;
    omittable_field<std::string> small_image;
    omittable_field<std::string> small_text;

    friend void to_json(nlohmann::json &j, const ActivityAssets &t) {
        //ToJsonExtra
        if(!t.large_image.is_omitted()) {j["large_image"] = t.large_image;}
        if(!t.large_text.is_omitted()) {j["large_text"] = t.large_text;}
        if(!t.small_image.is_omitted()) {j["small_image"] = t.small_image;}
        if(!t.small_text.is_omitted()) {j["small_text"] = t.small_text;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-secrets
class ActivitySecrets{
  public:
    ActivitySecrets(
        omittable_field<std::string> join = omitted,
        omittable_field<std::string> spectate = omitted,
        omittable_field<std::string> match = omitted
    ): 
        join(join),
        spectate(spectate),
        match(match)
    {}
    
    omittable_field<std::string> join;
    omittable_field<std::string> spectate;
    omittable_field<std::string> match;

    friend void to_json(nlohmann::json &j, const ActivitySecrets &t) {
        //ToJsonExtra
        if(!t.join.is_omitted()) {j["join"] = t.join;}
        if(!t.spectate.is_omitted()) {j["spectate"] = t.spectate;}
        if(!t.match.is_omitted()) {j["match"] = t.match;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-buttons
class ActivityButtons{
  public:
    ActivityButtons(
        field<std::string> label = uninitialized,
        field<std::string> url = uninitialized
    ): 
        label(label),
        url(url)
    {}
    
    field<std::string> label;
    field<std::string> url;

    friend void to_json(nlohmann::json &j, const ActivityButtons &t) {
        //ToJsonExtra
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#typing-start-typing-start-event-fields
class TypingStartEvent{
  public:
    TypingStartEvent(
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<Snowflake> user_id = uninitialized,
        field<int> timestamp = uninitialized,
        omittable_field<GuildMember> member = omitted
    ): 
        channel_id(channel_id),
        guild_id(guild_id),
        user_id(user_id),
        timestamp(timestamp),
        member(member)
    {}
    
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    field<Snowflake> user_id;
    field<int> timestamp;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const TypingStartEvent &t) {
        //ToJsonExtra
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.timestamp.is_omitted()) {j["timestamp"] = t.timestamp;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#voice-server-update-voice-server-update-event-fields
class VoiceServerUpdateEvent{
  public:
    VoiceServerUpdateEvent(
        field<std::string> token = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        nullable_field<std::string> endpoint = uninitialized
    ): 
        token(token),
        guild_id(guild_id),
        endpoint(endpoint)
    {}
    
    field<std::string> token;
    field<Snowflake> guild_id;
    nullable_field<std::string> endpoint;

    friend void to_json(nlohmann::json &j, const VoiceServerUpdateEvent &t) {
        //ToJsonExtra
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.endpoint.is_omitted()) {j["endpoint"] = t.endpoint;}
    }
};
// https://discord.com/developers/docs/topics/gateway-events#webhooks-update-webhooks-update-event-fields
class WebhooksUpdateEvent{
  public:
    WebhooksUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<Snowflake> channel_id = uninitialized
    ): 
        guild_id(guild_id),
        channel_id(channel_id)
    {}
    
    field<Snowflake> guild_id;
    field<Snowflake> channel_id;

    friend void to_json(nlohmann::json &j, const WebhooksUpdateEvent &t) {
        //ToJsonExtra
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
    }
};
