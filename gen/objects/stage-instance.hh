#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/stage-instance#stage-instance-object
class StageInstance{
  public:
    StageInstance(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<std::string> topic = uninitialized,
        field<int> privacy_level = uninitialized,
        field<bool> discoverable_disabled = uninitialized,
        nullable_field<Snowflake> guild_scheduled_event_id = uninitialized
    ): 
        id(id),
        guild_id(guild_id),
        channel_id(channel_id),
        topic(topic),
        privacy_level(privacy_level),
        discoverable_disabled(discoverable_disabled),
        guild_scheduled_event_id(guild_scheduled_event_id)
    {}
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<Snowflake> channel_id;
    field<std::string> topic;
    field<int> privacy_level;
    field<bool> discoverable_disabled;
    nullable_field<Snowflake> guild_scheduled_event_id;

    friend void to_json(nlohmann::json &j, const StageInstance &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.topic.is_omitted()) {j["topic"] = t.topic;}
        if(!t.privacy_level.is_omitted()) {j["privacy_level"] = t.privacy_level;}
        if(!t.discoverable_disabled.is_omitted()) {j["discoverable_disabled"] = t.discoverable_disabled;}
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
    }
};
