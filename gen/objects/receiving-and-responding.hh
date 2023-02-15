#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object-application-command-data-structure
class ApplicationCommandData{
  public:
    ApplicationCommandData(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<int> type = uninitialized,
        omittable_field<ResolvedData> resolved = omitted,
        omittable_field<std::vector<ApplicationCommandInteractionDataOption> > options = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<Snowflake> target_id = omitted
    ):
        id(id),
        name(name),
        type(type),
        resolved(resolved),
        options(options),
        guild_id(guild_id),
        target_id(target_id)
    {}
    
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
class MessageComponentData{
  public:
    MessageComponentData(
        field<std::string> custom_id = uninitialized,
        field<int> component_type = uninitialized,
        omittable_field<std::vector<SelectOption> > values = omitted
    ):
        custom_id(custom_id),
        component_type(component_type),
        values(values)
    {}
    
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
class ModalSubmitData{
  public:
    ModalSubmitData(
        field<std::string> custom_id = uninitialized,
        field<std::vector<Component> > components = uninitialized
    ):
        custom_id(custom_id),
        components(components)
    {}
    
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
        field<std::vector<Choice> > choices = uninitialized
    ):
        choices(choices)
    {}
    
    field<std::vector<Choice> > choices;

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
        if(j.contains("data")){j.at("data").get_to(t.data);}
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
