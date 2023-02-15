#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/topics/permissions#role-object-role-structure
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
    friend void from_json(const nlohmann::json &j, Role &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("color")){j.at("color").get_to(t.color);}
        if(j.contains("hoist")){j.at("hoist").get_to(t.hoist);}
        if(j.contains("icon")){j.at("icon").get_to(t.icon);}
        if(j.contains("unicode_emoji")){j.at("unicode_emoji").get_to(t.unicode_emoji);}
        if(j.contains("position")){j.at("position").get_to(t.position);}
        if(j.contains("permissions")){j.at("permissions").get_to(t.permissions);}
        if(j.contains("managed")){j.at("managed").get_to(t.managed);}
        if(j.contains("mentionable")){j.at("mentionable").get_to(t.mentionable);}
        if(j.contains("tags")){j.at("tags").get_to(t.tags);}
    }
};

// https://discord.com/developers/docs/topics/permissions#role-object-role-tags-structure
class RoleTags{
  public:
    RoleTags(
        omittable_field<Snowflake> bot_id = omitted,
        omittable_field<Snowflake> integration_id = omitted,
        omittable_field<std::nullptr_t> premium_subscriber = omitted,
        omittable_field<Snowflake> subscription_listing_id = omitted,
        omittable_field<std::nullptr_t> available_for_purchase = omitted,
        omittable_field<std::nullptr_t> guild_connections = omitted
    ):
        bot_id(bot_id),
        integration_id(integration_id),
        premium_subscriber(premium_subscriber),
        subscription_listing_id(subscription_listing_id),
        available_for_purchase(available_for_purchase),
        guild_connections(guild_connections)
    {}
    
    omittable_field<Snowflake> bot_id;
    omittable_field<Snowflake> integration_id;
    omittable_field<std::nullptr_t> premium_subscriber;
    omittable_field<Snowflake> subscription_listing_id;
    omittable_field<std::nullptr_t> available_for_purchase;
    omittable_field<std::nullptr_t> guild_connections;

    friend void to_json(nlohmann::json &j, const RoleTags &t) {
        if(!t.bot_id.is_omitted()) {j["bot_id"] = t.bot_id;}
        if(!t.integration_id.is_omitted()) {j["integration_id"] = t.integration_id;}
        if(!t.premium_subscriber.is_omitted()) {j["premium_subscriber"] = t.premium_subscriber;}
        if(!t.subscription_listing_id.is_omitted()) {j["subscription_listing_id"] = t.subscription_listing_id;}
        if(!t.available_for_purchase.is_omitted()) {j["available_for_purchase"] = t.available_for_purchase;}
        if(!t.guild_connections.is_omitted()) {j["guild_connections"] = t.guild_connections;}
    }
    friend void from_json(const nlohmann::json &j, RoleTags &t) {
        if(j.contains("bot_id")){j.at("bot_id").get_to(t.bot_id);}
        if(j.contains("integration_id")){j.at("integration_id").get_to(t.integration_id);}
        if(j.contains("premium_subscriber")){j.at("premium_subscriber").get_to(t.premium_subscriber);}
        if(j.contains("subscription_listing_id")){j.at("subscription_listing_id").get_to(t.subscription_listing_id);}
        if(j.contains("available_for_purchase")){j.at("available_for_purchase").get_to(t.available_for_purchase);}
        if(j.contains("guild_connections")){j.at("guild_connections").get_to(t.guild_connections);}
    }
};
