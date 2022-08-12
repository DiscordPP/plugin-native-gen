#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/audit-log#audit-log-object
class AuditLog{
  public:
    AuditLog(
        field<std::vector<AuditLogEntry> > audit_log_entries = uninitialized,
        field<std::vector<AutoModerationRule> > auto_moderation_rules = uninitialized,
        field<std::vector<GuildScheduledEvent> > guild_scheduled_events = uninitialized,
        field<std::vector<Integration> > integrations = uninitialized,
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<User> > users = uninitialized,
        field<std::vector<Webhook> > webhooks = uninitialized
    ): 
        audit_log_entries(audit_log_entries),
        auto_moderation_rules(auto_moderation_rules),
        guild_scheduled_events(guild_scheduled_events),
        integrations(integrations),
        threads(threads),
        users(users),
        webhooks(webhooks)
    {}
    
    field<std::vector<AuditLogEntry> > audit_log_entries;
    field<std::vector<AutoModerationRule> > auto_moderation_rules;
    field<std::vector<GuildScheduledEvent> > guild_scheduled_events;
    field<std::vector<Integration> > integrations;
    field<std::vector<Channel> > threads;
    field<std::vector<User> > users;
    field<std::vector<Webhook> > webhooks;

    friend void to_json(nlohmann::json &j, const AuditLog &t) {
        //ToJsonExtra
        if(!t.audit_log_entries.is_omitted()) {j["audit_log_entries"] = t.audit_log_entries;}
        if(!t.auto_moderation_rules.is_omitted()) {j["auto_moderation_rules"] = t.auto_moderation_rules;}
        if(!t.guild_scheduled_events.is_omitted()) {j["guild_scheduled_events"] = t.guild_scheduled_events;}
        if(!t.integrations.is_omitted()) {j["integrations"] = t.integrations;}
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.users.is_omitted()) {j["users"] = t.users;}
        if(!t.webhooks.is_omitted()) {j["webhooks"] = t.webhooks;}
    }
};
// https://discord.com/developers/docs/resources/audit-log#audit-log-entry-object
class AuditLogEntry{
  public:
    AuditLogEntry(
        nullable_field<std::string> target_id = uninitialized,
        omittable_field<std::vector<AuditLogChange> > changes = omitted,
        nullable_field<Snowflake> user_id = uninitialized,
        field<Snowflake> id = uninitialized,
        field<AuditLogEvent> action_type = uninitialized,
        omittable_field<OptionalAuditEntryInfo> options = omitted,
        omittable_field<std::string> reason = omitted
    ): 
        target_id(target_id),
        changes(changes),
        user_id(user_id),
        id(id),
        action_type(action_type),
        options(options),
        reason(reason)
    {}
    
    nullable_field<std::string> target_id;
    omittable_field<std::vector<AuditLogChange> > changes;
    nullable_field<Snowflake> user_id;
    field<Snowflake> id;
    field<AuditLogEvent> action_type;
    omittable_field<OptionalAuditEntryInfo> options;
    omittable_field<std::string> reason;

    friend void to_json(nlohmann::json &j, const AuditLogEntry &t) {
        //ToJsonExtra
        if(!t.target_id.is_omitted()) {j["target_id"] = t.target_id;}
        if(!t.changes.is_omitted()) {j["changes"] = t.changes;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.action_type.is_omitted()) {j["action_type"] = t.action_type;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.reason.is_omitted()) {j["reason"] = t.reason;}
    }
};
// https://discord.com/developers/docs/resources/audit-log#audit-log-change-object
class AuditLogChange{
  public:
    AuditLogChange(
        omittable_field<json> new_value = omitted,
        omittable_field<json> old_value = omitted,
        field<std::string> key = uninitialized
    ): 
        new_value(new_value),
        old_value(old_value),
        key(key)
    {}
    
    omittable_field<json> new_value;
    omittable_field<json> old_value;
    field<std::string> key;

    friend void to_json(nlohmann::json &j, const AuditLogChange &t) {
        //ToJsonExtra
        if(!t.new_value.is_omitted()) {j["new_value"] = t.new_value;}
        if(!t.old_value.is_omitted()) {j["old_value"] = t.old_value;}
        if(!t.key.is_omitted()) {j["key"] = t.key;}
    }
};
