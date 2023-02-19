#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "field.hh"

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

// https://discord.com/developers/docs/interactions/message-components#select-menu-object-select-option-structure
class SelectOption{
  public:
    SelectOption(
        field<std::string> label = uninitialized,
        field<std::string> value = uninitialized,
        omittable_field<std::string> description = omitted,
        omittable_field<Emoji> emoji = omitted,
        omittable_field<bool> default_selected = omitted
    ):
        label(label),
        value(value),
        description(description),
        emoji(emoji),
        default_selected(default_selected)
    {}
    SelectOption(const json &j) { from_json(j, *this); }
    
    field<std::string> label;
    field<std::string> value;
    omittable_field<std::string> description;
    omittable_field<Emoji> emoji;
    omittable_field<bool> default_selected;

    friend void to_json(nlohmann::json &j, const SelectOption &t) {
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
        if(!t.default_selected.is_omitted()) {j["default"] = t.default_selected;}
    }
    friend void from_json(const nlohmann::json &j, SelectOption &t) {
        if(j.contains("label")){j.at("label").get_to(t.label);}
        if(j.contains("value")){j.at("value").get_to(t.value);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("emoji")){j.at("emoji").get_to(t.emoji);}
        if(j.contains("default")){j.at("default").get_to(t.default_selected);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#component-object
class Component{
  public:
    Component(
        field<int> type = uninitialized
    ):
        type(type)
    {}
    Component(const json &j) { from_json(j, *this); }
    
    field<int> type;

    friend void to_json(nlohmann::json &j, const Component &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
    }
    friend void from_json(const nlohmann::json &j, Component &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
    }
};

// https://discord.com/developers/docs/resources/application#application-object-application-structure
class Application{
  public:
    Application(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> icon = uninitialized,
        field<std::string> description = uninitialized,
        omittable_field<std::vector<std::string> > rpc_origins = omitted,
        field<bool> bot_public = uninitialized,
        field<bool> bot_require_code_grant = uninitialized,
        omittable_field<std::string> terms_of_service_url = omitted,
        omittable_field<std::string> privacy_policy_url = omitted,
        omittable_field<User> owner = omitted,
        field<std::string> summary = uninitialized,
        field<std::string> verify_key = uninitialized,
        nullable_field<Team> team = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<Snowflake> primary_sku_id = omitted,
        omittable_field<std::string> slug = omitted,
        omittable_field<std::string> cover_image = omitted,
        omittable_field<int> flags = omitted,
        omittable_field<std::vector<std::string> > tags = omitted,
        omittable_field<InstallParams> install_params = omitted,
        omittable_field<std::string> custom_install_url = omitted,
        omittable_field<std::string> role_connections_verification_url = omitted
    ):
        id(id),
        name(name),
        icon(icon),
        description(description),
        rpc_origins(rpc_origins),
        bot_public(bot_public),
        bot_require_code_grant(bot_require_code_grant),
        terms_of_service_url(terms_of_service_url),
        privacy_policy_url(privacy_policy_url),
        owner(owner),
        summary(summary),
        verify_key(verify_key),
        team(team),
        guild_id(guild_id),
        primary_sku_id(primary_sku_id),
        slug(slug),
        cover_image(cover_image),
        flags(flags),
        tags(tags),
        install_params(install_params),
        custom_install_url(custom_install_url),
        role_connections_verification_url(role_connections_verification_url)
    {}
    Application(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    field<std::string> description;
    omittable_field<std::vector<std::string> > rpc_origins;
    field<bool> bot_public;
    field<bool> bot_require_code_grant;
    omittable_field<std::string> terms_of_service_url;
    omittable_field<std::string> privacy_policy_url;
    omittable_field<User> owner;
    field<std::string> summary;
    field<std::string> verify_key;
    nullable_field<Team> team;
    omittable_field<Snowflake> guild_id;
    omittable_field<Snowflake> primary_sku_id;
    omittable_field<std::string> slug;
    omittable_field<std::string> cover_image;
    omittable_field<int> flags;
    omittable_field<std::vector<std::string> > tags;
    omittable_field<InstallParams> install_params;
    omittable_field<std::string> custom_install_url;
    omittable_field<std::string> role_connections_verification_url;

    friend void to_json(nlohmann::json &j, const Application &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.rpc_origins.is_omitted()) {j["rpc_origins"] = t.rpc_origins;}
        if(!t.bot_public.is_omitted()) {j["bot_public"] = t.bot_public;}
        if(!t.bot_require_code_grant.is_omitted()) {j["bot_require_code_grant"] = t.bot_require_code_grant;}
        if(!t.terms_of_service_url.is_omitted()) {j["terms_of_service_url"] = t.terms_of_service_url;}
        if(!t.privacy_policy_url.is_omitted()) {j["privacy_policy_url"] = t.privacy_policy_url;}
        if(!t.owner.is_omitted()) {j["owner"] = t.owner;}
        if(!t.summary.is_omitted()) {j["summary"] = t.summary;}
        if(!t.verify_key.is_omitted()) {j["verify_key"] = t.verify_key;}
        if(!t.team.is_omitted()) {j["team"] = t.team;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.primary_sku_id.is_omitted()) {j["primary_sku_id"] = t.primary_sku_id;}
        if(!t.slug.is_omitted()) {j["slug"] = t.slug;}
        if(!t.cover_image.is_omitted()) {j["cover_image"] = t.cover_image;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.tags.is_omitted()) {j["tags"] = t.tags;}
        if(!t.install_params.is_omitted()) {j["install_params"] = t.install_params;}
        if(!t.custom_install_url.is_omitted()) {j["custom_install_url"] = t.custom_install_url;}
        if(!t.role_connections_verification_url.is_omitted()) {j["role_connections_verification_url"] = t.role_connections_verification_url;}
    }
    friend void from_json(const nlohmann::json &j, Application &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("icon")){j.at("icon").get_to(t.icon);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("rpc_origins")){j.at("rpc_origins").get_to(t.rpc_origins);}
        if(j.contains("bot_public")){j.at("bot_public").get_to(t.bot_public);}
        if(j.contains("bot_require_code_grant")){j.at("bot_require_code_grant").get_to(t.bot_require_code_grant);}
        if(j.contains("terms_of_service_url")){j.at("terms_of_service_url").get_to(t.terms_of_service_url);}
        if(j.contains("privacy_policy_url")){j.at("privacy_policy_url").get_to(t.privacy_policy_url);}
        if(j.contains("owner")){j.at("owner").get_to(t.owner);}
        if(j.contains("summary")){j.at("summary").get_to(t.summary);}
        if(j.contains("verify_key")){j.at("verify_key").get_to(t.verify_key);}
        if(j.contains("team")){j.at("team").get_to(t.team);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("primary_sku_id")){j.at("primary_sku_id").get_to(t.primary_sku_id);}
        if(j.contains("slug")){j.at("slug").get_to(t.slug);}
        if(j.contains("cover_image")){j.at("cover_image").get_to(t.cover_image);}
        if(j.contains("flags")){j.at("flags").get_to(t.flags);}
        if(j.contains("tags")){j.at("tags").get_to(t.tags);}
        if(j.contains("install_params")){j.at("install_params").get_to(t.install_params);}
        if(j.contains("custom_install_url")){j.at("custom_install_url").get_to(t.custom_install_url);}
        if(j.contains("role_connections_verification_url")){j.at("role_connections_verification_url").get_to(t.role_connections_verification_url);}
    }
};

// https://discord.com/developers/docs/resources/application#install-params-object-install-params-structure
class InstallParams{
  public:
    InstallParams(
        field<std::vector<std::string> > scopes = uninitialized,
        field<std::string> permissions = uninitialized
    ):
        scopes(scopes),
        permissions(permissions)
    {}
    InstallParams(const json &j) { from_json(j, *this); }
    
    field<std::vector<std::string> > scopes;
    field<std::string> permissions;

    friend void to_json(nlohmann::json &j, const InstallParams &t) {
        if(!t.scopes.is_omitted()) {j["scopes"] = t.scopes;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
    }
    friend void from_json(const nlohmann::json &j, InstallParams &t) {
        if(j.contains("scopes")){j.at("scopes").get_to(t.scopes);}
        if(j.contains("permissions")){j.at("permissions").get_to(t.permissions);}
    }
};

// https://discord.com/developers/docs/resources/application-role-connection-metadata#application-role-connection-metadata-object-application-role-connection-metadata-structure
class ApplicationRoleConnectionMetadata{
  public:
    ApplicationRoleConnectionMetadata(
        field<ApplicationRoleConnectionMetadataType> type = uninitialized,
        field<std::string> key = uninitialized,
        field<std::string> name = uninitialized,
        omittable_field<std::map<Locale, std::string>> name_localizations = omitted,
        field<std::string> description = uninitialized,
        omittable_field<std::map<Locale, std::string>> description_localizations = omitted
    ):
        type(type),
        key(key),
        name(name),
        name_localizations(name_localizations),
        description(description),
        description_localizations(description_localizations)
    {}
    ApplicationRoleConnectionMetadata(const json &j) { from_json(j, *this); }
    
    field<ApplicationRoleConnectionMetadataType> type;
    field<std::string> key;
    field<std::string> name;
    omittable_field<std::map<Locale, std::string>> name_localizations;
    field<std::string> description;
    omittable_field<std::map<Locale, std::string>> description_localizations;

    friend void to_json(nlohmann::json &j, const ApplicationRoleConnectionMetadata &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.key.is_omitted()) {j["key"] = t.key;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.name_localizations.is_omitted()) {j["name_localizations"] = t.name_localizations;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.description_localizations.is_omitted()) {j["description_localizations"] = t.description_localizations;}
    }
    friend void from_json(const nlohmann::json &j, ApplicationRoleConnectionMetadata &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("key")){j.at("key").get_to(t.key);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("name_localizations")){j.at("name_localizations").get_to(t.name_localizations);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("description_localizations")){j.at("description_localizations").get_to(t.description_localizations);}
    }
};

// https://discord.com/developers/docs/resources/audit-log#audit-log-object-audit-log-structure
class AuditLog{
  public:
    AuditLog(
        field<std::vector<ApplicationCommand> > application_commands = uninitialized,
        field<std::vector<AuditLogEntry> > audit_log_entries = uninitialized,
        field<std::vector<AutoModerationRule> > auto_moderation_rules = uninitialized,
        field<std::vector<GuildScheduledEvent> > guild_scheduled_events = uninitialized,
        field<std::vector<Integration> > integrations = uninitialized,
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<User> > users = uninitialized,
        field<std::vector<Webhook> > webhooks = uninitialized
    ):
        application_commands(application_commands),
        audit_log_entries(audit_log_entries),
        auto_moderation_rules(auto_moderation_rules),
        guild_scheduled_events(guild_scheduled_events),
        integrations(integrations),
        threads(threads),
        users(users),
        webhooks(webhooks)
    {}
    AuditLog(const json &j) { from_json(j, *this); }
    
    field<std::vector<ApplicationCommand> > application_commands;
    field<std::vector<AuditLogEntry> > audit_log_entries;
    field<std::vector<AutoModerationRule> > auto_moderation_rules;
    field<std::vector<GuildScheduledEvent> > guild_scheduled_events;
    field<std::vector<Integration> > integrations;
    field<std::vector<Channel> > threads;
    field<std::vector<User> > users;
    field<std::vector<Webhook> > webhooks;

    friend void to_json(nlohmann::json &j, const AuditLog &t) {
        if(!t.application_commands.is_omitted()) {j["application_commands"] = t.application_commands;}
        if(!t.audit_log_entries.is_omitted()) {j["audit_log_entries"] = t.audit_log_entries;}
        if(!t.auto_moderation_rules.is_omitted()) {j["auto_moderation_rules"] = t.auto_moderation_rules;}
        if(!t.guild_scheduled_events.is_omitted()) {j["guild_scheduled_events"] = t.guild_scheduled_events;}
        if(!t.integrations.is_omitted()) {j["integrations"] = t.integrations;}
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.users.is_omitted()) {j["users"] = t.users;}
        if(!t.webhooks.is_omitted()) {j["webhooks"] = t.webhooks;}
    }
    friend void from_json(const nlohmann::json &j, AuditLog &t) {
        if(j.contains("application_commands")){j.at("application_commands").get_to(t.application_commands);}
        if(j.contains("audit_log_entries")){j.at("audit_log_entries").get_to(t.audit_log_entries);}
        if(j.contains("auto_moderation_rules")){j.at("auto_moderation_rules").get_to(t.auto_moderation_rules);}
        if(j.contains("guild_scheduled_events")){j.at("guild_scheduled_events").get_to(t.guild_scheduled_events);}
        if(j.contains("integrations")){j.at("integrations").get_to(t.integrations);}
        if(j.contains("threads")){j.at("threads").get_to(t.threads);}
        if(j.contains("users")){j.at("users").get_to(t.users);}
        if(j.contains("webhooks")){j.at("webhooks").get_to(t.webhooks);}
    }
};

// https://discord.com/developers/docs/resources/audit-log#audit-log-entry-object-audit-log-entry-structure
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
    AuditLogEntry(const json &j) { from_json(j, *this); }
    
    nullable_field<std::string> target_id;
    omittable_field<std::vector<AuditLogChange> > changes;
    nullable_field<Snowflake> user_id;
    field<Snowflake> id;
    field<AuditLogEvent> action_type;
    omittable_field<OptionalAuditEntryInfo> options;
    omittable_field<std::string> reason;

    friend void to_json(nlohmann::json &j, const AuditLogEntry &t) {
        if(!t.target_id.is_omitted()) {j["target_id"] = t.target_id;}
        if(!t.changes.is_omitted()) {j["changes"] = t.changes;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.action_type.is_omitted()) {j["action_type"] = t.action_type;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.reason.is_omitted()) {j["reason"] = t.reason;}
    }
    friend void from_json(const nlohmann::json &j, AuditLogEntry &t) {
        if(j.contains("target_id")){j.at("target_id").get_to(t.target_id);}
        if(j.contains("changes")){j.at("changes").get_to(t.changes);}
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("action_type")){j.at("action_type").get_to(t.action_type);}
        if(j.contains("options")){j.at("options").get_to(t.options);}
        if(j.contains("reason")){j.at("reason").get_to(t.reason);}
    }
};

// https://discord.com/developers/docs/resources/audit-log#audit-log-entry-object-optional-audit-entry-info
class OptionalAuditEntryInfo{
  public:
    OptionalAuditEntryInfo(
        field<Snowflake> application_id = uninitialized,
        field<std::string> auto_moderation_rule_name = uninitialized,
        field<std::string> auto_moderation_rule_trigger_type = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<std::string> count = uninitialized,
        field<std::string> delete_member_days = uninitialized,
        field<Snowflake> id = uninitialized,
        field<std::string> members_removed = uninitialized,
        field<Snowflake> message_id = uninitialized,
        field<std::string> role_name = uninitialized,
        field<std::string> type = uninitialized
    ):
        application_id(application_id),
        auto_moderation_rule_name(auto_moderation_rule_name),
        auto_moderation_rule_trigger_type(auto_moderation_rule_trigger_type),
        channel_id(channel_id),
        count(count),
        delete_member_days(delete_member_days),
        id(id),
        members_removed(members_removed),
        message_id(message_id),
        role_name(role_name),
        type(type)
    {}
    OptionalAuditEntryInfo(const json &j) { from_json(j, *this); }
    
    field<Snowflake> application_id;
    field<std::string> auto_moderation_rule_name;
    field<std::string> auto_moderation_rule_trigger_type;
    field<Snowflake> channel_id;
    field<std::string> count;
    field<std::string> delete_member_days;
    field<Snowflake> id;
    field<std::string> members_removed;
    field<Snowflake> message_id;
    field<std::string> role_name;
    field<std::string> type;

    friend void to_json(nlohmann::json &j, const OptionalAuditEntryInfo &t) {
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.auto_moderation_rule_name.is_omitted()) {j["auto_moderation_rule_name"] = t.auto_moderation_rule_name;}
        if(!t.auto_moderation_rule_trigger_type.is_omitted()) {j["auto_moderation_rule_trigger_type"] = t.auto_moderation_rule_trigger_type;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.count.is_omitted()) {j["count"] = t.count;}
        if(!t.delete_member_days.is_omitted()) {j["delete_member_days"] = t.delete_member_days;}
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.members_removed.is_omitted()) {j["members_removed"] = t.members_removed;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.role_name.is_omitted()) {j["role_name"] = t.role_name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
    }
    friend void from_json(const nlohmann::json &j, OptionalAuditEntryInfo &t) {
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("auto_moderation_rule_name")){j.at("auto_moderation_rule_name").get_to(t.auto_moderation_rule_name);}
        if(j.contains("auto_moderation_rule_trigger_type")){j.at("auto_moderation_rule_trigger_type").get_to(t.auto_moderation_rule_trigger_type);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("count")){j.at("count").get_to(t.count);}
        if(j.contains("delete_member_days")){j.at("delete_member_days").get_to(t.delete_member_days);}
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("members_removed")){j.at("members_removed").get_to(t.members_removed);}
        if(j.contains("message_id")){j.at("message_id").get_to(t.message_id);}
        if(j.contains("role_name")){j.at("role_name").get_to(t.role_name);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
    }
};

// https://discord.com/developers/docs/resources/audit-log#audit-log-change-object-audit-log-change-structure
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
    AuditLogChange(const json &j) { from_json(j, *this); }
    
    omittable_field<json> new_value;
    omittable_field<json> old_value;
    field<std::string> key;

    friend void to_json(nlohmann::json &j, const AuditLogChange &t) {
        if(!t.new_value.is_omitted()) {j["new_value"] = t.new_value;}
        if(!t.old_value.is_omitted()) {j["old_value"] = t.old_value;}
        if(!t.key.is_omitted()) {j["key"] = t.key;}
    }
    friend void from_json(const nlohmann::json &j, AuditLogChange &t) {
        if(j.contains("new_value")){j.at("new_value").get_to(t.new_value);}
        if(j.contains("old_value")){j.at("old_value").get_to(t.old_value);}
        if(j.contains("key")){j.at("key").get_to(t.key);}
    }
};

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
        field<std::vector<AutoModerationAction> > actions = uninitialized,
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
    AutoModerationRule(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<std::string> name;
    field<Snowflake> creator_id;
    field<int> event_type;
    field<int> trigger_type;
    field<TriggerMetadata> trigger_metadata;
    field<std::vector<AutoModerationAction> > actions;
    field<bool> enabled;
    field<std::vector<Snowflake> > exempt_roles;
    field<std::vector<Snowflake> > exempt_channels;

    friend void to_json(nlohmann::json &j, const AutoModerationRule &t) {
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
    friend void from_json(const nlohmann::json &j, AutoModerationRule &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("creator_id")){j.at("creator_id").get_to(t.creator_id);}
        if(j.contains("event_type")){j.at("event_type").get_to(t.event_type);}
        if(j.contains("trigger_type")){j.at("trigger_type").get_to(t.trigger_type);}
        if(j.contains("trigger_metadata")){j.at("trigger_metadata").get_to(t.trigger_metadata);}
        if(j.contains("actions")){j.at("actions").get_to(t.actions);}
        if(j.contains("enabled")){j.at("enabled").get_to(t.enabled);}
        if(j.contains("exempt_roles")){j.at("exempt_roles").get_to(t.exempt_roles);}
        if(j.contains("exempt_channels")){j.at("exempt_channels").get_to(t.exempt_channels);}
    }
};

// https://discord.com/developers/docs/resources/auto-moderation#auto-moderation-rule-object-trigger-metadata
class TriggerMetadata{
  public:
    TriggerMetadata(
        field<std::vector<std::string> > keyword_filter = uninitialized,
        field<std::vector<std::string> > regex_patterns = uninitialized,
        field<std::vector<KeywordPresetType> > presets = uninitialized,
        field<std::vector<std::string> > allow_list = uninitialized,
        field<int> mention_total_limit = uninitialized
    ):
        keyword_filter(keyword_filter),
        regex_patterns(regex_patterns),
        presets(presets),
        allow_list(allow_list),
        mention_total_limit(mention_total_limit)
    {}
    TriggerMetadata(const json &j) { from_json(j, *this); }
    
    field<std::vector<std::string> > keyword_filter;
    field<std::vector<std::string> > regex_patterns;
    field<std::vector<KeywordPresetType> > presets;
    field<std::vector<std::string> > allow_list;
    field<int> mention_total_limit;

    friend void to_json(nlohmann::json &j, const TriggerMetadata &t) {
        if(!t.keyword_filter.is_omitted()) {j["keyword_filter"] = t.keyword_filter;}
        if(!t.regex_patterns.is_omitted()) {j["regex_patterns"] = t.regex_patterns;}
        if(!t.presets.is_omitted()) {j["presets"] = t.presets;}
        if(!t.allow_list.is_omitted()) {j["allow_list"] = t.allow_list;}
        if(!t.mention_total_limit.is_omitted()) {j["mention_total_limit"] = t.mention_total_limit;}
    }
    friend void from_json(const nlohmann::json &j, TriggerMetadata &t) {
        if(j.contains("keyword_filter")){j.at("keyword_filter").get_to(t.keyword_filter);}
        if(j.contains("regex_patterns")){j.at("regex_patterns").get_to(t.regex_patterns);}
        if(j.contains("presets")){j.at("presets").get_to(t.presets);}
        if(j.contains("allow_list")){j.at("allow_list").get_to(t.allow_list);}
        if(j.contains("mention_total_limit")){j.at("mention_total_limit").get_to(t.mention_total_limit);}
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
    AutoModerationAction(const json &j) { from_json(j, *this); }
    
    field<ActionType> type;
    omittable_field<ActionMetadata> metadata;

    friend void to_json(nlohmann::json &j, const AutoModerationAction &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.metadata.is_omitted()) {j["metadata"] = t.metadata;}
    }
    friend void from_json(const nlohmann::json &j, AutoModerationAction &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("metadata")){j.at("metadata").get_to(t.metadata);}
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
    ActionMetadata(const json &j) { from_json(j, *this); }
    
    field<Snowflake> channel_id;
    field<int> duration_seconds;

    friend void to_json(nlohmann::json &j, const ActionMetadata &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.duration_seconds.is_omitted()) {j["duration_seconds"] = t.duration_seconds;}
    }
    friend void from_json(const nlohmann::json &j, ActionMetadata &t) {
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("duration_seconds")){j.at("duration_seconds").get_to(t.duration_seconds);}
    }
};

// https://discord.com/developers/docs/resources/channel#channel-object-channel-structure
class Channel{
  public:
    Channel(
        field<Snowflake> id = uninitialized,
        field<int> type = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<int> position = omitted,
        omittable_field<std::vector<Overwrite> > permission_overwrites = omitted,
        nullable_omittable_field<std::string> name = omitted,
        nullable_omittable_field<std::string> topic = omitted,
        omittable_field<bool> nsfw = omitted,
        nullable_omittable_field<Snowflake> last_message_id = omitted,
        omittable_field<int> bitrate = omitted,
        omittable_field<int> user_limit = omitted,
        omittable_field<int> rate_limit_per_user = omitted,
        omittable_field<std::vector<User> > recipients = omitted,
        nullable_omittable_field<std::string> icon = omitted,
        omittable_field<Snowflake> owner_id = omitted,
        omittable_field<Snowflake> application_id = omitted,
        omittable_field<bool> managed = omitted,
        nullable_omittable_field<Snowflake> parent_id = omitted,
        nullable_omittable_field<Timestamp> last_pin_timestamp = omitted,
        nullable_omittable_field<std::string> rtc_region = omitted,
        omittable_field<int> video_quality_mode = omitted,
        omittable_field<int> message_count = omitted,
        omittable_field<int> member_count = omitted,
        omittable_field<ThreadMetadata> thread_metadata = omitted,
        omittable_field<ThreadMember> member = omitted,
        omittable_field<int> default_auto_archive_duration = omitted,
        omittable_field<std::string> permissions = omitted,
        omittable_field<int> flags = omitted,
        omittable_field<int> total_message_sent = omitted,
        omittable_field<std::vector<ForumTag> > available_tags = omitted,
        omittable_field<std::vector<Snowflake> > applied_tags = omitted,
        nullable_omittable_field<DefaultReaction> default_reaction_emoji = omitted,
        omittable_field<int> default_thread_rate_limit_per_user = omitted,
        nullable_omittable_field<int> default_sort_order = omitted,
        omittable_field<int> default_forum_layout = omitted
    ):
        id(id),
        type(type),
        guild_id(guild_id),
        position(position),
        permission_overwrites(permission_overwrites),
        name(name),
        topic(topic),
        nsfw(nsfw),
        last_message_id(last_message_id),
        bitrate(bitrate),
        user_limit(user_limit),
        rate_limit_per_user(rate_limit_per_user),
        recipients(recipients),
        icon(icon),
        owner_id(owner_id),
        application_id(application_id),
        managed(managed),
        parent_id(parent_id),
        last_pin_timestamp(last_pin_timestamp),
        rtc_region(rtc_region),
        video_quality_mode(video_quality_mode),
        message_count(message_count),
        member_count(member_count),
        thread_metadata(thread_metadata),
        member(member),
        default_auto_archive_duration(default_auto_archive_duration),
        permissions(permissions),
        flags(flags),
        total_message_sent(total_message_sent),
        available_tags(available_tags),
        applied_tags(applied_tags),
        default_reaction_emoji(default_reaction_emoji),
        default_thread_rate_limit_per_user(default_thread_rate_limit_per_user),
        default_sort_order(default_sort_order),
        default_forum_layout(default_forum_layout)
    {}
    Channel(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<int> type;
    omittable_field<Snowflake> guild_id;
    omittable_field<int> position;
    omittable_field<std::vector<Overwrite> > permission_overwrites;
    nullable_omittable_field<std::string> name;
    nullable_omittable_field<std::string> topic;
    omittable_field<bool> nsfw;
    nullable_omittable_field<Snowflake> last_message_id;
    omittable_field<int> bitrate;
    omittable_field<int> user_limit;
    omittable_field<int> rate_limit_per_user;
    omittable_field<std::vector<User> > recipients;
    nullable_omittable_field<std::string> icon;
    omittable_field<Snowflake> owner_id;
    omittable_field<Snowflake> application_id;
    omittable_field<bool> managed;
    nullable_omittable_field<Snowflake> parent_id;
    nullable_omittable_field<Timestamp> last_pin_timestamp;
    nullable_omittable_field<std::string> rtc_region;
    omittable_field<int> video_quality_mode;
    omittable_field<int> message_count;
    omittable_field<int> member_count;
    omittable_field<ThreadMetadata> thread_metadata;
    omittable_field<ThreadMember> member;
    omittable_field<int> default_auto_archive_duration;
    omittable_field<std::string> permissions;
    omittable_field<int> flags;
    omittable_field<int> total_message_sent;
    omittable_field<std::vector<ForumTag> > available_tags;
    omittable_field<std::vector<Snowflake> > applied_tags;
    nullable_omittable_field<DefaultReaction> default_reaction_emoji;
    omittable_field<int> default_thread_rate_limit_per_user;
    nullable_omittable_field<int> default_sort_order;
    omittable_field<int> default_forum_layout;

    friend void to_json(nlohmann::json &j, const Channel &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.position.is_omitted()) {j["position"] = t.position;}
        if(!t.permission_overwrites.is_omitted()) {j["permission_overwrites"] = t.permission_overwrites;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.topic.is_omitted()) {j["topic"] = t.topic;}
        if(!t.nsfw.is_omitted()) {j["nsfw"] = t.nsfw;}
        if(!t.last_message_id.is_omitted()) {j["last_message_id"] = t.last_message_id;}
        if(!t.bitrate.is_omitted()) {j["bitrate"] = t.bitrate;}
        if(!t.user_limit.is_omitted()) {j["user_limit"] = t.user_limit;}
        if(!t.rate_limit_per_user.is_omitted()) {j["rate_limit_per_user"] = t.rate_limit_per_user;}
        if(!t.recipients.is_omitted()) {j["recipients"] = t.recipients;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.owner_id.is_omitted()) {j["owner_id"] = t.owner_id;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.managed.is_omitted()) {j["managed"] = t.managed;}
        if(!t.parent_id.is_omitted()) {j["parent_id"] = t.parent_id;}
        if(!t.last_pin_timestamp.is_omitted()) {j["last_pin_timestamp"] = t.last_pin_timestamp;}
        if(!t.rtc_region.is_omitted()) {j["rtc_region"] = t.rtc_region;}
        if(!t.video_quality_mode.is_omitted()) {j["video_quality_mode"] = t.video_quality_mode;}
        if(!t.message_count.is_omitted()) {j["message_count"] = t.message_count;}
        if(!t.member_count.is_omitted()) {j["member_count"] = t.member_count;}
        if(!t.thread_metadata.is_omitted()) {j["thread_metadata"] = t.thread_metadata;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.default_auto_archive_duration.is_omitted()) {j["default_auto_archive_duration"] = t.default_auto_archive_duration;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.total_message_sent.is_omitted()) {j["total_message_sent"] = t.total_message_sent;}
        if(!t.available_tags.is_omitted()) {j["available_tags"] = t.available_tags;}
        if(!t.applied_tags.is_omitted()) {j["applied_tags"] = t.applied_tags;}
        if(!t.default_reaction_emoji.is_omitted()) {j["default_reaction_emoji"] = t.default_reaction_emoji;}
        if(!t.default_thread_rate_limit_per_user.is_omitted()) {j["default_thread_rate_limit_per_user"] = t.default_thread_rate_limit_per_user;}
        if(!t.default_sort_order.is_omitted()) {j["default_sort_order"] = t.default_sort_order;}
        if(!t.default_forum_layout.is_omitted()) {j["default_forum_layout"] = t.default_forum_layout;}
    }
    friend void from_json(const nlohmann::json &j, Channel &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("position")){j.at("position").get_to(t.position);}
        if(j.contains("permission_overwrites")){j.at("permission_overwrites").get_to(t.permission_overwrites);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("topic")){j.at("topic").get_to(t.topic);}
        if(j.contains("nsfw")){j.at("nsfw").get_to(t.nsfw);}
        if(j.contains("last_message_id")){j.at("last_message_id").get_to(t.last_message_id);}
        if(j.contains("bitrate")){j.at("bitrate").get_to(t.bitrate);}
        if(j.contains("user_limit")){j.at("user_limit").get_to(t.user_limit);}
        if(j.contains("rate_limit_per_user")){j.at("rate_limit_per_user").get_to(t.rate_limit_per_user);}
        if(j.contains("recipients")){j.at("recipients").get_to(t.recipients);}
        if(j.contains("icon")){j.at("icon").get_to(t.icon);}
        if(j.contains("owner_id")){j.at("owner_id").get_to(t.owner_id);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("managed")){j.at("managed").get_to(t.managed);}
        if(j.contains("parent_id")){j.at("parent_id").get_to(t.parent_id);}
        if(j.contains("last_pin_timestamp")){j.at("last_pin_timestamp").get_to(t.last_pin_timestamp);}
        if(j.contains("rtc_region")){j.at("rtc_region").get_to(t.rtc_region);}
        if(j.contains("video_quality_mode")){j.at("video_quality_mode").get_to(t.video_quality_mode);}
        if(j.contains("message_count")){j.at("message_count").get_to(t.message_count);}
        if(j.contains("member_count")){j.at("member_count").get_to(t.member_count);}
        if(j.contains("thread_metadata")){j.at("thread_metadata").get_to(t.thread_metadata);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
        if(j.contains("default_auto_archive_duration")){j.at("default_auto_archive_duration").get_to(t.default_auto_archive_duration);}
        if(j.contains("permissions")){j.at("permissions").get_to(t.permissions);}
        if(j.contains("flags")){j.at("flags").get_to(t.flags);}
        if(j.contains("total_message_sent")){j.at("total_message_sent").get_to(t.total_message_sent);}
        if(j.contains("available_tags")){j.at("available_tags").get_to(t.available_tags);}
        if(j.contains("applied_tags")){j.at("applied_tags").get_to(t.applied_tags);}
        if(j.contains("default_reaction_emoji")){j.at("default_reaction_emoji").get_to(t.default_reaction_emoji);}
        if(j.contains("default_thread_rate_limit_per_user")){j.at("default_thread_rate_limit_per_user").get_to(t.default_thread_rate_limit_per_user);}
        if(j.contains("default_sort_order")){j.at("default_sort_order").get_to(t.default_sort_order);}
        if(j.contains("default_forum_layout")){j.at("default_forum_layout").get_to(t.default_forum_layout);}
    }
};

