#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
        //ToJsonExtra
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
    
    field<int> uses;
    field<int> max_uses;
    field<int> max_age;
    field<bool> temporary;
    field<Timestamp> created_at;

    friend void to_json(nlohmann::json &j, const InviteMetadata &t) {
        //ToJsonExtra
        if(!t.uses.is_omitted()) {j["uses"] = t.uses;}
        if(!t.max_uses.is_omitted()) {j["max_uses"] = t.max_uses;}
        if(!t.max_age.is_omitted()) {j["max_age"] = t.max_age;}
        if(!t.temporary.is_omitted()) {j["temporary"] = t.temporary;}
        if(!t.created_at.is_omitted()) {j["created_at"] = t.created_at;}
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
    
    field<std::vector<GuildMember> > members;
    field<int> participant_count;
    field<int> speaker_count;
    field<std::string> topic;

    friend void to_json(nlohmann::json &j, const InviteStageInstance &t) {
        //ToJsonExtra
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.participant_count.is_omitted()) {j["participant_count"] = t.participant_count;}
        if(!t.speaker_count.is_omitted()) {j["speaker_count"] = t.speaker_count;}
        if(!t.topic.is_omitted()) {j["topic"] = t.topic;}
    }
};
