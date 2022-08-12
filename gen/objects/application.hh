#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/application#application-object
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
        omittable_field<std::string> custom_install_url = omitted
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
        custom_install_url(custom_install_url)
    {}
    
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

    friend void to_json(nlohmann::json &j, const Application &t) {
        //ToJsonExtra
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
    }
};
// https://discord.com/developers/docs/resources/application#install-params-object
class InstallParams{
  public:
    InstallParams(
        field<std::vector<std::string> > scopes = uninitialized,
        field<std::string> permissions = uninitialized
    ): 
        scopes(scopes),
        permissions(permissions)
    {}
    
    field<std::vector<std::string> > scopes;
    field<std::string> permissions;

    friend void to_json(nlohmann::json &j, const InstallParams &t) {
        //ToJsonExtra
        if(!t.scopes.is_omitted()) {j["scopes"] = t.scopes;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
    }
};
