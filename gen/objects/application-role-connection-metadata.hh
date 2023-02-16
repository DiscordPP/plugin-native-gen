#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
