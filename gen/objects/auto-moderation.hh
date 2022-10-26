#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-rule-object-auto-moderation-rule-structure
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
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-rule-object-trigger-metadata
class TriggerMetadata{
  public:
    TriggerMetadata(
        field<std::vector<std::string> > keyword_filter = uninitialized,
        field<std::vector<KeywordPresetType> > presets = uninitialized,
        field<std::vector<std::string> > allow_list = uninitialized,
        field<int> mention_total_limit = uninitialized
    ): 
        keyword_filter(keyword_filter),
        presets(presets),
        allow_list(allow_list),
        mention_total_limit(mention_total_limit)
    {}
    
    field<std::vector<std::string> > keyword_filter;
    field<std::vector<KeywordPresetType> > presets;
    field<std::vector<std::string> > allow_list;
    field<int> mention_total_limit;

    friend void to_json(nlohmann::json &j, const TriggerMetadata &t) {
        //ToJsonExtra
        if(!t.keyword_filter.is_omitted()) {j["keyword_filter"] = t.keyword_filter;}
        if(!t.presets.is_omitted()) {j["presets"] = t.presets;}
        if(!t.allow_list.is_omitted()) {j["allow_list"] = t.allow_list;}
        if(!t.mention_total_limit.is_omitted()) {j["mention_total_limit"] = t.mention_total_limit;}
    }
};
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-action-object-auto-moderation-action-structure
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
// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-action-object-action-metadata
class ActionMetadata{
  public:
    ActionMetadata(
        field<Snowflake> channel_id = uninitialized,
        field<int> duration_seconds = uninitialized
    ): 
        channel_id(channel_id),
        duration_seconds(duration_seconds)
    {}
    
    field<Snowflake> channel_id;
    field<int> duration_seconds;

    friend void to_json(nlohmann::json &j, const ActionMetadata &t) {
        //ToJsonExtra
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.duration_seconds.is_omitted()) {j["duration_seconds"] = t.duration_seconds;}
    }
};