// https://discord.com/developers/docs/resources/channel#message-object-message-structure
class Message{
  public:
    Message(
        field<Snowflake> id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<User> author = uninitialized,
        field<std::string> content = uninitialized,
        field<Timestamp> timestamp = uninitialized,
        nullable_field<Timestamp> edited_timestamp = uninitialized,
        field<bool> tts = uninitialized,
        field<bool> mention_everyone = uninitialized,
        field<std::vector<User> > mentions = uninitialized,
        field<std::vector<Snowflake> > mention_roles = uninitialized,
        omittable_field<std::vector<ChannelMention> > mention_channels = omitted,
        field<std::vector<Attachment> > attachments = uninitialized,
        field<std::vector<Embed> > embeds = uninitialized,
        omittable_field<std::vector<Reaction> > reactions = omitted,
        omittable_field<std::variant<int, std::string> > nonce = omitted,
        field<bool> pinned = uninitialized,
        omittable_field<Snowflake> webhook_id = omitted,
        field<int> type = uninitialized,
        omittable_field<MessageActivity> activity = omitted,
        omittable_field<Application> application = omitted,
        omittable_field<Snowflake> application_id = omitted,
        omittable_field<MessageReference> message_reference = omitted,
        omittable_field<int> flags = omitted,
        nullable_omittable_field<Message> referenced_message = omitted,
        omittable_field<MessageInteraction> interaction = omitted,
        omittable_field<Channel> thread = omitted,
        omittable_field<std::vector<Component> > components = omitted,
        omittable_field<std::vector<StickerItem> > sticker_items = omitted,
        omittable_field<std::vector<Sticker> > stickers = omitted,
        omittable_field<int> position = omitted,
        omittable_field<RoleSubscriptionData> role_subscription_data = omitted
    ):
        id(id),
        channel_id(channel_id),
        author(author),
        content(content),
        timestamp(timestamp),
        edited_timestamp(edited_timestamp),
        tts(tts),
        mention_everyone(mention_everyone),
        mentions(mentions),
        mention_roles(mention_roles),
        mention_channels(mention_channels),
        attachments(attachments),
        embeds(embeds),
        reactions(reactions),
        nonce(nonce),
        pinned(pinned),
        webhook_id(webhook_id),
        type(type),
        activity(activity),
        application(application),
        application_id(application_id),
        message_reference(message_reference),
        flags(flags),
        referenced_message(referenced_message),
        interaction(interaction),
        thread(thread),
        components(components),
        sticker_items(sticker_items),
        stickers(stickers),
        position(position),
        role_subscription_data(role_subscription_data)
    {}
    Message(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> channel_id;
    field<User> author;
    field<std::string> content;
    field<Timestamp> timestamp;
    nullable_field<Timestamp> edited_timestamp;
    field<bool> tts;
    field<bool> mention_everyone;
    field<std::vector<User> > mentions;
    field<std::vector<Snowflake> > mention_roles;
    omittable_field<std::vector<ChannelMention> > mention_channels;
    field<std::vector<Attachment> > attachments;
    field<std::vector<Embed> > embeds;
    omittable_field<std::vector<Reaction> > reactions;
    omittable_field<std::variant<int, std::string> > nonce;
    field<bool> pinned;
    omittable_field<Snowflake> webhook_id;
    field<int> type;
    omittable_field<MessageActivity> activity;
    omittable_field<Application> application;
    omittable_field<Snowflake> application_id;
    omittable_field<MessageReference> message_reference;
    omittable_field<int> flags;
    nullable_omittable_field<Message> referenced_message;
    omittable_field<MessageInteraction> interaction;
    omittable_field<Channel> thread;
    omittable_field<std::vector<Component> > components;
    omittable_field<std::vector<StickerItem> > sticker_items;
    omittable_field<std::vector<Sticker> > stickers;
    omittable_field<int> position;
    omittable_field<RoleSubscriptionData> role_subscription_data;

    friend void to_json(nlohmann::json &j, const Message &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.author.is_omitted()) {j["author"] = t.author;}
        if(!t.content.is_omitted()) {j["content"] = t.content;}
        if(!t.timestamp.is_omitted()) {j["timestamp"] = t.timestamp;}
        if(!t.edited_timestamp.is_omitted()) {j["edited_timestamp"] = t.edited_timestamp;}
        if(!t.tts.is_omitted()) {j["tts"] = t.tts;}
        if(!t.mention_everyone.is_omitted()) {j["mention_everyone"] = t.mention_everyone;}
        if(!t.mentions.is_omitted()) {j["mentions"] = t.mentions;}
        if(!t.mention_roles.is_omitted()) {j["mention_roles"] = t.mention_roles;}
        if(!t.mention_channels.is_omitted()) {j["mention_channels"] = t.mention_channels;}
        if(!t.attachments.is_omitted()) {j["attachments"] = t.attachments;}
        if(!t.embeds.is_omitted()) {j["embeds"] = t.embeds;}
        if(!t.reactions.is_omitted()) {j["reactions"] = t.reactions;}
        if(!t.nonce.is_omitted()) {j["nonce"] = t.nonce;}
        if(!t.pinned.is_omitted()) {j["pinned"] = t.pinned;}
        if(!t.webhook_id.is_omitted()) {j["webhook_id"] = t.webhook_id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.activity.is_omitted()) {j["activity"] = t.activity;}
        if(!t.application.is_omitted()) {j["application"] = t.application;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.message_reference.is_omitted()) {j["message_reference"] = t.message_reference;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.referenced_message.is_omitted()) {j["referenced_message"] = t.referenced_message;}
        if(!t.interaction.is_omitted()) {j["interaction"] = t.interaction;}
        if(!t.thread.is_omitted()) {j["thread"] = t.thread;}
        if(!t.components.is_omitted()) {j["components"] = t.components;}
        if(!t.sticker_items.is_omitted()) {j["sticker_items"] = t.sticker_items;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
        if(!t.position.is_omitted()) {j["position"] = t.position;}
        if(!t.role_subscription_data.is_omitted()) {j["role_subscription_data"] = t.role_subscription_data;}
    }
    friend void from_json(const nlohmann::json &j, Message &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("author")){j.at("author").get_to(t.author);}
        if(j.contains("content")){j.at("content").get_to(t.content);}
        if(j.contains("timestamp")){j.at("timestamp").get_to(t.timestamp);}
        if(j.contains("edited_timestamp")){j.at("edited_timestamp").get_to(t.edited_timestamp);}
        if(j.contains("tts")){j.at("tts").get_to(t.tts);}
        if(j.contains("mention_everyone")){j.at("mention_everyone").get_to(t.mention_everyone);}
        if(j.contains("mentions")){j.at("mentions").get_to(t.mentions);}
        if(j.contains("mention_roles")){j.at("mention_roles").get_to(t.mention_roles);}
        if(j.contains("mention_channels")){j.at("mention_channels").get_to(t.mention_channels);}
        if(j.contains("attachments")){j.at("attachments").get_to(t.attachments);}
        if(j.contains("embeds")){j.at("embeds").get_to(t.embeds);}
        if(j.contains("reactions")){j.at("reactions").get_to(t.reactions);}
        if(j.contains("nonce")){j.at("nonce").get_to(t.nonce);}
        if(j.contains("pinned")){j.at("pinned").get_to(t.pinned);}
        if(j.contains("webhook_id")){j.at("webhook_id").get_to(t.webhook_id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("activity")){j.at("activity").get_to(t.activity);}
        if(j.contains("application")){j.at("application").get_to(t.application);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("message_reference")){j.at("message_reference").get_to(t.message_reference);}
        if(j.contains("flags")){j.at("flags").get_to(t.flags);}
        if(j.contains("referenced_message")){j.at("referenced_message").get_to(t.referenced_message);}
        if(j.contains("interaction")){j.at("interaction").get_to(t.interaction);}
        if(j.contains("thread")){j.at("thread").get_to(t.thread);}
        if(j.contains("components")){j.at("components").get_to(t.components);}
        if(j.contains("sticker_items")){j.at("sticker_items").get_to(t.sticker_items);}
        if(j.contains("stickers")){j.at("stickers").get_to(t.stickers);}
        if(j.contains("position")){j.at("position").get_to(t.position);}
        if(j.contains("role_subscription_data")){j.at("role_subscription_data").get_to(t.role_subscription_data);}
    }
};

// https://discord.com/developers/docs/resources/channel#message-object-message-activity-structure
class MessageActivity{
  public:
    MessageActivity(
        field<int> type = uninitialized,
        omittable_field<std::string> party_id = omitted
    ):
        type(type),
        party_id(party_id)
    {}
    MessageActivity(const json &j) { from_json(j, *this); }
    
    field<int> type;
    omittable_field<std::string> party_id;

    friend void to_json(nlohmann::json &j, const MessageActivity &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.party_id.is_omitted()) {j["party_id"] = t.party_id;}
    }
    friend void from_json(const nlohmann::json &j, MessageActivity &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("party_id")){j.at("party_id").get_to(t.party_id);}
    }
};

// https://discord.com/developers/docs/resources/channel#message-reference-object-message-reference-structure
class MessageReference{
  public:
    MessageReference(
        omittable_field<Snowflake> message_id = omitted,
        omittable_field<Snowflake> channel_id = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<bool> fail_if_not_exists = omitted
    ):
        message_id(message_id),
        channel_id(channel_id),
        guild_id(guild_id),
        fail_if_not_exists(fail_if_not_exists)
    {}
    MessageReference(const json &j) { from_json(j, *this); }
    
    omittable_field<Snowflake> message_id;
    omittable_field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    omittable_field<bool> fail_if_not_exists;

    friend void to_json(nlohmann::json &j, const MessageReference &t) {
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.fail_if_not_exists.is_omitted()) {j["fail_if_not_exists"] = t.fail_if_not_exists;}
    }
    friend void from_json(const nlohmann::json &j, MessageReference &t) {
        if(j.contains("message_id")){j.at("message_id").get_to(t.message_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("fail_if_not_exists")){j.at("fail_if_not_exists").get_to(t.fail_if_not_exists);}
    }
};

// https://discord.com/developers/docs/resources/channel#followed-channel-object-followed-channel-structure
class FollowedChannel{
  public:
    FollowedChannel(
        field<Snowflake> channel_id = uninitialized,
        field<Snowflake> webhook_id = uninitialized
    ):
        channel_id(channel_id),
        webhook_id(webhook_id)
    {}
    FollowedChannel(const json &j) { from_json(j, *this); }
    
    field<Snowflake> channel_id;
    field<Snowflake> webhook_id;

    friend void to_json(nlohmann::json &j, const FollowedChannel &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.webhook_id.is_omitted()) {j["webhook_id"] = t.webhook_id;}
    }
    friend void from_json(const nlohmann::json &j, FollowedChannel &t) {
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("webhook_id")){j.at("webhook_id").get_to(t.webhook_id);}
    }
};

// https://discord.com/developers/docs/resources/channel#reaction-object-reaction-structure
class Reaction{
  public:
    Reaction(
        field<int> count = uninitialized,
        field<bool> me = uninitialized,
        field<Emoji> emoji = uninitialized
    ):
        count(count),
        me(me),
        emoji(emoji)
    {}
    Reaction(const json &j) { from_json(j, *this); }
    
    field<int> count;
    field<bool> me;
    field<Emoji> emoji;

    friend void to_json(nlohmann::json &j, const Reaction &t) {
        if(!t.count.is_omitted()) {j["count"] = t.count;}
        if(!t.me.is_omitted()) {j["me"] = t.me;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
    friend void from_json(const nlohmann::json &j, Reaction &t) {
        if(j.contains("count")){j.at("count").get_to(t.count);}
        if(j.contains("me")){j.at("me").get_to(t.me);}
        if(j.contains("emoji")){j.at("emoji").get_to(t.emoji);}
    }
};

// https://discord.com/developers/docs/resources/channel#overwrite-object-overwrite-structure
class Overwrite{
  public:
    Overwrite(
        field<Snowflake> id = uninitialized,
        field<int> type = uninitialized,
        field<std::string> allow = uninitialized,
        field<std::string> deny = uninitialized
    ):
        id(id),
        type(type),
        allow(allow),
        deny(deny)
    {}
    Overwrite(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<int> type;
    field<std::string> allow;
    field<std::string> deny;

    friend void to_json(nlohmann::json &j, const Overwrite &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.allow.is_omitted()) {j["allow"] = t.allow;}
        if(!t.deny.is_omitted()) {j["deny"] = t.deny;}
    }
    friend void from_json(const nlohmann::json &j, Overwrite &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("allow")){j.at("allow").get_to(t.allow);}
        if(j.contains("deny")){j.at("deny").get_to(t.deny);}
    }
};

// https://discord.com/developers/docs/resources/channel#thread-metadata-object-thread-metadata-structure
class ThreadMetadata{
  public:
    ThreadMetadata(
        field<bool> archived = uninitialized,
        field<int> auto_archive_duration = uninitialized,
        field<Timestamp> archive_timestamp = uninitialized,
        field<bool> locked = uninitialized,
        omittable_field<bool> invitable = omitted,
        nullable_omittable_field<Timestamp> create_timestamp = omitted
    ):
        archived(archived),
        auto_archive_duration(auto_archive_duration),
        archive_timestamp(archive_timestamp),
        locked(locked),
        invitable(invitable),
        create_timestamp(create_timestamp)
    {}
    ThreadMetadata(const json &j) { from_json(j, *this); }
    
    field<bool> archived;
    field<int> auto_archive_duration;
    field<Timestamp> archive_timestamp;
    field<bool> locked;
    omittable_field<bool> invitable;
    nullable_omittable_field<Timestamp> create_timestamp;

    friend void to_json(nlohmann::json &j, const ThreadMetadata &t) {
        if(!t.archived.is_omitted()) {j["archived"] = t.archived;}
        if(!t.auto_archive_duration.is_omitted()) {j["auto_archive_duration"] = t.auto_archive_duration;}
        if(!t.archive_timestamp.is_omitted()) {j["archive_timestamp"] = t.archive_timestamp;}
        if(!t.locked.is_omitted()) {j["locked"] = t.locked;}
        if(!t.invitable.is_omitted()) {j["invitable"] = t.invitable;}
        if(!t.create_timestamp.is_omitted()) {j["create_timestamp"] = t.create_timestamp;}
    }
    friend void from_json(const nlohmann::json &j, ThreadMetadata &t) {
        if(j.contains("archived")){j.at("archived").get_to(t.archived);}
        if(j.contains("auto_archive_duration")){j.at("auto_archive_duration").get_to(t.auto_archive_duration);}
        if(j.contains("archive_timestamp")){j.at("archive_timestamp").get_to(t.archive_timestamp);}
        if(j.contains("locked")){j.at("locked").get_to(t.locked);}
        if(j.contains("invitable")){j.at("invitable").get_to(t.invitable);}
        if(j.contains("create_timestamp")){j.at("create_timestamp").get_to(t.create_timestamp);}
    }
};

// https://discord.com/developers/docs/resources/channel#thread-member-object-thread-member-structure
class ThreadMember{
  public:
    ThreadMember(
        omittable_field<Snowflake> id = omitted,
        omittable_field<Snowflake> user_id = omitted,
        field<Timestamp> join_timestamp = uninitialized,
        field<int> flags = uninitialized,
        omittable_field<GuildMember> member = omitted
    ):
        id(id),
        user_id(user_id),
        join_timestamp(join_timestamp),
        flags(flags),
        member(member)
    {}
    ThreadMember(const json &j) { from_json(j, *this); }
    
    omittable_field<Snowflake> id;
    omittable_field<Snowflake> user_id;
    field<Timestamp> join_timestamp;
    field<int> flags;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const ThreadMember &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.join_timestamp.is_omitted()) {j["join_timestamp"] = t.join_timestamp;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
    }
    friend void from_json(const nlohmann::json &j, ThreadMember &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("join_timestamp")){j.at("join_timestamp").get_to(t.join_timestamp);}
        if(j.contains("flags")){j.at("flags").get_to(t.flags);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
    }
};

// https://discord.com/developers/docs/resources/channel#default-reaction-object-default-reaction-structure
class DefaultReaction{
  public:
    DefaultReaction(
        nullable_field<Snowflake> emoji_id = uninitialized,
        nullable_field<std::string> emoji_name = uninitialized
    ):
        emoji_id(emoji_id),
        emoji_name(emoji_name)
    {}
    DefaultReaction(const json &j) { from_json(j, *this); }
    
    nullable_field<Snowflake> emoji_id;
    nullable_field<std::string> emoji_name;

    friend void to_json(nlohmann::json &j, const DefaultReaction &t) {
        if(!t.emoji_id.is_omitted()) {j["emoji_id"] = t.emoji_id;}
        if(!t.emoji_name.is_omitted()) {j["emoji_name"] = t.emoji_name;}
    }
    friend void from_json(const nlohmann::json &j, DefaultReaction &t) {
        if(j.contains("emoji_id")){j.at("emoji_id").get_to(t.emoji_id);}
        if(j.contains("emoji_name")){j.at("emoji_name").get_to(t.emoji_name);}
    }
};

// https://discord.com/developers/docs/resources/channel#forum-tag-object-forum-tag-structure
class ForumTag{
  public:
    ForumTag(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<bool> moderated = uninitialized,
        nullable_field<Snowflake> emoji_id = uninitialized,
        nullable_field<std::string> emoji_name = uninitialized
    ):
        id(id),
        name(name),
        moderated(moderated),
        emoji_id(emoji_id),
        emoji_name(emoji_name)
    {}
    ForumTag(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    field<bool> moderated;
    nullable_field<Snowflake> emoji_id;
    nullable_field<std::string> emoji_name;

    friend void to_json(nlohmann::json &j, const ForumTag &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.moderated.is_omitted()) {j["moderated"] = t.moderated;}
        if(!t.emoji_id.is_omitted()) {j["emoji_id"] = t.emoji_id;}
        if(!t.emoji_name.is_omitted()) {j["emoji_name"] = t.emoji_name;}
    }
    friend void from_json(const nlohmann::json &j, ForumTag &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("moderated")){j.at("moderated").get_to(t.moderated);}
        if(j.contains("emoji_id")){j.at("emoji_id").get_to(t.emoji_id);}
        if(j.contains("emoji_name")){j.at("emoji_name").get_to(t.emoji_name);}
    }
};

// https://discord.com/developers/docs/resources/channel#embed-object-embed-structure
class Embed{
  public:
    Embed(
        omittable_field<std::string> title = omitted,
        omittable_field<std::string> type = omitted,
        omittable_field<std::string> description = omitted,
        omittable_field<std::string> url = omitted,
        omittable_field<Timestamp> timestamp = omitted,
        omittable_field<int> color = omitted,
        omittable_field<EmbedFooter> footer = omitted,
        omittable_field<EmbedImage> image = omitted,
        omittable_field<EmbedThumbnail> thumbnail = omitted,
        omittable_field<EmbedVideo> video = omitted,
        omittable_field<EmbedProvider> provider = omitted,
        omittable_field<EmbedAuthor> author = omitted,
        omittable_field<std::vector<EmbedField> > fields = omitted
    ):
        title(title),
        type(type),
        description(description),
        url(url),
        timestamp(timestamp),
        color(color),
        footer(footer),
        image(image),
        thumbnail(thumbnail),
        video(video),
        provider(provider),
        author(author),
        fields(fields)
    {}
    Embed(const json &j) { from_json(j, *this); }
    
    omittable_field<std::string> title;
    omittable_field<std::string> type;
    omittable_field<std::string> description;
    omittable_field<std::string> url;
    omittable_field<Timestamp> timestamp;
    omittable_field<int> color;
    omittable_field<EmbedFooter> footer;
    omittable_field<EmbedImage> image;
    omittable_field<EmbedThumbnail> thumbnail;
    omittable_field<EmbedVideo> video;
    omittable_field<EmbedProvider> provider;
    omittable_field<EmbedAuthor> author;
    omittable_field<std::vector<EmbedField> > fields;

    friend void to_json(nlohmann::json &j, const Embed &t) {
        if(!t.title.is_omitted()) {j["title"] = t.title;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.timestamp.is_omitted()) {j["timestamp"] = t.timestamp;}
        if(!t.color.is_omitted()) {j["color"] = t.color;}
        if(!t.footer.is_omitted()) {j["footer"] = t.footer;}
        if(!t.image.is_omitted()) {j["image"] = t.image;}
        if(!t.thumbnail.is_omitted()) {j["thumbnail"] = t.thumbnail;}
        if(!t.video.is_omitted()) {j["video"] = t.video;}
        if(!t.provider.is_omitted()) {j["provider"] = t.provider;}
        if(!t.author.is_omitted()) {j["author"] = t.author;}
        if(!t.fields.is_omitted()) {j["fields"] = t.fields;}
    }
    friend void from_json(const nlohmann::json &j, Embed &t) {
        if(j.contains("title")){j.at("title").get_to(t.title);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("timestamp")){j.at("timestamp").get_to(t.timestamp);}
        if(j.contains("color")){j.at("color").get_to(t.color);}
        if(j.contains("footer")){j.at("footer").get_to(t.footer);}
        if(j.contains("image")){j.at("image").get_to(t.image);}
        if(j.contains("thumbnail")){j.at("thumbnail").get_to(t.thumbnail);}
        if(j.contains("video")){j.at("video").get_to(t.video);}
        if(j.contains("provider")){j.at("provider").get_to(t.provider);}
        if(j.contains("author")){j.at("author").get_to(t.author);}
        if(j.contains("fields")){j.at("fields").get_to(t.fields);}
    }
};

// https://discord.com/developers/docs/resources/channel#embed-object-embed-thumbnail-structure
class EmbedThumbnail{
  public:
    EmbedThumbnail(
        field<std::string> url = uninitialized,
        omittable_field<std::string> proxy_url = omitted,
        omittable_field<int> height = omitted,
        omittable_field<int> width = omitted
    ):
        url(url),
        proxy_url(proxy_url),
        height(height),
        width(width)
    {}
    EmbedThumbnail(const json &j) { from_json(j, *this); }
    
    field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    friend void to_json(nlohmann::json &j, const EmbedThumbnail &t) {
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.proxy_url.is_omitted()) {j["proxy_url"] = t.proxy_url;}
        if(!t.height.is_omitted()) {j["height"] = t.height;}
        if(!t.width.is_omitted()) {j["width"] = t.width;}
    }
    friend void from_json(const nlohmann::json &j, EmbedThumbnail &t) {
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("proxy_url")){j.at("proxy_url").get_to(t.proxy_url);}
        if(j.contains("height")){j.at("height").get_to(t.height);}
        if(j.contains("width")){j.at("width").get_to(t.width);}
    }
};

