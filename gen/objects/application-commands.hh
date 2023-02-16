#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/interactions/application-commands#application-command-object-application-command-structure
class ApplicationCommand{
  public:
    ApplicationCommand(
        field<Snowflake> id = uninitialized,
        omittable_field<ApplicationCommandType> type = omitted,
        field<Snowflake> application_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<std::string> name = uninitialized,
        nullable_omittable_field<std::map<Locale, std::string>> name_localizations = omitted,
        field<std::string> description = uninitialized,
        nullable_omittable_field<std::map<Locale, std::string>> description_localizations = omitted,
        omittable_field<std::vector<ApplicationCommandOption> > options = omitted,
        nullable_field<std::string> default_member_permissions = uninitialized,
        omittable_field<bool> dm_permission = omitted,
        nullable_omittable_field<bool> default_permission = omitted,
        omittable_field<bool> nsfw = omitted,
        field<Snowflake> version = uninitialized
    ):
        id(id),
        type(type),
        application_id(application_id),
        guild_id(guild_id),
        name(name),
        name_localizations(name_localizations),
        description(description),
        description_localizations(description_localizations),
        options(options),
        default_member_permissions(default_member_permissions),
        dm_permission(dm_permission),
        default_permission(default_permission),
        nsfw(nsfw),
        version(version)
    {}
    ApplicationCommand(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    omittable_field<ApplicationCommandType> type;
    field<Snowflake> application_id;
    omittable_field<Snowflake> guild_id;
    field<std::string> name;
    nullable_omittable_field<std::map<Locale, std::string>> name_localizations;
    field<std::string> description;
    nullable_omittable_field<std::map<Locale, std::string>> description_localizations;
    omittable_field<std::vector<ApplicationCommandOption> > options;
    nullable_field<std::string> default_member_permissions;
    omittable_field<bool> dm_permission;
    nullable_omittable_field<bool> default_permission;
    omittable_field<bool> nsfw;
    field<Snowflake> version;

    friend void to_json(nlohmann::json &j, const ApplicationCommand &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.name_localizations.is_omitted()) {j["name_localizations"] = t.name_localizations;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.description_localizations.is_omitted()) {j["description_localizations"] = t.description_localizations;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.default_member_permissions.is_omitted()) {j["default_member_permissions"] = t.default_member_permissions;}
        if(!t.dm_permission.is_omitted()) {j["dm_permission"] = t.dm_permission;}
        if(!t.default_permission.is_omitted()) {j["default_permission"] = t.default_permission;}
        if(!t.nsfw.is_omitted()) {j["nsfw"] = t.nsfw;}
        if(!t.version.is_omitted()) {j["version"] = t.version;}
    }
    friend void from_json(const nlohmann::json &j, ApplicationCommand &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("name_localizations")){j.at("name_localizations").get_to(t.name_localizations);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("description_localizations")){j.at("description_localizations").get_to(t.description_localizations);}
        if(j.contains("options")){j.at("options").get_to(t.options);}
        if(j.contains("default_member_permissions")){j.at("default_member_permissions").get_to(t.default_member_permissions);}
        if(j.contains("dm_permission")){j.at("dm_permission").get_to(t.dm_permission);}
        if(j.contains("default_permission")){j.at("default_permission").get_to(t.default_permission);}
        if(j.contains("nsfw")){j.at("nsfw").get_to(t.nsfw);}
        if(j.contains("version")){j.at("version").get_to(t.version);}
    }
};

// https://discord.com/developers/docs/interactions/application-commands#application-command-object-application-command-option-structure
class ApplicationCommandOption{
  public:
    ApplicationCommandOption(
        field<ApplicationCommandOptionType> type = uninitialized,
        field<std::string> name = uninitialized,
        nullable_omittable_field<std::map<Locale, std::string>> name_localizations = omitted,
        field<std::string> description = uninitialized,
        nullable_omittable_field<std::map<Locale, std::string>> description_localizations = omitted,
        omittable_field<bool> required = omitted,
        omittable_field<std::vector<ApplicationCommandOptionChoice> > choices = omitted,
        omittable_field<std::vector<ApplicationCommandOption> > options = omitted,
        omittable_field<std::vector<ChannelType> > channel_types = omitted,
        omittable_field<std::variant<int, double>> min_value = omitted,
        omittable_field<std::variant<int, double>> max_value = omitted,
        omittable_field<int> min_length = omitted,
        omittable_field<int> max_length = omitted,
        omittable_field<bool> autocomplete = omitted
    ):
        type(type),
        name(name),
        name_localizations(name_localizations),
        description(description),
        description_localizations(description_localizations),
        required(required),
        choices(choices),
        options(options),
        channel_types(channel_types),
        min_value(min_value),
        max_value(max_value),
        min_length(min_length),
        max_length(max_length),
        autocomplete(autocomplete)
    {}
    ApplicationCommandOption(const json &j) { from_json(j, *this); }
    
