#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/user#user-object-user-structure
class User{
  public:
    User(
        field<Snowflake> id = uninitialized,
        field<std::string> username = uninitialized,
        field<std::string> discriminator = uninitialized,
        nullable_field<std::string> avatar = uninitialized,
        omittable_field<bool> bot = omitted,
        omittable_field<bool> system = omitted,
        omittable_field<bool> mfa_enabled = omitted,
        nullable_omittable_field<std::string> banner = omitted,
        nullable_omittable_field<int> accent_color = omitted,
        omittable_field<std::string> locale = omitted,
        omittable_field<bool> verified = omitted,
        nullable_omittable_field<std::string> email = omitted,
        omittable_field<int> flags = omitted,
        omittable_field<int> premium_type = omitted,
        omittable_field<int> public_flags = omitted
    ): 
        id(id),
        username(username),
        discriminator(discriminator),
        avatar(avatar),
        bot(bot),
        system(system),
        mfa_enabled(mfa_enabled),
        banner(banner),
        accent_color(accent_color),
        locale(locale),
        verified(verified),
        email(email),
        flags(flags),
        premium_type(premium_type),
        public_flags(public_flags)
    {}
    
    field<Snowflake> id;
    field<std::string> username;
    field<std::string> discriminator;
    nullable_field<std::string> avatar;
    omittable_field<bool> bot;
    omittable_field<bool> system;
    omittable_field<bool> mfa_enabled;
    nullable_omittable_field<std::string> banner;
    nullable_omittable_field<int> accent_color;
    omittable_field<std::string> locale;
    omittable_field<bool> verified;
    nullable_omittable_field<std::string> email;
    omittable_field<int> flags;
    omittable_field<int> premium_type;
    omittable_field<int> public_flags;

    friend void to_json(nlohmann::json &j, const User &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.username.is_omitted()) {j["username"] = t.username;}
        if(!t.discriminator.is_omitted()) {j["discriminator"] = t.discriminator;}
        if(!t.avatar.is_omitted()) {j["avatar"] = t.avatar;}
        if(!t.bot.is_omitted()) {j["bot"] = t.bot;}
        if(!t.system.is_omitted()) {j["system"] = t.system;}
        if(!t.mfa_enabled.is_omitted()) {j["mfa_enabled"] = t.mfa_enabled;}
        if(!t.banner.is_omitted()) {j["banner"] = t.banner;}
        if(!t.accent_color.is_omitted()) {j["accent_color"] = t.accent_color;}
        if(!t.locale.is_omitted()) {j["locale"] = t.locale;}
        if(!t.verified.is_omitted()) {j["verified"] = t.verified;}
        if(!t.email.is_omitted()) {j["email"] = t.email;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.premium_type.is_omitted()) {j["premium_type"] = t.premium_type;}
        if(!t.public_flags.is_omitted()) {j["public_flags"] = t.public_flags;}
    }
};
// https://discord.com/developers/docs/resources/user#connection-object-connection-structure
class Connection{
  public:
    Connection(
        field<std::string> id = uninitialized,
        field<std::string> name = uninitialized,
        field<std::string> type = uninitialized,
        omittable_field<bool> revoked = omitted,
        omittable_field<std::vector<Integration> > integrations = omitted,
        field<bool> verified = uninitialized,
        field<bool> friend_sync = uninitialized,
        field<bool> show_activity = uninitialized,
        field<bool> two_way_link = uninitialized,
        field<int> visibility = uninitialized
    ): 
        id(id),
        name(name),
        type(type),
        revoked(revoked),
        integrations(integrations),
        verified(verified),
        friend_sync(friend_sync),
        show_activity(show_activity),
        two_way_link(two_way_link),
        visibility(visibility)
    {}
    
    field<std::string> id;
    field<std::string> name;
    field<std::string> type;
    omittable_field<bool> revoked;
    omittable_field<std::vector<Integration> > integrations;
    field<bool> verified;
    field<bool> friend_sync;
    field<bool> show_activity;
    field<bool> two_way_link;
    field<int> visibility;

    friend void to_json(nlohmann::json &j, const Connection &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.revoked.is_omitted()) {j["revoked"] = t.revoked;}
        if(!t.integrations.is_omitted()) {j["integrations"] = t.integrations;}
        if(!t.verified.is_omitted()) {j["verified"] = t.verified;}
        if(!t.friend_sync.is_omitted()) {j["friend_sync"] = t.friend_sync;}
        if(!t.show_activity.is_omitted()) {j["show_activity"] = t.show_activity;}
        if(!t.two_way_link.is_omitted()) {j["two_way_link"] = t.two_way_link;}
        if(!t.visibility.is_omitted()) {j["visibility"] = t.visibility;}
    }
};
// https://discord.com/developers/docs/resources/user#application-role-connection-object-application-role-connection-structure
class ApplicationRoleConnection{
  public:
    ApplicationRoleConnection(
        nullable_field<std::string> platform_name = uninitialized,
        nullable_field<std::string> platform_username = uninitialized,
        field<Object> metadata = uninitialized
    ): 
        platform_name(platform_name),
        platform_username(platform_username),
        metadata(metadata)
    {}
    
    nullable_field<std::string> platform_name;
    nullable_field<std::string> platform_username;
    field<Object> metadata;

    friend void to_json(nlohmann::json &j, const ApplicationRoleConnection &t) {
        //ToJsonExtra
        if(!t.platform_name.is_omitted()) {j["platform_name"] = t.platform_name;}
        if(!t.platform_username.is_omitted()) {j["platform_username"] = t.platform_username;}
        if(!t.metadata.is_omitted()) {j["metadata"] = t.metadata;}
    }
};
