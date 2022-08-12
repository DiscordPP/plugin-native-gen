#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/webhook#webhook-object
class Webhook{
  public:
    Webhook(
        field<Snowflake> id = uninitialized,
        field<int> type = uninitialized,
        nullable_omittable_field<Snowflake> guild_id = omitted,
        nullable_field<Snowflake> channel_id = uninitialized,
        omittable_field<User> user = omitted,
        nullable_field<std::string> name = uninitialized,
        nullable_field<std::string> avatar = uninitialized,
        omittable_field<std::string> token = omitted,
        nullable_field<Snowflake> application_id = uninitialized,
        omittable_field<Guild> source_guild = omitted,
        omittable_field<Channel> source_channel = omitted,
        omittable_field<std::string> url = omitted
    ): 
        id(id),
        type(type),
        guild_id(guild_id),
        channel_id(channel_id),
        user(user),
        name(name),
        avatar(avatar),
        token(token),
        application_id(application_id),
        source_guild(source_guild),
        source_channel(source_channel),
        url(url)
    {}
    
    field<Snowflake> id;
    field<int> type;
    nullable_omittable_field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    omittable_field<User> user;
    nullable_field<std::string> name;
    nullable_field<std::string> avatar;
    omittable_field<std::string> token;
    nullable_field<Snowflake> application_id;
    omittable_field<Guild> source_guild;
    omittable_field<Channel> source_channel;
    omittable_field<std::string> url;

    friend void to_json(nlohmann::json &j, const Webhook &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.avatar.is_omitted()) {j["avatar"] = t.avatar;}
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.source_guild.is_omitted()) {j["source_guild"] = t.source_guild;}
        if(!t.source_channel.is_omitted()) {j["source_channel"] = t.source_channel;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
    }
};
