#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/guild-template#guild-template-object-guild-template-structure
class GuildTemplate{
  public:
    GuildTemplate(
        field<std::string> code = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> description = uninitialized,
        field<int> usage_count = uninitialized,
        field<Snowflake> creator_id = uninitialized,
        field<User> creator = uninitialized,
        field<Timestamp> created_at = uninitialized,
        field<Timestamp> updated_at = uninitialized,
        field<Snowflake> source_guild_id = uninitialized,
        field<Guild> serialized_source_guild = uninitialized,
        nullable_field<bool> is_dirty = uninitialized
    ):
        code(code),
        name(name),
        description(description),
        usage_count(usage_count),
        creator_id(creator_id),
        creator(creator),
        created_at(created_at),
        updated_at(updated_at),
        source_guild_id(source_guild_id),
        serialized_source_guild(serialized_source_guild),
        is_dirty(is_dirty)
    {}
    
    field<std::string> code;
    field<std::string> name;
    nullable_field<std::string> description;
    field<int> usage_count;
    field<Snowflake> creator_id;
    field<User> creator;
    field<Timestamp> created_at;
    field<Timestamp> updated_at;
    field<Snowflake> source_guild_id;
    field<Guild> serialized_source_guild;
    nullable_field<bool> is_dirty;

    friend void to_json(nlohmann::json &j, const GuildTemplate &t) {
        if(!t.code.is_omitted()) {j["code"] = t.code;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.usage_count.is_omitted()) {j["usage_count"] = t.usage_count;}
        if(!t.creator_id.is_omitted()) {j["creator_id"] = t.creator_id;}
        if(!t.creator.is_omitted()) {j["creator"] = t.creator;}
        if(!t.created_at.is_omitted()) {j["created_at"] = t.created_at;}
        if(!t.updated_at.is_omitted()) {j["updated_at"] = t.updated_at;}
        if(!t.source_guild_id.is_omitted()) {j["source_guild_id"] = t.source_guild_id;}
        if(!t.serialized_source_guild.is_omitted()) {j["serialized_source_guild"] = t.serialized_source_guild;}
        if(!t.is_dirty.is_omitted()) {j["is_dirty"] = t.is_dirty;}
    }
    friend void from_json(const nlohmann::json &j, GuildTemplate &t) {
        if(j.contains("code")){j.at("code").get_to(t.code);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("usage_count")){j.at("usage_count").get_to(t.usage_count);}
        if(j.contains("creator_id")){j.at("creator_id").get_to(t.creator_id);}
        if(j.contains("creator")){j.at("creator").get_to(t.creator);}
        if(j.contains("created_at")){j.at("created_at").get_to(t.created_at);}
        if(j.contains("updated_at")){j.at("updated_at").get_to(t.updated_at);}
        if(j.contains("source_guild_id")){j.at("source_guild_id").get_to(t.source_guild_id);}
        if(j.contains("serialized_source_guild")){j.at("serialized_source_guild").get_to(t.serialized_source_guild);}
        if(j.contains("is_dirty")){j.at("is_dirty").get_to(t.is_dirty);}
    }
};