// https://discord.com/developers/docs/resources/channel#embed-object-embed-video-structure
class EmbedVideo{
  public:
    EmbedVideo(
        omittable_field<std::string> url = omitted,
        omittable_field<std::string> proxy_url = omitted,
        omittable_field<int> height = omitted,
        omittable_field<int> width = omitted
    ):
        url(url),
        proxy_url(proxy_url),
        height(height),
        width(width)
    {}
    EmbedVideo(const json &j) { from_json(j, *this); }
    
    omittable_field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    friend void to_json(nlohmann::json &j, const EmbedVideo &t) {
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.proxy_url.is_omitted()) {j["proxy_url"] = t.proxy_url;}
        if(!t.height.is_omitted()) {j["height"] = t.height;}
        if(!t.width.is_omitted()) {j["width"] = t.width;}
    }
    friend void from_json(const nlohmann::json &j, EmbedVideo &t) {
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("proxy_url")){j.at("proxy_url").get_to(t.proxy_url);}
        if(j.contains("height")){j.at("height").get_to(t.height);}
        if(j.contains("width")){j.at("width").get_to(t.width);}
    }
};

// https://discord.com/developers/docs/resources/channel#embed-object-embed-image-structure
class EmbedImage{
  public:
    EmbedImage(
        field<std::string> url = uninitialized,
        omittable_field<std::string> proxy_url = omitted,
        omittable_field<int> height = omitted,
        omittable_field<int> width = omitted
    ):
        url(url),
        proxy_url(proxy_url),
        height(height),
        width(width)
    {}
    EmbedImage(const json &j) { from_json(j, *this); }
    
    field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    friend void to_json(nlohmann::json &j, const EmbedImage &t) {
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.proxy_url.is_omitted()) {j["proxy_url"] = t.proxy_url;}
        if(!t.height.is_omitted()) {j["height"] = t.height;}
        if(!t.width.is_omitted()) {j["width"] = t.width;}
    }
    friend void from_json(const nlohmann::json &j, EmbedImage &t) {
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("proxy_url")){j.at("proxy_url").get_to(t.proxy_url);}
        if(j.contains("height")){j.at("height").get_to(t.height);}
        if(j.contains("width")){j.at("width").get_to(t.width);}
    }
};

// https://discord.com/developers/docs/resources/channel#embed-object-embed-provider-structure
class EmbedProvider{
  public:
    EmbedProvider(
        omittable_field<std::string> name = omitted,
        omittable_field<std::string> url = omitted
    ):
        name(name),
        url(url)
    {}
    EmbedProvider(const json &j) { from_json(j, *this); }
    
    omittable_field<std::string> name;
    omittable_field<std::string> url;

    friend void to_json(nlohmann::json &j, const EmbedProvider &t) {
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
    }
    friend void from_json(const nlohmann::json &j, EmbedProvider &t) {
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
    }
};

// https://discord.com/developers/docs/resources/channel#embed-object-embed-author-structure
class EmbedAuthor{
  public:
    EmbedAuthor(
        field<std::string> name = uninitialized,
        omittable_field<std::string> url = omitted,
        omittable_field<std::string> icon_url = omitted,
        omittable_field<std::string> proxy_icon_url = omitted
    ):
        name(name),
        url(url),
        icon_url(icon_url),
        proxy_icon_url(proxy_icon_url)
    {}
    EmbedAuthor(const json &j) { from_json(j, *this); }
    
    field<std::string> name;
    omittable_field<std::string> url;
    omittable_field<std::string> icon_url;
    omittable_field<std::string> proxy_icon_url;

    friend void to_json(nlohmann::json &j, const EmbedAuthor &t) {
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.icon_url.is_omitted()) {j["icon_url"] = t.icon_url;}
        if(!t.proxy_icon_url.is_omitted()) {j["proxy_icon_url"] = t.proxy_icon_url;}
    }
    friend void from_json(const nlohmann::json &j, EmbedAuthor &t) {
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("icon_url")){j.at("icon_url").get_to(t.icon_url);}
        if(j.contains("proxy_icon_url")){j.at("proxy_icon_url").get_to(t.proxy_icon_url);}
    }
};

// https://discord.com/developers/docs/resources/channel#embed-object-embed-footer-structure
class EmbedFooter{
  public:
    EmbedFooter(
        field<std::string> text = uninitialized,
        omittable_field<std::string> icon_url = omitted,
        omittable_field<std::string> proxy_icon_url = omitted
    ):
        text(text),
        icon_url(icon_url),
        proxy_icon_url(proxy_icon_url)
    {}
    EmbedFooter(const json &j) { from_json(j, *this); }
    
    field<std::string> text;
    omittable_field<std::string> icon_url;
    omittable_field<std::string> proxy_icon_url;

    friend void to_json(nlohmann::json &j, const EmbedFooter &t) {
        if(!t.text.is_omitted()) {j["text"] = t.text;}
        if(!t.icon_url.is_omitted()) {j["icon_url"] = t.icon_url;}
        if(!t.proxy_icon_url.is_omitted()) {j["proxy_icon_url"] = t.proxy_icon_url;}
    }
    friend void from_json(const nlohmann::json &j, EmbedFooter &t) {
        if(j.contains("text")){j.at("text").get_to(t.text);}
        if(j.contains("icon_url")){j.at("icon_url").get_to(t.icon_url);}
        if(j.contains("proxy_icon_url")){j.at("proxy_icon_url").get_to(t.proxy_icon_url);}
    }
};

// https://discord.com/developers/docs/resources/channel#embed-object-embed-field-structure
class EmbedField{
  public:
    EmbedField(
        field<std::string> name = uninitialized,
        field<std::string> value = uninitialized,
        omittable_field<bool> display_inline = omitted
    ):
        name(name),
        value(value),
        display_inline(display_inline)
    {}
    EmbedField(const json &j) { from_json(j, *this); }
    
    field<std::string> name;
    field<std::string> value;
    omittable_field<bool> display_inline;

    friend void to_json(nlohmann::json &j, const EmbedField &t) {
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.display_inline.is_omitted()) {j["inline"] = t.display_inline;}
    }
    friend void from_json(const nlohmann::json &j, EmbedField &t) {
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("value")){j.at("value").get_to(t.value);}
        if(j.contains("inline")){j.at("inline").get_to(t.display_inline);}
    }
};

// https://discord.com/developers/docs/resources/channel#attachment-object-attachment-structure
class Attachment{
  public:
    Attachment(
        field<Snowflake> id = uninitialized,
        field<std::string> filename = uninitialized,
        omittable_field<std::string> description = omitted,
        omittable_field<std::string> content_type = omitted,
        field<int> size = uninitialized,
        field<std::string> url = uninitialized,
        field<std::string> proxy_url = uninitialized,
        nullable_omittable_field<int> height = omitted,
        nullable_omittable_field<int> width = omitted,
        omittable_field<bool> ephemeral = omitted
    ):
        id(id),
        filename(filename),
        description(description),
        content_type(content_type),
        size(size),
        url(url),
        proxy_url(proxy_url),
        height(height),
        width(width),
        ephemeral(ephemeral)
    {}
    Attachment(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> filename;
    omittable_field<std::string> description;
    omittable_field<std::string> content_type;
    field<int> size;
    field<std::string> url;
    field<std::string> proxy_url;
    nullable_omittable_field<int> height;
    nullable_omittable_field<int> width;
    omittable_field<bool> ephemeral;

    friend void to_json(nlohmann::json &j, const Attachment &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.filename.is_omitted()) {j["filename"] = t.filename;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.content_type.is_omitted()) {j["content_type"] = t.content_type;}
        if(!t.size.is_omitted()) {j["size"] = t.size;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.proxy_url.is_omitted()) {j["proxy_url"] = t.proxy_url;}
        if(!t.height.is_omitted()) {j["height"] = t.height;}
        if(!t.width.is_omitted()) {j["width"] = t.width;}
        if(!t.ephemeral.is_omitted()) {j["ephemeral"] = t.ephemeral;}
    }
    friend void from_json(const nlohmann::json &j, Attachment &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("filename")){j.at("filename").get_to(t.filename);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("content_type")){j.at("content_type").get_to(t.content_type);}
        if(j.contains("size")){j.at("size").get_to(t.size);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("proxy_url")){j.at("proxy_url").get_to(t.proxy_url);}
        if(j.contains("height")){j.at("height").get_to(t.height);}
        if(j.contains("width")){j.at("width").get_to(t.width);}
        if(j.contains("ephemeral")){j.at("ephemeral").get_to(t.ephemeral);}
    }
};

// https://discord.com/developers/docs/resources/channel#channel-mention-object-channel-mention-structure
class ChannelMention{
  public:
    ChannelMention(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<int> type = uninitialized,
        field<std::string> name = uninitialized
    ):
        id(id),
        guild_id(guild_id),
        type(type),
        name(name)
    {}
    ChannelMention(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<int> type;
    field<std::string> name;

    friend void to_json(nlohmann::json &j, const ChannelMention &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
    }
    friend void from_json(const nlohmann::json &j, ChannelMention &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
    }
};

// https://discord.com/developers/docs/resources/channel#allowed-mentions-object-allowed-mentions-structure
class AllowedMentions{
  public:
    AllowedMentions(
        field<std::vector<AllowedMentionType> > parse = uninitialized,
        field<std::vector<Snowflake> > roles = uninitialized,
        field<std::vector<Snowflake> > users = uninitialized,
        field<bool> replied_user = uninitialized
    ):
        parse(parse),
        roles(roles),
        users(users),
        replied_user(replied_user)
    {}
    AllowedMentions(const json &j) { from_json(j, *this); }
    
    field<std::vector<AllowedMentionType> > parse;
    field<std::vector<Snowflake> > roles;
    field<std::vector<Snowflake> > users;
    field<bool> replied_user;

    friend void to_json(nlohmann::json &j, const AllowedMentions &t) {
        if(!t.parse.is_omitted()) {j["parse"] = t.parse;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.users.is_omitted()) {j["users"] = t.users;}
        if(!t.replied_user.is_omitted()) {j["replied_user"] = t.replied_user;}
    }
    friend void from_json(const nlohmann::json &j, AllowedMentions &t) {
        if(j.contains("parse")){j.at("parse").get_to(t.parse);}
        if(j.contains("roles")){j.at("roles").get_to(t.roles);}
        if(j.contains("users")){j.at("users").get_to(t.users);}
        if(j.contains("replied_user")){j.at("replied_user").get_to(t.replied_user);}
    }
};

// https://discord.com/developers/docs/resources/channel#role-subscription-data-object-role-subscription-data-object-structure
class RoleSubscriptionData{
  public:
    RoleSubscriptionData(
        field<Snowflake> role_subscription_listing_id = uninitialized,
        field<std::string> tier_name = uninitialized,
        field<int> total_months_subscribed = uninitialized,
        field<bool> is_renewal = uninitialized
    ):
        role_subscription_listing_id(role_subscription_listing_id),
        tier_name(tier_name),
        total_months_subscribed(total_months_subscribed),
        is_renewal(is_renewal)
    {}
    RoleSubscriptionData(const json &j) { from_json(j, *this); }
    
    field<Snowflake> role_subscription_listing_id;
    field<std::string> tier_name;
    field<int> total_months_subscribed;
    field<bool> is_renewal;

    friend void to_json(nlohmann::json &j, const RoleSubscriptionData &t) {
        if(!t.role_subscription_listing_id.is_omitted()) {j["role_subscription_listing_id"] = t.role_subscription_listing_id;}
        if(!t.tier_name.is_omitted()) {j["tier_name"] = t.tier_name;}
        if(!t.total_months_subscribed.is_omitted()) {j["total_months_subscribed"] = t.total_months_subscribed;}
        if(!t.is_renewal.is_omitted()) {j["is_renewal"] = t.is_renewal;}
    }
    friend void from_json(const nlohmann::json &j, RoleSubscriptionData &t) {
        if(j.contains("role_subscription_listing_id")){j.at("role_subscription_listing_id").get_to(t.role_subscription_listing_id);}
        if(j.contains("tier_name")){j.at("tier_name").get_to(t.tier_name);}
        if(j.contains("total_months_subscribed")){j.at("total_months_subscribed").get_to(t.total_months_subscribed);}
        if(j.contains("is_renewal")){j.at("is_renewal").get_to(t.is_renewal);}
    }
};

// https://discord.com/developers/docs/resources/channel#list-public-archived-threads-response-body
class ListPublicArchivedThreadsResponse{
  public:
    ListPublicArchivedThreadsResponse(
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<ThreadMember> > members = uninitialized,
        field<bool> has_more = uninitialized
    ):
        threads(threads),
        members(members),
        has_more(has_more)
    {}
    ListPublicArchivedThreadsResponse(const json &j) { from_json(j, *this); }
    
    field<std::vector<Channel> > threads;
    field<std::vector<ThreadMember> > members;
    field<bool> has_more;

    friend void to_json(nlohmann::json &j, const ListPublicArchivedThreadsResponse &t) {
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.has_more.is_omitted()) {j["has_more"] = t.has_more;}
    }
    friend void from_json(const nlohmann::json &j, ListPublicArchivedThreadsResponse &t) {
        if(j.contains("threads")){j.at("threads").get_to(t.threads);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("has_more")){j.at("has_more").get_to(t.has_more);}
    }
};

// https://discord.com/developers/docs/resources/channel#list-private-archived-threads-response-body
class ListPrivateArchivedThreadsResponse{
  public:
    ListPrivateArchivedThreadsResponse(
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<ThreadMember> > members = uninitialized,
        field<bool> has_more = uninitialized
    ):
        threads(threads),
        members(members),
        has_more(has_more)
    {}
    ListPrivateArchivedThreadsResponse(const json &j) { from_json(j, *this); }
    
    field<std::vector<Channel> > threads;
    field<std::vector<ThreadMember> > members;
    field<bool> has_more;

    friend void to_json(nlohmann::json &j, const ListPrivateArchivedThreadsResponse &t) {
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.has_more.is_omitted()) {j["has_more"] = t.has_more;}
    }
    friend void from_json(const nlohmann::json &j, ListPrivateArchivedThreadsResponse &t) {
        if(j.contains("threads")){j.at("threads").get_to(t.threads);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("has_more")){j.at("has_more").get_to(t.has_more);}
    }
};

// https://discord.com/developers/docs/resources/channel#list-joined-private-archived-threads-response-body
class ListJoinedPrivateArchivedThreadsResponse{
  public:
    ListJoinedPrivateArchivedThreadsResponse(
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<ThreadMember> > members = uninitialized,
        field<bool> has_more = uninitialized
    ):
        threads(threads),
        members(members),
        has_more(has_more)
    {}
    ListJoinedPrivateArchivedThreadsResponse(const json &j) { from_json(j, *this); }
    
    field<std::vector<Channel> > threads;
    field<std::vector<ThreadMember> > members;
    field<bool> has_more;

    friend void to_json(nlohmann::json &j, const ListJoinedPrivateArchivedThreadsResponse &t) {
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.has_more.is_omitted()) {j["has_more"] = t.has_more;}
    }
    friend void from_json(const nlohmann::json &j, ListJoinedPrivateArchivedThreadsResponse &t) {
        if(j.contains("threads")){j.at("threads").get_to(t.threads);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("has_more")){j.at("has_more").get_to(t.has_more);}
    }
};

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
    Emoji(const json &j) { from_json(j, *this); }
    
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

// https://discord.com/developers/docs/resources/guild#guild-object-guild-structure
class Guild{
  public:
    Guild(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> icon = uninitialized,
        nullable_omittable_field<std::string> icon_hash = omitted,
        nullable_field<std::string> splash = uninitialized,
        nullable_field<std::string> discovery_splash = uninitialized,
        omittable_field<bool> owner = omitted,
        field<Snowflake> owner_id = uninitialized,
        omittable_field<std::string> permissions = omitted,
        nullable_omittable_field<std::string> region = omitted,
        nullable_field<Snowflake> afk_channel_id = uninitialized,
        field<int> afk_timeout = uninitialized,
        omittable_field<bool> widget_enabled = omitted,
        nullable_omittable_field<Snowflake> widget_channel_id = omitted,
        field<int> verification_level = uninitialized,
        field<int> default_message_notifications = uninitialized,
        field<int> explicit_content_filter = uninitialized,
        field<std::vector<Role> > roles = uninitialized,
        field<std::vector<Emoji> > emojis = uninitialized,
        field<std::vector<GuildFeature> > features = uninitialized,
        field<int> mfa_level = uninitialized,
        nullable_field<Snowflake> application_id = uninitialized,
        nullable_field<Snowflake> system_channel_id = uninitialized,
        field<int> system_channel_flags = uninitialized,
        nullable_field<Snowflake> rules_channel_id = uninitialized,
        nullable_omittable_field<int> max_presences = omitted,
        omittable_field<int> max_members = omitted,
        nullable_field<std::string> vanity_url_code = uninitialized,
        nullable_field<std::string> description = uninitialized,
        nullable_field<std::string> banner = uninitialized,
        field<int> premium_tier = uninitialized,
        omittable_field<int> premium_subscription_count = omitted,
        field<std::string> preferred_locale = uninitialized,
        nullable_field<Snowflake> public_updates_channel_id = uninitialized,
        omittable_field<int> max_video_channel_users = omitted,
        omittable_field<int> approximate_member_count = omitted,
        omittable_field<int> approximate_presence_count = omitted,
        omittable_field<WelcomeScreen> welcome_screen = omitted,
        field<int> nsfw_level = uninitialized,
        omittable_field<std::vector<Sticker> > stickers = omitted,
        field<bool> premium_progress_bar_enabled = uninitialized,
        omittable_field<bool> unavailable = omitted
    ):
        id(id),
        name(name),
        icon(icon),
        icon_hash(icon_hash),
        splash(splash),
        discovery_splash(discovery_splash),
        owner(owner),
        owner_id(owner_id),
        permissions(permissions),
        region(region),
        afk_channel_id(afk_channel_id),
        afk_timeout(afk_timeout),
        widget_enabled(widget_enabled),
        widget_channel_id(widget_channel_id),
        verification_level(verification_level),
        default_message_notifications(default_message_notifications),
        explicit_content_filter(explicit_content_filter),
        roles(roles),
        emojis(emojis),
        features(features),
        mfa_level(mfa_level),
        application_id(application_id),
        system_channel_id(system_channel_id),
        system_channel_flags(system_channel_flags),
        rules_channel_id(rules_channel_id),
        max_presences(max_presences),
        max_members(max_members),
        vanity_url_code(vanity_url_code),
        description(description),
        banner(banner),
        premium_tier(premium_tier),
        premium_subscription_count(premium_subscription_count),
        preferred_locale(preferred_locale),
        public_updates_channel_id(public_updates_channel_id),
        max_video_channel_users(max_video_channel_users),
        approximate_member_count(approximate_member_count),
        approximate_presence_count(approximate_presence_count),
        welcome_screen(welcome_screen),
        nsfw_level(nsfw_level),
        stickers(stickers),
        premium_progress_bar_enabled(premium_progress_bar_enabled),
        unavailable(unavailable)
    {}
    Guild(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    nullable_omittable_field<std::string> icon_hash;
    nullable_field<std::string> splash;
    nullable_field<std::string> discovery_splash;
    omittable_field<bool> owner;
    field<Snowflake> owner_id;
    omittable_field<std::string> permissions;
    nullable_omittable_field<std::string> region;
    nullable_field<Snowflake> afk_channel_id;
    field<int> afk_timeout;
    omittable_field<bool> widget_enabled;
    nullable_omittable_field<Snowflake> widget_channel_id;
    field<int> verification_level;
    field<int> default_message_notifications;
    field<int> explicit_content_filter;
    field<std::vector<Role> > roles;
    field<std::vector<Emoji> > emojis;
    field<std::vector<GuildFeature> > features;
    field<int> mfa_level;
    nullable_field<Snowflake> application_id;
    nullable_field<Snowflake> system_channel_id;
    field<int> system_channel_flags;
    nullable_field<Snowflake> rules_channel_id;
    nullable_omittable_field<int> max_presences;
    omittable_field<int> max_members;
    nullable_field<std::string> vanity_url_code;
    nullable_field<std::string> description;
    nullable_field<std::string> banner;
    field<int> premium_tier;
    omittable_field<int> premium_subscription_count;
    field<std::string> preferred_locale;
    nullable_field<Snowflake> public_updates_channel_id;
    omittable_field<int> max_video_channel_users;
    omittable_field<int> approximate_member_count;
    omittable_field<int> approximate_presence_count;
    omittable_field<WelcomeScreen> welcome_screen;
    field<int> nsfw_level;
    omittable_field<std::vector<Sticker> > stickers;
    field<bool> premium_progress_bar_enabled;
    omittable_field<bool> unavailable;

    friend void to_json(nlohmann::json &j, const Guild &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.icon_hash.is_omitted()) {j["icon_hash"] = t.icon_hash;}
        if(!t.splash.is_omitted()) {j["splash"] = t.splash;}
        if(!t.discovery_splash.is_omitted()) {j["discovery_splash"] = t.discovery_splash;}
        if(!t.owner.is_omitted()) {j["owner"] = t.owner;}
        if(!t.owner_id.is_omitted()) {j["owner_id"] = t.owner_id;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
        if(!t.region.is_omitted()) {j["region"] = t.region;}
        if(!t.afk_channel_id.is_omitted()) {j["afk_channel_id"] = t.afk_channel_id;}
        if(!t.afk_timeout.is_omitted()) {j["afk_timeout"] = t.afk_timeout;}
        if(!t.widget_enabled.is_omitted()) {j["widget_enabled"] = t.widget_enabled;}
        if(!t.widget_channel_id.is_omitted()) {j["widget_channel_id"] = t.widget_channel_id;}
        if(!t.verification_level.is_omitted()) {j["verification_level"] = t.verification_level;}
        if(!t.default_message_notifications.is_omitted()) {j["default_message_notifications"] = t.default_message_notifications;}
        if(!t.explicit_content_filter.is_omitted()) {j["explicit_content_filter"] = t.explicit_content_filter;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.emojis.is_omitted()) {j["emojis"] = t.emojis;}
        if(!t.features.is_omitted()) {j["features"] = t.features;}
        if(!t.mfa_level.is_omitted()) {j["mfa_level"] = t.mfa_level;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.system_channel_id.is_omitted()) {j["system_channel_id"] = t.system_channel_id;}
        if(!t.system_channel_flags.is_omitted()) {j["system_channel_flags"] = t.system_channel_flags;}
        if(!t.rules_channel_id.is_omitted()) {j["rules_channel_id"] = t.rules_channel_id;}
        if(!t.max_presences.is_omitted()) {j["max_presences"] = t.max_presences;}
        if(!t.max_members.is_omitted()) {j["max_members"] = t.max_members;}
        if(!t.vanity_url_code.is_omitted()) {j["vanity_url_code"] = t.vanity_url_code;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.banner.is_omitted()) {j["banner"] = t.banner;}
        if(!t.premium_tier.is_omitted()) {j["premium_tier"] = t.premium_tier;}
        if(!t.premium_subscription_count.is_omitted()) {j["premium_subscription_count"] = t.premium_subscription_count;}
        if(!t.preferred_locale.is_omitted()) {j["preferred_locale"] = t.preferred_locale;}
        if(!t.public_updates_channel_id.is_omitted()) {j["public_updates_channel_id"] = t.public_updates_channel_id;}
        if(!t.max_video_channel_users.is_omitted()) {j["max_video_channel_users"] = t.max_video_channel_users;}
        if(!t.approximate_member_count.is_omitted()) {j["approximate_member_count"] = t.approximate_member_count;}
        if(!t.approximate_presence_count.is_omitted()) {j["approximate_presence_count"] = t.approximate_presence_count;}
        if(!t.welcome_screen.is_omitted()) {j["welcome_screen"] = t.welcome_screen;}
        if(!t.nsfw_level.is_omitted()) {j["nsfw_level"] = t.nsfw_level;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
        if(!t.premium_progress_bar_enabled.is_omitted()) {j["premium_progress_bar_enabled"] = t.premium_progress_bar_enabled;}
        if(!t.unavailable.is_omitted()) {j["unavailable"] = t.unavailable;}
    }
    friend void from_json(const nlohmann::json &j, Guild &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("icon")){j.at("icon").get_to(t.icon);}
        if(j.contains("icon_hash")){j.at("icon_hash").get_to(t.icon_hash);}
        if(j.contains("splash")){j.at("splash").get_to(t.splash);}
        if(j.contains("discovery_splash")){j.at("discovery_splash").get_to(t.discovery_splash);}
        if(j.contains("owner")){j.at("owner").get_to(t.owner);}
        if(j.contains("owner_id")){j.at("owner_id").get_to(t.owner_id);}
        if(j.contains("permissions")){j.at("permissions").get_to(t.permissions);}
        if(j.contains("region")){j.at("region").get_to(t.region);}
        if(j.contains("afk_channel_id")){j.at("afk_channel_id").get_to(t.afk_channel_id);}
        if(j.contains("afk_timeout")){j.at("afk_timeout").get_to(t.afk_timeout);}
        if(j.contains("widget_enabled")){j.at("widget_enabled").get_to(t.widget_enabled);}
        if(j.contains("widget_channel_id")){j.at("widget_channel_id").get_to(t.widget_channel_id);}
        if(j.contains("verification_level")){j.at("verification_level").get_to(t.verification_level);}
        if(j.contains("default_message_notifications")){j.at("default_message_notifications").get_to(t.default_message_notifications);}
        if(j.contains("explicit_content_filter")){j.at("explicit_content_filter").get_to(t.explicit_content_filter);}
        if(j.contains("roles")){j.at("roles").get_to(t.roles);}
        if(j.contains("emojis")){j.at("emojis").get_to(t.emojis);}
        if(j.contains("features")){j.at("features").get_to(t.features);}
        if(j.contains("mfa_level")){j.at("mfa_level").get_to(t.mfa_level);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("system_channel_id")){j.at("system_channel_id").get_to(t.system_channel_id);}
        if(j.contains("system_channel_flags")){j.at("system_channel_flags").get_to(t.system_channel_flags);}
        if(j.contains("rules_channel_id")){j.at("rules_channel_id").get_to(t.rules_channel_id);}
        if(j.contains("max_presences")){j.at("max_presences").get_to(t.max_presences);}
        if(j.contains("max_members")){j.at("max_members").get_to(t.max_members);}
        if(j.contains("vanity_url_code")){j.at("vanity_url_code").get_to(t.vanity_url_code);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("banner")){j.at("banner").get_to(t.banner);}
        if(j.contains("premium_tier")){j.at("premium_tier").get_to(t.premium_tier);}
        if(j.contains("premium_subscription_count")){j.at("premium_subscription_count").get_to(t.premium_subscription_count);}
        if(j.contains("preferred_locale")){j.at("preferred_locale").get_to(t.preferred_locale);}
        if(j.contains("public_updates_channel_id")){j.at("public_updates_channel_id").get_to(t.public_updates_channel_id);}
        if(j.contains("max_video_channel_users")){j.at("max_video_channel_users").get_to(t.max_video_channel_users);}
        if(j.contains("approximate_member_count")){j.at("approximate_member_count").get_to(t.approximate_member_count);}
        if(j.contains("approximate_presence_count")){j.at("approximate_presence_count").get_to(t.approximate_presence_count);}
        if(j.contains("welcome_screen")){j.at("welcome_screen").get_to(t.welcome_screen);}
        if(j.contains("nsfw_level")){j.at("nsfw_level").get_to(t.nsfw_level);}
        if(j.contains("stickers")){j.at("stickers").get_to(t.stickers);}
        if(j.contains("premium_progress_bar_enabled")){j.at("premium_progress_bar_enabled").get_to(t.premium_progress_bar_enabled);}
        if(j.contains("unavailable")){j.at("unavailable").get_to(t.unavailable);}
    }
};

// https://discord.com/developers/docs/resources/guild#guild-preview-object-guild-preview-structure
class GuildPreview{
  public:
    GuildPreview(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> icon = uninitialized,
        nullable_field<std::string> splash = uninitialized,
        nullable_field<std::string> discovery_splash = uninitialized,
        field<std::vector<Emoji> > emojis = uninitialized,
        field<std::vector<GuildFeature> > features = uninitialized,
        field<int> approximate_member_count = uninitialized,
        field<int> approximate_presence_count = uninitialized,
        nullable_field<std::string> description = uninitialized,
        field<std::vector<Sticker> > stickers = uninitialized
    ):
        id(id),
        name(name),
        icon(icon),
        splash(splash),
        discovery_splash(discovery_splash),
        emojis(emojis),
        features(features),
        approximate_member_count(approximate_member_count),
        approximate_presence_count(approximate_presence_count),
        description(description),
        stickers(stickers)
    {}
    GuildPreview(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    nullable_field<std::string> splash;
    nullable_field<std::string> discovery_splash;
    field<std::vector<Emoji> > emojis;
    field<std::vector<GuildFeature> > features;
    field<int> approximate_member_count;
    field<int> approximate_presence_count;
    nullable_field<std::string> description;
    field<std::vector<Sticker> > stickers;

    friend void to_json(nlohmann::json &j, const GuildPreview &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.splash.is_omitted()) {j["splash"] = t.splash;}
        if(!t.discovery_splash.is_omitted()) {j["discovery_splash"] = t.discovery_splash;}
        if(!t.emojis.is_omitted()) {j["emojis"] = t.emojis;}
        if(!t.features.is_omitted()) {j["features"] = t.features;}
        if(!t.approximate_member_count.is_omitted()) {j["approximate_member_count"] = t.approximate_member_count;}
        if(!t.approximate_presence_count.is_omitted()) {j["approximate_presence_count"] = t.approximate_presence_count;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
    }
    friend void from_json(const nlohmann::json &j, GuildPreview &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("icon")){j.at("icon").get_to(t.icon);}
        if(j.contains("splash")){j.at("splash").get_to(t.splash);}
        if(j.contains("discovery_splash")){j.at("discovery_splash").get_to(t.discovery_splash);}
        if(j.contains("emojis")){j.at("emojis").get_to(t.emojis);}
        if(j.contains("features")){j.at("features").get_to(t.features);}
        if(j.contains("approximate_member_count")){j.at("approximate_member_count").get_to(t.approximate_member_count);}
        if(j.contains("approximate_presence_count")){j.at("approximate_presence_count").get_to(t.approximate_presence_count);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("stickers")){j.at("stickers").get_to(t.stickers);}
    }
};

// https://discord.com/developers/docs/resources/guild#guild-widget-settings-object-guild-widget-settings-structure
class GuildWidgetSettings{
  public:
    GuildWidgetSettings(
        field<bool> enabled = uninitialized,
        nullable_field<Snowflake> channel_id = uninitialized
    ):
        enabled(enabled),
        channel_id(channel_id)
    {}
    GuildWidgetSettings(const json &j) { from_json(j, *this); }
    
