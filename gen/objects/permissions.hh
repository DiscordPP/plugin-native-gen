#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/topics/permissions#role-object
class Role{
  public:
    Role(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<int> color = uninitialized,
        field<bool> hoist = uninitialized,
        nullable_omittable_field<std::string> icon = omitted,
        nullable_omittable_field<std::string> unicode_emoji = omitted,
        field<int> position = uninitialized,
        field<std::string> permissions = uninitialized,
        field<bool> managed = uninitialized,
        field<bool> mentionable = uninitialized,
        omittable_field<RoleTags> tags = omitted
    ): 
        id(id),
        name(name),
        color(color),
        hoist(hoist),
        icon(icon),
        unicode_emoji(unicode_emoji),
        position(position),
        permissions(permissions),
        managed(managed),
        mentionable(mentionable),
        tags(tags)
    {}
    
    field<Snowflake> id;
    field<std::string> name;
    field<int> color;
    field<bool> hoist;
    nullable_omittable_field<std::string> icon;
    nullable_omittable_field<std::string> unicode_emoji;
    field<int> position;
    field<std::string> permissions;
    field<bool> managed;
    field<bool> mentionable;
    omittable_field<RoleTags> tags;

    friend void to_json(nlohmann::json &j, const Role &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.color.is_omitted()) {j["color"] = t.color;}
        if(!t.hoist.is_omitted()) {j["hoist"] = t.hoist;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.unicode_emoji.is_omitted()) {j["unicode_emoji"] = t.unicode_emoji;}
        if(!t.position.is_omitted()) {j["position"] = t.position;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
        if(!t.managed.is_omitted()) {j["managed"] = t.managed;}
        if(!t.mentionable.is_omitted()) {j["mentionable"] = t.mentionable;}
        if(!t.tags.is_omitted()) {j["tags"] = t.tags;}
    }
};
// https://discord.com/developers/docs/topics/permissions#role-object
class RoleTags{
  public:
    RoleTags(
        omittable_field<Snowflake> bot_id = omitted,
        omittable_field<Snowflake> integration_id = omitted,
        omittable_field<std::nullptr_t> premium_subscriber = omitted
    ): 
        bot_id(bot_id),
        integration_id(integration_id),
        premium_subscriber(premium_subscriber)
    {}
    
    omittable_field<Snowflake> bot_id;
    omittable_field<Snowflake> integration_id;
    omittable_field<std::nullptr_t> premium_subscriber;

    friend void to_json(nlohmann::json &j, const RoleTags &t) {
        //ToJsonExtra
        if(!t.bot_id.is_omitted()) {j["bot_id"] = t.bot_id;}
        if(!t.integration_id.is_omitted()) {j["integration_id"] = t.integration_id;}
        if(!t.premium_subscriber.is_omitted()) {j["premium_subscriber"] = t.premium_subscriber;}
    }
};
