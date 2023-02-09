#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
    friend void from_json(const nlohmann::json &j, GetCurrentAuthorizationInformationResponse &t {
        if(j.contains(application)){j.at(application).get_to(t.application);}
        if(j.contains(scopes)){j.at(scopes).get_to(t.scopes);}
        if(j.contains(expires)){j.at(expires).get_to(t.expires);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
    }
};
