#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/emoji#emoji-object-emoji-structure
class Emoji{
  public:
    Emoji(
        nullable_field<Snowflake> id = uninitialized,
        nullable_field<std::string> name = uninitialized,
        omittable_field<std::vector<Snowflake> > roles = omitted,
        omittable_field<User> user = omitted,
        omittable_field<bool> require_colons = omitted,
        omittable_field<bool> managed = omitted,
        omittable_field<bool> animated = omitted,
        omittable_field<bool> available = omitted
    ):
        id(id),
        name(name),
        roles(roles),
        user(user),
        require_colons(require_colons),
        managed(managed),
        animated(animated),
        available(available)
    {}
    
    nullable_field<Snowflake> id;
    nullable_field<std::string> name;
    omittable_field<std::vector<Snowflake> > roles;
    omittable_field<User> user;
    omittable_field<bool> require_colons;
    omittable_field<bool> managed;
    omittable_field<bool> animated;
    omittable_field<bool> available;

    friend void to_json(nlohmann::json &j, const Emoji &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.require_colons.is_omitted()) {j["require_colons"] = t.require_colons;}
        if(!t.managed.is_omitted()) {j["managed"] = t.managed;}
        if(!t.animated.is_omitted()) {j["animated"] = t.animated;}
        if(!t.available.is_omitted()) {j["available"] = t.available;}
    }
    friend void from_json(const nlohmann::json &j, Emoji &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("roles")){j.at("roles").get_to(t.roles);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("require_colons")){j.at("require_colons").get_to(t.require_colons);}
        if(j.contains("managed")){j.at("managed").get_to(t.managed);}
        if(j.contains("animated")){j.at("animated").get_to(t.animated);}
        if(j.contains("available")){j.at("available").get_to(t.available);}
    }
};