    field<ApplicationCommandOptionType> type;
    field<std::string> name;
    nullable_omittable_field<std::map<Locale, std::string>> name_localizations;
    field<std::string> description;
    nullable_omittable_field<std::map<Locale, std::string>> description_localizations;
    omittable_field<bool> required;
    omittable_field<std::vector<ApplicationCommandOptionChoice> > choices;
    omittable_field<std::vector<ApplicationCommandOption> > options;
    omittable_field<std::vector<ChannelType> > channel_types;
    omittable_field<std::variant<int, double>> min_value;
    omittable_field<std::variant<int, double>> max_value;
    omittable_field<int> min_length;
    omittable_field<int> max_length;
    omittable_field<bool> autocomplete;

    friend void to_json(nlohmann::json &j, const ApplicationCommandOption &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.name_localizations.is_omitted()) {j["name_localizations"] = t.name_localizations;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.description_localizations.is_omitted()) {j["description_localizations"] = t.description_localizations;}
        if(!t.required.is_omitted()) {j["required"] = t.required;}
        if(!t.choices.is_omitted()) {j["choices"] = t.choices;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.channel_types.is_omitted()) {j["channel_types"] = t.channel_types;}
        if(!t.min_value.is_omitted()) {j["min_value"] = t.min_value;}
        if(!t.max_value.is_omitted()) {j["max_value"] = t.max_value;}
        if(!t.min_length.is_omitted()) {j["min_length"] = t.min_length;}
        if(!t.max_length.is_omitted()) {j["max_length"] = t.max_length;}
        if(!t.autocomplete.is_omitted()) {j["autocomplete"] = t.autocomplete;}
    }
    friend void from_json(const nlohmann::json &j, ApplicationCommandOption &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("name_localizations")){j.at("name_localizations").get_to(t.name_localizations);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("description_localizations")){j.at("description_localizations").get_to(t.description_localizations);}
        if(j.contains("required")){j.at("required").get_to(t.required);}
        if(j.contains("choices")){j.at("choices").get_to(t.choices);}
        if(j.contains("options")){j.at("options").get_to(t.options);}
        if(j.contains("channel_types")){j.at("channel_types").get_to(t.channel_types);}
        if(j.contains("min_value")){j.at("min_value").get_to(t.min_value);}
        if(j.contains("max_value")){j.at("max_value").get_to(t.max_value);}
        if(j.contains("min_length")){j.at("min_length").get_to(t.min_length);}
        if(j.contains("max_length")){j.at("max_length").get_to(t.max_length);}
        if(j.contains("autocomplete")){j.at("autocomplete").get_to(t.autocomplete);}
    }
};

// https://discord.com/developers/docs/interactions/application-commands#application-command-object-application-command-option-choice-structure
class ApplicationCommandOptionChoice{
  public:
    ApplicationCommandOptionChoice(
        field<std::string> name = uninitialized,
        nullable_omittable_field<std::map<Locale, std::string>> name_localizations = omitted,
        field<std::variant<std::string, int, double> > value = uninitialized
    ):
        name(name),
        name_localizations(name_localizations),
        value(value)
    {}
    ApplicationCommandOptionChoice(const json &j) { from_json(j, *this); }
    
    field<std::string> name;
    nullable_omittable_field<std::map<Locale, std::string>> name_localizations;
    field<std::variant<std::string, int, double> > value;

    friend void to_json(nlohmann::json &j, const ApplicationCommandOptionChoice &t) {
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.name_localizations.is_omitted()) {j["name_localizations"] = t.name_localizations;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
    }
    friend void from_json(const nlohmann::json &j, ApplicationCommandOptionChoice &t) {
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("name_localizations")){j.at("name_localizations").get_to(t.name_localizations);}
        if(j.contains("value")){j.at("value").get_to(t.value);}
    }
};

// https://discord.com/developers/docs/interactions/application-commands#application-command-permissions-object-guild-application-command-permissions-structure
class GuildApplicationCommandPermissions{
  public:
    GuildApplicationCommandPermissions(
        field<Snowflake> id = uninitialized,
        field<Snowflake> application_id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<ApplicationCommandPermissions> > permissions = uninitialized
    ):
        id(id),
        application_id(application_id),
        guild_id(guild_id),
        permissions(permissions)
    {}
    GuildApplicationCommandPermissions(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> application_id;
    field<Snowflake> guild_id;
    field<std::vector<ApplicationCommandPermissions> > permissions;

    friend void to_json(nlohmann::json &j, const GuildApplicationCommandPermissions &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
    }
    friend void from_json(const nlohmann::json &j, GuildApplicationCommandPermissions &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("permissions")){j.at("permissions").get_to(t.permissions);}
    }
};

// https://discord.com/developers/docs/interactions/application-commands#application-command-permissions-object-application-command-permissions-structure
class ApplicationCommandPermissions{
  public:
    ApplicationCommandPermissions(
        field<Snowflake> id = uninitialized,
        field<ApplicationCommandPermissionType> type = uninitialized,
        field<bool> permission = uninitialized
    ):
        id(id),
        type(type),
        permission(permission)
    {}
    ApplicationCommandPermissions(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<ApplicationCommandPermissionType> type;
    field<bool> permission;

    friend void to_json(nlohmann::json &j, const ApplicationCommandPermissions &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.permission.is_omitted()) {j["permission"] = t.permission;}
    }
    friend void from_json(const nlohmann::json &j, ApplicationCommandPermissions &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("permission")){j.at("permission").get_to(t.permission);}
    }
};
