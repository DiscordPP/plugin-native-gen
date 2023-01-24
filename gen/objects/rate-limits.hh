#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
    friend void from_json(const nlohmann::json &j, RateLimitResponse &t {
        if(j.contains(message)){j.at(message).get_to(t.message);}
        if(j.contains(retry_after)){j.at(retry_after).get_to(t.retry_after);}
        if(j.contains(global)){j.at(global).get_to(t.global);}
        if(j.contains(code)){j.at(code).get_to(t.code);}
    }
};
