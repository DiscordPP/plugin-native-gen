#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/topics/gateway#payloads
class GatewayPayload{
  public:
    GatewayPayload(
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

    friend void to_json(nlohmann::json &j, const GatewayPayload &t) {
        //ToJsonExtra
        if(!t.op.is_omitted()) {j["op"] = t.op;}
        if(!t.d.is_omitted()) {j["d"] = t.d;}
        if(!t.s.is_omitted()) {j["s"] = t.s;}
        if(!t.t.is_omitted()) {j["t"] = t.t;}
    }
};
// https://discord.com/developers/docs/topics/gateway#identify
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
// https://discord.com/developers/docs/topics/gateway#resume
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
// https://discord.com/developers/docs/topics/gateway#request-guild-members
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
// https://discord.com/developers/docs/topics/gateway#update-voice-state
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
// https://discord.com/developers/docs/topics/gateway#update-presence
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
// https://discord.com/developers/docs/topics/gateway#hello
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
// https://discord.com/developers/docs/topics/gateway#activity-object
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
// https://discord.com/developers/docs/topics/gateway#session-start-limit-object
class SessionStartLimit{
  public:
    SessionStartLimit(
        field<int> total = uninitialized,
        field<int> remaining = uninitialized,
        field<int> reset_after = uninitialized,
        field<int> max_concurrency = uninitialized
    ): 
        total(total),
        remaining(remaining),
        reset_after(reset_after),
        max_concurrency(max_concurrency)
    {}
    
    field<int> total;
    field<int> remaining;
    field<int> reset_after;
    field<int> max_concurrency;

    friend void to_json(nlohmann::json &j, const SessionStartLimit &t) {
        //ToJsonExtra
        if(!t.total.is_omitted()) {j["total"] = t.total;}
        if(!t.remaining.is_omitted()) {j["remaining"] = t.remaining;}
        if(!t.reset_after.is_omitted()) {j["reset_after"] = t.reset_after;}
        if(!t.max_concurrency.is_omitted()) {j["max_concurrency"] = t.max_concurrency;}
    }
};
