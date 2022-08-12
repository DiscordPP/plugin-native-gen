#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/channel#channel-object
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
        omittable_field<int> total_message_sent = omitted
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
        total_message_sent(total_message_sent)
    {}
    
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

    friend void to_json(nlohmann::json &j, const Channel &t) {
        //ToJsonExtra
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
    }
};
// https://discord.com/developers/docs/resources/channel#message-object
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
        omittable_field<int> position = omitted
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
        position(position)
    {}
    
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

    friend void to_json(nlohmann::json &j, const Message &t) {
        //ToJsonExtra
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
    }
};
// https://discord.com/developers/docs/resources/channel#message-object
class MessageActivity{
  public:
    MessageActivity(
        field<int> type = uninitialized,
        omittable_field<std::string> party_id = omitted
    ): 
        type(type),
        party_id(party_id)
    {}
    
    field<int> type;
    omittable_field<std::string> party_id;

    friend void to_json(nlohmann::json &j, const MessageActivity &t) {
        //ToJsonExtra
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.party_id.is_omitted()) {j["party_id"] = t.party_id;}
    }
};
// https://discord.com/developers/docs/resources/channel#message-reference-object
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
    
    omittable_field<Snowflake> message_id;
    omittable_field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    omittable_field<bool> fail_if_not_exists;

    friend void to_json(nlohmann::json &j, const MessageReference &t) {
        //ToJsonExtra
        if(!t.message_id.is_omitted()) {j["message_id"] = t.message_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.fail_if_not_exists.is_omitted()) {j["fail_if_not_exists"] = t.fail_if_not_exists;}
    }
};
// https://discord.com/developers/docs/resources/channel#followed-channel-object
class FollowedChannel{
  public:
    FollowedChannel(
        field<Snowflake> channel_id = uninitialized,
        field<Snowflake> webhook_id = uninitialized
    ): 
        channel_id(channel_id),
        webhook_id(webhook_id)
    {}
    
    field<Snowflake> channel_id;
    field<Snowflake> webhook_id;

    friend void to_json(nlohmann::json &j, const FollowedChannel &t) {
        //ToJsonExtra
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.webhook_id.is_omitted()) {j["webhook_id"] = t.webhook_id;}
    }
};
// https://discord.com/developers/docs/resources/channel#reaction-object
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
    
    field<int> count;
    field<bool> me;
    field<Emoji> emoji;

    friend void to_json(nlohmann::json &j, const Reaction &t) {
        //ToJsonExtra
        if(!t.count.is_omitted()) {j["count"] = t.count;}
        if(!t.me.is_omitted()) {j["me"] = t.me;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
    }
};
// https://discord.com/developers/docs/resources/channel#overwrite-object
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
    
    field<Snowflake> id;
    field<int> type;
    field<std::string> allow;
    field<std::string> deny;

    friend void to_json(nlohmann::json &j, const Overwrite &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.allow.is_omitted()) {j["allow"] = t.allow;}
        if(!t.deny.is_omitted()) {j["deny"] = t.deny;}
    }
};
// https://discord.com/developers/docs/resources/channel#thread-metadata-object
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
    
    field<bool> archived;
    field<int> auto_archive_duration;
    field<Timestamp> archive_timestamp;
    field<bool> locked;
    omittable_field<bool> invitable;
    nullable_omittable_field<Timestamp> create_timestamp;

    friend void to_json(nlohmann::json &j, const ThreadMetadata &t) {
        //ToJsonExtra
        if(!t.archived.is_omitted()) {j["archived"] = t.archived;}
        if(!t.auto_archive_duration.is_omitted()) {j["auto_archive_duration"] = t.auto_archive_duration;}
        if(!t.archive_timestamp.is_omitted()) {j["archive_timestamp"] = t.archive_timestamp;}
        if(!t.locked.is_omitted()) {j["locked"] = t.locked;}
        if(!t.invitable.is_omitted()) {j["invitable"] = t.invitable;}
        if(!t.create_timestamp.is_omitted()) {j["create_timestamp"] = t.create_timestamp;}
    }
};
// https://discord.com/developers/docs/resources/channel#thread-member-object
class ThreadMember{
  public:
    ThreadMember(
        omittable_field<Snowflake> id = omitted,
        omittable_field<Snowflake> user_id = omitted,
        field<Timestamp> join_timestamp = uninitialized,
        field<int> flags = uninitialized
    ): 
        id(id),
        user_id(user_id),
        join_timestamp(join_timestamp),
        flags(flags)
    {}
    
    omittable_field<Snowflake> id;
    omittable_field<Snowflake> user_id;
    field<Timestamp> join_timestamp;
    field<int> flags;