    field<bool> enabled;
    nullable_field<Snowflake> channel_id;

    friend void to_json(nlohmann::json &j, const GuildWidgetSettings &t) {
        if(!t.enabled.is_omitted()) {j["enabled"] = t.enabled;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildWidgetSettings &t) {
        if(j.contains("enabled")){j.at("enabled").get_to(t.enabled);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
    }
};

// https://discord.com/developers/docs/resources/guild#guild-widget-object-guild-widget-structure
class GuildWidget{
  public:
    GuildWidget(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> instant_invite = uninitialized,
        field<std::vector<Channel> > channels = uninitialized,
        field<std::vector<User> > members = uninitialized,
        field<int> presence_count = uninitialized
    ):
        id(id),
        name(name),
        instant_invite(instant_invite),
        channels(channels),
        members(members),
        presence_count(presence_count)
    {}
    GuildWidget(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> instant_invite;
    field<std::vector<Channel> > channels;
    field<std::vector<User> > members;
    field<int> presence_count;

    friend void to_json(nlohmann::json &j, const GuildWidget &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.instant_invite.is_omitted()) {j["instant_invite"] = t.instant_invite;}
        if(!t.channels.is_omitted()) {j["channels"] = t.channels;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.presence_count.is_omitted()) {j["presence_count"] = t.presence_count;}
    }
    friend void from_json(const nlohmann::json &j, GuildWidget &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("instant_invite")){j.at("instant_invite").get_to(t.instant_invite);}
        if(j.contains("channels")){j.at("channels").get_to(t.channels);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("presence_count")){j.at("presence_count").get_to(t.presence_count);}
    }
};

// https://discord.com/developers/docs/resources/guild#guild-member-object-guild-member-structure
class GuildMember{
  public:
    GuildMember(
        omittable_field<User> user = omitted,
        nullable_omittable_field<std::string> nick = omitted,
        nullable_omittable_field<std::string> avatar = omitted,
        field<std::vector<Snowflake> > roles = uninitialized,
        field<Timestamp> joined_at = uninitialized,
        nullable_omittable_field<Timestamp> premium_since = omitted,
        field<bool> deaf = uninitialized,
        field<bool> mute = uninitialized,
        field<int> flags = uninitialized,
        omittable_field<bool> pending = omitted,
        omittable_field<std::string> permissions = omitted,
        nullable_omittable_field<Timestamp> communication_disabled_until = omitted
    ):
        user(user),
        nick(nick),
        avatar(avatar),
        roles(roles),
        joined_at(joined_at),
        premium_since(premium_since),
        deaf(deaf),
        mute(mute),
        flags(flags),
        pending(pending),
        permissions(permissions),
        communication_disabled_until(communication_disabled_until)
    {}
    GuildMember(const json &j) { from_json(j, *this); }
    
    omittable_field<User> user;
    nullable_omittable_field<std::string> nick;
    nullable_omittable_field<std::string> avatar;
    field<std::vector<Snowflake> > roles;
    field<Timestamp> joined_at;
    nullable_omittable_field<Timestamp> premium_since;
    field<bool> deaf;
    field<bool> mute;
    field<int> flags;
    omittable_field<bool> pending;
    omittable_field<std::string> permissions;
    nullable_omittable_field<Timestamp> communication_disabled_until;

    friend void to_json(nlohmann::json &j, const GuildMember &t) {
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.nick.is_omitted()) {j["nick"] = t.nick;}
        if(!t.avatar.is_omitted()) {j["avatar"] = t.avatar;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.joined_at.is_omitted()) {j["joined_at"] = t.joined_at;}
        if(!t.premium_since.is_omitted()) {j["premium_since"] = t.premium_since;}
        if(!t.deaf.is_omitted()) {j["deaf"] = t.deaf;}
        if(!t.mute.is_omitted()) {j["mute"] = t.mute;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.pending.is_omitted()) {j["pending"] = t.pending;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
        if(!t.communication_disabled_until.is_omitted()) {j["communication_disabled_until"] = t.communication_disabled_until;}
    }
    friend void from_json(const nlohmann::json &j, GuildMember &t) {
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("nick")){j.at("nick").get_to(t.nick);}
        if(j.contains("avatar")){j.at("avatar").get_to(t.avatar);}
        if(j.contains("roles")){j.at("roles").get_to(t.roles);}
        if(j.contains("joined_at")){j.at("joined_at").get_to(t.joined_at);}
        if(j.contains("premium_since")){j.at("premium_since").get_to(t.premium_since);}
        if(j.contains("deaf")){j.at("deaf").get_to(t.deaf);}
        if(j.contains("mute")){j.at("mute").get_to(t.mute);}
        if(j.contains("flags")){j.at("flags").get_to(t.flags);}
        if(j.contains("pending")){j.at("pending").get_to(t.pending);}
        if(j.contains("permissions")){j.at("permissions").get_to(t.permissions);}
        if(j.contains("communication_disabled_until")){j.at("communication_disabled_until").get_to(t.communication_disabled_until);}
    }
};

// https://discord.com/developers/docs/resources/guild#integration-object-integration-structure
class Integration{
  public:
    Integration(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<std::string> type = uninitialized,
        field<bool> enabled = uninitialized,
        omittable_field<bool> syncing = omitted,
        omittable_field<Snowflake> role_id = omitted,
        omittable_field<bool> enable_emoticons = omitted,
        omittable_field<IntegrationExpireBehavior> expire_behavior = omitted,
        omittable_field<int> expire_grace_period = omitted,
        omittable_field<User> user = omitted,
        field<IntegrationAccount> account = uninitialized,
        omittable_field<Timestamp> synced_at = omitted,
        omittable_field<int> subscriber_count = omitted,
        omittable_field<bool> revoked = omitted,
        omittable_field<Application> application = omitted,
        omittable_field<std::vector<OAuth2Scope> > scopes = omitted
    ):
        id(id),
        name(name),
        type(type),
        enabled(enabled),
        syncing(syncing),
        role_id(role_id),
        enable_emoticons(enable_emoticons),
        expire_behavior(expire_behavior),
        expire_grace_period(expire_grace_period),
        user(user),
        account(account),
        synced_at(synced_at),
        subscriber_count(subscriber_count),
        revoked(revoked),
        application(application),
        scopes(scopes)
    {}
    Integration(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    field<std::string> type;
    field<bool> enabled;
    omittable_field<bool> syncing;
    omittable_field<Snowflake> role_id;
    omittable_field<bool> enable_emoticons;
    omittable_field<IntegrationExpireBehavior> expire_behavior;
    omittable_field<int> expire_grace_period;
    omittable_field<User> user;
    field<IntegrationAccount> account;
    omittable_field<Timestamp> synced_at;
    omittable_field<int> subscriber_count;
    omittable_field<bool> revoked;
    omittable_field<Application> application;
    omittable_field<std::vector<OAuth2Scope> > scopes;

    friend void to_json(nlohmann::json &j, const Integration &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.enabled.is_omitted()) {j["enabled"] = t.enabled;}
        if(!t.syncing.is_omitted()) {j["syncing"] = t.syncing;}
        if(!t.role_id.is_omitted()) {j["role_id"] = t.role_id;}
        if(!t.enable_emoticons.is_omitted()) {j["enable_emoticons"] = t.enable_emoticons;}
        if(!t.expire_behavior.is_omitted()) {j["expire_behavior"] = t.expire_behavior;}
        if(!t.expire_grace_period.is_omitted()) {j["expire_grace_period"] = t.expire_grace_period;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.account.is_omitted()) {j["account"] = t.account;}
        if(!t.synced_at.is_omitted()) {j["synced_at"] = t.synced_at;}
        if(!t.subscriber_count.is_omitted()) {j["subscriber_count"] = t.subscriber_count;}
        if(!t.revoked.is_omitted()) {j["revoked"] = t.revoked;}
        if(!t.application.is_omitted()) {j["application"] = t.application;}
        if(!t.scopes.is_omitted()) {j["scopes"] = t.scopes;}
    }
    friend void from_json(const nlohmann::json &j, Integration &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("enabled")){j.at("enabled").get_to(t.enabled);}
        if(j.contains("syncing")){j.at("syncing").get_to(t.syncing);}
        if(j.contains("role_id")){j.at("role_id").get_to(t.role_id);}
        if(j.contains("enable_emoticons")){j.at("enable_emoticons").get_to(t.enable_emoticons);}
        if(j.contains("expire_behavior")){j.at("expire_behavior").get_to(t.expire_behavior);}
        if(j.contains("expire_grace_period")){j.at("expire_grace_period").get_to(t.expire_grace_period);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("account")){j.at("account").get_to(t.account);}
        if(j.contains("synced_at")){j.at("synced_at").get_to(t.synced_at);}
        if(j.contains("subscriber_count")){j.at("subscriber_count").get_to(t.subscriber_count);}
        if(j.contains("revoked")){j.at("revoked").get_to(t.revoked);}
        if(j.contains("application")){j.at("application").get_to(t.application);}
        if(j.contains("scopes")){j.at("scopes").get_to(t.scopes);}
    }
};

// https://discord.com/developers/docs/resources/guild#integration-account-object-integration-account-structure
class IntegrationAccount{
  public:
    IntegrationAccount(
        field<std::string> id = uninitialized,
        field<std::string> name = uninitialized
    ):
        id(id),
        name(name)
    {}
    IntegrationAccount(const json &j) { from_json(j, *this); }
    
    field<std::string> id;
    field<std::string> name;

    friend void to_json(nlohmann::json &j, const IntegrationAccount &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationAccount &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
    }
};

// https://discord.com/developers/docs/resources/guild#integration-application-object-integration-application-structure
class IntegrationApplication{
  public:
    IntegrationApplication(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> icon = uninitialized,
        field<std::string> description = uninitialized,
        omittable_field<User> bot = omitted
    ):
        id(id),
        name(name),
        icon(icon),
        description(description),
        bot(bot)
    {}
    IntegrationApplication(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    field<std::string> description;
    omittable_field<User> bot;

    friend void to_json(nlohmann::json &j, const IntegrationApplication &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.bot.is_omitted()) {j["bot"] = t.bot;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationApplication &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("icon")){j.at("icon").get_to(t.icon);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("bot")){j.at("bot").get_to(t.bot);}
    }
};

// https://discord.com/developers/docs/resources/guild#ban-object-ban-structure
class Ban{
  public:
    Ban(
        nullable_field<std::string> reason = uninitialized,
        field<User> user = uninitialized
    ):
        reason(reason),
        user(user)
    {}
    Ban(const json &j) { from_json(j, *this); }
    
    nullable_field<std::string> reason;
    field<User> user;

    friend void to_json(nlohmann::json &j, const Ban &t) {
        if(!t.reason.is_omitted()) {j["reason"] = t.reason;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, Ban &t) {
        if(j.contains("reason")){j.at("reason").get_to(t.reason);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
    }
};

// https://discord.com/developers/docs/resources/guild#welcome-screen-object-welcome-screen-structure
class WelcomeScreen{
  public:
    WelcomeScreen(
        nullable_field<std::string> description = uninitialized,
        field<std::vector<WelcomeScreenChannel> > welcome_channels = uninitialized
    ):
        description(description),
        welcome_channels(welcome_channels)
    {}
    WelcomeScreen(const json &j) { from_json(j, *this); }
    
    nullable_field<std::string> description;
    field<std::vector<WelcomeScreenChannel> > welcome_channels;

    friend void to_json(nlohmann::json &j, const WelcomeScreen &t) {
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.welcome_channels.is_omitted()) {j["welcome_channels"] = t.welcome_channels;}
    }
    friend void from_json(const nlohmann::json &j, WelcomeScreen &t) {
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("welcome_channels")){j.at("welcome_channels").get_to(t.welcome_channels);}
    }
};

// https://discord.com/developers/docs/resources/guild#welcome-screen-object-welcome-screen-channel-structure
class WelcomeScreenChannel{
  public:
    WelcomeScreenChannel(
        field<Snowflake> channel_id = uninitialized,
        field<std::string> description = uninitialized,
        nullable_field<Snowflake> emoji_id = uninitialized,
        nullable_field<std::string> emoji_name = uninitialized
    ):
        channel_id(channel_id),
        description(description),
        emoji_id(emoji_id),
        emoji_name(emoji_name)
    {}
    WelcomeScreenChannel(const json &j) { from_json(j, *this); }
    
    field<Snowflake> channel_id;
    field<std::string> description;
    nullable_field<Snowflake> emoji_id;
    nullable_field<std::string> emoji_name;

    friend void to_json(nlohmann::json &j, const WelcomeScreenChannel &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.emoji_id.is_omitted()) {j["emoji_id"] = t.emoji_id;}
        if(!t.emoji_name.is_omitted()) {j["emoji_name"] = t.emoji_name;}
    }
    friend void from_json(const nlohmann::json &j, WelcomeScreenChannel &t) {
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("emoji_id")){j.at("emoji_id").get_to(t.emoji_id);}
        if(j.contains("emoji_name")){j.at("emoji_name").get_to(t.emoji_name);}
    }
};

// https://discord.com/developers/docs/resources/guild#list-active-guild-threads-response-body
class ListActiveGuildThreadsResponse{
  public:
    ListActiveGuildThreadsResponse(
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<ThreadMember> > members = uninitialized
    ):
        threads(threads),
        members(members)
    {}
    ListActiveGuildThreadsResponse(const json &j) { from_json(j, *this); }
    
    field<std::vector<Channel> > threads;
    field<std::vector<ThreadMember> > members;

    friend void to_json(nlohmann::json &j, const ListActiveGuildThreadsResponse &t) {
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
    }
    friend void from_json(const nlohmann::json &j, ListActiveGuildThreadsResponse &t) {
        if(j.contains("threads")){j.at("threads").get_to(t.threads);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
    }
};

// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-object-guild-scheduled-event-structure
class GuildScheduledEvent{
  public:
    GuildScheduledEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        nullable_field<Snowflake> channel_id = uninitialized,
        nullable_omittable_field<Snowflake> creator_id = omitted,
        field<std::string> name = uninitialized,
        nullable_omittable_field<std::string> description = omitted,
        field<Timestamp> scheduled_start_time = uninitialized,
        nullable_field<Timestamp> scheduled_end_time = uninitialized,
        field<GuildScheduledEventPrivacyLevel> privacy_level = uninitialized,
        field<GuildScheduledEventStatus> status = uninitialized,
        field<GuildScheduledEventEntityType> entity_type = uninitialized,
        nullable_field<Snowflake> entity_id = uninitialized,
        nullable_field<GuildScheduledEventEntityMetadata> entity_metadata = uninitialized,
        omittable_field<User> creator = omitted,
        omittable_field<int> user_count = omitted,
        nullable_omittable_field<std::string> image = omitted
    ):
        id(id),
        guild_id(guild_id),
        channel_id(channel_id),
        creator_id(creator_id),
        name(name),
        description(description),
        scheduled_start_time(scheduled_start_time),
        scheduled_end_time(scheduled_end_time),
        privacy_level(privacy_level),
        status(status),
        entity_type(entity_type),
        entity_id(entity_id),
        entity_metadata(entity_metadata),
        creator(creator),
        user_count(user_count),
        image(image)
    {}
    GuildScheduledEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    nullable_omittable_field<Snowflake> creator_id;
    field<std::string> name;
    nullable_omittable_field<std::string> description;
    field<Timestamp> scheduled_start_time;
    nullable_field<Timestamp> scheduled_end_time;
    field<GuildScheduledEventPrivacyLevel> privacy_level;
    field<GuildScheduledEventStatus> status;
    field<GuildScheduledEventEntityType> entity_type;
    nullable_field<Snowflake> entity_id;
    nullable_field<GuildScheduledEventEntityMetadata> entity_metadata;
    omittable_field<User> creator;
    omittable_field<int> user_count;
    nullable_omittable_field<std::string> image;

    friend void to_json(nlohmann::json &j, const GuildScheduledEvent &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.creator_id.is_omitted()) {j["creator_id"] = t.creator_id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.scheduled_start_time.is_omitted()) {j["scheduled_start_time"] = t.scheduled_start_time;}
        if(!t.scheduled_end_time.is_omitted()) {j["scheduled_end_time"] = t.scheduled_end_time;}
        if(!t.privacy_level.is_omitted()) {j["privacy_level"] = t.privacy_level;}
        if(!t.status.is_omitted()) {j["status"] = t.status;}
        if(!t.entity_type.is_omitted()) {j["entity_type"] = t.entity_type;}
        if(!t.entity_id.is_omitted()) {j["entity_id"] = t.entity_id;}
        if(!t.entity_metadata.is_omitted()) {j["entity_metadata"] = t.entity_metadata;}
        if(!t.creator.is_omitted()) {j["creator"] = t.creator;}
        if(!t.user_count.is_omitted()) {j["user_count"] = t.user_count;}
        if(!t.image.is_omitted()) {j["image"] = t.image;}
    }
    friend void from_json(const nlohmann::json &j, GuildScheduledEvent &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("creator_id")){j.at("creator_id").get_to(t.creator_id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("scheduled_start_time")){j.at("scheduled_start_time").get_to(t.scheduled_start_time);}
        if(j.contains("scheduled_end_time")){j.at("scheduled_end_time").get_to(t.scheduled_end_time);}
        if(j.contains("privacy_level")){j.at("privacy_level").get_to(t.privacy_level);}
        if(j.contains("status")){j.at("status").get_to(t.status);}
        if(j.contains("entity_type")){j.at("entity_type").get_to(t.entity_type);}
        if(j.contains("entity_id")){j.at("entity_id").get_to(t.entity_id);}
        if(j.contains("entity_metadata")){j.at("entity_metadata").get_to(t.entity_metadata);}
        if(j.contains("creator")){j.at("creator").get_to(t.creator);}
        if(j.contains("user_count")){j.at("user_count").get_to(t.user_count);}
        if(j.contains("image")){j.at("image").get_to(t.image);}
    }
};

// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-object-guild-scheduled-event-entity-metadata
class GuildScheduledEventEntityMetadata{
  public:
    GuildScheduledEventEntityMetadata(
        omittable_field<std::string> location = omitted
    ):
        location(location)
    {}
    GuildScheduledEventEntityMetadata(const json &j) { from_json(j, *this); }
    
    omittable_field<std::string> location;

    friend void to_json(nlohmann::json &j, const GuildScheduledEventEntityMetadata &t) {
        if(!t.location.is_omitted()) {j["location"] = t.location;}
    }
    friend void from_json(const nlohmann::json &j, GuildScheduledEventEntityMetadata &t) {
        if(j.contains("location")){j.at("location").get_to(t.location);}
    }
};

// https://discord.com/developers/docs/resources/guild-scheduled-event#guild-scheduled-event-user-object-guild-scheduled-event-user-structure
class GuildScheduledEventUser{
  public:
    GuildScheduledEventUser(
        field<Snowflake> guild_scheduled_event_id = uninitialized,
        field<User> user = uninitialized,
        omittable_field<GuildMember> member = omitted
    ):
        guild_scheduled_event_id(guild_scheduled_event_id),
        user(user),
        member(member)
    {}
    GuildScheduledEventUser(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_scheduled_event_id;
    field<User> user;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const GuildScheduledEventUser &t) {
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
    }
    friend void from_json(const nlohmann::json &j, GuildScheduledEventUser &t) {
        if(j.contains("guild_scheduled_event_id")){j.at("guild_scheduled_event_id").get_to(t.guild_scheduled_event_id);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
    }
};

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
    GuildTemplate(const json &j) { from_json(j, *this); }
    
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

// https://discord.com/developers/docs/resources/invite#invite-object-invite-structure
class Invite{
  public:
    Invite(
        field<std::string> code = uninitialized,
        omittable_field<Guild> guild = omitted,
        nullable_field<Channel> channel = uninitialized,
        omittable_field<User> inviter = omitted,
        omittable_field<int> target_type = omitted,
        omittable_field<User> target_user = omitted,
        omittable_field<Application> target_application = omitted,
        omittable_field<int> approximate_presence_count = omitted,
        omittable_field<int> approximate_member_count = omitted,
        nullable_omittable_field<Timestamp> expires_at = omitted,
        omittable_field<InviteStageInstance> stage_instance = omitted,
        omittable_field<GuildScheduledEvent> guild_scheduled_event = omitted
    ):
        code(code),
        guild(guild),
        channel(channel),
        inviter(inviter),
        target_type(target_type),
        target_user(target_user),
        target_application(target_application),
        approximate_presence_count(approximate_presence_count),
        approximate_member_count(approximate_member_count),
        expires_at(expires_at),
        stage_instance(stage_instance),
        guild_scheduled_event(guild_scheduled_event)
    {}
    Invite(const json &j) { from_json(j, *this); }
    
    field<std::string> code;
    omittable_field<Guild> guild;
    nullable_field<Channel> channel;
    omittable_field<User> inviter;
    omittable_field<int> target_type;
    omittable_field<User> target_user;
    omittable_field<Application> target_application;
    omittable_field<int> approximate_presence_count;
    omittable_field<int> approximate_member_count;
    nullable_omittable_field<Timestamp> expires_at;
    omittable_field<InviteStageInstance> stage_instance;
    omittable_field<GuildScheduledEvent> guild_scheduled_event;

    friend void to_json(nlohmann::json &j, const Invite &t) {
        if(!t.code.is_omitted()) {j["code"] = t.code;}
        if(!t.guild.is_omitted()) {j["guild"] = t.guild;}
        if(!t.channel.is_omitted()) {j["channel"] = t.channel;}
        if(!t.inviter.is_omitted()) {j["inviter"] = t.inviter;}
        if(!t.target_type.is_omitted()) {j["target_type"] = t.target_type;}
        if(!t.target_user.is_omitted()) {j["target_user"] = t.target_user;}
        if(!t.target_application.is_omitted()) {j["target_application"] = t.target_application;}
        if(!t.approximate_presence_count.is_omitted()) {j["approximate_presence_count"] = t.approximate_presence_count;}
        if(!t.approximate_member_count.is_omitted()) {j["approximate_member_count"] = t.approximate_member_count;}
        if(!t.expires_at.is_omitted()) {j["expires_at"] = t.expires_at;}
        if(!t.stage_instance.is_omitted()) {j["stage_instance"] = t.stage_instance;}
        if(!t.guild_scheduled_event.is_omitted()) {j["guild_scheduled_event"] = t.guild_scheduled_event;}
    }
    friend void from_json(const nlohmann::json &j, Invite &t) {
        if(j.contains("code")){j.at("code").get_to(t.code);}
        if(j.contains("guild")){j.at("guild").get_to(t.guild);}
        if(j.contains("channel")){j.at("channel").get_to(t.channel);}
        if(j.contains("inviter")){j.at("inviter").get_to(t.inviter);}
        if(j.contains("target_type")){j.at("target_type").get_to(t.target_type);}
        if(j.contains("target_user")){j.at("target_user").get_to(t.target_user);}
        if(j.contains("target_application")){j.at("target_application").get_to(t.target_application);}
        if(j.contains("approximate_presence_count")){j.at("approximate_presence_count").get_to(t.approximate_presence_count);}
        if(j.contains("approximate_member_count")){j.at("approximate_member_count").get_to(t.approximate_member_count);}
        if(j.contains("expires_at")){j.at("expires_at").get_to(t.expires_at);}
        if(j.contains("stage_instance")){j.at("stage_instance").get_to(t.stage_instance);}
        if(j.contains("guild_scheduled_event")){j.at("guild_scheduled_event").get_to(t.guild_scheduled_event);}
    }
};

// https://discord.com/developers/docs/resources/invite#invite-metadata-object-invite-metadata-structure
class InviteMetadata{
  public:
    InviteMetadata(
        field<int> uses = uninitialized,
        field<int> max_uses = uninitialized,
        field<int> max_age = uninitialized,
        field<bool> temporary = uninitialized,
        field<Timestamp> created_at = uninitialized
    ):
        uses(uses),
        max_uses(max_uses),
        max_age(max_age),
        temporary(temporary),
        created_at(created_at)
    {}
    InviteMetadata(const json &j) { from_json(j, *this); }
    
    field<int> uses;
    field<int> max_uses;
    field<int> max_age;
    field<bool> temporary;
    field<Timestamp> created_at;

