#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-object-guild-scheduled-event-structure
class GuildScheduledEvent{
  public:
    GuildScheduledEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        nullable_field<Snowflake> channel_id = uninitialized,
        nullable_omittable_field<Snowflake> creator_id = omitted,
        field<std::string> name = uninitialized,
        nullable_omittable_field<std::string> description = omitted,
        field<Timestamp> scheduled_start_time = uninitialized,
        nullable_field<Timestamp> scheduled_end_time = uninitialized,
        field<PrivacyLevel> privacy_level = uninitialized,
        field<EventStatus> status = uninitialized,
        field<ScheduledEntityType> entity_type = uninitialized,
        nullable_field<Snowflake> entity_id = uninitialized,
        nullable_field<GuildScheduledEventEntityMetadata> entity_metadata = uninitialized,
        omittable_field<User> creator = omitted,
        omittable_field<int> user_count = omitted,
        nullable_omittable_field<std::string> image = omitted
    ): 
        id(id),
        guild_id(guild_id),
        channel_id(channel_id),
        creator_id(creator_id),
        name(name),
        description(description),
        scheduled_start_time(scheduled_start_time),
        scheduled_end_time(scheduled_end_time),
        privacy_level(privacy_level),
        status(status),
        entity_type(entity_type),
        entity_id(entity_id),
        entity_metadata(entity_metadata),
        creator(creator),
        user_count(user_count),
        image(image)
    {}
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    nullable_omittable_field<Snowflake> creator_id;
    field<std::string> name;
    nullable_omittable_field<std::string> description;
    field<Timestamp> scheduled_start_time;
    nullable_field<Timestamp> scheduled_end_time;
    field<PrivacyLevel> privacy_level;
    field<EventStatus> status;
    field<ScheduledEntityType> entity_type;
    nullable_field<Snowflake> entity_id;
    nullable_field<GuildScheduledEventEntityMetadata> entity_metadata;
    omittable_field<User> creator;
    omittable_field<int> user_count;
    nullable_omittable_field<std::string> image;

    friend void to_json(nlohmann::json &j, const GuildScheduledEvent &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.creator_id.is_omitted()) {j["creator_id"] = t.creator_id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.scheduled_start_time.is_omitted()) {j["scheduled_start_time"] = t.scheduled_start_time;}
        if(!t.scheduled_end_time.is_omitted()) {j["scheduled_end_time"] = t.scheduled_end_time;}
        if(!t.privacy_level.is_omitted()) {j["privacy_level"] = t.privacy_level;}
        if(!t.status.is_omitted()) {j["status"] = t.status;}
        if(!t.entity_type.is_omitted()) {j["entity_type"] = t.entity_type;}
        if(!t.entity_id.is_omitted()) {j["entity_id"] = t.entity_id;}
        if(!t.entity_metadata.is_omitted()) {j["entity_metadata"] = t.entity_metadata;}
        if(!t.creator.is_omitted()) {j["creator"] = t.creator;}
        if(!t.user_count.is_omitted()) {j["user_count"] = t.user_count;}
        if(!t.image.is_omitted()) {j["image"] = t.image;}
    }
};
// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-object-guild-scheduled-event-entity-metadata
class GuildScheduledEventEntityMetadata{
  public:
    GuildScheduledEventEntityMetadata(
        omittable_field<std::string> location = omitted
    ): 
        location(location)
    {}
    
    omittable_field<std::string> location;

    friend void to_json(nlohmann::json &j, const GuildScheduledEventEntityMetadata &t) {
        //ToJsonExtra
        if(!t.location.is_omitted()) {j["location"] = t.location;}
    }
};
// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-user-object-guild-scheduled-event-user-structure
class GuildScheduledEventUser{
  public:
    GuildScheduledEventUser(
        field<Snowflake> guild_scheduled_event_id = uninitialized,
        field<User> user = uninitialized,
        omittable_field<GuildMember> member = omitted
    ): 
        guild_scheduled_event_id(guild_scheduled_event_id),
        user(user),
        member(member)
    {}
    
    field<Snowflake> guild_scheduled_event_id;
    field<User> user;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const GuildScheduledEventUser &t) {
        //ToJsonExtra
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
    }
};
