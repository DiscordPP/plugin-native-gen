#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/voice#voice-state-object-voice-state-structure
class VoiceState{
  public:
    VoiceState(
        omittable_field<Snowflake> guild_id = omitted,
        nullable_field<Snowflake> channel_id = uninitialized,
        field<Snowflake> user_id = uninitialized,
        omittable_field<GuildMember> member = omitted,
        field<std::string> session_id = uninitialized,
        field<bool> deaf = uninitialized,
        field<bool> mute = uninitialized,
        field<bool> self_deaf = uninitialized,
        field<bool> self_mute = uninitialized,
        omittable_field<bool> self_stream = omitted,
        field<bool> self_video = uninitialized,
        field<bool> suppress = uninitialized,
        nullable_field<Timestamp> request_to_speak_timestamp = uninitialized
    ):
        guild_id(guild_id),
        channel_id(channel_id),
        user_id(user_id),
        member(member),
        session_id(session_id),
        deaf(deaf),
        mute(mute),
        self_deaf(self_deaf),
        self_mute(self_mute),
        self_stream(self_stream),
        self_video(self_video),
        suppress(suppress),
        request_to_speak_timestamp(request_to_speak_timestamp)
    {}
    VoiceState(const json &j) { from_json(j, *this); }
    
    omittable_field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    field<Snowflake> user_id;
    omittable_field<GuildMember> member;
    field<std::string> session_id;
    field<bool> deaf;
    field<bool> mute;
    field<bool> self_deaf;
    field<bool> self_mute;
    omittable_field<bool> self_stream;
    field<bool> self_video;
    field<bool> suppress;
    nullable_field<Timestamp> request_to_speak_timestamp;

    friend void to_json(nlohmann::json &j, const VoiceState &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.session_id.is_omitted()) {j["session_id"] = t.session_id;}
        if(!t.deaf.is_omitted()) {j["deaf"] = t.deaf;}
        if(!t.mute.is_omitted()) {j["mute"] = t.mute;}
        if(!t.self_deaf.is_omitted()) {j["self_deaf"] = t.self_deaf;}
        if(!t.self_mute.is_omitted()) {j["self_mute"] = t.self_mute;}
        if(!t.self_stream.is_omitted()) {j["self_stream"] = t.self_stream;}
        if(!t.self_video.is_omitted()) {j["self_video"] = t.self_video;}
        if(!t.suppress.is_omitted()) {j["suppress"] = t.suppress;}
        if(!t.request_to_speak_timestamp.is_omitted()) {j["request_to_speak_timestamp"] = t.request_to_speak_timestamp;}
    }
    friend void from_json(const nlohmann::json &j, VoiceState &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
        if(j.contains("session_id")){j.at("session_id").get_to(t.session_id);}
        if(j.contains("deaf")){j.at("deaf").get_to(t.deaf);}
        if(j.contains("mute")){j.at("mute").get_to(t.mute);}
        if(j.contains("self_deaf")){j.at("self_deaf").get_to(t.self_deaf);}
        if(j.contains("self_mute")){j.at("self_mute").get_to(t.self_mute);}
        if(j.contains("self_stream")){j.at("self_stream").get_to(t.self_stream);}
        if(j.contains("self_video")){j.at("self_video").get_to(t.self_video);}
        if(j.contains("suppress")){j.at("suppress").get_to(t.suppress);}
        if(j.contains("request_to_speak_timestamp")){j.at("request_to_speak_timestamp").get_to(t.request_to_speak_timestamp);}
    }
};

// https://discord.com/developers/docs/resources/voice#voice-region-object-voice-region-structure
class VoiceRegion{
  public:
    VoiceRegion(
        field<std::string> id = uninitialized,
        field<std::string> name = uninitialized,
        field<bool> optimal = uninitialized,
        field<bool> deprecated = uninitialized,
        field<bool> custom = uninitialized
    ):
        id(id),
        name(name),
        optimal(optimal),
        deprecated(deprecated),
        custom(custom)
    {}
    VoiceRegion(const json &j) { from_json(j, *this); }
    
    field<std::string> id;
    field<std::string> name;
    field<bool> optimal;
    field<bool> deprecated;
    field<bool> custom;

    friend void to_json(nlohmann::json &j, const VoiceRegion &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.optimal.is_omitted()) {j["optimal"] = t.optimal;}
        if(!t.deprecated.is_omitted()) {j["deprecated"] = t.deprecated;}
        if(!t.custom.is_omitted()) {j["custom"] = t.custom;}
    }
    friend void from_json(const nlohmann::json &j, VoiceRegion &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("optimal")){j.at("optimal").get_to(t.optimal);}
        if(j.contains("deprecated")){j.at("deprecated").get_to(t.deprecated);}
        if(j.contains("custom")){j.at("custom").get_to(t.custom);}
    }
};