    friend void to_json(nlohmann::json &j, const InviteMetadata &t) {
        if(!t.uses.is_omitted()) {j["uses"] = t.uses;}
        if(!t.max_uses.is_omitted()) {j["max_uses"] = t.max_uses;}
        if(!t.max_age.is_omitted()) {j["max_age"] = t.max_age;}
        if(!t.temporary.is_omitted()) {j["temporary"] = t.temporary;}
        if(!t.created_at.is_omitted()) {j["created_at"] = t.created_at;}
    }
    friend void from_json(const nlohmann::json &j, InviteMetadata &t) {
        if(j.contains("uses")){j.at("uses").get_to(t.uses);}
        if(j.contains("max_uses")){j.at("max_uses").get_to(t.max_uses);}
        if(j.contains("max_age")){j.at("max_age").get_to(t.max_age);}
        if(j.contains("temporary")){j.at("temporary").get_to(t.temporary);}
        if(j.contains("created_at")){j.at("created_at").get_to(t.created_at);}
    }
};

// https://discord.com/developers/docs/resources/invite#invite-stage-instance-object-invite-stage-instance-structure
class InviteStageInstance{
  public:
    InviteStageInstance(
        field<std::vector<GuildMember> > members = uninitialized,
        field<int> participant_count = uninitialized,
        field<int> speaker_count = uninitialized,
        field<std::string> topic = uninitialized
    ):
        members(members),
        participant_count(participant_count),
        speaker_count(speaker_count),
        topic(topic)
    {}
    InviteStageInstance(const json &j) { from_json(j, *this); }
    
    field<std::vector<GuildMember> > members;
    field<int> participant_count;
    field<int> speaker_count;
    field<std::string> topic;

    friend void to_json(nlohmann::json &j, const InviteStageInstance &t) {
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.participant_count.is_omitted()) {j["participant_count"] = t.participant_count;}
        if(!t.speaker_count.is_omitted()) {j["speaker_count"] = t.speaker_count;}
        if(!t.topic.is_omitted()) {j["topic"] = t.topic;}
    }
    friend void from_json(const nlohmann::json &j, InviteStageInstance &t) {
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("participant_count")){j.at("participant_count").get_to(t.participant_count);}
        if(j.contains("speaker_count")){j.at("speaker_count").get_to(t.speaker_count);}
        if(j.contains("topic")){j.at("topic").get_to(t.topic);}
    }
};

// https://discord.com/developers/docs/resources/stage-instance#stage-instance-object-stage-instance-structure
class StageInstance{
  public:
    StageInstance(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<std::string> topic = uninitialized,
        field<int> privacy_level = uninitialized,
        field<bool> discoverable_disabled = uninitialized,
        nullable_field<Snowflake> guild_scheduled_event_id = uninitialized
    ):
        id(id),
        guild_id(guild_id),
        channel_id(channel_id),
        topic(topic),
        privacy_level(privacy_level),
        discoverable_disabled(discoverable_disabled),
        guild_scheduled_event_id(guild_scheduled_event_id)
    {}
    StageInstance(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<Snowflake> channel_id;
    field<std::string> topic;
    field<int> privacy_level;
    field<bool> discoverable_disabled;
    nullable_field<Snowflake> guild_scheduled_event_id;

    friend void to_json(nlohmann::json &j, const StageInstance &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.topic.is_omitted()) {j["topic"] = t.topic;}
        if(!t.privacy_level.is_omitted()) {j["privacy_level"] = t.privacy_level;}
        if(!t.discoverable_disabled.is_omitted()) {j["discoverable_disabled"] = t.discoverable_disabled;}
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
    }
    friend void from_json(const nlohmann::json &j, StageInstance &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("topic")){j.at("topic").get_to(t.topic);}
        if(j.contains("privacy_level")){j.at("privacy_level").get_to(t.privacy_level);}
        if(j.contains("discoverable_disabled")){j.at("discoverable_disabled").get_to(t.discoverable_disabled);}
        if(j.contains("guild_scheduled_event_id")){j.at("guild_scheduled_event_id").get_to(t.guild_scheduled_event_id);}
    }
};

// https://discord.com/developers/docs/resources/sticker#sticker-object-sticker-structure
class Sticker{
  public:
    Sticker(
        field<Snowflake> id = uninitialized,
        omittable_field<Snowflake> pack_id = omitted,
        field<std::string> name = uninitialized,
        nullable_field<std::string> description = uninitialized,
        field<std::string> tags = uninitialized,
        omittable_field<std::string> asset = omitted,
        field<int> type = uninitialized,
        field<int> format_type = uninitialized,
        omittable_field<bool> available = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<User> user = omitted,
        omittable_field<int> sort_value = omitted
    ):
        id(id),
        pack_id(pack_id),
        name(name),
        description(description),
        tags(tags),
        asset(asset),
        type(type),
        format_type(format_type),
        available(available),
        guild_id(guild_id),
        user(user),
        sort_value(sort_value)
    {}
    Sticker(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    omittable_field<Snowflake> pack_id;
    field<std::string> name;
    nullable_field<std::string> description;
    field<std::string> tags;
    omittable_field<std::string> asset;
    field<int> type;
    field<int> format_type;
    omittable_field<bool> available;
    omittable_field<Snowflake> guild_id;
    omittable_field<User> user;
    omittable_field<int> sort_value;

    friend void to_json(nlohmann::json &j, const Sticker &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.pack_id.is_omitted()) {j["pack_id"] = t.pack_id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.tags.is_omitted()) {j["tags"] = t.tags;}
        if(!t.asset.is_omitted()) {j["asset"] = t.asset;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.format_type.is_omitted()) {j["format_type"] = t.format_type;}
        if(!t.available.is_omitted()) {j["available"] = t.available;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.sort_value.is_omitted()) {j["sort_value"] = t.sort_value;}
    }
    friend void from_json(const nlohmann::json &j, Sticker &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("pack_id")){j.at("pack_id").get_to(t.pack_id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("tags")){j.at("tags").get_to(t.tags);}
        if(j.contains("asset")){j.at("asset").get_to(t.asset);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("format_type")){j.at("format_type").get_to(t.format_type);}
        if(j.contains("available")){j.at("available").get_to(t.available);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("sort_value")){j.at("sort_value").get_to(t.sort_value);}
    }
};

// https://discord.com/developers/docs/resources/sticker#sticker-item-object-sticker-item-structure
class StickerItem{
  public:
    StickerItem(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<int> format_type = uninitialized
    ):
        id(id),
        name(name),
        format_type(format_type)
    {}
    StickerItem(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    field<int> format_type;

    friend void to_json(nlohmann::json &j, const StickerItem &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.format_type.is_omitted()) {j["format_type"] = t.format_type;}
    }
    friend void from_json(const nlohmann::json &j, StickerItem &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("format_type")){j.at("format_type").get_to(t.format_type);}
    }
};

// https://discord.com/developers/docs/resources/sticker#sticker-pack-object-sticker-pack-structure
class StickerPack{
  public:
    StickerPack(
        field<Snowflake> id = uninitialized,
        field<std::vector<Sticker> > stickers = uninitialized,
        field<std::string> name = uninitialized,
        field<Snowflake> sku_id = uninitialized,
        omittable_field<Snowflake> cover_sticker_id = omitted,
        field<std::string> description = uninitialized,
        omittable_field<Snowflake> banner_asset_id = omitted
    ):
        id(id),
        stickers(stickers),
        name(name),
        sku_id(sku_id),
        cover_sticker_id(cover_sticker_id),
        description(description),
        banner_asset_id(banner_asset_id)
    {}
    StickerPack(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::vector<Sticker> > stickers;
    field<std::string> name;
    field<Snowflake> sku_id;
    omittable_field<Snowflake> cover_sticker_id;
    field<std::string> description;
    omittable_field<Snowflake> banner_asset_id;

    friend void to_json(nlohmann::json &j, const StickerPack &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.sku_id.is_omitted()) {j["sku_id"] = t.sku_id;}
        if(!t.cover_sticker_id.is_omitted()) {j["cover_sticker_id"] = t.cover_sticker_id;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.banner_asset_id.is_omitted()) {j["banner_asset_id"] = t.banner_asset_id;}
    }
    friend void from_json(const nlohmann::json &j, StickerPack &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("stickers")){j.at("stickers").get_to(t.stickers);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("sku_id")){j.at("sku_id").get_to(t.sku_id);}
        if(j.contains("cover_sticker_id")){j.at("cover_sticker_id").get_to(t.cover_sticker_id);}
        if(j.contains("description")){j.at("description").get_to(t.description);}
        if(j.contains("banner_asset_id")){j.at("banner_asset_id").get_to(t.banner_asset_id);}
    }
};

// https://discord.com/developers/docs/resources/sticker#list-nitro-sticker-packs-response-structure
class ListNitroStickerPacksResponse{
  public:
    ListNitroStickerPacksResponse(
        field<std::vector<StickerPack> > sticker_packs = uninitialized
    ):
        sticker_packs(sticker_packs)
    {}
    ListNitroStickerPacksResponse(const json &j) { from_json(j, *this); }
    
    field<std::vector<StickerPack> > sticker_packs;

    friend void to_json(nlohmann::json &j, const ListNitroStickerPacksResponse &t) {
        if(!t.sticker_packs.is_omitted()) {j["sticker_packs"] = t.sticker_packs;}
    }
    friend void from_json(const nlohmann::json &j, ListNitroStickerPacksResponse &t) {
        if(j.contains("sticker_packs")){j.at("sticker_packs").get_to(t.sticker_packs);}
    }
};

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
    User(const json &j) { from_json(j, *this); }
    
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
    friend void from_json(const nlohmann::json &j, User &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("username")){j.at("username").get_to(t.username);}
        if(j.contains("discriminator")){j.at("discriminator").get_to(t.discriminator);}
        if(j.contains("avatar")){j.at("avatar").get_to(t.avatar);}
        if(j.contains("bot")){j.at("bot").get_to(t.bot);}
        if(j.contains("system")){j.at("system").get_to(t.system);}
        if(j.contains("mfa_enabled")){j.at("mfa_enabled").get_to(t.mfa_enabled);}
        if(j.contains("banner")){j.at("banner").get_to(t.banner);}
        if(j.contains("accent_color")){j.at("accent_color").get_to(t.accent_color);}
        if(j.contains("locale")){j.at("locale").get_to(t.locale);}
        if(j.contains("verified")){j.at("verified").get_to(t.verified);}
        if(j.contains("email")){j.at("email").get_to(t.email);}
        if(j.contains("flags")){j.at("flags").get_to(t.flags);}
        if(j.contains("premium_type")){j.at("premium_type").get_to(t.premium_type);}
        if(j.contains("public_flags")){j.at("public_flags").get_to(t.public_flags);}
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
    Connection(const json &j) { from_json(j, *this); }
    
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
    friend void from_json(const nlohmann::json &j, Connection &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("revoked")){j.at("revoked").get_to(t.revoked);}
        if(j.contains("integrations")){j.at("integrations").get_to(t.integrations);}
        if(j.contains("verified")){j.at("verified").get_to(t.verified);}
        if(j.contains("friend_sync")){j.at("friend_sync").get_to(t.friend_sync);}
        if(j.contains("show_activity")){j.at("show_activity").get_to(t.show_activity);}
        if(j.contains("two_way_link")){j.at("two_way_link").get_to(t.two_way_link);}
        if(j.contains("visibility")){j.at("visibility").get_to(t.visibility);}
    }
};

// https://discord.com/developers/docs/resources/user#application-role-connection-object-application-role-connection-structure
class ApplicationRoleConnection{
  public:
    ApplicationRoleConnection(
        nullable_field<std::string> platform_name = uninitialized,
        nullable_field<std::string> platform_username = uninitialized,
        field<ApplicationRoleConnectionMetadata> metadata = uninitialized
    ):
        platform_name(platform_name),
        platform_username(platform_username),
        metadata(metadata)
    {}
    ApplicationRoleConnection(const json &j) { from_json(j, *this); }
    
    nullable_field<std::string> platform_name;
    nullable_field<std::string> platform_username;
    field<ApplicationRoleConnectionMetadata> metadata;

    friend void to_json(nlohmann::json &j, const ApplicationRoleConnection &t) {
        if(!t.platform_name.is_omitted()) {j["platform_name"] = t.platform_name;}
        if(!t.platform_username.is_omitted()) {j["platform_username"] = t.platform_username;}
        if(!t.metadata.is_omitted()) {j["metadata"] = t.metadata;}
    }
    friend void from_json(const nlohmann::json &j, ApplicationRoleConnection &t) {
        if(j.contains("platform_name")){j.at("platform_name").get_to(t.platform_name);}
        if(j.contains("platform_username")){j.at("platform_username").get_to(t.platform_username);}
        if(j.contains("metadata")){j.at("metadata").get_to(t.metadata);}
    }
};

// https://discord.com/developers/docs/resources/voice#voice-state-object-voice-state-structure
class VoiceState{
  public:
    VoiceState(
        omittable_field<Snowflake> guild_id = omitted,
        nullable_field<Snowflake> channel_id = uninitialized,
        field<Snowflake> user_id = uninitialized,
        omittable_field<GuildMember> member = omitted,
        field<std::string> session_id = uninitialized,
        field<bool> deaf = uninitialized,
        field<bool> mute = uninitialized,
        field<bool> self_deaf = uninitialized,
        field<bool> self_mute = uninitialized,
        omittable_field<bool> self_stream = omitted,
        field<bool> self_video = uninitialized,
        field<bool> suppress = uninitialized,
        nullable_field<Timestamp> request_to_speak_timestamp = uninitialized
    ):
        guild_id(guild_id),
        channel_id(channel_id),
        user_id(user_id),
        member(member),
        session_id(session_id),
        deaf(deaf),
        mute(mute),
        self_deaf(self_deaf),
        self_mute(self_mute),
        self_stream(self_stream),
        self_video(self_video),
        suppress(suppress),
        request_to_speak_timestamp(request_to_speak_timestamp)
    {}
    VoiceState(const json &j) { from_json(j, *this); }
    
    omittable_field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    field<Snowflake> user_id;
    omittable_field<GuildMember> member;
    field<std::string> session_id;
    field<bool> deaf;
    field<bool> mute;
    field<bool> self_deaf;
    field<bool> self_mute;
    omittable_field<bool> self_stream;
    field<bool> self_video;
    field<bool> suppress;
    nullable_field<Timestamp> request_to_speak_timestamp;

    friend void to_json(nlohmann::json &j, const VoiceState &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.session_id.is_omitted()) {j["session_id"] = t.session_id;}
        if(!t.deaf.is_omitted()) {j["deaf"] = t.deaf;}
        if(!t.mute.is_omitted()) {j["mute"] = t.mute;}
        if(!t.self_deaf.is_omitted()) {j["self_deaf"] = t.self_deaf;}
        if(!t.self_mute.is_omitted()) {j["self_mute"] = t.self_mute;}
        if(!t.self_stream.is_omitted()) {j["self_stream"] = t.self_stream;}
        if(!t.self_video.is_omitted()) {j["self_video"] = t.self_video;}
        if(!t.suppress.is_omitted()) {j["suppress"] = t.suppress;}
        if(!t.request_to_speak_timestamp.is_omitted()) {j["request_to_speak_timestamp"] = t.request_to_speak_timestamp;}
    }
    friend void from_json(const nlohmann::json &j, VoiceState &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
        if(j.contains("session_id")){j.at("session_id").get_to(t.session_id);}
        if(j.contains("deaf")){j.at("deaf").get_to(t.deaf);}
        if(j.contains("mute")){j.at("mute").get_to(t.mute);}
        if(j.contains("self_deaf")){j.at("self_deaf").get_to(t.self_deaf);}
        if(j.contains("self_mute")){j.at("self_mute").get_to(t.self_mute);}
        if(j.contains("self_stream")){j.at("self_stream").get_to(t.self_stream);}
        if(j.contains("self_video")){j.at("self_video").get_to(t.self_video);}
        if(j.contains("suppress")){j.at("suppress").get_to(t.suppress);}
        if(j.contains("request_to_speak_timestamp")){j.at("request_to_speak_timestamp").get_to(t.request_to_speak_timestamp);}
    }
};

// https://discord.com/developers/docs/resources/voice#voice-region-object-voice-region-structure
class VoiceRegion{
  public:
    VoiceRegion(
        field<std::string> id = uninitialized,
        field<std::string> name = uninitialized,
        field<bool> optimal = uninitialized,
        field<bool> deprecated = uninitialized,
        field<bool> custom = uninitialized
    ):
        id(id),
        name(name),
        optimal(optimal),
        deprecated(deprecated),
        custom(custom)
    {}
    VoiceRegion(const json &j) { from_json(j, *this); }
    
    field<std::string> id;
    field<std::string> name;
    field<bool> optimal;
    field<bool> deprecated;
    field<bool> custom;

    friend void to_json(nlohmann::json &j, const VoiceRegion &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.optimal.is_omitted()) {j["optimal"] = t.optimal;}
        if(!t.deprecated.is_omitted()) {j["deprecated"] = t.deprecated;}
        if(!t.custom.is_omitted()) {j["custom"] = t.custom;}
    }
    friend void from_json(const nlohmann::json &j, VoiceRegion &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("optimal")){j.at("optimal").get_to(t.optimal);}
        if(j.contains("deprecated")){j.at("deprecated").get_to(t.deprecated);}
        if(j.contains("custom")){j.at("custom").get_to(t.custom);}
    }
};

// https://discord.com/developers/docs/resources/webhook#webhook-object-webhook-structure
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
    Webhook(const json &j) { from_json(j, *this); }
    
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
    friend void from_json(const nlohmann::json &j, Webhook &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("avatar")){j.at("avatar").get_to(t.avatar);}
        if(j.contains("token")){j.at("token").get_to(t.token);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("source_guild")){j.at("source_guild").get_to(t.source_guild);}
        if(j.contains("source_channel")){j.at("source_channel").get_to(t.source_channel);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
    }
};

// https://discord.com/developers/docs/topics/gateway#get-gateway-bot-json-response
class GetGatewayBotResponse{
  public:
    GetGatewayBotResponse(
        field<std::string> url = uninitialized,
        field<int> shards = uninitialized,
        field<SessionStartLimit> session_start_limit = uninitialized
    ):
        url(url),
        shards(shards),
        session_start_limit(session_start_limit)
    {}
    GetGatewayBotResponse(const json &j) { from_json(j, *this); }
    
    field<std::string> url;
    field<int> shards;
    field<SessionStartLimit> session_start_limit;

    friend void to_json(nlohmann::json &j, const GetGatewayBotResponse &t) {
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.shards.is_omitted()) {j["shards"] = t.shards;}
        if(!t.session_start_limit.is_omitted()) {j["session_start_limit"] = t.session_start_limit;}
    }
    friend void from_json(const nlohmann::json &j, GetGatewayBotResponse &t) {
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("shards")){j.at("shards").get_to(t.shards);}
        if(j.contains("session_start_limit")){j.at("session_start_limit").get_to(t.session_start_limit);}
    }
};

// https://discord.com/developers/docs/topics/gateway#session-start-limit-object-session-start-limit-structure
class SessionStartLimit{
  public:
    SessionStartLimit(
        field<int> total = uninitialized,
        field<int> remaining = uninitialized,
        field<int> reset_after = uninitialized,
        field<int> max_concurrency = uninitialized
    ):
        total(total),
        remaining(remaining),
        reset_after(reset_after),
        max_concurrency(max_concurrency)
    {}
    SessionStartLimit(const json &j) { from_json(j, *this); }
    
    field<int> total;
    field<int> remaining;
    field<int> reset_after;
    field<int> max_concurrency;

