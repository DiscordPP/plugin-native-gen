#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.require_colons.is_omitted()) {j["require_colons"] = t.require_colons;}
        if(!t.managed.is_omitted()) {j["managed"] = t.managed;}
        if(!t.animated.is_omitted()) {j["animated"] = t.animated;}
        if(!t.available.is_omitted()) {j["available"] = t.available;}
    }
};