    friend void to_json(nlohmann::json &j, const ThreadMember &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.user_id.is_omitted()) {j["user_id"] = t.user_id;}
        if(!t.join_timestamp.is_omitted()) {j["join_timestamp"] = t.join_timestamp;}
        if(!t.flags.is_omitted()) {j["flags"] = t.flags;}
    }
};
// https://discord.com/developers/docs/resources/channel#embed-object
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
        //ToJsonExtra
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
};
// https://discord.com/developers/docs/resources/channel#embed-object
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
    
    field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    friend void to_json(nlohmann::json &j, const EmbedThumbnail &t) {
        //ToJsonExtra
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.proxy_url.is_omitted()) {j["proxy_url"] = t.proxy_url;}
        if(!t.height.is_omitted()) {j["height"] = t.height;}
        if(!t.width.is_omitted()) {j["width"] = t.width;}
    }
};
// https://discord.com/developers/docs/resources/channel#embed-object
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
    
    omittable_field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    friend void to_json(nlohmann::json &j, const EmbedVideo &t) {
        //ToJsonExtra
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.proxy_url.is_omitted()) {j["proxy_url"] = t.proxy_url;}
        if(!t.height.is_omitted()) {j["height"] = t.height;}
        if(!t.width.is_omitted()) {j["width"] = t.width;}
    }
};
// https://discord.com/developers/docs/resources/channel#embed-object
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
    
    field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    friend void to_json(nlohmann::json &j, const EmbedImage &t) {
        //ToJsonExtra
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.proxy_url.is_omitted()) {j["proxy_url"] = t.proxy_url;}
        if(!t.height.is_omitted()) {j["height"] = t.height;}
        if(!t.width.is_omitted()) {j["width"] = t.width;}
    }
};
// https://discord.com/developers/docs/resources/channel#embed-object
class EmbedProvider{
  public:
    EmbedProvider(
        omittable_field<std::string> name = omitted,
        omittable_field<std::string> url = omitted
    ): 
        name(name),
        url(url)
    {}
    
    omittable_field<std::string> name;
    omittable_field<std::string> url;

    friend void to_json(nlohmann::json &j, const EmbedProvider &t) {
        //ToJsonExtra
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
    }
};
// https://discord.com/developers/docs/resources/channel#embed-object
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
    
    field<std::string> name;
    omittable_field<std::string> url;
    omittable_field<std::string> icon_url;
    omittable_field<std::string> proxy_icon_url;

    friend void to_json(nlohmann::json &j, const EmbedAuthor &t) {
        //ToJsonExtra
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.icon_url.is_omitted()) {j["icon_url"] = t.icon_url;}
        if(!t.proxy_icon_url.is_omitted()) {j["proxy_icon_url"] = t.proxy_icon_url;}
    }
};
// https://discord.com/developers/docs/resources/channel#embed-object
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
    
    field<std::string> text;
    omittable_field<std::string> icon_url;
    omittable_field<std::string> proxy_icon_url;

    friend void to_json(nlohmann::json &j, const EmbedFooter &t) {
        //ToJsonExtra
        if(!t.text.is_omitted()) {j["text"] = t.text;}
        if(!t.icon_url.is_omitted()) {j["icon_url"] = t.icon_url;}
        if(!t.proxy_icon_url.is_omitted()) {j["proxy_icon_url"] = t.proxy_icon_url;}
    }
};
// https://discord.com/developers/docs/resources/channel#embed-object
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
    
    field<std::string> name;
    field<std::string> value;
    omittable_field<bool> display_inline;

    friend void to_json(nlohmann::json &j, const EmbedField &t) {
        //ToJsonExtra
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.display_inline.is_omitted()) {j["inline"] = t.display_inline;}
    }
};
// https://discord.com/developers/docs/resources/channel#attachment-object
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
        //ToJsonExtra
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
};
// https://discord.com/developers/docs/resources/channel#channel-mention-object
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
    
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<int> type;
    field<std::string> name;

    friend void to_json(nlohmann::json &j, const ChannelMention &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
    }
};
// https://discord.com/developers/docs/resources/channel#allowed-mentions-object
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
    
    field<std::vector<AllowedMentionType> > parse;
    field<std::vector<Snowflake> > roles;
    field<std::vector<Snowflake> > users;
    field<bool> replied_user;

    friend void to_json(nlohmann::json &j, const AllowedMentions &t) {
        //ToJsonExtra
        if(!t.parse.is_omitted()) {j["parse"] = t.parse;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.users.is_omitted()) {j["users"] = t.users;}
        if(!t.replied_user.is_omitted()) {j["replied_user"] = t.replied_user;}
    }
};
