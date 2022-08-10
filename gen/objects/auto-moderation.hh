#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

class AutoModerationRule{
  public:
    AutoModerationRule(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<std::string> name = uninitialized,
        field<Snowflake> creator_id = uninitialized,
        field<int> event_type = uninitialized,
        field<int> trigger_type = uninitialized,
        field<TriggerMetadata> trigger_metadata = uninitialized,
        field<std::vector<Action> > actions = uninitialized,
        field<bool> enabled = uninitialized,
        field<std::vector<Snowflake> > exempt_roles = uninitialized,
        field<std::vector<Snowflake> > exempt_channels = uninitialized
    ): 
        id(id),
        guild_id(guild_id),
        name(name),
        creator_id(creator_id),
        event_type(event_type),
        trigger_type(trigger_type),
        trigger_metadata(trigger_metadata),
        actions(actions),
        enabled(enabled),
        exempt_roles(exempt_roles),
        exempt_channels(exempt_channels)
    {}
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<std::string> name;
    field<Snowflake> creator_id;
    field<int> event_type;
    field<int> trigger_type;
    field<TriggerMetadata> trigger_metadata;
    field<std::vector<Action> > actions;
    field<bool> enabled;
    field<std::vector<Snowflake> > exempt_roles;
    field<std::vector<Snowflake> > exempt_channels;

    friend void to_json(nlohmann::json &j, const AutoModerationRule &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.creator_id.is_omitted()) {j["creator_id"] = t.creator_id;}
        if(!t.event_type.is_omitted()) {j["event_type"] = t.event_type;}
        if(!t.trigger_type.is_omitted()) {j["trigger_type"] = t.trigger_type;}
        if(!t.trigger_metadata.is_omitted()) {j["trigger_metadata"] = t.trigger_metadata;}
        if(!t.actions.is_omitted()) {j["actions"] = t.actions;}
        if(!t.enabled.is_omitted()) {j["enabled"] = t.enabled;}
        if(!t.exempt_roles.is_omitted()) {j["exempt_roles"] = t.exempt_roles;}
        if(!t.exempt_channels.is_omitted()) {j["exempt_channels"] = t.exempt_channels;}
    }
};
class AutoModerationAction{
  public:
    AutoModerationAction(
        field<ActionType> type = uninitialized,
        omittable_field<ActionMetadata> metadata = omitted
    ): 
        type(type),
        metadata(metadata)
    {}
    
    field<ActionType> type;
    omittable_field<ActionMetadata> metadata;

    friend void to_json(nlohmann::json &j, const AutoModerationAction &t) {
        //ToJsonExtra
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.metadata.is_omitted()) {j["metadata"] = t.metadata;}
    }
};
