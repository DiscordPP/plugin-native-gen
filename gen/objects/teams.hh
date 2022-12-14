#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
    
    nullable_field<std::string> icon;
    field<Snowflake> id;
    field<std::vector<TeamMember> > members;
    field<std::string> name;
    field<Snowflake> owner_user_id;

    friend void to_json(nlohmann::json &j, const Team &t) {
        //ToJsonExtra
        if(!t.icon.is_omitted()) {j["icon"] = t.icon;}
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.owner_user_id.is_omitted()) {j["owner_user_id"] = t.owner_user_id;}
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
    
    field<int> membership_state;
    field<std::vector<std::string> > permissions;
    field<Snowflake> team_id;
    field<User> user;

    friend void to_json(nlohmann::json &j, const TeamMember &t) {
        //ToJsonExtra
        if(!t.membership_state.is_omitted()) {j["membership_state"] = t.membership_state;}
        if(!t.permissions.is_omitted()) {j["permissions"] = t.permissions;}
        if(!t.team_id.is_omitted()) {j["team_id"] = t.team_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
    }
};
