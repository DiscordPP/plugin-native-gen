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
        if(!t.op.is_omitted()) {j["op"] = t.op;}
        if(!t.d.is_omitted()) {j["d"] = t.d;}
        if(!t.s.is_omitted()) {j["s"] = t.s;}
        if(!t.t.is_omitted()) {j["t"] = t.t;}
    }
    friend void from_json(const nlohmann::json &j, Payload &t {
        if(j.contains(op)){j.at(op).get_to(t.op);}
        if(j.contains(d)){j.at(d).get_to(t.d);}
        if(j.contains(s)){j.at(s).get_to(t.s);}
        if(j.contains(t)){j.at(t).get_to(t.t);}
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
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.properties.is_omitted()) {j["properties"] = t.properties;}
        if(!t.compress.is_omitted()) {j["compress"] = t.compress;}
        if(!t.large_threshold.is_omitted()) {j["large_threshold"] = t.large_threshold;}
        if(!t.shard.is_omitted()) {j["shard"] = t.shard;}
        if(!t.presence.is_omitted()) {j["presence"] = t.presence;}
        if(!t.intents.is_omitted()) {j["intents"] = t.intents;}
    }
    friend void from_json(const nlohmann::json &j, Identify &t {
        if(j.contains(token)){j.at(token).get_to(t.token);}
        if(j.contains(properties)){j.at(properties).get_to(t.properties);}
        if(j.contains(compress)){j.at(compress).get_to(t.compress);}
        if(j.contains(large_threshold)){j.at(large_threshold).get_to(t.large_threshold);}
        if(j.contains(shard)){j.at(shard).get_to(t.shard);}
        if(j.contains(presence)){j.at(presence).get_to(t.presence);}
        if(j.contains(intents)){j.at(intents).get_to(t.intents);}
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
        if(!t.os.is_omitted()) {j["os"] = t.os;}
        if(!t.browser.is_omitted()) {j["browser"] = t.browser;}
        if(!t.device.is_omitted()) {j["device"] = t.device;}
    }
    friend void from_json(const nlohmann::json &j, IdentifyConnectionProperties &t {
        if(j.contains(os)){j.at(os).get_to(t.os);}
        if(j.contains(browser)){j.at(browser).get_to(t.browser);}
        if(j.contains(device)){j.at(device).get_to(t.device);}
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
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.session_id.is_omitted()) {j["session_id"] = t.session_id;}
        if(!t.seq.is_omitted()) {j["seq"] = t.seq;}
    }
    friend void from_json(const nlohmann::json &j, Resume &t {
        if(j.contains(token)){j.at(token).get_to(t.token);}
        if(j.contains(session_id)){j.at(session_id).get_to(t.session_id);}
        if(j.contains(seq)){j.at(seq).get_to(t.seq);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.query.is_omitted()) {j["query"] = t.query;}
        if(!t.limit.is_omitted()) {j["limit"] = t.limit;}
        if(!t.presences.is_omitted()) {j["presences"] = t.presences;}
        if(!t.user_ids.is_omitted()) {j["user_ids"] = t.user_ids;}
        if(!t.nonce.is_omitted()) {j["nonce"] = t.nonce;}
    }
    friend void from_json(const nlohmann::json &j, GuildRequestMembers &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(query)){j.at(query).get_to(t.query);}
        if(j.contains(limit)){j.at(limit).get_to(t.limit);}
        if(j.contains(presences)){j.at(presences).get_to(t.presences);}
        if(j.contains(user_ids)){j.at(user_ids).get_to(t.user_ids);}
        if(j.contains(nonce)){j.at(nonce).get_to(t.nonce);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.self_mute.is_omitted()) {j["self_mute"] = t.self_mute;}
        if(!t.self_deaf.is_omitted()) {j["self_deaf"] = t.self_deaf;}
    }
    friend void from_json(const nlohmann::json &j, GatewayVoiceStateUpdate &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(self_mute)){j.at(self_mute).get_to(t.self_mute);}
        if(j.contains(self_deaf)){j.at(self_deaf).get_to(t.self_deaf);}
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
        if(!t.since.is_omitted()) {j["since"] = t.since;}
        if(!t.activities.is_omitted()) {j["activities"] = t.activities;}
        if(!t.status.is_omitted()) {j["status"] = t.status;}
        if(!t.afk.is_omitted()) {j["afk"] = t.afk;}
    }
    friend void from_json(const nlohmann::json &j, GatewayPresenceUpdate &t {
        if(j.contains(since)){j.at(since).get_to(t.since);}
        if(j.contains(activities)){j.at(activities).get_to(t.activities);}
        if(j.contains(status)){j.at(status).get_to(t.status);}
        if(j.contains(afk)){j.at(afk).get_to(t.afk);}
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
        if(!t.heartbeat_interval.is_omitted()) {j["heartbeat_interval"] = t.heartbeat_interval;}
    }
    friend void from_json(const nlohmann::json &j, Hello &t {
        if(j.contains(heartbeat_interval)){j.at(heartbeat_interval).get_to(t.heartbeat_interval);}
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
        if(!t.v.is_omitted()) {j["v"] = t.v;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.guilds.is_omitted()) {j["guilds"] = t.guilds;}
        if(!t.session_id.is_omitted()) {j["session_id"] = t.session_id;}
        if(!t.resume_gateway_url.is_omitted()) {j["resume_gateway_url"] = t.resume_gateway_url;}
        if(!t.shard.is_omitted()) {j["shard"] = t.shard;}
        if(!t.application.is_omitted()) {j["application"] = t.application;}
    }
    friend void from_json(const nlohmann::json &j, ReadyEvent &t {
        if(j.contains(v)){j.at(v).get_to(t.v);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
        if(j.contains(guilds)){j.at(guilds).get_to(t.guilds);}
        if(j.contains(session_id)){j.at(session_id).get_to(t.session_id);}
        if(j.contains(resume_gateway_url)){j.at(resume_gateway_url).get_to(t.resume_gateway_url);}
        if(j.contains(shard)){j.at(shard).get_to(t.shard);}
        if(j.contains(application)){j.at(application).get_to(t.application);}
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
    friend void from_json(const nlohmann::json &j, AutoModerationActionExecutionEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(action)){j.at(action).get_to(t.action);}
        if(j.contains(rule_id)){j.at(rule_id).get_to(t.rule_id);}
        if(j.contains(rule_trigger_type)){j.at(rule_trigger_type).get_to(t.rule_trigger_type);}
        if(j.contains(user_id)){j.at(user_id).get_to(t.user_id);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(message_id)){j.at(message_id).get_to(t.message_id);}
        if(j.contains(alert_system_message_id)){j.at(alert_system_message_id).get_to(t.alert_system_message_id);}
        if(j.contains(content)){j.at(content).get_to(t.content);}
        if(j.contains(matched_keyword)){j.at(matched_keyword).get_to(t.matched_keyword);}
        if(j.contains(matched_content)){j.at(matched_content).get_to(t.matched_content);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_ids.is_omitted()) {j["channel_ids"] = t.channel_ids;}
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
    }
    friend void from_json(const nlohmann::json &j, ThreadListSyncEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(channel_ids)){j.at(channel_ids).get_to(t.channel_ids);}
        if(j.contains(threads)){j.at(threads).get_to(t.threads);}
        if(j.contains(members)){j.at(members).get_to(t.members);}
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
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member_count.is_omitted()) {j["member_count"] = t.member_count;}
        if(!t.added_members.is_omitted()) {j["added_members"] = t.added_members;}
        if(!t.removed_member_ids.is_omitted()) {j["removed_member_ids"] = t.removed_member_ids;}
    }
    friend void from_json(const nlohmann::json &j, ThreadMembersUpdateEvent &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(member_count)){j.at(member_count).get_to(t.member_count);}
        if(j.contains(added_members)){j.at(added_members).get_to(t.added_members);}
        if(j.contains(removed_member_ids)){j.at(removed_member_ids).get_to(t.removed_member_ids);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.last_pin_timestamp.is_omitted()) {j["last_pin_timestamp"] = t.last_pin_timestamp;}
    }
    friend void from_json(const nlohmann::json &j, ChannelPinsUpdateEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(last_pin_timestamp)){j.at(last_pin_timestamp).get_to(t.last_pin_timestamp);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, GuildBanAddEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, GuildBanRemoveEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.emojis.is_omitted()) {j["emojis"] = t.emojis;}
    }
    friend void from_json(const nlohmann::json &j, GuildEmojisUpdateEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(emojis)){j.at(emojis).get_to(t.emojis);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
    }
    friend void from_json(const nlohmann::json &j, GuildStickersUpdateEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(stickers)){j.at(stickers).get_to(t.stickers);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildIntegrationsUpdateEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, GuildMemberRemoveEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
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
    friend void from_json(const nlohmann::json &j, GuildMemberUpdateEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(roles)){j.at(roles).get_to(t.roles);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
        if(j.contains(nick)){j.at(nick).get_to(t.nick);}
        if(j.contains(avatar)){j.at(avatar).get_to(t.avatar);}
        if(j.contains(joined_at)){j.at(joined_at).get_to(t.joined_at);}
        if(j.contains(premium_since)){j.at(premium_since).get_to(t.premium_since);}
        if(j.contains(deaf)){j.at(deaf).get_to(t.deaf);}
        if(j.contains(mute)){j.at(mute).get_to(t.mute);}
        if(j.contains(pending)){j.at(pending).get_to(t.pending);}
        if(j.contains(communication_disabled_until)){j.at(communication_disabled_until).get_to(t.communication_disabled_until);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.chunk_index.is_omitted()) {j["chunk_index"] = t.chunk_index;}
        if(!t.chunk_count.is_omitted()) {j["chunk_count"] = t.chunk_count;}
        if(!t.not_found.is_omitted()) {j["not_found"] = t.not_found;}
        if(!t.presences.is_omitted()) {j["presences"] = t.presences;}
        if(!t.nonce.is_omitted()) {j["nonce"] = t.nonce;}
    }
    friend void from_json(const nlohmann::json &j, GuildMembersChunkEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(members)){j.at(members).get_to(t.members);}
        if(j.contains(chunk_index)){j.at(chunk_index).get_to(t.chunk_index);}
        if(j.contains(chunk_count)){j.at(chunk_count).get_to(t.chunk_count);}
        if(j.contains(not_found)){j.at(not_found).get_to(t.not_found);}
        if(j.contains(presences)){j.at(presences).get_to(t.presences);}
        if(j.contains(nonce)){j.at(nonce).get_to(t.nonce);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role.is_omitted()) {j["role"] = t.role;}
    }
    friend void from_json(const nlohmann::json &j, GuildRoleCreateEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(role)){j.at(role).get_to(t.role);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role.is_omitted()) {j["role"] = t.role;}
    }
    friend void from_json(const nlohmann::json &j, GuildRoleUpdateEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(role)){j.at(role).get_to(t.role);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role_id.is_omitted()) {j["role_id"] = t.role_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildRoleDeleteEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(role_id)){j.at(role_id).get_to(t.role_id);}
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
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildScheduledEventUserAddEvent &t {
        if(j.contains(guild_scheduled_event_id)){j.at(guild_scheduled_event_id).get_to(t.guild_scheduled_event_id);}
        if(j.contains(user_id)){j.at(user_id).get_to(t.user_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
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
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildScheduledEventUserRemoveEvent &t {
        if(j.contains(guild_scheduled_event_id)){j.at(guild_scheduled_event_id).get_to(t.guild_scheduled_event_id);}
        if(j.contains(user_id)){j.at(user_id).get_to(t.user_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationCreateEventAdditional &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationUpdateEventAdditional &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
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
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationDeleteEvent &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(application_id)){j.at(application_id).get_to(t.application_id);}
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
    friend void from_json(const nlohmann::json &j, InviteCreateEvent &t {
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(code)){j.at(code).get_to(t.code);}
        if(j.contains(created_at)){j.at(created_at).get_to(t.created_at);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(inviter)){j.at(inviter).get_to(t.inviter);}
        if(j.contains(max_age)){j.at(max_age).get_to(t.max_age);}
        if(j.contains(max_uses)){j.at(max_uses).get_to(t.max_uses);}
        if(j.contains(target_type)){j.at(target_type).get_to(t.target_type);}
        if(j.contains(target_user)){j.at(target_user).get_to(t.target_user);}
        if(j.contains(target_application)){j.at(target_application).get_to(t.target_application);}
        if(j.contains(temporary)){j.at(temporary).get_to(t.temporary);}
        if(j.contains(uses)){j.at(uses).get_to(t.uses);}
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
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.code.is_omitted()) {j["code"] = t.code;}
    }
    friend void from_json(const nlohmann::json &j, InviteDeleteEvent &t {
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(code)){j.at(code).get_to(t.code);}
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
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, MessageDeleteEvent &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
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
        if(!t.ids.is_omitted()) {j["ids"] = t.ids;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, MessageDeleteBulkEvent &t {
        if(j.contains(ids)){j.at(ids).get_to(t.ids);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
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
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
    friend void from_json(const nlohmann::json &j, MessageReactionAddEvent &t {
        if(j.contains(user_id)){j.at(user_id).get_to(t.user_id);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(message_id)){j.at(message_id).get_to(t.message_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(member)){j.at(member).get_to(t.member);}
        if(j.contains(emoji)){j.at(emoji).get_to(t.emoji);}
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
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
    friend void from_json(const nlohmann::json &j, MessageReactionRemoveEvent &t {
        if(j.contains(user_id)){j.at(user_id).get_to(t.user_id);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(message_id)){j.at(message_id).get_to(t.message_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(emoji)){j.at(emoji).get_to(t.emoji);}
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
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, MessageReactionRemoveAllEvent &t {
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(message_id)){j.at(message_id).get_to(t.message_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
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
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
    friend void from_json(const nlohmann::json &j, MessageReactionRemoveEmojiEvent &t {
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(message_id)){j.at(message_id).get_to(t.message_id);}
        if(j.contains(emoji)){j.at(emoji).get_to(t.emoji);}
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
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.status.is_omitted()) {j["status"] = t.status;}
        if(!t.activities.is_omitted()) {j["activities"] = t.activities;}
        if(!t.client_status.is_omitted()) {j["client_status"] = t.client_status;}
    }
    friend void from_json(const nlohmann::json &j, PresenceUpdateEvent &t {
        if(j.contains(user)){j.at(user).get_to(t.user);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(status)){j.at(status).get_to(t.status);}
        if(j.contains(activities)){j.at(activities).get_to(t.activities);}
        if(j.contains(client_status)){j.at(client_status).get_to(t.client_status);}
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
        if(!t.desktop.is_omitted()) {j["desktop"] = t.desktop;}
        if(!t.mobile.is_omitted()) {j["mobile"] = t.mobile;}
        if(!t.web.is_omitted()) {j["web"] = t.web;}
    }
    friend void from_json(const nlohmann::json &j, ClientStatus &t {
        if(j.contains(desktop)){j.at(desktop).get_to(t.desktop);}
        if(j.contains(mobile)){j.at(mobile).get_to(t.mobile);}
        if(j.contains(web)){j.at(web).get_to(t.web);}
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
    friend void from_json(const nlohmann::json &j, Activity &t {
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(type)){j.at(type).get_to(t.type);}
        if(j.contains(url)){j.at(url).get_to(t.url);}
        if(j.contains(created_at)){j.at(created_at).get_to(t.created_at);}
        if(j.contains(timestamps)){j.at(timestamps).get_to(t.timestamps);}
        if(j.contains(application_id)){j.at(application_id).get_to(t.application_id);}
        if(j.contains(details)){j.at(details).get_to(t.details);}
        if(j.contains(state)){j.at(state).get_to(t.state);}
        if(j.contains(emoji)){j.at(emoji).get_to(t.emoji);}
        if(j.contains(party)){j.at(party).get_to(t.party);}
        if(j.contains(assets)){j.at(assets).get_to(t.assets);}
        if(j.contains(secrets)){j.at(secrets).get_to(t.secrets);}
        if(j.contains(instance)){j.at(instance).get_to(t.instance);}
        if(j.contains(flags)){j.at(flags).get_to(t.flags);}
        if(j.contains(buttons)){j.at(buttons).get_to(t.buttons);}
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
        if(!t.start.is_omitted()) {j["start"] = t.start;}
        if(!t.end.is_omitted()) {j["end"] = t.end;}
    }
    friend void from_json(const nlohmann::json &j, ActivityTimestamps &t {
        if(j.contains(start)){j.at(start).get_to(t.start);}
        if(j.contains(end)){j.at(end).get_to(t.end);}
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
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.animated.is_omitted()) {j["animated"] = t.animated;}
    }
    friend void from_json(const nlohmann::json &j, ActivityEmoji &t {
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(animated)){j.at(animated).get_to(t.animated);}
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
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.size.is_omitted()) {j["size"] = t.size;}
    }
    friend void from_json(const nlohmann::json &j, ActivityParty &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(size)){j.at(size).get_to(t.size);}
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
        if(!t.large_image.is_omitted()) {j["large_image"] = t.large_image;}
        if(!t.large_text.is_omitted()) {j["large_text"] = t.large_text;}
        if(!t.small_image.is_omitted()) {j["small_image"] = t.small_image;}
        if(!t.small_text.is_omitted()) {j["small_text"] = t.small_text;}
    }
    friend void from_json(const nlohmann::json &j, ActivityAssets &t {
        if(j.contains(large_image)){j.at(large_image).get_to(t.large_image);}
        if(j.contains(large_text)){j.at(large_text).get_to(t.large_text);}
        if(j.contains(small_image)){j.at(small_image).get_to(t.small_image);}
        if(j.contains(small_text)){j.at(small_text).get_to(t.small_text);}
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
        if(!t.join.is_omitted()) {j["join"] = t.join;}
        if(!t.spectate.is_omitted()) {j["spectate"] = t.spectate;}
        if(!t.match.is_omitted()) {j["match"] = t.match;}
    }
    friend void from_json(const nlohmann::json &j, ActivitySecrets &t {
        if(j.contains(join)){j.at(join).get_to(t.join);}
        if(j.contains(spectate)){j.at(spectate).get_to(t.spectate);}
        if(j.contains(match)){j.at(match).get_to(t.match);}
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
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
    }
    friend void from_json(const nlohmann::json &j, ActivityButtons &t {
        if(j.contains(label)){j.at(label).get_to(t.label);}
        if(j.contains(url)){j.at(url).get_to(t.url);}
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
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.timestamp.is_omitted()) {j["timestamp"] = t.timestamp;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
    }
    friend void from_json(const nlohmann::json &j, TypingStartEvent &t {
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(user_id)){j.at(user_id).get_to(t.user_id);}
        if(j.contains(timestamp)){j.at(timestamp).get_to(t.timestamp);}
        if(j.contains(member)){j.at(member).get_to(t.member);}
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
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.endpoint.is_omitted()) {j["endpoint"] = t.endpoint;}
    }
    friend void from_json(const nlohmann::json &j, VoiceServerUpdateEvent &t {
        if(j.contains(token)){j.at(token).get_to(t.token);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(endpoint)){j.at(endpoint).get_to(t.endpoint);}
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
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
    }
    friend void from_json(const nlohmann::json &j, WebhooksUpdateEvent &t {
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(channel_id)){j.at(channel_id).get_to(t.channel_id);}
    }
};