    friend void to_json(nlohmann::json &j, const SessionStartLimit &t) {
        if(!t.total.is_omitted()) {j["total"] = t.total;}
        if(!t.remaining.is_omitted()) {j["remaining"] = t.remaining;}
        if(!t.reset_after.is_omitted()) {j["reset_after"] = t.reset_after;}
        if(!t.max_concurrency.is_omitted()) {j["max_concurrency"] = t.max_concurrency;}
    }
    friend void from_json(const nlohmann::json &j, SessionStartLimit &t) {
        if(j.contains("total")){j.at("total").get_to(t.total);}
        if(j.contains("remaining")){j.at("remaining").get_to(t.remaining);}
        if(j.contains("reset_after")){j.at("reset_after").get_to(t.reset_after);}
        if(j.contains("max_concurrency")){j.at("max_concurrency").get_to(t.max_concurrency);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#payload-structure
class Payload{
  public:
    Payload(
        field<int> op = uninitialized,
        nullable_field<json> d = uninitialized,
        nullable_field<int> s = uninitialized,
        nullable_field<std::string> t = uninitialized
    ):
        op(op),
        d(d),
        s(s),
        t(t)
    {}
    Payload(const json &j) { from_json(j, *this); }
    
    field<int> op;
    nullable_field<json> d;
    nullable_field<int> s;
    nullable_field<std::string> t;

    friend void to_json(nlohmann::json &j, const Payload &t) {
        if(!t.op.is_omitted()) {j["op"] = t.op;}
        if(!t.d.is_omitted()) {j["d"] = t.d;}
        if(!t.s.is_omitted()) {j["s"] = t.s;}
        if(!t.t.is_omitted()) {j["t"] = t.t;}
    }
    friend void from_json(const nlohmann::json &j, Payload &t) {
        if(j.contains("op")){j.at("op").get_to(t.op);}
        if(j.contains("d")){j.at("d").get_to(t.d);}
        if(j.contains("s")){j.at("s").get_to(t.s);}
        if(j.contains("t")){j.at("t").get_to(t.t);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#identify-identify-structure
class Identify{
  public:
    Identify(
        field<std::string> token = uninitialized,
        field<IdentifyConnectionProperties> properties = uninitialized,
        omittable_field<bool> compress = omitted,
        omittable_field<int> large_threshold = omitted,
        omittable_field<std::array<int, 2>> shard = omitted,
        omittable_field<GatewayPresenceUpdate> presence = omitted,
        field<int> intents = uninitialized
    ):
        token(token),
        properties(properties),
        compress(compress),
        large_threshold(large_threshold),
        shard(shard),
        presence(presence),
        intents(intents)
    {}
    Identify(const json &j) { from_json(j, *this); }
    
    field<std::string> token;
    field<IdentifyConnectionProperties> properties;
    omittable_field<bool> compress;
    omittable_field<int> large_threshold;
    omittable_field<std::array<int, 2>> shard;
    omittable_field<GatewayPresenceUpdate> presence;
    field<int> intents;

    friend void to_json(nlohmann::json &j, const Identify &t) {
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.properties.is_omitted()) {j["properties"] = t.properties;}
        if(!t.compress.is_omitted()) {j["compress"] = t.compress;}
        if(!t.large_threshold.is_omitted()) {j["large_threshold"] = t.large_threshold;}
        if(!t.shard.is_omitted()) {j["shard"] = t.shard;}
        if(!t.presence.is_omitted()) {j["presence"] = t.presence;}
        if(!t.intents.is_omitted()) {j["intents"] = t.intents;}
    }
    friend void from_json(const nlohmann::json &j, Identify &t) {
        if(j.contains("token")){j.at("token").get_to(t.token);}
        if(j.contains("properties")){j.at("properties").get_to(t.properties);}
        if(j.contains("compress")){j.at("compress").get_to(t.compress);}
        if(j.contains("large_threshold")){j.at("large_threshold").get_to(t.large_threshold);}
        if(j.contains("shard")){j.at("shard").get_to(t.shard);}
        if(j.contains("presence")){j.at("presence").get_to(t.presence);}
        if(j.contains("intents")){j.at("intents").get_to(t.intents);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#identify-identify-connection-properties
class IdentifyConnectionProperties{
  public:
    IdentifyConnectionProperties(
        field<std::string> os = uninitialized,
        field<std::string> browser = uninitialized,
        field<std::string> device = uninitialized
    ):
        os(os),
        browser(browser),
        device(device)
    {}
    IdentifyConnectionProperties(const json &j) { from_json(j, *this); }
    
    field<std::string> os;
    field<std::string> browser;
    field<std::string> device;

    friend void to_json(nlohmann::json &j, const IdentifyConnectionProperties &t) {
        if(!t.os.is_omitted()) {j["os"] = t.os;}
        if(!t.browser.is_omitted()) {j["browser"] = t.browser;}
        if(!t.device.is_omitted()) {j["device"] = t.device;}
    }
    friend void from_json(const nlohmann::json &j, IdentifyConnectionProperties &t) {
        if(j.contains("os")){j.at("os").get_to(t.os);}
        if(j.contains("browser")){j.at("browser").get_to(t.browser);}
        if(j.contains("device")){j.at("device").get_to(t.device);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#resume-resume-structure
class Resume{
  public:
    Resume(
        field<std::string> token = uninitialized,
        field<std::string> session_id = uninitialized,
        field<int> seq = uninitialized
    ):
        token(token),
        session_id(session_id),
        seq(seq)
    {}
    Resume(const json &j) { from_json(j, *this); }
    
    field<std::string> token;
    field<std::string> session_id;
    field<int> seq;

    friend void to_json(nlohmann::json &j, const Resume &t) {
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.session_id.is_omitted()) {j["session_id"] = t.session_id;}
        if(!t.seq.is_omitted()) {j["seq"] = t.seq;}
    }
    friend void from_json(const nlohmann::json &j, Resume &t) {
        if(j.contains("token")){j.at("token").get_to(t.token);}
        if(j.contains("session_id")){j.at("session_id").get_to(t.session_id);}
        if(j.contains("seq")){j.at("seq").get_to(t.seq);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#request-guild-members-guild-request-members-structure
class GuildRequestMembers{
  public:
    GuildRequestMembers(
        field<Snowflake> guild_id = uninitialized,
        omittable_field<std::string> query = omitted,
        field<int> limit = uninitialized,
        omittable_field<bool> presences = omitted,
        omittable_field<std::variant<Snowflake, std::vector<Snowflake> > > user_ids = omitted,
        omittable_field<std::string> nonce = omitted
    ):
        guild_id(guild_id),
        query(query),
        limit(limit),
        presences(presences),
        user_ids(user_ids),
        nonce(nonce)
    {}
    GuildRequestMembers(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    omittable_field<std::string> query;
    field<int> limit;
    omittable_field<bool> presences;
    omittable_field<std::variant<Snowflake, std::vector<Snowflake> > > user_ids;
    omittable_field<std::string> nonce;

    friend void to_json(nlohmann::json &j, const GuildRequestMembers &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.query.is_omitted()) {j["query"] = t.query;}
        if(!t.limit.is_omitted()) {j["limit"] = t.limit;}
        if(!t.presences.is_omitted()) {j["presences"] = t.presences;}
        if(!t.user_ids.is_omitted()) {j["user_ids"] = t.user_ids;}
        if(!t.nonce.is_omitted()) {j["nonce"] = t.nonce;}
    }
    friend void from_json(const nlohmann::json &j, GuildRequestMembers &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("query")){j.at("query").get_to(t.query);}
        if(j.contains("limit")){j.at("limit").get_to(t.limit);}
        if(j.contains("presences")){j.at("presences").get_to(t.presences);}
        if(j.contains("user_ids")){j.at("user_ids").get_to(t.user_ids);}
        if(j.contains("nonce")){j.at("nonce").get_to(t.nonce);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#update-voice-state-gateway-voice-state-update-structure
class GatewayVoiceStateUpdate{
  public:
    GatewayVoiceStateUpdate(
        field<Snowflake> guild_id = uninitialized,
        nullable_field<Snowflake> channel_id = uninitialized,
        field<bool> self_mute = uninitialized,
        field<bool> self_deaf = uninitialized
    ):
        guild_id(guild_id),
        channel_id(channel_id),
        self_mute(self_mute),
        self_deaf(self_deaf)
    {}
    GatewayVoiceStateUpdate(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    field<bool> self_mute;
    field<bool> self_deaf;

    friend void to_json(nlohmann::json &j, const GatewayVoiceStateUpdate &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.self_mute.is_omitted()) {j["self_mute"] = t.self_mute;}
        if(!t.self_deaf.is_omitted()) {j["self_deaf"] = t.self_deaf;}
    }
    friend void from_json(const nlohmann::json &j, GatewayVoiceStateUpdate &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("self_mute")){j.at("self_mute").get_to(t.self_mute);}
        if(j.contains("self_deaf")){j.at("self_deaf").get_to(t.self_deaf);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#update-presence-gateway-presence-update-structure
class GatewayPresenceUpdate{
  public:
    GatewayPresenceUpdate(
        nullable_field<int> since = uninitialized,
        field<std::vector<Activity> > activities = uninitialized,
        field<std::string> status = uninitialized,
        field<bool> afk = uninitialized
    ):
        since(since),
        activities(activities),
        status(status),
        afk(afk)
    {}
    GatewayPresenceUpdate(const json &j) { from_json(j, *this); }
    
    nullable_field<int> since;
    field<std::vector<Activity> > activities;
    field<std::string> status;
    field<bool> afk;

    friend void to_json(nlohmann::json &j, const GatewayPresenceUpdate &t) {
        if(!t.since.is_omitted()) {j["since"] = t.since;}
        if(!t.activities.is_omitted()) {j["activities"] = t.activities;}
        if(!t.status.is_omitted()) {j["status"] = t.status;}
        if(!t.afk.is_omitted()) {j["afk"] = t.afk;}
    }
    friend void from_json(const nlohmann::json &j, GatewayPresenceUpdate &t) {
        if(j.contains("since")){j.at("since").get_to(t.since);}
        if(j.contains("activities")){j.at("activities").get_to(t.activities);}
        if(j.contains("status")){j.at("status").get_to(t.status);}
        if(j.contains("afk")){j.at("afk").get_to(t.afk);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#hello-hello-structure
class Hello{
  public:
    Hello(
        field<int> heartbeat_interval = uninitialized
    ):
        heartbeat_interval(heartbeat_interval)
    {}
    Hello(const json &j) { from_json(j, *this); }
    
    field<int> heartbeat_interval;

    friend void to_json(nlohmann::json &j, const Hello &t) {
        if(!t.heartbeat_interval.is_omitted()) {j["heartbeat_interval"] = t.heartbeat_interval;}
    }
    friend void from_json(const nlohmann::json &j, Hello &t) {
        if(j.contains("heartbeat_interval")){j.at("heartbeat_interval").get_to(t.heartbeat_interval);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#ready-ready-event-fields
class ReadyEvent{
  public:
    ReadyEvent(
        field<int> v = uninitialized,
        field<User> user = uninitialized,
        field<std::vector<Guild> > guilds = uninitialized,
        field<std::string> session_id = uninitialized,
        field<std::string> resume_gateway_url = uninitialized,
        omittable_field<std::array<int, 2>> shard = omitted,
        field<Application> application = uninitialized
    ):
        v(v),
        user(user),
        guilds(guilds),
        session_id(session_id),
        resume_gateway_url(resume_gateway_url),
        shard(shard),
        application(application)
    {}
    ReadyEvent(const json &j) { from_json(j, *this); }
    
    field<int> v;
    field<User> user;
    field<std::vector<Guild> > guilds;
    field<std::string> session_id;
    field<std::string> resume_gateway_url;
    omittable_field<std::array<int, 2>> shard;
    field<Application> application;

    friend void to_json(nlohmann::json &j, const ReadyEvent &t) {
        if(!t.v.is_omitted()) {j["v"] = t.v;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.guilds.is_omitted()) {j["guilds"] = t.guilds;}
        if(!t.session_id.is_omitted()) {j["session_id"] = t.session_id;}
        if(!t.resume_gateway_url.is_omitted()) {j["resume_gateway_url"] = t.resume_gateway_url;}
        if(!t.shard.is_omitted()) {j["shard"] = t.shard;}
        if(!t.application.is_omitted()) {j["application"] = t.application;}
    }
    friend void from_json(const nlohmann::json &j, ReadyEvent &t) {
        if(j.contains("v")){j.at("v").get_to(t.v);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("guilds")){j.at("guilds").get_to(t.guilds);}
        if(j.contains("session_id")){j.at("session_id").get_to(t.session_id);}
        if(j.contains("resume_gateway_url")){j.at("resume_gateway_url").get_to(t.resume_gateway_url);}
        if(j.contains("shard")){j.at("shard").get_to(t.shard);}
        if(j.contains("application")){j.at("application").get_to(t.application);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#auto-moderation-action-execution-auto-moderation-action-execution-event-fields
class AutoModerationActionExecutionEvent{
  public:
    AutoModerationActionExecutionEvent(
        field<Snowflake> guild_id = uninitialized,
        field<AutoModerationAction> action = uninitialized,
        field<Snowflake> rule_id = uninitialized,
        field<TriggerType> rule_trigger_type = uninitialized,
        field<Snowflake> user_id = uninitialized,
        omittable_field<Snowflake> channel_id = omitted,
        omittable_field<Snowflake> message_id = omitted,
        omittable_field<Snowflake> alert_system_message_id = omitted,
        field<std::string> content = uninitialized,
        nullable_field<std::string> matched_keyword = uninitialized,
        nullable_field<std::string> matched_content = uninitialized
    ):
        guild_id(guild_id),
        action(action),
        rule_id(rule_id),
        rule_trigger_type(rule_trigger_type),
        user_id(user_id),
        channel_id(channel_id),
        message_id(message_id),
        alert_system_message_id(alert_system_message_id),
        content(content),
        matched_keyword(matched_keyword),
        matched_content(matched_content)
    {}
    AutoModerationActionExecutionEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<AutoModerationAction> action;
    field<Snowflake> rule_id;
    field<TriggerType> rule_trigger_type;
    field<Snowflake> user_id;
    omittable_field<Snowflake> channel_id;
    omittable_field<Snowflake> message_id;
    omittable_field<Snowflake> alert_system_message_id;
    field<std::string> content;
    nullable_field<std::string> matched_keyword;
    nullable_field<std::string> matched_content;

    friend void to_json(nlohmann::json &j, const AutoModerationActionExecutionEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.action.is_omitted()) {j["action"] = t.action;}
        if(!t.rule_id.is_omitted()) {j["rule_id"] = t.rule_id;}
        if(!t.rule_trigger_type.is_omitted()) {j["rule_trigger_type"] = t.rule_trigger_type;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.alert_system_message_id.is_omitted()) {j["alert_system_message_id"] = t.alert_system_message_id;}
        if(!t.content.is_omitted()) {j["content"] = t.content;}
        if(!t.matched_keyword.is_omitted()) {j["matched_keyword"] = t.matched_keyword;}
        if(!t.matched_content.is_omitted()) {j["matched_content"] = t.matched_content;}
    }
    friend void from_json(const nlohmann::json &j, AutoModerationActionExecutionEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("action")){j.at("action").get_to(t.action);}
        if(j.contains("rule_id")){j.at("rule_id").get_to(t.rule_id);}
        if(j.contains("rule_trigger_type")){j.at("rule_trigger_type").get_to(t.rule_trigger_type);}
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("message_id")){j.at("message_id").get_to(t.message_id);}
        if(j.contains("alert_system_message_id")){j.at("alert_system_message_id").get_to(t.alert_system_message_id);}
        if(j.contains("content")){j.at("content").get_to(t.content);}
        if(j.contains("matched_keyword")){j.at("matched_keyword").get_to(t.matched_keyword);}
        if(j.contains("matched_content")){j.at("matched_content").get_to(t.matched_content);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#thread-list-sync-thread-list-sync-event-fields
class ThreadListSyncEvent{
  public:
    ThreadListSyncEvent(
        field<Snowflake> guild_id = uninitialized,
        omittable_field<std::vector<Snowflake> > channel_ids = omitted,
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<ThreadMember> > members = uninitialized
    ):
        guild_id(guild_id),
        channel_ids(channel_ids),
        threads(threads),
        members(members)
    {}
    ThreadListSyncEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    omittable_field<std::vector<Snowflake> > channel_ids;
    field<std::vector<Channel> > threads;
    field<std::vector<ThreadMember> > members;

    friend void to_json(nlohmann::json &j, const ThreadListSyncEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_ids.is_omitted()) {j["channel_ids"] = t.channel_ids;}
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
    }
    friend void from_json(const nlohmann::json &j, ThreadListSyncEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_ids")){j.at("channel_ids").get_to(t.channel_ids);}
        if(j.contains("threads")){j.at("threads").get_to(t.threads);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#thread-members-update-thread-members-update-event-fields
class ThreadMembersUpdateEvent{
  public:
    ThreadMembersUpdateEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<int> member_count = uninitialized,
        omittable_field<std::vector<ThreadMember> > added_members = omitted,
        omittable_field<std::vector<Snowflake> > removed_member_ids = omitted
    ):
        id(id),
        guild_id(guild_id),
        member_count(member_count),
        added_members(added_members),
        removed_member_ids(removed_member_ids)
    {}
    ThreadMembersUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<int> member_count;
    omittable_field<std::vector<ThreadMember> > added_members;
    omittable_field<std::vector<Snowflake> > removed_member_ids;

    friend void to_json(nlohmann::json &j, const ThreadMembersUpdateEvent &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member_count.is_omitted()) {j["member_count"] = t.member_count;}
        if(!t.added_members.is_omitted()) {j["added_members"] = t.added_members;}
        if(!t.removed_member_ids.is_omitted()) {j["removed_member_ids"] = t.removed_member_ids;}
    }
    friend void from_json(const nlohmann::json &j, ThreadMembersUpdateEvent &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("member_count")){j.at("member_count").get_to(t.member_count);}
        if(j.contains("added_members")){j.at("added_members").get_to(t.added_members);}
        if(j.contains("removed_member_ids")){j.at("removed_member_ids").get_to(t.removed_member_ids);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#channel-pins-update-channel-pins-update-event-fields
class ChannelPinsUpdateEvent{
  public:
    ChannelPinsUpdateEvent(
        omittable_field<Snowflake> guild_id = omitted,
        field<Snowflake> channel_id = uninitialized,
        nullable_omittable_field<Timestamp> last_pin_timestamp = omitted
    ):
        guild_id(guild_id),
        channel_id(channel_id),
        last_pin_timestamp(last_pin_timestamp)
    {}
    ChannelPinsUpdateEvent(const json &j) { from_json(j, *this); }
    
    omittable_field<Snowflake> guild_id;
    field<Snowflake> channel_id;
    nullable_omittable_field<Timestamp> last_pin_timestamp;

    friend void to_json(nlohmann::json &j, const ChannelPinsUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.last_pin_timestamp.is_omitted()) {j["last_pin_timestamp"] = t.last_pin_timestamp;}
    }
    friend void from_json(const nlohmann::json &j, ChannelPinsUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("last_pin_timestamp")){j.at("last_pin_timestamp").get_to(t.last_pin_timestamp);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-ban-add-guild-ban-add-event-fields
class GuildBanAddEvent{
  public:
    GuildBanAddEvent(
        field<Snowflake> guild_id = uninitialized,
        field<User> user = uninitialized
    ):
        guild_id(guild_id),
        user(user)
    {}
    GuildBanAddEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<User> user;

    friend void to_json(nlohmann::json &j, const GuildBanAddEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, GuildBanAddEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-ban-remove-guild-ban-remove-event-fields
class GuildBanRemoveEvent{
  public:
    GuildBanRemoveEvent(
        field<Snowflake> guild_id = uninitialized,
        field<User> user = uninitialized
    ):
        guild_id(guild_id),
        user(user)
    {}
    GuildBanRemoveEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<User> user;

    friend void to_json(nlohmann::json &j, const GuildBanRemoveEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, GuildBanRemoveEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-emojis-update-guild-emojis-update-event-fields
class GuildEmojisUpdateEvent{
  public:
    GuildEmojisUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<Emoji> > emojis = uninitialized
    ):
        guild_id(guild_id),
        emojis(emojis)
    {}
    GuildEmojisUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<std::vector<Emoji> > emojis;

    friend void to_json(nlohmann::json &j, const GuildEmojisUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.emojis.is_omitted()) {j["emojis"] = t.emojis;}
    }
    friend void from_json(const nlohmann::json &j, GuildEmojisUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("emojis")){j.at("emojis").get_to(t.emojis);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-stickers-update-guild-stickers-update-event-fields
class GuildStickersUpdateEvent{
  public:
    GuildStickersUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<Sticker> > stickers = uninitialized
    ):
        guild_id(guild_id),
        stickers(stickers)
    {}
    GuildStickersUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<std::vector<Sticker> > stickers;

    friend void to_json(nlohmann::json &j, const GuildStickersUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
    }
    friend void from_json(const nlohmann::json &j, GuildStickersUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("stickers")){j.at("stickers").get_to(t.stickers);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-integrations-update-guild-integrations-update-event-fields
class GuildIntegrationsUpdateEvent{
  public:
    GuildIntegrationsUpdateEvent(
        field<Snowflake> guild_id = uninitialized
    ):
        guild_id(guild_id)
    {}
    GuildIntegrationsUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildIntegrationsUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildIntegrationsUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-member-remove-guild-member-remove-event-fields
class GuildMemberRemoveEvent{
  public:
    GuildMemberRemoveEvent(
        field<Snowflake> guild_id = uninitialized,
        field<User> user = uninitialized
    ):
        guild_id(guild_id),
        user(user)
    {}
    GuildMemberRemoveEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<User> user;

    friend void to_json(nlohmann::json &j, const GuildMemberRemoveEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, GuildMemberRemoveEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-member-update-guild-member-update-event-fields
class GuildMemberUpdateEvent{
  public:
    GuildMemberUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<Snowflake> > roles = uninitialized,
        field<User> user = uninitialized,
        nullable_omittable_field<std::string> nick = omitted,
        nullable_field<std::string> avatar = uninitialized,
        nullable_field<Timestamp> joined_at = uninitialized,
        nullable_omittable_field<Timestamp> premium_since = omitted,
        omittable_field<bool> deaf = omitted,
        omittable_field<bool> mute = omitted,
        omittable_field<bool> pending = omitted,
        nullable_omittable_field<Timestamp> communication_disabled_until = omitted
    ):
        guild_id(guild_id),
        roles(roles),
        user(user),
        nick(nick),
        avatar(avatar),
        joined_at(joined_at),
        premium_since(premium_since),
        deaf(deaf),
        mute(mute),
        pending(pending),
        communication_disabled_until(communication_disabled_until)
    {}
    GuildMemberUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<std::vector<Snowflake> > roles;
    field<User> user;
    nullable_omittable_field<std::string> nick;
    nullable_field<std::string> avatar;
    nullable_field<Timestamp> joined_at;
    nullable_omittable_field<Timestamp> premium_since;
    omittable_field<bool> deaf;
    omittable_field<bool> mute;
    omittable_field<bool> pending;
    nullable_omittable_field<Timestamp> communication_disabled_until;

    friend void to_json(nlohmann::json &j, const GuildMemberUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.nick.is_omitted()) {j["nick"] = t.nick;}
        if(!t.avatar.is_omitted()) {j["avatar"] = t.avatar;}
        if(!t.joined_at.is_omitted()) {j["joined_at"] = t.joined_at;}
        if(!t.premium_since.is_omitted()) {j["premium_since"] = t.premium_since;}
        if(!t.deaf.is_omitted()) {j["deaf"] = t.deaf;}
        if(!t.mute.is_omitted()) {j["mute"] = t.mute;}
        if(!t.pending.is_omitted()) {j["pending"] = t.pending;}
        if(!t.communication_disabled_until.is_omitted()) {j["communication_disabled_until"] = t.communication_disabled_until;}
    }
    friend void from_json(const nlohmann::json &j, GuildMemberUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("roles")){j.at("roles").get_to(t.roles);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("nick")){j.at("nick").get_to(t.nick);}
        if(j.contains("avatar")){j.at("avatar").get_to(t.avatar);}
        if(j.contains("joined_at")){j.at("joined_at").get_to(t.joined_at);}
        if(j.contains("premium_since")){j.at("premium_since").get_to(t.premium_since);}
        if(j.contains("deaf")){j.at("deaf").get_to(t.deaf);}
        if(j.contains("mute")){j.at("mute").get_to(t.mute);}
        if(j.contains("pending")){j.at("pending").get_to(t.pending);}
        if(j.contains("communication_disabled_until")){j.at("communication_disabled_until").get_to(t.communication_disabled_until);}
    }
};

class Presence;
// https://discord.com/developers/docs/topics/gateway-events#guild-members-chunk-guild-members-chunk-event-fields
class GuildMembersChunkEvent{
  public:
    GuildMembersChunkEvent(
        field<Snowflake> guild_id = uninitialized,
        field<std::vector<GuildMember> > members = uninitialized,
        field<int> chunk_index = uninitialized,
        field<int> chunk_count = uninitialized,
        omittable_field<std::vector<Snowflake> > not_found = omitted,
        omittable_field<std::vector<Presence> > presences = omitted,
        omittable_field<std::string> nonce = omitted
    ):
        guild_id(guild_id),
        members(members),
        chunk_index(chunk_index),
        chunk_count(chunk_count),
        not_found(not_found),
        presences(presences),
        nonce(nonce)
    {}
    GuildMembersChunkEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<std::vector<GuildMember> > members;
    field<int> chunk_index;
    field<int> chunk_count;
    omittable_field<std::vector<Snowflake> > not_found;
    omittable_field<std::vector<Presence> > presences;
    omittable_field<std::string> nonce;

    friend void to_json(nlohmann::json &j, const GuildMembersChunkEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.chunk_index.is_omitted()) {j["chunk_index"] = t.chunk_index;}
        if(!t.chunk_count.is_omitted()) {j["chunk_count"] = t.chunk_count;}
        if(!t.not_found.is_omitted()) {j["not_found"] = t.not_found;}
        if(!t.presences.is_omitted()) {j["presences"] = t.presences;}
        if(!t.nonce.is_omitted()) {j["nonce"] = t.nonce;}
    }
    friend void from_json(const nlohmann::json &j, GuildMembersChunkEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("chunk_index")){j.at("chunk_index").get_to(t.chunk_index);}
        if(j.contains("chunk_count")){j.at("chunk_count").get_to(t.chunk_count);}
        if(j.contains("not_found")){j.at("not_found").get_to(t.not_found);}
        if(j.contains("presences")){j.at("presences").get_to(t.presences);}
        if(j.contains("nonce")){j.at("nonce").get_to(t.nonce);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-role-create-guild-role-create-event-fields
class GuildRoleCreateEvent{
  public:
    GuildRoleCreateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<Role> role = uninitialized
    ):
        guild_id(guild_id),
        role(role)
    {}
    GuildRoleCreateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<Role> role;

    friend void to_json(nlohmann::json &j, const GuildRoleCreateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role.is_omitted()) {j["role"] = t.role;}
    }
    friend void from_json(const nlohmann::json &j, GuildRoleCreateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("role")){j.at("role").get_to(t.role);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-role-update-guild-role-update-event-fields
class GuildRoleUpdateEvent{
  public:
    GuildRoleUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<Role> role = uninitialized
    ):
        guild_id(guild_id),
        role(role)
    {}
    GuildRoleUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<Role> role;

    friend void to_json(nlohmann::json &j, const GuildRoleUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role.is_omitted()) {j["role"] = t.role;}
    }
    friend void from_json(const nlohmann::json &j, GuildRoleUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("role")){j.at("role").get_to(t.role);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-role-delete-guild-role-delete-event-fields
class GuildRoleDeleteEvent{
  public:
    GuildRoleDeleteEvent(
        field<Snowflake> guild_id = uninitialized,
        field<Snowflake> role_id = uninitialized
    ):
        guild_id(guild_id),
        role_id(role_id)
    {}
    GuildRoleDeleteEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<Snowflake> role_id;

    friend void to_json(nlohmann::json &j, const GuildRoleDeleteEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.role_id.is_omitted()) {j["role_id"] = t.role_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildRoleDeleteEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("role_id")){j.at("role_id").get_to(t.role_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-scheduled-event-user-add-guild-scheduled-event-user-add-event-fields
class GuildScheduledEventUserAddEvent{
  public:
    GuildScheduledEventUserAddEvent(
        field<Snowflake> guild_scheduled_event_id = uninitialized,
        field<Snowflake> user_id = uninitialized,
        field<Snowflake> guild_id = uninitialized
    ):
        guild_scheduled_event_id(guild_scheduled_event_id),
        user_id(user_id),
        guild_id(guild_id)
    {}
    GuildScheduledEventUserAddEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_scheduled_event_id;
    field<Snowflake> user_id;
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildScheduledEventUserAddEvent &t) {
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildScheduledEventUserAddEvent &t) {
        if(j.contains("guild_scheduled_event_id")){j.at("guild_scheduled_event_id").get_to(t.guild_scheduled_event_id);}
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-scheduled-event-user-remove-guild-scheduled-event-user-remove-event-fields
class GuildScheduledEventUserRemoveEvent{
  public:
    GuildScheduledEventUserRemoveEvent(
        field<Snowflake> guild_scheduled_event_id = uninitialized,
        field<Snowflake> user_id = uninitialized,
        field<Snowflake> guild_id = uninitialized
    ):
        guild_scheduled_event_id(guild_scheduled_event_id),
        user_id(user_id),
        guild_id(guild_id)
    {}
    GuildScheduledEventUserRemoveEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_scheduled_event_id;
    field<Snowflake> user_id;
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildScheduledEventUserRemoveEvent &t) {
        if(!t.guild_scheduled_event_id.is_omitted()) {j["guild_scheduled_event_id"] = t.guild_scheduled_event_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildScheduledEventUserRemoveEvent &t) {
        if(j.contains("guild_scheduled_event_id")){j.at("guild_scheduled_event_id").get_to(t.guild_scheduled_event_id);}
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#integration-create-integration-create-event-additional-fields
class IntegrationCreateEventAdditional{
  public:
    IntegrationCreateEventAdditional(
        field<Snowflake> guild_id = uninitialized
    ):
        guild_id(guild_id)
    {}
    IntegrationCreateEventAdditional(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const IntegrationCreateEventAdditional &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationCreateEventAdditional &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#integration-update-integration-update-event-additional-fields
class IntegrationUpdateEventAdditional{
  public:
    IntegrationUpdateEventAdditional(
        field<Snowflake> guild_id = uninitialized
    ):
        guild_id(guild_id)
    {}
    IntegrationUpdateEventAdditional(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const IntegrationUpdateEventAdditional &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationUpdateEventAdditional &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#integration-delete-integration-delete-event-fields
class IntegrationDeleteEvent{
  public:
    IntegrationDeleteEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        omittable_field<Snowflake> application_id = omitted
    ):
        id(id),
        guild_id(guild_id),
        application_id(application_id)
    {}
    IntegrationDeleteEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    omittable_field<Snowflake> application_id;

    friend void to_json(nlohmann::json &j, const IntegrationDeleteEvent &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
    }
    friend void from_json(const nlohmann::json &j, IntegrationDeleteEvent &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#invite-create-invite-create-event-fields
class InviteCreateEvent{
  public:
    InviteCreateEvent(
        field<Snowflake> channel_id = uninitialized,
        field<std::string> code = uninitialized,
        field<Timestamp> created_at = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<User> inviter = omitted,
        field<int> max_age = uninitialized,
        field<int> max_uses = uninitialized,
        omittable_field<int> target_type = omitted,
        omittable_field<User> target_user = omitted,
        omittable_field<Application> target_application = omitted,
        field<bool> temporary = uninitialized,
        field<int> uses = uninitialized
    ):
        channel_id(channel_id),
        code(code),
        created_at(created_at),
        guild_id(guild_id),
        inviter(inviter),
        max_age(max_age),
        max_uses(max_uses),
        target_type(target_type),
        target_user(target_user),
        target_application(target_application),
        temporary(temporary),
        uses(uses)
    {}
    InviteCreateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> channel_id;
    field<std::string> code;
    field<Timestamp> created_at;
    omittable_field<Snowflake> guild_id;
    omittable_field<User> inviter;
    field<int> max_age;
    field<int> max_uses;
    omittable_field<int> target_type;
    omittable_field<User> target_user;
    omittable_field<Application> target_application;
    field<bool> temporary;
    field<int> uses;

    friend void to_json(nlohmann::json &j, const InviteCreateEvent &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.code.is_omitted()) {j["code"] = t.code;}
        if(!t.created_at.is_omitted()) {j["created_at"] = t.created_at;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.inviter.is_omitted()) {j["inviter"] = t.inviter;}
        if(!t.max_age.is_omitted()) {j["max_age"] = t.max_age;}
        if(!t.max_uses.is_omitted()) {j["max_uses"] = t.max_uses;}
        if(!t.target_type.is_omitted()) {j["target_type"] = t.target_type;}
        if(!t.target_user.is_omitted()) {j["target_user"] = t.target_user;}
        if(!t.target_application.is_omitted()) {j["target_application"] = t.target_application;}
        if(!t.temporary.is_omitted()) {j["temporary"] = t.temporary;}
        if(!t.uses.is_omitted()) {j["uses"] = t.uses;}
    }
    friend void from_json(const nlohmann::json &j, InviteCreateEvent &t) {
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("code")){j.at("code").get_to(t.code);}
        if(j.contains("created_at")){j.at("created_at").get_to(t.created_at);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("inviter")){j.at("inviter").get_to(t.inviter);}
        if(j.contains("max_age")){j.at("max_age").get_to(t.max_age);}
        if(j.contains("max_uses")){j.at("max_uses").get_to(t.max_uses);}
        if(j.contains("target_type")){j.at("target_type").get_to(t.target_type);}
        if(j.contains("target_user")){j.at("target_user").get_to(t.target_user);}
        if(j.contains("target_application")){j.at("target_application").get_to(t.target_application);}
        if(j.contains("temporary")){j.at("temporary").get_to(t.temporary);}
        if(j.contains("uses")){j.at("uses").get_to(t.uses);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#invite-delete-invite-delete-event-fields
class InviteDeleteEvent{
  public:
    InviteDeleteEvent(
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<std::string> code = uninitialized
    ):
        channel_id(channel_id),
        guild_id(guild_id),
        code(code)
    {}
    InviteDeleteEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    field<std::string> code;

    friend void to_json(nlohmann::json &j, const InviteDeleteEvent &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.code.is_omitted()) {j["code"] = t.code;}
    }
    friend void from_json(const nlohmann::json &j, InviteDeleteEvent &t) {
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("code")){j.at("code").get_to(t.code);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#message-delete-message-delete-event-fields
class MessageDeleteEvent{
  public:
    MessageDeleteEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted
    ):
        id(id),
        channel_id(channel_id),
        guild_id(guild_id)
    {}
    MessageDeleteEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const MessageDeleteEvent &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, MessageDeleteEvent &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#message-delete-bulk-message-delete-bulk-event-fields
class MessageDeleteBulkEvent{
  public:
    MessageDeleteBulkEvent(
        field<std::vector<Snowflake> > ids = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted
    ):
        ids(ids),
        channel_id(channel_id),
        guild_id(guild_id)
    {}
    MessageDeleteBulkEvent(const json &j) { from_json(j, *this); }
    
    field<std::vector<Snowflake> > ids;
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const MessageDeleteBulkEvent &t) {
        if(!t.ids.is_omitted()) {j["ids"] = t.ids;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, MessageDeleteBulkEvent &t) {
        if(j.contains("ids")){j.at("ids").get_to(t.ids);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#message-reaction-add-message-reaction-add-event-fields
class MessageReactionAddEvent{
  public:
    MessageReactionAddEvent(
        field<Snowflake> user_id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<Snowflake> message_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<GuildMember> member = omitted,
        field<Emoji> emoji = uninitialized
    ):
        user_id(user_id),
        channel_id(channel_id),
        message_id(message_id),
        guild_id(guild_id),
        member(member),
        emoji(emoji)
    {}
    MessageReactionAddEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> user_id;
    field<Snowflake> channel_id;
    field<Snowflake> message_id;
    omittable_field<Snowflake> guild_id;
    omittable_field<GuildMember> member;
    field<Emoji> emoji;

    friend void to_json(nlohmann::json &j, const MessageReactionAddEvent &t) {
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
    friend void from_json(const nlohmann::json &j, MessageReactionAddEvent &t) {
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("message_id")){j.at("message_id").get_to(t.message_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
        if(j.contains("emoji")){j.at("emoji").get_to(t.emoji);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#message-reaction-remove-message-reaction-remove-event-fields
class MessageReactionRemoveEvent{
  public:
    MessageReactionRemoveEvent(
        field<Snowflake> user_id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<Snowflake> message_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<Emoji> emoji = uninitialized
    ):
        user_id(user_id),
        channel_id(channel_id),
        message_id(message_id),
        guild_id(guild_id),
        emoji(emoji)
    {}
    MessageReactionRemoveEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> user_id;
    field<Snowflake> channel_id;
    field<Snowflake> message_id;
    omittable_field<Snowflake> guild_id;
    field<Emoji> emoji;

    friend void to_json(nlohmann::json &j, const MessageReactionRemoveEvent &t) {
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
    friend void from_json(const nlohmann::json &j, MessageReactionRemoveEvent &t) {
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("message_id")){j.at("message_id").get_to(t.message_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("emoji")){j.at("emoji").get_to(t.emoji);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#message-reaction-remove-all-message-reaction-remove-all-event-fields
class MessageReactionRemoveAllEvent{
  public:
    MessageReactionRemoveAllEvent(
        field<Snowflake> channel_id = uninitialized,
        field<Snowflake> message_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted
    ):
        channel_id(channel_id),
        message_id(message_id),
        guild_id(guild_id)
    {}
    MessageReactionRemoveAllEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> channel_id;
    field<Snowflake> message_id;
    omittable_field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const MessageReactionRemoveAllEvent &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, MessageReactionRemoveAllEvent &t) {
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("message_id")){j.at("message_id").get_to(t.message_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#message-reaction-remove-emoji-message-reaction-remove-emoji-event-fields
class MessageReactionRemoveEmojiEvent{
  public:
    MessageReactionRemoveEmojiEvent(
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<Snowflake> message_id = uninitialized,
        field<Emoji> emoji = uninitialized
    ):
        channel_id(channel_id),
        guild_id(guild_id),
        message_id(message_id),
        emoji(emoji)
    {}
    MessageReactionRemoveEmojiEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    field<Snowflake> message_id;
    field<Emoji> emoji;

    friend void to_json(nlohmann::json &j, const MessageReactionRemoveEmojiEvent &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
    friend void from_json(const nlohmann::json &j, MessageReactionRemoveEmojiEvent &t) {
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("message_id")){j.at("message_id").get_to(t.message_id);}
        if(j.contains("emoji")){j.at("emoji").get_to(t.emoji);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#presence-update-presence-update-event-fields
class Presence{
  public:
    Presence(
        field<User> user = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        field<std::string> status = uninitialized,
        field<std::vector<Activity> > activities = uninitialized,
        field<ClientStatus> client_status = uninitialized
    ):
        user(user),
        guild_id(guild_id),
        status(status),
        activities(activities),
        client_status(client_status)
    {}
    Presence(const json &j) { from_json(j, *this); }
    
    field<User> user;
    field<Snowflake> guild_id;
    field<std::string> status;
    field<std::vector<Activity> > activities;
    field<ClientStatus> client_status;

    friend void to_json(nlohmann::json &j, const Presence &t) {
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.status.is_omitted()) {j["status"] = t.status;}
        if(!t.activities.is_omitted()) {j["activities"] = t.activities;}
        if(!t.client_status.is_omitted()) {j["client_status"] = t.client_status;}
    }
    friend void from_json(const nlohmann::json &j, Presence &t) {
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("status")){j.at("status").get_to(t.status);}
        if(j.contains("activities")){j.at("activities").get_to(t.activities);}
        if(j.contains("client_status")){j.at("client_status").get_to(t.client_status);}
    }
};
using PresenceUpdateEvent = Presence;
using PresenceUpdate = Presence;

// https://discord.com/developers/docs/topics/gateway-events#presence-client-status-object
class ClientStatus{
  public:
    ClientStatus(
        omittable_field<std::string> desktop = omitted,
        omittable_field<std::string> mobile = omitted,
        omittable_field<std::string> web = omitted
    ):
        desktop(desktop),
        mobile(mobile),
        web(web)
    {}
    ClientStatus(const json &j) { from_json(j, *this); }
    
    omittable_field<std::string> desktop;
    omittable_field<std::string> mobile;
    omittable_field<std::string> web;

    friend void to_json(nlohmann::json &j, const ClientStatus &t) {
        if(!t.desktop.is_omitted()) {j["desktop"] = t.desktop;}
        if(!t.mobile.is_omitted()) {j["mobile"] = t.mobile;}
        if(!t.web.is_omitted()) {j["web"] = t.web;}
    }
    friend void from_json(const nlohmann::json &j, ClientStatus &t) {
        if(j.contains("desktop")){j.at("desktop").get_to(t.desktop);}
        if(j.contains("mobile")){j.at("mobile").get_to(t.mobile);}
        if(j.contains("web")){j.at("web").get_to(t.web);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-structure
class Activity{
  public:
    Activity(
        field<std::string> name = uninitialized,
        field<int> type = uninitialized,
        nullable_omittable_field<std::string> url = omitted,
        field<int> created_at = uninitialized,
        omittable_field<ActivityTimestamps> timestamps = omitted,
        omittable_field<Snowflake> application_id = omitted,
        nullable_omittable_field<std::string> details = omitted,
        nullable_omittable_field<std::string> state = omitted,
        nullable_omittable_field<Emoji> emoji = omitted,
        omittable_field<ActivityParty> party = omitted,
        omittable_field<ActivityAssets> assets = omitted,
        omittable_field<ActivitySecrets> secrets = omitted,
        omittable_field<bool> instance = omitted,
        omittable_field<int> flags = omitted,
        omittable_field<std::vector<Button> > buttons = omitted
    ):
        name(name),
        type(type),
        url(url),
        created_at(created_at),
        timestamps(timestamps),
        application_id(application_id),
        details(details),
        state(state),
        emoji(emoji),
        party(party),
        assets(assets),
        secrets(secrets),
        instance(instance),
        flags(flags),
        buttons(buttons)
    {}
    Activity(const json &j) { from_json(j, *this); }
    
    field<std::string> name;
    field<int> type;
    nullable_omittable_field<std::string> url;
    field<int> created_at;
    omittable_field<ActivityTimestamps> timestamps;
    omittable_field<Snowflake> application_id;
    nullable_omittable_field<std::string> details;
    nullable_omittable_field<std::string> state;
    nullable_omittable_field<Emoji> emoji;
    omittable_field<ActivityParty> party;
    omittable_field<ActivityAssets> assets;
    omittable_field<ActivitySecrets> secrets;
    omittable_field<bool> instance;
    omittable_field<int> flags;
    omittable_field<std::vector<Button> > buttons;

    friend void to_json(nlohmann::json &j, const Activity &t) {
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.created_at.is_omitted()) {j["created_at"] = t.created_at;}
        if(!t.timestamps.is_omitted()) {j["timestamps"] = t.timestamps;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.details.is_omitted()) {j["details"] = t.details;}
        if(!t.state.is_omitted()) {j["state"] = t.state;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
        if(!t.party.is_omitted()) {j["party"] = t.party;}
        if(!t.assets.is_omitted()) {j["assets"] = t.assets;}
        if(!t.secrets.is_omitted()) {j["secrets"] = t.secrets;}
        if(!t.instance.is_omitted()) {j["instance"] = t.instance;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.buttons.is_omitted()) {j["buttons"] = t.buttons;}
    }
    friend void from_json(const nlohmann::json &j, Activity &t) {
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("created_at")){j.at("created_at").get_to(t.created_at);}
        if(j.contains("timestamps")){j.at("timestamps").get_to(t.timestamps);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("details")){j.at("details").get_to(t.details);}
        if(j.contains("state")){j.at("state").get_to(t.state);}
        if(j.contains("emoji")){j.at("emoji").get_to(t.emoji);}
        if(j.contains("party")){j.at("party").get_to(t.party);}
        if(j.contains("assets")){j.at("assets").get_to(t.assets);}
        if(j.contains("secrets")){j.at("secrets").get_to(t.secrets);}
        if(j.contains("instance")){j.at("instance").get_to(t.instance);}
        if(j.contains("flags")){j.at("flags").get_to(t.flags);}
        if(j.contains("buttons")){j.at("buttons").get_to(t.buttons);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-timestamps
class ActivityTimestamps{
  public:
    ActivityTimestamps(
        omittable_field<int> start = omitted,
        omittable_field<int> end = omitted
    ):
        start(start),
        end(end)
    {}
    ActivityTimestamps(const json &j) { from_json(j, *this); }
    
    omittable_field<int> start;
    omittable_field<int> end;

    friend void to_json(nlohmann::json &j, const ActivityTimestamps &t) {
        if(!t.start.is_omitted()) {j["start"] = t.start;}
        if(!t.end.is_omitted()) {j["end"] = t.end;}
    }
    friend void from_json(const nlohmann::json &j, ActivityTimestamps &t) {
        if(j.contains("start")){j.at("start").get_to(t.start);}
        if(j.contains("end")){j.at("end").get_to(t.end);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-emoji
class ActivityEmoji{
  public:
    ActivityEmoji(
        field<std::string> name = uninitialized,
        omittable_field<Snowflake> id = omitted,
        omittable_field<bool> animated = omitted
    ):
        name(name),
        id(id),
        animated(animated)
    {}
    ActivityEmoji(const json &j) { from_json(j, *this); }
    
    field<std::string> name;
    omittable_field<Snowflake> id;
    omittable_field<bool> animated;

    friend void to_json(nlohmann::json &j, const ActivityEmoji &t) {
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.animated.is_omitted()) {j["animated"] = t.animated;}
    }
    friend void from_json(const nlohmann::json &j, ActivityEmoji &t) {
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("animated")){j.at("animated").get_to(t.animated);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-party
class ActivityParty{
  public:
    ActivityParty(
        omittable_field<std::string> id = omitted,
        omittable_field<std::array<int, 2>> size = omitted
    ):
        id(id),
        size(size)
    {}
    ActivityParty(const json &j) { from_json(j, *this); }
    
    omittable_field<std::string> id;
    omittable_field<std::array<int, 2>> size;

    friend void to_json(nlohmann::json &j, const ActivityParty &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.size.is_omitted()) {j["size"] = t.size;}
    }
    friend void from_json(const nlohmann::json &j, ActivityParty &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("size")){j.at("size").get_to(t.size);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-assets
class ActivityAssets{
  public:
    ActivityAssets(
        omittable_field<std::string> large_image = omitted,
        omittable_field<std::string> large_text = omitted,
        omittable_field<std::string> small_image = omitted,
        omittable_field<std::string> small_text = omitted
    ):
        large_image(large_image),
        large_text(large_text),
        small_image(small_image),
        small_text(small_text)
    {}
    ActivityAssets(const json &j) { from_json(j, *this); }
    
    omittable_field<std::string> large_image;
    omittable_field<std::string> large_text;
    omittable_field<std::string> small_image;
    omittable_field<std::string> small_text;

    friend void to_json(nlohmann::json &j, const ActivityAssets &t) {
        if(!t.large_image.is_omitted()) {j["large_image"] = t.large_image;}
        if(!t.large_text.is_omitted()) {j["large_text"] = t.large_text;}
        if(!t.small_image.is_omitted()) {j["small_image"] = t.small_image;}
        if(!t.small_text.is_omitted()) {j["small_text"] = t.small_text;}
    }
    friend void from_json(const nlohmann::json &j, ActivityAssets &t) {
        if(j.contains("large_image")){j.at("large_image").get_to(t.large_image);}
        if(j.contains("large_text")){j.at("large_text").get_to(t.large_text);}
        if(j.contains("small_image")){j.at("small_image").get_to(t.small_image);}
        if(j.contains("small_text")){j.at("small_text").get_to(t.small_text);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-secrets
class ActivitySecrets{
  public:
    ActivitySecrets(
        omittable_field<std::string> join = omitted,
        omittable_field<std::string> spectate = omitted,
        omittable_field<std::string> match = omitted
    ):
        join(join),
        spectate(spectate),
        match(match)
    {}
    ActivitySecrets(const json &j) { from_json(j, *this); }
    
    omittable_field<std::string> join;
    omittable_field<std::string> spectate;
    omittable_field<std::string> match;

    friend void to_json(nlohmann::json &j, const ActivitySecrets &t) {
        if(!t.join.is_omitted()) {j["join"] = t.join;}
        if(!t.spectate.is_omitted()) {j["spectate"] = t.spectate;}
        if(!t.match.is_omitted()) {j["match"] = t.match;}
    }
    friend void from_json(const nlohmann::json &j, ActivitySecrets &t) {
        if(j.contains("join")){j.at("join").get_to(t.join);}
        if(j.contains("spectate")){j.at("spectate").get_to(t.spectate);}
        if(j.contains("match")){j.at("match").get_to(t.match);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#activity-object-activity-buttons
class ActivityButtons{
  public:
    ActivityButtons(
        field<std::string> label = uninitialized,
        field<std::string> url = uninitialized
    ):
        label(label),
        url(url)
    {}
    ActivityButtons(const json &j) { from_json(j, *this); }
    
    field<std::string> label;
    field<std::string> url;

    friend void to_json(nlohmann::json &j, const ActivityButtons &t) {
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
    }
    friend void from_json(const nlohmann::json &j, ActivityButtons &t) {
        if(j.contains("label")){j.at("label").get_to(t.label);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#typing-start-typing-start-event-fields
class TypingStartEvent{
  public:
    TypingStartEvent(
        field<Snowflake> channel_id = uninitialized,
        omittable_field<Snowflake> guild_id = omitted,
        field<Snowflake> user_id = uninitialized,
        field<int> timestamp = uninitialized,
        omittable_field<GuildMember> member = omitted
    ):
        channel_id(channel_id),
        guild_id(guild_id),
        user_id(user_id),
        timestamp(timestamp),
        member(member)
    {}
    TypingStartEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    field<Snowflake> user_id;
    field<int> timestamp;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const TypingStartEvent &t) {
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.timestamp.is_omitted()) {j["timestamp"] = t.timestamp;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
    }
    friend void from_json(const nlohmann::json &j, TypingStartEvent &t) {
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("user_id")){j.at("user_id").get_to(t.user_id);}
        if(j.contains("timestamp")){j.at("timestamp").get_to(t.timestamp);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#voice-server-update-voice-server-update-event-fields
class VoiceServerUpdateEvent{
  public:
    VoiceServerUpdateEvent(
        field<std::string> token = uninitialized,
        field<Snowflake> guild_id = uninitialized,
        nullable_field<std::string> endpoint = uninitialized
    ):
        token(token),
        guild_id(guild_id),
        endpoint(endpoint)
    {}
    VoiceServerUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<std::string> token;
    field<Snowflake> guild_id;
    nullable_field<std::string> endpoint;

    friend void to_json(nlohmann::json &j, const VoiceServerUpdateEvent &t) {
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.endpoint.is_omitted()) {j["endpoint"] = t.endpoint;}
    }
    friend void from_json(const nlohmann::json &j, VoiceServerUpdateEvent &t) {
        if(j.contains("token")){j.at("token").get_to(t.token);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("endpoint")){j.at("endpoint").get_to(t.endpoint);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#webhooks-update-webhooks-update-event-fields
class WebhooksUpdateEvent{
  public:
    WebhooksUpdateEvent(
        field<Snowflake> guild_id = uninitialized,
        field<Snowflake> channel_id = uninitialized
    ):
        guild_id(guild_id),
        channel_id(channel_id)
    {}
    WebhooksUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;
    field<Snowflake> channel_id;

    friend void to_json(nlohmann::json &j, const WebhooksUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
    }
    friend void from_json(const nlohmann::json &j, WebhooksUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
    }
};

// https://discord.com/developers/docs/topics/oauth2#get-current-authorization-information-response-structure
class GetCurrentAuthorizationInformationResponse{
  public:
    GetCurrentAuthorizationInformationResponse(
        field<Application> application = uninitialized,
        field<std::vector<std::string> > scopes = uninitialized,
        field<Timestamp> expires = uninitialized,
        omittable_field<User> user = omitted
    ):
        application(application),
        scopes(scopes),
        expires(expires),
        user(user)
    {}
    GetCurrentAuthorizationInformationResponse(const json &j) { from_json(j, *this); }
    
    field<Application> application;
    field<std::vector<std::string> > scopes;
    field<Timestamp> expires;
    omittable_field<User> user;

    friend void to_json(nlohmann::json &j, const GetCurrentAuthorizationInformationResponse &t) {
        if(!t.application.is_omitted()) {j["application"] = t.application;}
        if(!t.scopes.is_omitted()) {j["scopes"] = t.scopes;}
        if(!t.expires.is_omitted()) {j["expires"] = t.expires;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, GetCurrentAuthorizationInformationResponse &t) {
        if(j.contains("application")){j.at("application").get_to(t.application);}
        if(j.contains("scopes")){j.at("scopes").get_to(t.scopes);}
        if(j.contains("expires")){j.at("expires").get_to(t.expires);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
    }
};

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
    Role(const json &j) { from_json(j, *this); }
    
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
    RoleTags(const json &j) { from_json(j, *this); }
    
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

// https://discord.com/developers/docs/topics/rate-limits#exceeding-a-rate-limit-rate-limit-response-structure
class RateLimitResponse{
  public:
    RateLimitResponse(
        field<std::string> message = uninitialized,
        field<float> retry_after = uninitialized,
        field<bool> global = uninitialized,
        omittable_field<int> code = omitted
    ):
        message(message),
        retry_after(retry_after),
        global(global),
        code(code)
    {}
    RateLimitResponse(const json &j) { from_json(j, *this); }
    
    field<std::string> message;
    field<float> retry_after;
    field<bool> global;
    omittable_field<int> code;

    friend void to_json(nlohmann::json &j, const RateLimitResponse &t) {
        if(!t.message.is_omitted()) {j["message"] = t.message;}
        if(!t.retry_after.is_omitted()) {j["retry_after"] = t.retry_after;}
        if(!t.global.is_omitted()) {j["global"] = t.global;}
        if(!t.code.is_omitted()) {j["code"] = t.code;}
    }
    friend void from_json(const nlohmann::json &j, RateLimitResponse &t) {
        if(j.contains("message")){j.at("message").get_to(t.message);}
        if(j.contains("retry_after")){j.at("retry_after").get_to(t.retry_after);}
        if(j.contains("global")){j.at("global").get_to(t.global);}
        if(j.contains("code")){j.at("code").get_to(t.code);}
    }
};

// https://discord.com/developers/docs/topics/teams#data-models-team-object
class Team{
  public:
    Team(
        nullable_field<std::string> icon = uninitialized,
        field<Snowflake> id = uninitialized,
        field<std::vector<TeamMember> > members = uninitialized,
        field<std::string> name = uninitialized,
        field<Snowflake> owner_user_id = uninitialized
    ):
        icon(icon),
        id(id),
        members(members),
        name(name),
        owner_user_id(owner_user_id)
    {}
    Team(const json &j) { from_json(j, *this); }
    
    nullable_field<std::string> icon;
    field<Snowflake> id;
    field<std::vector<TeamMember> > members;
    field<std::string> name;
    field<Snowflake> owner_user_id;

    friend void to_json(nlohmann::json &j, const Team &t) {
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.owner_user_id.is_omitted()) {j["owner_user_id"] = t.owner_user_id;}
    }
    friend void from_json(const nlohmann::json &j, Team &t) {
        if(j.contains("icon")){j.at("icon").get_to(t.icon);}
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("owner_user_id")){j.at("owner_user_id").get_to(t.owner_user_id);}
    }
};

// https://discord.com/developers/docs/topics/teams#data-models-team-member-object
class TeamMember{
  public:
    TeamMember(
        field<int> membership_state = uninitialized,
        field<std::vector<std::string> > permissions = uninitialized,
        field<Snowflake> team_id = uninitialized,
        field<User> user = uninitialized
    ):
        membership_state(membership_state),
        permissions(permissions),
        team_id(team_id),
        user(user)
    {}
    TeamMember(const json &j) { from_json(j, *this); }
    
    field<int> membership_state;
    field<std::vector<std::string> > permissions;
    field<Snowflake> team_id;
    field<User> user;

    friend void to_json(nlohmann::json &j, const TeamMember &t) {
        if(!t.membership_state.is_omitted()) {j["membership_state"] = t.membership_state;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
        if(!t.team_id.is_omitted()) {j["team_id"] = t.team_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
    friend void from_json(const nlohmann::json &j, TeamMember &t) {
        if(j.contains("membership_state")){j.at("membership_state").get_to(t.membership_state);}
        if(j.contains("permissions")){j.at("permissions").get_to(t.permissions);}
        if(j.contains("team_id")){j.at("team_id").get_to(t.team_id);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#button-object-button-structure
class Button: public Component{
  public:
    Button(
        field<int> style = uninitialized,
        omittable_field<std::string> label = omitted,
        omittable_field<Emoji> emoji = omitted,
        omittable_field<std::string> custom_id = omitted,
        omittable_field<std::string> url = omitted,
        omittable_field<bool> disabled = omitted
    ):
        Component(
            field<int>(2)
        ),
        style(style),
        label(label),
        emoji(emoji),
        custom_id(custom_id),
        url(url),
        disabled(disabled)
    {}
    Button(const json &j) { from_json(j, *this); }
    
    field<int> style;
    omittable_field<std::string> label;
    omittable_field<Emoji> emoji;
    omittable_field<std::string> custom_id;
    omittable_field<std::string> url;
    omittable_field<bool> disabled;

    friend void to_json(nlohmann::json &j, const Button &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.style.is_omitted()) {j["style"] = t.style;}
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.disabled.is_omitted()) {j["disabled"] = t.disabled;}
    }
    friend void from_json(const nlohmann::json &j, Button &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("style")){j.at("style").get_to(t.style);}
        if(j.contains("label")){j.at("label").get_to(t.label);}
        if(j.contains("emoji")){j.at("emoji").get_to(t.emoji);}
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("url")){j.at("url").get_to(t.url);}
        if(j.contains("disabled")){j.at("disabled").get_to(t.disabled);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#select-menu-object-select-menu-structure
class SelectMenu: public Component{
  public:
    SelectMenu(
        field<int> type = uninitialized,
        field<std::string> custom_id = uninitialized,
        omittable_field<std::vector<SelectOption> > options = omitted,
        omittable_field<std::vector<ChannelType> > channel_types = omitted,
        omittable_field<std::string> placeholder = omitted,
        omittable_field<int> min_values = omitted,
        omittable_field<int> max_values = omitted,
        omittable_field<bool> disabled = omitted
    ):
        Component(
            type
        ),
        custom_id(custom_id),
        options(options),
        channel_types(channel_types),
        placeholder(placeholder),
        min_values(min_values),
        max_values(max_values),
        disabled(disabled)
    {}
    SelectMenu(const json &j) { from_json(j, *this); }
    
    field<std::string> custom_id;
    omittable_field<std::vector<SelectOption> > options;
    omittable_field<std::vector<ChannelType> > channel_types;
    omittable_field<std::string> placeholder;
    omittable_field<int> min_values;
    omittable_field<int> max_values;
    omittable_field<bool> disabled;

    friend void to_json(nlohmann::json &j, const SelectMenu &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.channel_types.is_omitted()) {j["channel_types"] = t.channel_types;}
        if(!t.placeholder.is_omitted()) {j["placeholder"] = t.placeholder;}
        if(!t.min_values.is_omitted()) {j["min_values"] = t.min_values;}
        if(!t.max_values.is_omitted()) {j["max_values"] = t.max_values;}
        if(!t.disabled.is_omitted()) {j["disabled"] = t.disabled;}
    }
    friend void from_json(const nlohmann::json &j, SelectMenu &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("options")){j.at("options").get_to(t.options);}
        if(j.contains("channel_types")){j.at("channel_types").get_to(t.channel_types);}
        if(j.contains("placeholder")){j.at("placeholder").get_to(t.placeholder);}
        if(j.contains("min_values")){j.at("min_values").get_to(t.min_values);}
        if(j.contains("max_values")){j.at("max_values").get_to(t.max_values);}
        if(j.contains("disabled")){j.at("disabled").get_to(t.disabled);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#text-inputs-text-input-structure
class TextInput: public Component{
  public:
    TextInput(
        field<std::string> custom_id = uninitialized,
        field<int> style = uninitialized,
        field<std::string> label = uninitialized,
        omittable_field<int> min_length = omitted,
        omittable_field<int> max_length = omitted,
        omittable_field<bool> required = omitted,
        omittable_field<std::string> value = omitted,
        omittable_field<std::string> placeholder = omitted
    ):
        Component(
            field<int>(4)
        ),
        custom_id(custom_id),
        style(style),
        label(label),
        min_length(min_length),
        max_length(max_length),
        required(required),
        value(value),
        placeholder(placeholder)
    {}
    TextInput(const json &j) { from_json(j, *this); }
    
    field<std::string> custom_id;
    field<int> style;
    field<std::string> label;
    omittable_field<int> min_length;
    omittable_field<int> max_length;
    omittable_field<bool> required;
    omittable_field<std::string> value;
    omittable_field<std::string> placeholder;

    friend void to_json(nlohmann::json &j, const TextInput &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.style.is_omitted()) {j["style"] = t.style;}
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.min_length.is_omitted()) {j["min_length"] = t.min_length;}
        if(!t.max_length.is_omitted()) {j["max_length"] = t.max_length;}
        if(!t.required.is_omitted()) {j["required"] = t.required;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.placeholder.is_omitted()) {j["placeholder"] = t.placeholder;}
    }
    friend void from_json(const nlohmann::json &j, TextInput &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("style")){j.at("style").get_to(t.style);}
        if(j.contains("label")){j.at("label").get_to(t.label);}
        if(j.contains("min_length")){j.at("min_length").get_to(t.min_length);}
        if(j.contains("max_length")){j.at("max_length").get_to(t.max_length);}
        if(j.contains("required")){j.at("required").get_to(t.required);}
        if(j.contains("value")){j.at("value").get_to(t.value);}
        if(j.contains("placeholder")){j.at("placeholder").get_to(t.placeholder);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#action-rows
class ActionRow: public Component{
  public:
    ActionRow(
        field<std::vector<Component> > components = uninitialized
    ):
        Component(
            field<int>(1)
        ),
        components(components)
    {}
    ActionRow(const json &j) { from_json(j, *this); }
    
    field<std::vector<Component> > components;

    friend void to_json(nlohmann::json &j, const ActionRow &t) {
        if(!t.components.is_omitted()) {j["components"] = t.components;}
    }
    friend void from_json(const nlohmann::json &j, ActionRow &t) {
        if(j.contains("components")){j.at("components").get_to(t.components);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object-resolved-data-structure
class ResolvedData{
  public:
    ResolvedData(
        omittable_field<std::map<Snowflake, User> > users = omitted,
        omittable_field<std::map<Snowflake, GuildMember> > members = omitted,
        omittable_field<std::map<Snowflake, Role> > roles = omitted,
        omittable_field<std::map<Snowflake, Channel> > channels = omitted,
        omittable_field<std::map<Snowflake, Message> > messages = omitted,
        omittable_field<std::map<Snowflake, Attachment> > attachments = omitted
    ):
        users(users),
        members(members),
        roles(roles),
        channels(channels),
        messages(messages),
        attachments(attachments)
    {}
    ResolvedData(const json &j) { from_json(j, *this); }
    
    omittable_field<std::map<Snowflake, User> > users;
    omittable_field<std::map<Snowflake, GuildMember> > members;
    omittable_field<std::map<Snowflake, Role> > roles;
    omittable_field<std::map<Snowflake, Channel> > channels;
    omittable_field<std::map<Snowflake, Message> > messages;
    omittable_field<std::map<Snowflake, Attachment> > attachments;

    friend void to_json(nlohmann::json &j, const ResolvedData &t) {
        if(!t.users.is_omitted()) {j["users"] = t.users;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.channels.is_omitted()) {j["channels"] = t.channels;}
        if(!t.messages.is_omitted()) {j["messages"] = t.messages;}
        if(!t.attachments.is_omitted()) {j["attachments"] = t.attachments;}
    }
    friend void from_json(const nlohmann::json &j, ResolvedData &t) {
        if(j.contains("users")){j.at("users").get_to(t.users);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("roles")){j.at("roles").get_to(t.roles);}
        if(j.contains("channels")){j.at("channels").get_to(t.channels);}
        if(j.contains("messages")){j.at("messages").get_to(t.messages);}
        if(j.contains("attachments")){j.at("attachments").get_to(t.attachments);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object-application-command-interaction-data-option-structure
class ApplicationCommandInteractionDataOption{
  public:
    ApplicationCommandInteractionDataOption(
        field<std::string> name = uninitialized,
        field<int> type = uninitialized,
        omittable_field<std::variant<std::string, int, double, bool> > value = omitted,
        omittable_field<std::vector<ApplicationCommandInteractionDataOption> > options = omitted,
        omittable_field<bool> focused = omitted
    ):
        name(name),
        type(type),
        value(value),
        options(options),
        focused(focused)
    {}
    ApplicationCommandInteractionDataOption(const json &j) { from_json(j, *this); }
    
    field<std::string> name;
    field<int> type;
    omittable_field<std::variant<std::string, int, double, bool> > value;
    omittable_field<std::vector<ApplicationCommandInteractionDataOption> > options;
    omittable_field<bool> focused;

    friend void to_json(nlohmann::json &j, const ApplicationCommandInteractionDataOption &t) {
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.focused.is_omitted()) {j["focused"] = t.focused;}
    }
    friend void from_json(const nlohmann::json &j, ApplicationCommandInteractionDataOption &t) {
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("value")){j.at("value").get_to(t.value);}
        if(j.contains("options")){j.at("options").get_to(t.options);}
        if(j.contains("focused")){j.at("focused").get_to(t.focused);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#message-interaction-object-message-interaction-structure
class MessageInteraction{
  public:
    MessageInteraction(
        field<Snowflake> id = uninitialized,
        field<InteractionType> type = uninitialized,
        field<std::string> name = uninitialized,
        field<User> user = uninitialized,
        omittable_field<GuildMember> member = omitted
    ):
        id(id),
        type(type),
        name(name),
        user(user),
        member(member)
    {}
    MessageInteraction(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<InteractionType> type;
    field<std::string> name;
    field<User> user;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const MessageInteraction &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
    }
    friend void from_json(const nlohmann::json &j, MessageInteraction &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-response-object-interaction-response-structure
class InteractionResponse{
  public:
    InteractionResponse(
        field<InteractionCallbackType> type = uninitialized,
        omittable_field<InteractionCallbackData> data = omitted
    ):
        type(type),
        data(data)
    {}
    InteractionResponse(const json &j) { from_json(j, *this); }
    
    field<InteractionCallbackType> type;
    omittable_field<InteractionCallbackData> data;

    friend void to_json(nlohmann::json &j, const InteractionResponse &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.data.is_omitted()) {j["data"] = t.data;}
    }
    friend void from_json(const nlohmann::json &j, InteractionResponse &t) {
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("data")){j.at("data").get_to(t.data);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-response-object-messages
class MessagesCallback{
  public:
    MessagesCallback(
        omittable_field<bool> tts = omitted,
        omittable_field<std::string> content = omitted,
        omittable_field<std::vector<Embed> > embeds = omitted,
        omittable_field<AllowedMentions> allowed_mentions = omitted,
        omittable_field<int> flags = omitted,
        omittable_field<std::vector<Component> > components = omitted,
        omittable_field<std::vector<Attachment> > attachments = omitted
    ):
        tts(tts),
        content(content),
        embeds(embeds),
        allowed_mentions(allowed_mentions),
        flags(flags),
        components(components),
        attachments(attachments)
    {}
    MessagesCallback(const json &j) { from_json(j, *this); }
    
    omittable_field<bool> tts;
    omittable_field<std::string> content;
    omittable_field<std::vector<Embed> > embeds;
    omittable_field<AllowedMentions> allowed_mentions;
    omittable_field<int> flags;
    omittable_field<std::vector<Component> > components;
    omittable_field<std::vector<Attachment> > attachments;

    friend void to_json(nlohmann::json &j, const MessagesCallback &t) {
        if(!t.tts.is_omitted()) {j["tts"] = t.tts;}
        if(!t.content.is_omitted()) {j["content"] = t.content;}
        if(!t.embeds.is_omitted()) {j["embeds"] = t.embeds;}
        if(!t.allowed_mentions.is_omitted()) {j["allowed_mentions"] = t.allowed_mentions;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
        if(!t.components.is_omitted()) {j["components"] = t.components;}
        if(!t.attachments.is_omitted()) {j["attachments"] = t.attachments;}
    }
    friend void from_json(const nlohmann::json &j, MessagesCallback &t) {
        if(j.contains("tts")){j.at("tts").get_to(t.tts);}
        if(j.contains("content")){j.at("content").get_to(t.content);}
        if(j.contains("embeds")){j.at("embeds").get_to(t.embeds);}
        if(j.contains("allowed_mentions")){j.at("allowed_mentions").get_to(t.allowed_mentions);}
        if(j.contains("flags")){j.at("flags").get_to(t.flags);}
        if(j.contains("components")){j.at("components").get_to(t.components);}
        if(j.contains("attachments")){j.at("attachments").get_to(t.attachments);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-response-object-autocomplete
class AutocompleteCallback{
  public:
    AutocompleteCallback(
        field<std::vector<ApplicationCommandOptionChoice> > choices = uninitialized
    ):
        choices(choices)
    {}
    AutocompleteCallback(const json &j) { from_json(j, *this); }
    
    field<std::vector<ApplicationCommandOptionChoice> > choices;

    friend void to_json(nlohmann::json &j, const AutocompleteCallback &t) {
        if(!t.choices.is_omitted()) {j["choices"] = t.choices;}
    }
    friend void from_json(const nlohmann::json &j, AutocompleteCallback &t) {
        if(j.contains("choices")){j.at("choices").get_to(t.choices);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-response-object-modal
class ModalCallback{
  public:
    ModalCallback(
        field<std::string> custom_id = uninitialized,
        field<std::string> title = uninitialized,
        field<std::vector<Component> > components = uninitialized
    ):
        custom_id(custom_id),
        title(title),
        components(components)
    {}
    ModalCallback(const json &j) { from_json(j, *this); }
    
    field<std::string> custom_id;
    field<std::string> title;
    field<std::vector<Component> > components;

    friend void to_json(nlohmann::json &j, const ModalCallback &t) {
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.title.is_omitted()) {j["title"] = t.title;}
        if(!t.components.is_omitted()) {j["components"] = t.components;}
    }
    friend void from_json(const nlohmann::json &j, ModalCallback &t) {
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("title")){j.at("title").get_to(t.title);}
        if(j.contains("components")){j.at("components").get_to(t.components);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#thread-member-update-thread-member-update-event-extra-fields
class ThreadMemberUpdateEvent: public ThreadMember{
  public:
    ThreadMemberUpdateEvent(
        omittable_field<Snowflake> id = omitted,
        omittable_field<Snowflake> user_id = omitted,
        field<Timestamp> join_timestamp = uninitialized,
        field<int> flags = uninitialized,
        omittable_field<GuildMember> member = omitted,
        field<Snowflake> guild_id = uninitialized
    ):
        ThreadMember(
            id,
            user_id,
            join_timestamp,
            flags,
            member
        ),
        guild_id(guild_id)
    {}
    ThreadMemberUpdateEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const ThreadMemberUpdateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, ThreadMemberUpdateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-create-guild-create-extra-fields
class GuildCreateEvent: public Guild{
  public:
    GuildCreateEvent(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        nullable_field<std::string> icon = uninitialized,
        nullable_omittable_field<std::string> icon_hash = omitted,
        nullable_field<std::string> splash = uninitialized,
        nullable_field<std::string> discovery_splash = uninitialized,
        omittable_field<bool> owner = omitted,
        field<Snowflake> owner_id = uninitialized,
        omittable_field<std::string> permissions = omitted,
        nullable_omittable_field<std::string> region = omitted,
        nullable_field<Snowflake> afk_channel_id = uninitialized,
        field<int> afk_timeout = uninitialized,
        omittable_field<bool> widget_enabled = omitted,
        nullable_omittable_field<Snowflake> widget_channel_id = omitted,
        field<int> verification_level = uninitialized,
        field<int> default_message_notifications = uninitialized,
        field<int> explicit_content_filter = uninitialized,
        field<std::vector<Role> > roles = uninitialized,
        field<std::vector<Emoji> > emojis = uninitialized,
        field<std::vector<GuildFeature> > features = uninitialized,
        field<int> mfa_level = uninitialized,
        nullable_field<Snowflake> application_id = uninitialized,
        nullable_field<Snowflake> system_channel_id = uninitialized,
        field<int> system_channel_flags = uninitialized,
        nullable_field<Snowflake> rules_channel_id = uninitialized,
        nullable_omittable_field<int> max_presences = omitted,
        omittable_field<int> max_members = omitted,
        nullable_field<std::string> vanity_url_code = uninitialized,
        nullable_field<std::string> description = uninitialized,
        nullable_field<std::string> banner = uninitialized,
        field<int> premium_tier = uninitialized,
        omittable_field<int> premium_subscription_count = omitted,
        field<std::string> preferred_locale = uninitialized,
        nullable_field<Snowflake> public_updates_channel_id = uninitialized,
        omittable_field<int> max_video_channel_users = omitted,
        omittable_field<int> approximate_member_count = omitted,
        omittable_field<int> approximate_presence_count = omitted,
        omittable_field<WelcomeScreen> welcome_screen = omitted,
        field<int> nsfw_level = uninitialized,
        omittable_field<std::vector<Sticker> > stickers = omitted,
        field<bool> premium_progress_bar_enabled = uninitialized,
        omittable_field<bool> unavailable = omitted,
        field<Timestamp> joined_at = uninitialized,
        field<bool> large = uninitialized,
        field<int> member_count = uninitialized,
        field<std::vector<VoiceState> > voice_states = uninitialized,
        field<std::vector<GuildMember> > members = uninitialized,
        field<std::vector<Channel> > channels = uninitialized,
        field<std::vector<Channel> > threads = uninitialized,
        field<std::vector<PresenceUpdate> > presences = uninitialized,
        field<std::vector<StageInstance> > stage_instances = uninitialized,
        field<std::vector<GuildScheduledEvent> > guild_scheduled_events = uninitialized
    ):
        Guild(
            id,
            name,
            icon,
            icon_hash,
            splash,
            discovery_splash,
            owner,
            owner_id,
            permissions,
            region,
            afk_channel_id,
            afk_timeout,
            widget_enabled,
            widget_channel_id,
            verification_level,
            default_message_notifications,
            explicit_content_filter,
            roles,
            emojis,
            features,
            mfa_level,
            application_id,
            system_channel_id,
            system_channel_flags,
            rules_channel_id,
            max_presences,
            max_members,
            vanity_url_code,
            description,
            banner,
            premium_tier,
            premium_subscription_count,
            preferred_locale,
            public_updates_channel_id,
            max_video_channel_users,
            approximate_member_count,
            approximate_presence_count,
            welcome_screen,
            nsfw_level,
            stickers,
            premium_progress_bar_enabled,
            unavailable
        ),
        joined_at(joined_at),
        large(large),
        member_count(member_count),
        voice_states(voice_states),
        members(members),
        channels(channels),
        threads(threads),
        presences(presences),
        stage_instances(stage_instances),
        guild_scheduled_events(guild_scheduled_events)
    {}
    GuildCreateEvent(const json &j) { from_json(j, *this); }
    
    field<Timestamp> joined_at;
    field<bool> large;
    field<int> member_count;
    field<std::vector<VoiceState> > voice_states;
    field<std::vector<GuildMember> > members;
    field<std::vector<Channel> > channels;
    field<std::vector<Channel> > threads;
    field<std::vector<PresenceUpdate> > presences;
    field<std::vector<StageInstance> > stage_instances;
    field<std::vector<GuildScheduledEvent> > guild_scheduled_events;

    friend void to_json(nlohmann::json &j, const GuildCreateEvent &t) {
        if(!t.joined_at.is_omitted()) {j["joined_at"] = t.joined_at;}
        if(!t.large.is_omitted()) {j["large"] = t.large;}
        if(!t.unavailable.is_omitted()) {j["unavailable"] = t.unavailable;}
        if(!t.member_count.is_omitted()) {j["member_count"] = t.member_count;}
        if(!t.voice_states.is_omitted()) {j["voice_states"] = t.voice_states;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.channels.is_omitted()) {j["channels"] = t.channels;}
        if(!t.threads.is_omitted()) {j["threads"] = t.threads;}
        if(!t.presences.is_omitted()) {j["presences"] = t.presences;}
        if(!t.stage_instances.is_omitted()) {j["stage_instances"] = t.stage_instances;}
        if(!t.guild_scheduled_events.is_omitted()) {j["guild_scheduled_events"] = t.guild_scheduled_events;}
    }
    friend void from_json(const nlohmann::json &j, GuildCreateEvent &t) {
        if(j.contains("joined_at")){j.at("joined_at").get_to(t.joined_at);}
        if(j.contains("large")){j.at("large").get_to(t.large);}
        if(j.contains("unavailable")){j.at("unavailable").get_to(t.unavailable);}
        if(j.contains("member_count")){j.at("member_count").get_to(t.member_count);}
        if(j.contains("voice_states")){j.at("voice_states").get_to(t.voice_states);}
        if(j.contains("members")){j.at("members").get_to(t.members);}
        if(j.contains("channels")){j.at("channels").get_to(t.channels);}
        if(j.contains("threads")){j.at("threads").get_to(t.threads);}
        if(j.contains("presences")){j.at("presences").get_to(t.presences);}
        if(j.contains("stage_instances")){j.at("stage_instances").get_to(t.stage_instances);}
        if(j.contains("guild_scheduled_events")){j.at("guild_scheduled_events").get_to(t.guild_scheduled_events);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#guild-member-add-guild-member-add-extra-fields
class GuildMemberAddEvent: public GuildMember{
  public:
    GuildMemberAddEvent(
        omittable_field<User> user = omitted,
        nullable_omittable_field<std::string> nick = omitted,
        nullable_omittable_field<std::string> avatar = omitted,
        field<std::vector<Snowflake> > roles = uninitialized,
        field<Timestamp> joined_at = uninitialized,
        nullable_omittable_field<Timestamp> premium_since = omitted,
        field<bool> deaf = uninitialized,
        field<bool> mute = uninitialized,
        field<int> flags = uninitialized,
        omittable_field<bool> pending = omitted,
        omittable_field<std::string> permissions = omitted,
        nullable_omittable_field<Timestamp> communication_disabled_until = omitted,
        field<Snowflake> guild_id = uninitialized
    ):
        GuildMember(
            user,
            nick,
            avatar,
            roles,
            joined_at,
            premium_since,
            deaf,
            mute,
            flags,
            pending,
            permissions,
            communication_disabled_until
        ),
        guild_id(guild_id)
    {}
    GuildMemberAddEvent(const json &j) { from_json(j, *this); }
    
    field<Snowflake> guild_id;

    friend void to_json(nlohmann::json &j, const GuildMemberAddEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
    }
    friend void from_json(const nlohmann::json &j, GuildMemberAddEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
    }
};

// https://discord.com/developers/docs/topics/gateway-events#message-create-message-create-extra-fields
class MessageCreateEvent: public Message{
  public:
    MessageCreateEvent(
        field<Snowflake> id = uninitialized,
        field<Snowflake> channel_id = uninitialized,
        field<User> author = uninitialized,
        field<std::string> content = uninitialized,
        field<Timestamp> timestamp = uninitialized,
        nullable_field<Timestamp> edited_timestamp = uninitialized,
        field<bool> tts = uninitialized,
        field<bool> mention_everyone = uninitialized,
        field<std::vector<User> > mentions = uninitialized,
        field<std::vector<Snowflake> > mention_roles = uninitialized,
        omittable_field<std::vector<ChannelMention> > mention_channels = omitted,
        field<std::vector<Attachment> > attachments = uninitialized,
        field<std::vector<Embed> > embeds = uninitialized,
        omittable_field<std::vector<Reaction> > reactions = omitted,
        omittable_field<std::variant<int, std::string> > nonce = omitted,
        field<bool> pinned = uninitialized,
        omittable_field<Snowflake> webhook_id = omitted,
        field<int> type = uninitialized,
        omittable_field<MessageActivity> activity = omitted,
        omittable_field<Application> application = omitted,
        omittable_field<Snowflake> application_id = omitted,
        omittable_field<MessageReference> message_reference = omitted,
        omittable_field<int> flags = omitted,
        nullable_omittable_field<Message> referenced_message = omitted,
        omittable_field<MessageInteraction> interaction = omitted,
        omittable_field<Channel> thread = omitted,
        omittable_field<std::vector<Component> > components = omitted,
        omittable_field<std::vector<StickerItem> > sticker_items = omitted,
        omittable_field<std::vector<Sticker> > stickers = omitted,
        omittable_field<int> position = omitted,
        omittable_field<RoleSubscriptionData> role_subscription_data = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<GuildMember> member = omitted
    ):
        Message(
            id,
            channel_id,
            author,
            content,
            timestamp,
            edited_timestamp,
            tts,
            mention_everyone,
            mentions,
            mention_roles,
            mention_channels,
            attachments,
            embeds,
            reactions,
            nonce,
            pinned,
            webhook_id,
            type,
            activity,
            application,
            application_id,
            message_reference,
            flags,
            referenced_message,
            interaction,
            thread,
            components,
            sticker_items,
            stickers,
            position,
            role_subscription_data
        ),
        guild_id(guild_id),
        member(member)
    {}
    MessageCreateEvent(const json &j) { from_json(j, *this); }
    
    omittable_field<Snowflake> guild_id;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const MessageCreateEvent &t) {
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.mentions.is_omitted()) {j["mentions"] = t.mentions;}
    }
    friend void from_json(const nlohmann::json &j, MessageCreateEvent &t) {
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
        if(j.contains("mentions")){j.at("mentions").get_to(t.mentions);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object-application-command-data-structure
class ApplicationCommandData: public ResolvedData{
  public:
    ApplicationCommandData(
        omittable_field<std::map<Snowflake, User> > users = omitted,
        omittable_field<std::map<Snowflake, GuildMember> > members = omitted,
        omittable_field<std::map<Snowflake, Role> > roles = omitted,
        omittable_field<std::map<Snowflake, Channel> > channels = omitted,
        omittable_field<std::map<Snowflake, Message> > messages = omitted,
        omittable_field<std::map<Snowflake, Attachment> > attachments = omitted,
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<int> type = uninitialized,
        omittable_field<ResolvedData> resolved = omitted,
        omittable_field<std::vector<ApplicationCommandInteractionDataOption> > options = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<Snowflake> target_id = omitted
    ):
        ResolvedData(
            users,
            members,
            roles,
            channels,
            messages,
            attachments
        ),
        id(id),
        name(name),
        type(type),
        resolved(resolved),
        options(options),
        guild_id(guild_id),
        target_id(target_id)
    {}
    ApplicationCommandData(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<std::string> name;
    field<int> type;
    omittable_field<ResolvedData> resolved;
    omittable_field<std::vector<ApplicationCommandInteractionDataOption> > options;
    omittable_field<Snowflake> guild_id;
    omittable_field<Snowflake> target_id;

    friend void to_json(nlohmann::json &j, const ApplicationCommandData &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.resolved.is_omitted()) {j["resolved"] = t.resolved;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.target_id.is_omitted()) {j["target_id"] = t.target_id;}
    }
    friend void from_json(const nlohmann::json &j, ApplicationCommandData &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("name")){j.at("name").get_to(t.name);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("resolved")){j.at("resolved").get_to(t.resolved);}
        if(j.contains("options")){j.at("options").get_to(t.options);}
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("target_id")){j.at("target_id").get_to(t.target_id);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object-message-component-data-structure
class MessageComponentData: public ResolvedData{
  public:
    MessageComponentData(
        omittable_field<std::map<Snowflake, User> > users = omitted,
        omittable_field<std::map<Snowflake, GuildMember> > members = omitted,
        omittable_field<std::map<Snowflake, Role> > roles = omitted,
        omittable_field<std::map<Snowflake, Channel> > channels = omitted,
        omittable_field<std::map<Snowflake, Message> > messages = omitted,
        omittable_field<std::map<Snowflake, Attachment> > attachments = omitted,
        field<std::string> custom_id = uninitialized,
        field<int> component_type = uninitialized,
        omittable_field<std::vector<SelectOption> > values = omitted
    ):
        ResolvedData(
            users,
            members,
            roles,
            channels,
            messages,
            attachments
        ),
        custom_id(custom_id),
        component_type(component_type),
        values(values)
    {}
    MessageComponentData(const json &j) { from_json(j, *this); }
    
    field<std::string> custom_id;
    field<int> component_type;
    omittable_field<std::vector<SelectOption> > values;

    friend void to_json(nlohmann::json &j, const MessageComponentData &t) {
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.component_type.is_omitted()) {j["component_type"] = t.component_type;}
        if(!t.values.is_omitted()) {j["values"] = t.values;}
    }
    friend void from_json(const nlohmann::json &j, MessageComponentData &t) {
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("component_type")){j.at("component_type").get_to(t.component_type);}
        if(j.contains("values")){j.at("values").get_to(t.values);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object-modal-submit-data-structure
class ModalSubmitData: public ResolvedData{
  public:
    ModalSubmitData(
        omittable_field<std::map<Snowflake, User> > users = omitted,
        omittable_field<std::map<Snowflake, GuildMember> > members = omitted,
        omittable_field<std::map<Snowflake, Role> > roles = omitted,
        omittable_field<std::map<Snowflake, Channel> > channels = omitted,
        omittable_field<std::map<Snowflake, Message> > messages = omitted,
        omittable_field<std::map<Snowflake, Attachment> > attachments = omitted,
        field<std::string> custom_id = uninitialized,
        field<std::vector<Component> > components = uninitialized
    ):
        ResolvedData(
            users,
            members,
            roles,
            channels,
            messages,
            attachments
        ),
        custom_id(custom_id),
        components(components)
    {}
    ModalSubmitData(const json &j) { from_json(j, *this); }
    
    field<std::string> custom_id;
    field<std::vector<Component> > components;

    friend void to_json(nlohmann::json &j, const ModalSubmitData &t) {
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.components.is_omitted()) {j["components"] = t.components;}
    }
    friend void from_json(const nlohmann::json &j, ModalSubmitData &t) {
        if(j.contains("custom_id")){j.at("custom_id").get_to(t.custom_id);}
        if(j.contains("components")){j.at("components").get_to(t.components);}
    }
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object-interaction-structure
class Interaction{
  public:
    Interaction(
        field<Snowflake> id = uninitialized,
        field<Snowflake> application_id = uninitialized,
        field<InteractionType> type = uninitialized,
        omittable_field<std::variant<ApplicationCommandData, MessageComponentData, ModalSubmitData, ResolvedData> > data = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<Snowflake> channel_id = omitted,
        omittable_field<GuildMember> member = omitted,
        omittable_field<User> user = omitted,
        field<std::string> token = uninitialized,
        field<int> version = uninitialized,
        omittable_field<Message> message = omitted,
        omittable_field<std::string> app_permissions = omitted,
        omittable_field<std::string> locale = omitted,
        omittable_field<std::string> guild_locale = omitted
    ):
        id(id),
        application_id(application_id),
        type(type),
        data(data),
        guild_id(guild_id),
        channel_id(channel_id),
        member(member),
        user(user),
        token(token),
        version(version),
        message(message),
        app_permissions(app_permissions),
        locale(locale),
        guild_locale(guild_locale)
    {}
    Interaction(const json &j) { from_json(j, *this); }
    
    field<Snowflake> id;
    field<Snowflake> application_id;
    field<InteractionType> type;
    omittable_field<std::variant<ApplicationCommandData, MessageComponentData, ModalSubmitData, ResolvedData> > data;
    omittable_field<Snowflake> guild_id;
    omittable_field<Snowflake> channel_id;
    omittable_field<GuildMember> member;
    omittable_field<User> user;
    field<std::string> token;
    field<int> version;
    omittable_field<Message> message;
    omittable_field<std::string> app_permissions;
    omittable_field<std::string> locale;
    omittable_field<std::string> guild_locale;

    friend void to_json(nlohmann::json &j, const Interaction &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.data.is_omitted()) {j["data"] = t.data;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.version.is_omitted()) {j["version"] = t.version;}
        if(!t.message.is_omitted()) {j["message"] = t.message;}
        if(!t.app_permissions.is_omitted()) {j["app_permissions"] = t.app_permissions;}
        if(!t.locale.is_omitted()) {j["locale"] = t.locale;}
        if(!t.guild_locale.is_omitted()) {j["guild_locale"] = t.guild_locale;}
    }
    friend void from_json(const nlohmann::json &j, Interaction &t) {
        if(j.contains("id")){j.at("id").get_to(t.id);}
        if(j.contains("application_id")){j.at("application_id").get_to(t.application_id);}
        if(j.contains("type")){j.at("type").get_to(t.type);}
        if(j.contains("data")){
            switch(t.type) {
            case (int)InteractionType::APPLICATION_COMMAND:
            case (int)InteractionType::APPLICATION_COMMAND_AUTOCOMPLETE:
                j.at("data").get<ApplicationCommandData>();
            case (int)InteractionType::MESSAGE_COMPONENT:
                j.at("data").get<MessageComponentData>();
            case (int)InteractionType::MODAL_SUBMIT:
                j.at("data").get<ModalSubmitData>();
            default:
                throw std::runtime_error("Unknown interaction type");
            }
        }
        if(j.contains("guild_id")){j.at("guild_id").get_to(t.guild_id);}
        if(j.contains("channel_id")){j.at("channel_id").get_to(t.channel_id);}
        if(j.contains("member")){j.at("member").get_to(t.member);}
        if(j.contains("user")){j.at("user").get_to(t.user);}
        if(j.contains("token")){j.at("token").get_to(t.token);}
        if(j.contains("version")){j.at("version").get_to(t.version);}
        if(j.contains("message")){j.at("message").get_to(t.message);}
        if(j.contains("app_permissions")){j.at("app_permissions").get_to(t.app_permissions);}
        if(j.contains("locale")){j.at("locale").get_to(t.locale);}
        if(j.contains("guild_locale")){j.at("guild_locale").get_to(t.guild_locale);}
    }
};
