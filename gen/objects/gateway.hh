#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
