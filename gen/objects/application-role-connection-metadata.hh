#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/application-role-connection-metadata#application-role-connection-metadata-object-application-role-connection-metadata-structure
class ApplicationRoleConnectionMetadata{
  public:
    ApplicationRoleConnectionMetadata(
        field<Applicationroleconnectionmetadatatype> type = uninitialized,
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
    
    field<Applicationroleconnectionmetadatatype> type;
    field<std::string> key;
    field<std::string> name;
    omittable_field<std::map<Locale, std::string>> name_localizations;
    field<std::string> description;
    omittable_field<std::map<Locale, std::string>> description_localizations;

    friend void to_json(nlohmann::json &j, const ApplicationRoleConnectionMetadata &t) {
        //ToJsonExtra
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.key.is_omitted()) {j["key"] = t.key;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.name_localizations.is_omitted()) {j["name_localizations"] = t.name_localizations;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.description_localizations.is_omitted()) {j["description_localizations"] = t.description_localizations;}
    }
};
