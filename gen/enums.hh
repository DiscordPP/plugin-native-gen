#pragma once

namespace discordpp {


// Application Commands //

enum class ApplicationCommandType : int {
    CHAT_INPUT = 1,
    USER = 2,
    MESSAGE = 3
};

enum class ApplicationCommandOptionType : int {
    SUB_COMMAND = 1,
    SUB_COMMAND_GROUP = 2,
    STRING = 3,
    INTEGER = 4,
    BOOLEAN = 5,
    USER = 6,
    CHANNEL = 7,
    ROLE = 8,
    MENTIONABLE = 9,
    NUMBER = 10,
    ATTACHMENT = 11
};

enum class ApplicationCommandPermissionType : int {
    ROLE = 1,
    USER = 2,
    CHANNEL = 3
};


// Message Components //

enum class ButtonStyle : int {
    Primary = 1,
    Secondary = 2,
    Success = 3,
    Danger = 4,
    Link = 5
};

enum class TextInputStyle : int {
    Short = 1,
    Paragraph = 2
};


// Receiving and Responding //

enum class InteractionType : int {
    PING = 1,
    APPLICATION_COMMAND = 2,
    MESSAGE_COMPONENT = 3,
    APPLICATION_COMMAND_AUTOCOMPLETE = 4,
    MODAL_SUBMIT = 5
};

enum class InteractionCallbackType : int {
    PONG = 1,
    CHANNEL_MESSAGE_WITH_SOURCE = 4,
    DEFERRED_CHANNEL_MESSAGE_WITH_SOURCE = 5,
    DEFERRED_UPDATE_MESSAGE = 6,
    UPDATE_MESSAGE = 7,
    APPLICATION_COMMAND_AUTOCOMPLETE_RESULT = 8,
    MODAL = 9
};


// Application //

enum class ApplicationFlag : int {
    GATEWAY_PRESENCE = 1,
    GATEWAY_PRESENCE_LIMITED = 1,
    GATEWAY_GUILD_MEMBERS = 1,
    GATEWAY_GUILD_MEMBERS_LIMITED = 1,
    VERIFICATION_PENDING_GUILD_LIMIT = 1,
    EMBEDDED = 1,
    GATEWAY_MESSAGE_CONTENT = 1,
    GATEWAY_MESSAGE_CONTENT_LIMITED = 1,
    APPLICATION_COMMAND_BADGE = 1
};


// Application Role Connection Metadata //

enum class ApplicationRoleConnectionMetadataType : int {
    INTEGER_LESS_THAN_OR_EQUAL = 1,
    INTEGER_GREATER_THAN_OR_EQUAL = 2,
    INTEGER_EQUAL = 3,
    INTEGER_NOT_EQUAL = 4,
    DATETIME_LESS_THAN_OR_EQUAL = 5,
    DATETIME_GREATER_THAN_OR_EQUAL = 6,
    BOOLEAN_EQUAL = 7,
    BOOLEAN_NOT_EQUAL = 8
};


// Audit Log //

enum class AuditLogEvent : int {
    GUILD_UPDATE = 1,
    CHANNEL_CREATE = 10,
    CHANNEL_UPDATE = 11,
    CHANNEL_DELETE = 12,
    CHANNEL_OVERWRITE_CREATE = 13,
    CHANNEL_OVERWRITE_UPDATE = 14,
    CHANNEL_OVERWRITE_DELETE = 15,
    MEMBER_KICK = 20,
    MEMBER_PRUNE = 21,
    MEMBER_BAN_ADD = 22,
    MEMBER_BAN_REMOVE = 23,
    MEMBER_UPDATE = 24,
    MEMBER_ROLE_UPDATE = 25,
    MEMBER_MOVE = 26,
    MEMBER_DISCONNECT = 27,
    BOT_ADD = 28,
    ROLE_CREATE = 30,
    ROLE_UPDATE = 31,
    ROLE_DELETE = 32,
    INVITE_CREATE = 40,
    INVITE_UPDATE = 41,
    INVITE_DELETE = 42,
    WEBHOOK_CREATE = 50,
    WEBHOOK_UPDATE = 51,
    WEBHOOK_DELETE = 52,
    EMOJI_CREATE = 60,
    EMOJI_UPDATE = 61,
    EMOJI_DELETE = 62,
    MESSAGE_DELETE = 72,
    MESSAGE_BULK_DELETE = 73,
    MESSAGE_PIN = 74,
    MESSAGE_UNPIN = 75,
    INTEGRATION_CREATE = 80,
    INTEGRATION_UPDATE = 81,
    INTEGRATION_DELETE = 82,
    STAGE_INSTANCE_CREATE = 83,
    STAGE_INSTANCE_UPDATE = 84,
    STAGE_INSTANCE_DELETE = 85,
    STICKER_CREATE = 90,
    STICKER_UPDATE = 91,
    STICKER_DELETE = 92,
    GUILD_SCHEDULED_EVENT_CREATE = 100,
    GUILD_SCHEDULED_EVENT_UPDATE = 101,
    GUILD_SCHEDULED_EVENT_DELETE = 102,
    THREAD_CREATE = 110,
    THREAD_UPDATE = 111,
    THREAD_DELETE = 112,
    APPLICATION_COMMAND_PERMISSION_UPDATE = 121,
    AUTO_MODERATION_RULE_CREATE = 140,
    AUTO_MODERATION_RULE_UPDATE = 141,
    AUTO_MODERATION_RULE_DELETE = 142,
    AUTO_MODERATION_BLOCK_MESSAGE = 143,
    AUTO_MODERATION_FLAG_TO_CHANNEL = 144,
    AUTO_MODERATION_USER_COMMUNICATION_DISABLED = 145
};


// Auto Moderation //

enum class TriggerType : int {
    KEYWORD = 1,
    SPAM = 3,
    KEYWORD_PRESET = 4,
    MENTION_SPAM = 5
};

enum class KeywordPresetType : int {
    PROFANITY = 1,
    SEXUAL_CONTENT = 2,
    SLURS = 3
};

enum class EventType : int {
    MESSAGE_SEND = 1
};

enum class ActionType : int {
    BLOCK_MESSAGE = 1,
    SEND_ALERT_MESSAGE = 2,
    TIMEOUT = 3
};


// Channel //

enum class ChannelType : int {
    GUILD_TEXT = 0,
    DM = 1,
    GUILD_VOICE = 2,
    GROUP_DM = 3,
    GUILD_CATEGORY = 4,
    GUILD_ANNOUNCEMENT = 5,
    ANNOUNCEMENT_THREAD = 10,
    PUBLIC_THREAD = 11,
    PRIVATE_THREAD = 12,
    GUILD_STAGE_VOICE = 13,
    GUILD_DIRECTORY = 14,
    GUILD_FORUM = 15
};

enum class VideoQualityMode : int {
    AUTO = 1,
    FULL = 2
};

enum class ChannelFlag : int {
    PINNED = 1,
    REQUIRE_TAG = 1
};

enum class SortOrderType : int {
    LATEST_ACTIVITY = 0,
    CREATION_DATE = 1
};

enum class ForumLayoutType : int {
    NOT_SET = 0,
    LIST_VIEW = 1,
    GALLERY_VIEW = 2
};

enum class MessageType : int {
    DEFAULT = 0,
    RECIPIENT_ADD = 1,
    RECIPIENT_REMOVE = 2,
    CALL = 3,
    CHANNEL_NAME_CHANGE = 4,
    CHANNEL_ICON_CHANGE = 5,
    CHANNEL_PINNED_MESSAGE = 6,
    USER_JOIN = 7,
    GUILD_BOOST = 8,
    GUILD_BOOST_TIER_1 = 9,
    GUILD_BOOST_TIER_2 = 10,
    GUILD_BOOST_TIER_3 = 11,
    CHANNEL_FOLLOW_ADD = 12,
    GUILD_DISCOVERY_DISQUALIFIED = 14,
    GUILD_DISCOVERY_REQUALIFIED = 15,
    GUILD_DISCOVERY_GRACE_PERIOD_INITIAL_WARNING = 16,
    GUILD_DISCOVERY_GRACE_PERIOD_FINAL_WARNING = 17,
    THREAD_CREATED = 18,
    REPLY = 19,
    CHAT_INPUT_COMMAND = 20,
    THREAD_STARTER_MESSAGE = 21,
    GUILD_INVITE_REMINDER = 22,
    CONTEXT_MENU_COMMAND = 23,
    AUTO_MODERATION_ACTION = 24,
    ROLE_SUBSCRIPTION_PURCHASE = 25,
    INTERACTION_PREMIUM_UPSELL = 26,
    GUILD_APPLICATION_PREMIUM_SUBSCRIPTION = 32
};

enum class MessageActivityType : int {
    JOIN = 1,
    SPECTATE = 2,
    LISTEN = 3,
    JOIN_REQUEST = 5
};

enum class MessageFlag : int {
    CROSSPOSTED = 1,
    IS_CROSSPOST = 1,
    SUPPRESS_EMBEDS = 1,
    SOURCE_MESSAGE_DELETED = 1,
    URGENT = 1,
    HAS_THREAD = 1,
    EPHEMERAL = 1,
    LOADING = 1,
    FAILED_TO_MENTION_SOME_ROLES_IN_THREAD = 1,
    SUPPRESS_NOTIFICATIONS = 1
};

enum class EmbedType {
    rich,
    image,
    video,
    gifv,
    article,
    link
};
NLOHMANN_JSON_SERIALIZE_ENUM(EmbedType, {
    {EmbedType::rich, "rich"},
    {EmbedType::image, "image"},
    {EmbedType::video, "video"},
    {EmbedType::gifv, "gifv"},
    {EmbedType::article, "article"},
    {EmbedType::link, "link"}
})

enum class AllowedMentionType {
    Role_Mentions,
    User_Mentions,
    Everyone_Mentions
};
NLOHMANN_JSON_SERIALIZE_ENUM(AllowedMentionType, {
    {AllowedMentionType::Role_Mentions, "roles"},
    {AllowedMentionType::User_Mentions, "users"},
    {AllowedMentionType::Everyone_Mentions, "everyone"}
})


// Guild //

enum class DefaultMessageNotificationLevel : int {
    ALL_MESSAGES = 0,
    ONLY_MENTIONS = 1
};

enum class ExplicitContentFilterLevel : int {
    DISABLED = 0,
    MEMBERS_WITHOUT_ROLES = 1,
    ALL_MEMBERS = 2
};

enum class MFALevel : int {
    NONE = 0,
    ELEVATED = 1
};

enum class VerificationLevel : int {
    NONE = 0,
    LOW = 1,
    MEDIUM = 2,
    HIGH = 3,
    VERY_HIGH = 4
};

enum class GuildNSFWLevel : int {
    DEFAULT = 0,
    EXPLICIT = 1,
    SAFE = 2,
    AGE_RESTRICTED = 3
};

enum class PremiumTier : int {
    NONE = 0,
    TIER_1 = 1,
    TIER_2 = 2,
    TIER_3 = 3
};

enum class SystemChannelFlag : int {
    SUPPRESS_JOIN_NOTIFICATIONS = 1,
    SUPPRESS_PREMIUM_SUBSCRIPTIONS = 1,
    SUPPRESS_GUILD_REMINDER_NOTIFICATIONS = 1,
    SUPPRESS_JOIN_NOTIFICATION_REPLIES = 1,
    SUPPRESS_ROLE_SUBSCRIPTION_PURCHASE_NOTIFICATIONS = 1,
    SUPPRESS_ROLE_SUBSCRIPTION_PURCHASE_NOTIFICATION_REPLIES = 1
};

enum class GuildFeature {
    ANIMATED_BANNER,
    ANIMATED_ICON,
    APPLICATION_COMMAND_PERMISSIONS_V2,
    AUTO_MODERATION,
    BANNER,
    COMMUNITY,
    CREATOR_MONETIZABLE_PROVISIONAL,
    CREATOR_STORE_PAGE,
    DEVELOPER_SUPPORT_SERVER,
    DISCOVERABLE,
    FEATURABLE,
    INVITES_DISABLED,
    INVITE_SPLASH,
    MEMBER_VERIFICATION_GATE_ENABLED,
    MORE_STICKERS,
    NEWS,
    PARTNERED,
    PREVIEW_ENABLED,
    ROLE_ICONS,
    ROLE_SUBSCRIPTIONS_AVAILABLE_FOR_PURCHASE,
    ROLE_SUBSCRIPTIONS_ENABLED,
    TICKETED_EVENTS_ENABLED,
    VANITY_URL,
    VERIFIED,
    VIP_REGIONS,
    WELCOME_SCREEN_ENABLED
};
NLOHMANN_JSON_SERIALIZE_ENUM(GuildFeature, {
    {GuildFeature::ANIMATED_BANNER, "ANIMATED_BANNER"},
    {GuildFeature::ANIMATED_ICON, "ANIMATED_ICON"},
    {GuildFeature::APPLICATION_COMMAND_PERMISSIONS_V2, "APPLICATION_COMMAND_PERMISSIONS_V2"},
    {GuildFeature::AUTO_MODERATION, "AUTO_MODERATION"},
    {GuildFeature::BANNER, "BANNER"},
    {GuildFeature::COMMUNITY, "COMMUNITY"},
    {GuildFeature::CREATOR_MONETIZABLE_PROVISIONAL, "CREATOR_MONETIZABLE_PROVISIONAL"},
    {GuildFeature::CREATOR_STORE_PAGE, "CREATOR_STORE_PAGE"},
    {GuildFeature::DEVELOPER_SUPPORT_SERVER, "DEVELOPER_SUPPORT_SERVER"},
    {GuildFeature::DISCOVERABLE, "DISCOVERABLE"},
    {GuildFeature::FEATURABLE, "FEATURABLE"},
    {GuildFeature::INVITES_DISABLED, "INVITES_DISABLED"},
    {GuildFeature::INVITE_SPLASH, "INVITE_SPLASH"},
    {GuildFeature::MEMBER_VERIFICATION_GATE_ENABLED, "MEMBER_VERIFICATION_GATE_ENABLED"},
    {GuildFeature::MORE_STICKERS, "MORE_STICKERS"},
    {GuildFeature::NEWS, "NEWS"},
    {GuildFeature::PARTNERED, "PARTNERED"},
    {GuildFeature::PREVIEW_ENABLED, "PREVIEW_ENABLED"},
    {GuildFeature::ROLE_ICONS, "ROLE_ICONS"},
    {GuildFeature::ROLE_SUBSCRIPTIONS_AVAILABLE_FOR_PURCHASE, "ROLE_SUBSCRIPTIONS_AVAILABLE_FOR_PURCHASE"},
    {GuildFeature::ROLE_SUBSCRIPTIONS_ENABLED, "ROLE_SUBSCRIPTIONS_ENABLED"},
    {GuildFeature::TICKETED_EVENTS_ENABLED, "TICKETED_EVENTS_ENABLED"},
    {GuildFeature::VANITY_URL, "VANITY_URL"},
    {GuildFeature::VERIFIED, "VERIFIED"},
    {GuildFeature::VIP_REGIONS, "VIP_REGIONS"},
    {GuildFeature::WELCOME_SCREEN_ENABLED, "WELCOME_SCREEN_ENABLED"}
})

enum class MutableGuildFeature {
    COMMUNITY,
    INVITES_DISABLED,
    DISCOVERABLE
};
NLOHMANN_JSON_SERIALIZE_ENUM(MutableGuildFeature, {
    {MutableGuildFeature::COMMUNITY, "COMMUNITY"},
    {MutableGuildFeature::INVITES_DISABLED, "INVITES_DISABLED"},
    {MutableGuildFeature::DISCOVERABLE, "DISCOVERABLE"}
})

enum class IntegrationExpireBehavior : int {
    Remove_role = 0,
    Kick = 1
};

enum class WidgetStyleOption {
    shield,
    banner1,
    banner2,
    banner3,
    banner4
};
NLOHMANN_JSON_SERIALIZE_ENUM(WidgetStyleOption, {
    {WidgetStyleOption::shield, "shield"},
    {WidgetStyleOption::banner1, "banner1"},
    {WidgetStyleOption::banner2, "banner2"},
    {WidgetStyleOption::banner3, "banner3"},
    {WidgetStyleOption::banner4, "banner4"}
})


// Guild Scheduled Event //

enum class GuildScheduledEventPrivacyLevel : int {
    GUILD_ONLY = 2
};

enum class GuildScheduledEventEntityType : int {
    STAGE_INSTANCE = 1,
    VOICE = 2,
    EXTERNAL = 3
};

enum class GuildScheduledEventStatu : int {
    SCHEDULED = 1,
    ACTIVE = 2,
    COMPLETED = 3,
    CANCELED = 4
};


// Invite //

enum class InviteTargetType : int {
    STREAM = 1,
    EMBEDDED_APPLICATION = 2
};


// Stage Instance //

enum class PrivacyLevel : int {
    PUBLIC = 1,
    GUILD_ONLY = 2
};


// Sticker //

enum class StickerType : int {
    STANDARD = 1,
    GUILD = 2
};

enum class StickerFormatType : int {
    PNG = 1,
    APNG = 2,
    LOTTIE = 3,
    GIF = 4
};


// User //

enum class UserFlag : int {
    STAFF = 1,
    PARTNER = 1,
    HYPESQUAD = 1,
    BUG_HUNTER_LEVEL_1 = 1,
    HYPESQUAD_ONLINE_HOUSE_1 = 1,
    HYPESQUAD_ONLINE_HOUSE_2 = 1,
    HYPESQUAD_ONLINE_HOUSE_3 = 1,
    PREMIUM_EARLY_SUPPORTER = 1,
    TEAM_PSEUDO_USER = 1,
    BUG_HUNTER_LEVEL_2 = 1,
    VERIFIED_BOT = 1,
    VERIFIED_DEVELOPER = 1,
    CERTIFIED_MODERATOR = 1,
    BOT_HTTP_INTERACTIONS = 1,
    ACTIVE_DEVELOPER = 1
};

enum class PremiumType : int {
    None = 0,
    Nitro_Classic = 1,
    Nitro = 2,
    Nitro_Basic = 3
};

enum class Service {
    Battle.net,
    eBay,
    Epic_Games,
    Facebook,
    GitHub,
    League_of_Legends,
    PayPal,
    PlayStation_Network,
    Reddit,
    Riot_Games,
    Spotify,
    Skype,
    Steam,
    TikTok,
    Twitch,
    Twitter,
    Xbox,
    YouTube
};
NLOHMANN_JSON_SERIALIZE_ENUM(Service, {
    {Service::Battle.net, "battlenet"},
    {Service::eBay, "ebay"},
    {Service::Epic_Games, "epicgames"},
    {Service::Facebook, "facebook"},
    {Service::GitHub, "github"},
    {Service::League_of_Legends, "leagueoflegends"},
    {Service::PayPal, "paypal"},
    {Service::PlayStation_Network, "playstation"},
    {Service::Reddit, "reddit"},
    {Service::Riot_Games, "riotgames"},
    {Service::Spotify, "spotify"},
    {Service::Skype, "skype"},
    {Service::Steam, "steam"},
    {Service::TikTok, "tiktok"},
    {Service::Twitch, "twitch"},
    {Service::Twitter, "twitter"},
    {Service::Xbox, "xbox"},
    {Service::YouTube, "youtube"}
})

enum class VisibilityType : int {
    None = 0,
    Everyone = 1
};


// Webhook //

enum class WebhookType : int {
    Incoming = 1,
    Channel_Follower = 2,
    Application = 3
};


// Gateway //

enum class GatewayCommand {
    Identify,
    Resume,
    Heartbeat,
    Request_Guild_Members,
    Update_Voice_State,
    Update_Presence
};
NLOHMANN_JSON_SERIALIZE_ENUM(GatewayCommand, {
    {GatewayCommand::Identify, "Identify"},
    {GatewayCommand::Resume, "Resume"},
    {GatewayCommand::Heartbeat, "Heartbeat"},
    {GatewayCommand::Request_Guild_Members, "Request Guild Members"},
    {GatewayCommand::Update_Voice_State, "Update Voice State"},
    {GatewayCommand::Update_Presence, "Update Presence"}
})

enum class GatewayEvent {
    Hello,
    Ready,
    Resumed,
    Reconnect,
    Invalid_Session,
    Application_Command_Permissions_Update,
    Auto_Moderation_Rule_Create,
    Auto_Moderation_Rule_Update,
    Auto_Moderation_Rule_Delete,
    Auto_Moderation_Action_Execution,
    Channel_Create,
    Channel_Update,
    Channel_Delete,
    Channel_Pins_Update,
    Thread_Create,
    Thread_Update,
    Thread_Delete,
    Thread_List_Sync,
    Thread_Member_Update,
    Thread_Members_Update,
    Guild_Create,
    Guild_Update,
    Guild_Delete,
    Guild_Ban_Add,
    Guild_Ban_Remove,
    Guild_Emojis_Update,
    Guild_Stickers_Update,
    Guild_Integrations_Update,
    Guild_Member_Add,
    Guild_Member_Remove,
    Guild_Member_Update,
    Guild_Members_Chunk,
    Guild_Role_Create,
    Guild_Role_Update,
    Guild_Role_Delete,
    Guild_Scheduled_Event_Create,
    Guild_Scheduled_Event_Update,
    Guild_Scheduled_Event_Delete,
    Guild_Scheduled_Event_User_Add,
    Guild_Scheduled_Event_User_Remove,
    Integration_Create,
    Integration_Update,
    Integration_Delete,
    Interaction_Create,
    Invite_Create,
    Invite_Delete,
    Message_Create,
    Message_Update,
    Message_Delete,
    Message_Delete_Bulk,
    Message_Reaction_Add,
    Message_Reaction_Remove,
    Message_Reaction_Remove_All,
    Message_Reaction_Remove_Emoji,
    Presence_Update,
    Stage_Instance_Create,
    Stage_Instance_Delete,
    Stage_Instance_Update,
    Typing_Start,
    User_Update,
    Voice_State_Update,
    Voice_Server_Update,
    Webhooks_Update
};
NLOHMANN_JSON_SERIALIZE_ENUM(GatewayEvent, {
    {GatewayEvent::Hello, "Hello"},
    {GatewayEvent::Ready, "Ready"},
    {GatewayEvent::Resumed, "Resumed"},
    {GatewayEvent::Reconnect, "Reconnect"},
    {GatewayEvent::Invalid_Session, "Invalid Session"},
    {GatewayEvent::Application_Command_Permissions_Update, "Application Command Permissions Update"},
    {GatewayEvent::Auto_Moderation_Rule_Create, "Auto Moderation Rule Create"},
    {GatewayEvent::Auto_Moderation_Rule_Update, "Auto Moderation Rule Update"},
    {GatewayEvent::Auto_Moderation_Rule_Delete, "Auto Moderation Rule Delete"},
    {GatewayEvent::Auto_Moderation_Action_Execution, "Auto Moderation Action Execution"},
    {GatewayEvent::Channel_Create, "Channel Create"},
    {GatewayEvent::Channel_Update, "Channel Update"},
    {GatewayEvent::Channel_Delete, "Channel Delete"},
    {GatewayEvent::Channel_Pins_Update, "Channel Pins Update"},
    {GatewayEvent::Thread_Create, "Thread Create"},
    {GatewayEvent::Thread_Update, "Thread Update"},
    {GatewayEvent::Thread_Delete, "Thread Delete"},
    {GatewayEvent::Thread_List_Sync, "Thread List Sync"},
    {GatewayEvent::Thread_Member_Update, "Thread Member Update"},
    {GatewayEvent::Thread_Members_Update, "Thread Members Update"},
    {GatewayEvent::Guild_Create, "Guild Create"},
    {GatewayEvent::Guild_Update, "Guild Update"},
    {GatewayEvent::Guild_Delete, "Guild Delete"},
    {GatewayEvent::Guild_Ban_Add, "Guild Ban Add"},
    {GatewayEvent::Guild_Ban_Remove, "Guild Ban Remove"},
    {GatewayEvent::Guild_Emojis_Update, "Guild Emojis Update"},
    {GatewayEvent::Guild_Stickers_Update, "Guild Stickers Update"},
    {GatewayEvent::Guild_Integrations_Update, "Guild Integrations Update"},
    {GatewayEvent::Guild_Member_Add, "Guild Member Add"},
    {GatewayEvent::Guild_Member_Remove, "Guild Member Remove"},
    {GatewayEvent::Guild_Member_Update, "Guild Member Update"},
    {GatewayEvent::Guild_Members_Chunk, "Guild Members Chunk"},
    {GatewayEvent::Guild_Role_Create, "Guild Role Create"},
    {GatewayEvent::Guild_Role_Update, "Guild Role Update"},
    {GatewayEvent::Guild_Role_Delete, "Guild Role Delete"},
    {GatewayEvent::Guild_Scheduled_Event_Create, "Guild Scheduled Event Create"},
    {GatewayEvent::Guild_Scheduled_Event_Update, "Guild Scheduled Event Update"},
    {GatewayEvent::Guild_Scheduled_Event_Delete, "Guild Scheduled Event Delete"},
    {GatewayEvent::Guild_Scheduled_Event_User_Add, "Guild Scheduled Event User Add"},
    {GatewayEvent::Guild_Scheduled_Event_User_Remove, "Guild Scheduled Event User Remove"},
    {GatewayEvent::Integration_Create, "Integration Create"},
    {GatewayEvent::Integration_Update, "Integration Update"},
    {GatewayEvent::Integration_Delete, "Integration Delete"},
    {GatewayEvent::Interaction_Create, "Interaction Create"},
    {GatewayEvent::Invite_Create, "Invite Create"},
    {GatewayEvent::Invite_Delete, "Invite Delete"},
    {GatewayEvent::Message_Create, "Message Create"},
    {GatewayEvent::Message_Update, "Message Update"},
    {GatewayEvent::Message_Delete, "Message Delete"},
    {GatewayEvent::Message_Delete_Bulk, "Message Delete Bulk"},
    {GatewayEvent::Message_Reaction_Add, "Message Reaction Add"},
    {GatewayEvent::Message_Reaction_Remove, "Message Reaction Remove"},
    {GatewayEvent::Message_Reaction_Remove_All, "Message Reaction Remove All"},
    {GatewayEvent::Message_Reaction_Remove_Emoji, "Message Reaction Remove Emoji"},
    {GatewayEvent::Presence_Update, "Presence Update"},
    {GatewayEvent::Stage_Instance_Create, "Stage Instance Create"},
    {GatewayEvent::Stage_Instance_Delete, "Stage Instance Delete"},
    {GatewayEvent::Stage_Instance_Update, "Stage Instance Update"},
    {GatewayEvent::Typing_Start, "Typing Start"},
    {GatewayEvent::User_Update, "User Update"},
    {GatewayEvent::Voice_State_Update, "Voice State Update"},
    {GatewayEvent::Voice_Server_Update, "Voice Server Update"},
    {GatewayEvent::Webhooks_Update, "Webhooks Update"}
})

enum class StatusType {
    online,
    dnd,
    idle,
    invisible,
    offline
};
NLOHMANN_JSON_SERIALIZE_ENUM(StatusType, {
    {StatusType::online, "online"},
    {StatusType::dnd, "dnd"},
    {StatusType::idle, "idle"},
    {StatusType::invisible, "invisible"},
    {StatusType::offline, "offline"}
})

enum class ActivityType : int {
    Game = 0,
    Streaming = 1,
    Listening = 2,
    Watching = 3,
    Custom = 4,
    Competing = 5
};

enum class ActivityFlag : int {
    INSTANCE = 1,
    JOIN = 1,
    SPECTATE = 1,
    JOIN_REQUEST = 1,
    SYNC = 1,
    PLAY = 1,
    PARTY_PRIVACY_FRIENDS = 1,
    PARTY_PRIVACY_VOICE_CHANNEL = 1,
    EMBEDDED = 1
};


// Gateway Events //

enum class SendEvent {
    Identify,
    Resume,
    Heartbeat,
    Request_Guild_Members,
    Update_Voice_State,
    Update_Presence
};
NLOHMANN_JSON_SERIALIZE_ENUM(SendEvent, {
    {SendEvent::Identify, "Identify"},
    {SendEvent::Resume, "Resume"},
    {SendEvent::Heartbeat, "Heartbeat"},
    {SendEvent::Request_Guild_Members, "Request Guild Members"},
    {SendEvent::Update_Voice_State, "Update Voice State"},
    {SendEvent::Update_Presence, "Update Presence"}
})

enum class StatusType {
    online,
    dnd,
    idle,
    invisible,
    offline
};
NLOHMANN_JSON_SERIALIZE_ENUM(StatusType, {
    {StatusType::online, "online"},
    {StatusType::dnd, "dnd"},
    {StatusType::idle, "idle"},
    {StatusType::invisible, "invisible"},
    {StatusType::offline, "offline"}
})

enum class ReceiveEvent {
    Hello,
    Ready,
    Resumed,
    Reconnect,
    Invalid_Session,
    Application_Command_Permissions_Update,
    Auto_Moderation_Rule_Create,
    Auto_Moderation_Rule_Update,
    Auto_Moderation_Rule_Delete,
    Auto_Moderation_Action_Execution,
    Channel_Create,
    Channel_Update,
    Channel_Delete,
    Channel_Pins_Update,
    Thread_Create,
    Thread_Update,
    Thread_Delete,
    Thread_List_Sync,
    Thread_Member_Update,
    Thread_Members_Update,
    Guild_Create,
    Guild_Update,
    Guild_Delete,
    Guild_Audit_Log_Entry_Create,
    Guild_Ban_Add,
    Guild_Ban_Remove,
    Guild_Emojis_Update,
    Guild_Stickers_Update,
    Guild_Integrations_Update,
    Guild_Member_Add,
    Guild_Member_Remove,
    Guild_Member_Update,
    Guild_Members_Chunk,
    Guild_Role_Create,
    Guild_Role_Update,
    Guild_Role_Delete,
    Guild_Scheduled_Event_Create,
    Guild_Scheduled_Event_Update,
    Guild_Scheduled_Event_Delete,
    Guild_Scheduled_Event_User_Add,
    Guild_Scheduled_Event_User_Remove,
    Integration_Create,
    Integration_Update,
    Integration_Delete,
    Interaction_Create,
    Invite_Create,
    Invite_Delete,
    Message_Create,
    Message_Update,
    Message_Delete,
    Message_Delete_Bulk,
    Message_Reaction_Add,
    Message_Reaction_Remove,
    Message_Reaction_Remove_All,
    Message_Reaction_Remove_Emoji,
    Presence_Update,
    Stage_Instance_Create,
    Stage_Instance_Update,
    Stage_Instance_Delete,
    Typing_Start,
    User_Update,
    Voice_State_Update,
    Voice_Server_Update,
    Webhooks_Update
};
NLOHMANN_JSON_SERIALIZE_ENUM(ReceiveEvent, {
    {ReceiveEvent::Hello, "Hello"},
    {ReceiveEvent::Ready, "Ready"},
    {ReceiveEvent::Resumed, "Resumed"},
    {ReceiveEvent::Reconnect, "Reconnect"},
    {ReceiveEvent::Invalid_Session, "Invalid Session"},
    {ReceiveEvent::Application_Command_Permissions_Update, "Application Command Permissions Update"},
    {ReceiveEvent::Auto_Moderation_Rule_Create, "Auto Moderation Rule Create"},
    {ReceiveEvent::Auto_Moderation_Rule_Update, "Auto Moderation Rule Update"},
    {ReceiveEvent::Auto_Moderation_Rule_Delete, "Auto Moderation Rule Delete"},
    {ReceiveEvent::Auto_Moderation_Action_Execution, "Auto Moderation Action Execution"},
    {ReceiveEvent::Channel_Create, "Channel Create"},
    {ReceiveEvent::Channel_Update, "Channel Update"},
    {ReceiveEvent::Channel_Delete, "Channel Delete"},
    {ReceiveEvent::Channel_Pins_Update, "Channel Pins Update"},
    {ReceiveEvent::Thread_Create, "Thread Create"},
    {ReceiveEvent::Thread_Update, "Thread Update"},
    {ReceiveEvent::Thread_Delete, "Thread Delete"},
    {ReceiveEvent::Thread_List_Sync, "Thread List Sync"},
    {ReceiveEvent::Thread_Member_Update, "Thread Member Update"},
    {ReceiveEvent::Thread_Members_Update, "Thread Members Update"},
    {ReceiveEvent::Guild_Create, "Guild Create"},
    {ReceiveEvent::Guild_Update, "Guild Update"},
    {ReceiveEvent::Guild_Delete, "Guild Delete"},
    {ReceiveEvent::Guild_Audit_Log_Entry_Create, "Guild Audit Log Entry Create"},
    {ReceiveEvent::Guild_Ban_Add, "Guild Ban Add"},
    {ReceiveEvent::Guild_Ban_Remove, "Guild Ban Remove"},
    {ReceiveEvent::Guild_Emojis_Update, "Guild Emojis Update"},
    {ReceiveEvent::Guild_Stickers_Update, "Guild Stickers Update"},
    {ReceiveEvent::Guild_Integrations_Update, "Guild Integrations Update"},
    {ReceiveEvent::Guild_Member_Add, "Guild Member Add"},
    {ReceiveEvent::Guild_Member_Remove, "Guild Member Remove"},
    {ReceiveEvent::Guild_Member_Update, "Guild Member Update"},
    {ReceiveEvent::Guild_Members_Chunk, "Guild Members Chunk"},
    {ReceiveEvent::Guild_Role_Create, "Guild Role Create"},
    {ReceiveEvent::Guild_Role_Update, "Guild Role Update"},
    {ReceiveEvent::Guild_Role_Delete, "Guild Role Delete"},
    {ReceiveEvent::Guild_Scheduled_Event_Create, "Guild Scheduled Event Create"},
    {ReceiveEvent::Guild_Scheduled_Event_Update, "Guild Scheduled Event Update"},
    {ReceiveEvent::Guild_Scheduled_Event_Delete, "Guild Scheduled Event Delete"},
    {ReceiveEvent::Guild_Scheduled_Event_User_Add, "Guild Scheduled Event User Add"},
    {ReceiveEvent::Guild_Scheduled_Event_User_Remove, "Guild Scheduled Event User Remove"},
    {ReceiveEvent::Integration_Create, "Integration Create"},
    {ReceiveEvent::Integration_Update, "Integration Update"},
    {ReceiveEvent::Integration_Delete, "Integration Delete"},
    {ReceiveEvent::Interaction_Create, "Interaction Create"},
    {ReceiveEvent::Invite_Create, "Invite Create"},
    {ReceiveEvent::Invite_Delete, "Invite Delete"},
    {ReceiveEvent::Message_Create, "Message Create"},
    {ReceiveEvent::Message_Update, "Message Update"},
    {ReceiveEvent::Message_Delete, "Message Delete"},
    {ReceiveEvent::Message_Delete_Bulk, "Message Delete Bulk"},
    {ReceiveEvent::Message_Reaction_Add, "Message Reaction Add"},
    {ReceiveEvent::Message_Reaction_Remove, "Message Reaction Remove"},
    {ReceiveEvent::Message_Reaction_Remove_All, "Message Reaction Remove All"},
    {ReceiveEvent::Message_Reaction_Remove_Emoji, "Message Reaction Remove Emoji"},
    {ReceiveEvent::Presence_Update, "Presence Update"},
    {ReceiveEvent::Stage_Instance_Create, "Stage Instance Create"},
    {ReceiveEvent::Stage_Instance_Update, "Stage Instance Update"},
    {ReceiveEvent::Stage_Instance_Delete, "Stage Instance Delete"},
    {ReceiveEvent::Typing_Start, "Typing Start"},
    {ReceiveEvent::User_Update, "User Update"},
    {ReceiveEvent::Voice_State_Update, "Voice State Update"},
    {ReceiveEvent::Voice_Server_Update, "Voice Server Update"},
    {ReceiveEvent::Webhooks_Update, "Webhooks Update"}
})

enum class ActivityType : int {
    Game = 0,
    Streaming = 1,
    Listening = 2,
    Watching = 3,
    Custom = 4,
    Competing = 5
};

enum class ActivityFlag : int {
    INSTANCE = 1,
    JOIN = 1,
    SPECTATE = 1,
    JOIN_REQUEST = 1,
    SYNC = 1,
    PLAY = 1,
    PARTY_PRIVACY_FRIENDS = 1,
    PARTY_PRIVACY_VOICE_CHANNEL = 1,
    EMBEDDED = 1
};


// OAuth2 //

enum class OAuth2Scope {
    activities.read,
    activities.write,
    applications.builds.read,
    applications.builds.upload,
    applications.commands,
    applications.commands.update,
    applications.commands.permissions.update,
    applications.entitlements,
    applications.store.update,
    bot,
    connections,
    dm_channels.read,
    email,
    gdm.join,
    guilds,
    guilds.join,
    guilds.members.read,
    identify,
    messages.read,
    relationships.read,
    role_connections.write,
    rpc,
    rpc.activities.write,
    rpc.notifications.read,
    rpc.voice.read,
    rpc.voice.write,
    voice,
    webhook.incoming
};
NLOHMANN_JSON_SERIALIZE_ENUM(OAuth2Scope, {
    {OAuth2Scope::activities.read, "activities.read"},
    {OAuth2Scope::activities.write, "activities.write"},
    {OAuth2Scope::applications.builds.read, "applications.builds.read"},
    {OAuth2Scope::applications.builds.upload, "applications.builds.upload"},
    {OAuth2Scope::applications.commands, "applications.commands"},
    {OAuth2Scope::applications.commands.update, "applications.commands.update"},
    {OAuth2Scope::applications.commands.permissions.update, "applications.commands.permissions.update"},
    {OAuth2Scope::applications.entitlements, "applications.entitlements"},
    {OAuth2Scope::applications.store.update, "applications.store.update"},
    {OAuth2Scope::bot, "bot"},
    {OAuth2Scope::connections, "connections"},
    {OAuth2Scope::dm_channels.read, "dm_channels.read"},
    {OAuth2Scope::email, "email"},
    {OAuth2Scope::gdm.join, "gdm.join"},
    {OAuth2Scope::guilds, "guilds"},
    {OAuth2Scope::guilds.join, "guilds.join"},
    {OAuth2Scope::guilds.members.read, "guilds.members.read"},
    {OAuth2Scope::identify, "identify"},
    {OAuth2Scope::messages.read, "messages.read"},
    {OAuth2Scope::relationships.read, "relationships.read"},
    {OAuth2Scope::role_connections.write, "role_connections.write"},
    {OAuth2Scope::rpc, "rpc"},
    {OAuth2Scope::rpc.activities.write, "rpc.activities.write"},
    {OAuth2Scope::rpc.notifications.read, "rpc.notifications.read"},
    {OAuth2Scope::rpc.voice.read, "rpc.voice.read"},
    {OAuth2Scope::rpc.voice.write, "rpc.voice.write"},
    {OAuth2Scope::voice, "voice"},
    {OAuth2Scope::webhook.incoming, "webhook.incoming"}
})

enum class BotAuthParameter {
    client_id,
    scope,
    permissions,
    guild_id,
    disable_guild_select
};
NLOHMANN_JSON_SERIALIZE_ENUM(BotAuthParameter, {
    {BotAuthParameter::client_id, "client_id"},
    {BotAuthParameter::scope, "scope"},
    {BotAuthParameter::permissions, "permissions"},
    {BotAuthParameter::guild_id, "guild_id"},
    {BotAuthParameter::disable_guild_select, "disable_guild_select"}
})


// Opcodes and Status Codes //

enum class GatewayOpcode : int {
    Dispatch = 0,
    Heartbeat = 1,
    Identify = 2,
    Presence_Update = 3,
    Voice_State_Update = 4,
    Resume = 6,
    Reconnect = 7,
    Request_Guild_Members = 8,
    Invalid_Session = 9,
    Hello = 10,
    Heartbeat_ACK = 11
};

enum class GatewayCloseEventCode : int {
    Unknown_error = 4000,
    Unknown_opcode = 4001,
    Decode_error = 4002,
    Not_authenticated = 4003,
    Authentication_failed = 4004,
    Already_authenticated = 4005,
    Invalid_seq = 4007,
    Rate_limited = 4008,
    Session_timed_out = 4009,
    Invalid_shard = 4010,
    Sharding_required = 4011,
    Invalid_API_version = 4012,
    Invalid_intent(s) = 4013,
    Disallowed_intent(s) = 4014
};

enum class VoiceOpcode : int {
    Identify = 0,
    Select_Protocol = 1,
    Ready = 2,
    Heartbeat = 3,
    Session_Description = 4,
    Speaking = 5,
    Heartbeat_ACK = 6,
    Resume = 7,
    Hello = 8,
    Resumed = 9,
    Client_Disconnect = 13
};

enum class VoiceCloseEventCode : int {
    Unknown_opcode = 4001,
    Failed_to_decode_payload = 4002,
    Not_authenticated = 4003,
    Authentication_failed = 4004,
    Already_authenticated = 4005,
    Session_no_longer_valid = 4006,
    Session_timeout = 4009,
    Server_not_found = 4011,
    Unknown_protocol = 4012,
    Disconnected = 4014,
    Voice_server_crashed = 4015,
    Unknown_encryption_mode = 4016
};

enum class JSONErrorCode : int {
    General_error_(such_as_a_malformed_request_body,_amongst_other_things) = 0,
    Unknown_account = 10001,
    Unknown_application = 10002,
    Unknown_channel = 10003,
    Unknown_guild = 10004,
    Unknown_integration = 10005,
    Unknown_invite = 10006,
    Unknown_member = 10007,
    Unknown_message = 10008,
    Unknown_permission_overwrite = 10009,
    Unknown_provider = 10010,
    Unknown_role = 10011,
    Unknown_token = 10012,
    Unknown_user = 10013,
    Unknown_emoji = 10014,
    Unknown_webhook = 10015,
    Unknown_webhook_service = 10016,
    Unknown_session = 10020,
    Unknown_ban = 10026,
    Unknown_SKU = 10027,
    Unknown_Store_Listing = 10028,
    Unknown_entitlement = 10029,
    Unknown_build = 10030,
    Unknown_lobby = 10031,
    Unknown_branch = 10032,
    Unknown_store_directory_layout = 10033,
    Unknown_redistributable = 10036,
    Unknown_gift_code = 10038,
    Unknown_stream = 10049,
    Unknown_premium_server_subscribe_cooldown = 10050,
    Unknown_guild_template = 10057,
    Unknown_discoverable_server_category = 10059,
    Unknown_sticker = 10060,
    Unknown_interaction = 10062,
    Unknown_application_command = 10063,
    Unknown_voice_state = 10065,
    Unknown_application_command_permissions = 10066,
    Unknown_Stage_Instance = 10067,
    Unknown_Guild_Member_Verification_Form = 10068,
    Unknown_Guild_Welcome_Screen = 10069,
    Unknown_Guild_Scheduled_Event = 10070,
    Unknown_Guild_Scheduled_Event_User = 10071,
    Unknown_Tag = 10087,
    Bots_cannot_use_this_endpoint = 20001,
    Only_bots_can_use_this_endpoint = 20002,
    Explicit_content_cannot_be_sent_to_the_desired_recipient(s) = 20009,
    You_are_not_authorized_to_perform_this_action_on_this_application = 20012,
    This_action_cannot_be_performed_due_to_slowmode_rate_limit = 20016,
    Only_the_owner_of_this_account_can_perform_this_action = 20018,
    This_message_cannot_be_edited_due_to_announcement_rate_limits = 20022,
    Under_minimum_age = 20024,
    The_channel_you_are_writing_has_hit_the_write_rate_limit = 20028,
    The_write_action_you_are_performing_on_the_server_has_hit_the_write_rate_limit = 20029,
    Your_Stage_topic,_server_name,_server_description,_or_channel_names_contain_words_that_are_not_allowed = 20031,
    Guild_premium_subscription_level_too_low = 20035,
    Maximum_number_of_guilds_reached_(100) = 30001,
    Maximum_number_of_friends_reached_(1000) = 30002,
    Maximum_number_of_pins_reached_for_the_channel_(50) = 30003,
    Maximum_number_of_recipients_reached_(10) = 30004,
    Maximum_number_of_guild_roles_reached_(250) = 30005,
    Maximum_number_of_webhooks_reached_(10) = 30007,
    Maximum_number_of_emojis_reached = 30008,
    Maximum_number_of_reactions_reached_(20) = 30010,
    Maximum_number_of_guild_channels_reached_(500) = 30013,
    Maximum_number_of_attachments_in_a_message_reached_(10) = 30015,
    Maximum_number_of_invites_reached_(1000) = 30016,
    Maximum_number_of_animated_emojis_reached = 30018,
    Maximum_number_of_server_members_reached = 30019,
    Maximum_number_of_server_categories_has_been_reached_(5) = 30030,
    Guild_already_has_a_template = 30031,
    Maximum_number_of_application_commands_reached = 30032,
    Max_number_of_thread_participants_has_been_reached_(1000) = 30033,
    Max_number_of_daily_application_command_creates_has_been_reached_(200) = 30034,
    Maximum_number_of_bans_for_non-guild_members_have_been_exceeded = 30035,
    Maximum_number_of_bans_fetches_has_been_reached = 30037,
    Maximum_number_of_uncompleted_guild_scheduled_events_reached_(100) = 30038,
    Maximum_number_of_stickers_reached = 30039,
    Maximum_number_of_prune_requests_has_been_reached._Try_again_later = 30040,
    Maximum_number_of_guild_widget_settings_updates_has_been_reached._Try_again_later = 30042,
    Maximum_number_of_edits_to_messages_older_than_1_hour_reached._Try_again_later = 30046,
    Maximum_number_of_pinned_threads_in_a_forum_channel_has_been_reached = 30047,
    Maximum_number_of_tags_in_a_forum_channel_has_been_reached = 30048,
    Bitrate_is_too_high_for_channel_of_this_type = 30052,
    Maximum_number_of_premium_emojis_reached_(25) = 30056,
    Maximum_number_of_webhooks_per_guild_reached_(1000) = 30058,
    Unauthorized._Provide_a_valid_token_and_try_again = 40001,
    You_need_to_verify_your_account_in_order_to_perform_this_action = 40002,
    You_are_opening_direct_messages_too_fast = 40003,
    Send_messages_has_been_temporarily_disabled = 40004,
    Request_entity_too_large._Try_sending_something_smaller_in_size = 40005,
    This_feature_has_been_temporarily_disabled_server-side = 40006,
    The_user_is_banned_from_this_guild = 40007,
    Connection_has_been_revoked = 40012,
    Target_user_is_not_connected_to_voice = 40032,
    This_message_has_already_been_crossposted = 40033,
    An_application_command_with_that_name_already_exists = 40041,
    Application_interaction_failed_to_send = 40043,
    Cannot_send_a_message_in_a_forum_channel = 40058,
    Interaction_has_already_been_acknowledged = 40060,
    Tag_names_must_be_unique = 40061,
    Service_resource_is_being_rate_limited = 40062,
    There_are_no_tags_available_that_can_be_set_by_non-moderators = 40066,
    A_tag_is_required_to_create_a_forum_post_in_this_channel = 40067,
    Missing_access = 50001,
    Invalid_account_type = 50002,
    Cannot_execute_action_on_a_DM_channel = 50003,
    Guild_widget_disabled = 50004,
    Cannot_edit_a_message_authored_by_another_user = 50005,
    Cannot_send_an_empty_message = 50006,
    Cannot_send_messages_to_this_user = 50007,
    Cannot_send_messages_in_a_non-text_channel = 50008,
    Channel_verification_level_is_too_high_for_you_to_gain_access = 50009,
    OAuth2_application_does_not_have_a_bot = 50010,
    OAuth2_application_limit_reached = 50011,
    Invalid_OAuth2_state = 50012,
    You_lack_permissions_to_perform_that_action = 50013,
    Invalid_authentication_token_provided = 50014,
    Note_was_too_long = 50015,
    Provided_too_few_or_too_many_messages_to_delete._Must_provide_at_least_2_and_fewer_than_100_messages_to_delete = 50016,
    Invalid_MFA_Level = 50017,
    A_message_can_only_be_pinned_to_the_channel_it_was_sent_in = 50019,
    Invite_code_was_either_invalid_or_taken = 50020,
    Cannot_execute_action_on_a_system_message = 50021,
    Cannot_execute_action_on_this_channel_type = 50024,
    Invalid_OAuth2_access_token_provided = 50025,
    Missing_required_OAuth2_scope = 50026,
    Invalid_webhook_token_provided = 50027,
    Invalid_role = 50028,
    Invalid_Recipient(s) = 50033,
    A_message_provided_was_too_old_to_bulk_delete = 50034,
    Invalid_form_body_(returned_for_both_application/json_and_multipart/form-data_bodies),_or_invalid_Content-Type_provided = 50035,
    An_invite_was_accepted_to_a_guild_the_application's_bot_is_not_in = 50036,
    Invalid_Activity_Action = 50039,
    Invalid_API_version_provided = 50041,
    File_uploaded_exceeds_the_maximum_size = 50045,
    Invalid_file_uploaded = 50046,
    Cannot_self-redeem_this_gift = 50054,
    Invalid_Guild = 50055,
    Invalid_request_origin = 50067,
    Invalid_message_type = 50068,
    Payment_source_required_to_redeem_gift = 50070,
    Cannot_modify_a_system_webhook = 50073,
    Cannot_delete_a_channel_required_for_Community_guilds = 50074,
    Cannot_edit_stickers_within_a_message = 50080,
    Invalid_sticker_sent = 50081,
    Tried_to_perform_an_operation_on_an_archived_thread,_such_as_editing_a_message_or_adding_a_user_to_the_thread = 50083,
    Invalid_thread_notification_settings = 50084,
    before_value_is_earlier_than_the_thread_creation_date = 50085,
    Community_server_channels_must_be_text_channels = 50086,
    The_entity_type_of_the_event_is_different_from_the_entity_you_are_trying_to_start_the_event_for = 50091,
    This_server_is_not_available_in_your_location = 50095,
    This_server_needs_monetization_enabled_in_order_to_perform_this_action = 50097,
    This_server_needs_more_boosts_to_perform_this_action = 50101,
    The_request_body_contains_invalid_JSON. = 50109,
    Ownership_cannot_be_transferred_to_a_bot_user = 50132,
    Failed_to_resize_asset_below_the_maximum_size:_262144 = 50138,
    Cannot_mix_subscription_and_non_subscription_roles_for_an_emoji = 50144,
    Cannot_convert_between_premium_emoji_and_normal_emoji = 50145,
    Uploaded_file_not_found. = 50146,
    You_do_not_have_permission_to_send_this_sticker. = 50600,
    Two_factor_is_required_for_this_operation = 60003,
    No_users_with_DiscordTag_exist = 80004,
    Reaction_was_blocked = 90001,
    Application_not_yet_available._Try_again_later = 110001,
    API_resource_is_currently_overloaded._Try_again_a_little_later = 130000,
    The_Stage_is_already_open = 150006,
    Cannot_reply_without_permission_to_read_message_history = 160002,
    A_thread_has_already_been_created_for_this_message = 160004,
    Thread_is_locked = 160005,
    Maximum_number_of_active_threads_reached = 160006,
    Maximum_number_of_active_announcement_threads_reached = 160007,
    Invalid_JSON_for_uploaded_Lottie_file = 170001,
    Uploaded_Lotties_cannot_contain_rasterized_images_such_as_PNG_or_JPEG = 170002,
    Sticker_maximum_framerate_exceeded = 170003,
    Sticker_frame_count_exceeds_maximum_of_1000_frames = 170004,
    Lottie_animation_maximum_dimensions_exceeded = 170005,
    Sticker_frame_rate_is_either_too_small_or_too_large = 170006,
    Sticker_animation_duration_exceeds_maximum_of_5_seconds = 170007,
    Cannot_update_a_finished_event = 180000,
    Failed_to_create_stage_needed_for_stage_event = 180002,
    Message_was_blocked_by_automatic_moderation = 200000,
    Title_was_blocked_by_automatic_moderation = 200001,
    Webhooks_posted_to_forum_channels_must_have_a_thread_name_or_thread_id = 220001,
    Webhooks_posted_to_forum_channels_cannot_have_both_a_thread_name_and_thread_id = 220002,
    Webhooks_can_only_create_threads_in_forum_channels = 220003,
    Webhook_services_cannot_be_used_in_forum_channels = 220004,
    Message_blocked_by_harmful_links_filter = 240000
};

enum class RPCErrorCode : int {
    Unknown_error = 1000,
    Invalid_payload = 4000,
    Invalid_command = 4002,
    Invalid_guild = 4003,
    Invalid_event = 4004,
    Invalid_channel = 4005,
    Invalid_permissions = 4006,
    Invalid_client_ID = 4007,
    Invalid_origin = 4008,
    Invalid_token = 4009,
    Invalid_user = 4010,
    OAuth2_error = 5000,
    Select_channel_timed_out = 5001,
    GET_GUILD_timed_out = 5002,
    Select_voice_force_required = 5003,
    Capture_shortcut_already_listening = 5004
};

enum class RPCCloseEventCode : int {
    Invalid_client_ID = 4000,
    Invalid_origin = 4001,
    Rate_limited = 4002,
    Token_revoked = 4003,
    Invalid_version = 4004,
    Invalid_encoding = 4005
};


// Permissions //

enum class BitwisePermissionFlag : int {
    CREATE_INSTANT_INVITE = 0x0000000000000001,
    KICK_MEMBERS = 0x0000000000000002,
    BAN_MEMBERS = 0x0000000000000004,
    ADMINISTRATOR = 0x0000000000000008,
    MANAGE_CHANNELS = 0x0000000000000010,
    MANAGE_GUILD = 0x0000000000000020,
    ADD_REACTIONS = 0x0000000000000040,
    VIEW_AUDIT_LOG = 0x0000000000000080,
    PRIORITY_SPEAKER = 0x0000000000000100,
    STREAM = 0x0000000000000200,
    VIEW_CHANNEL = 0x0000000000000400,
    SEND_MESSAGES = 0x0000000000000800,
    SEND_TTS_MESSAGES = 0x0000000000001000,
    MANAGE_MESSAGES = 0x0000000000002000,
    EMBED_LINKS = 0x0000000000004000,
    ATTACH_FILES = 0x0000000000008000,
    READ_MESSAGE_HISTORY = 0x0000000000010000,
    MENTION_EVERYONE = 0x0000000000020000,
    USE_EXTERNAL_EMOJIS = 0x0000000000040000,
    VIEW_GUILD_INSIGHTS = 0x0000000000080000,
    CONNECT = 0x0000000000100000,
    SPEAK = 0x0000000000200000,
    MUTE_MEMBERS = 0x0000000000400000,
    DEAFEN_MEMBERS = 0x0000000000800000,
    MOVE_MEMBERS = 0x0000000001000000,
    USE_VAD = 0x0000000002000000,
    CHANGE_NICKNAME = 0x0000000004000000,
    MANAGE_NICKNAMES = 0x0000000008000000,
    MANAGE_ROLES = 0x0000000010000000,
    MANAGE_WEBHOOKS = 0x0000000020000000,
    MANAGE_EMOJIS_AND_STICKERS = 0x0000000040000000,
    USE_APPLICATION_COMMANDS = 0x0000000080000000,
    REQUEST_TO_SPEAK = 0x0000000100000000,
    MANAGE_EVENTS = 0x0000000200000000,
    MANAGE_THREADS = 0x0000000400000000,
    CREATE_PUBLIC_THREADS = 0x0000000800000000,
    CREATE_PRIVATE_THREADS = 0x0000001000000000,
    USE_EXTERNAL_STICKERS = 0x0000002000000000,
    SEND_MESSAGES_IN_THREADS = 0x0000004000000000,
    USE_EMBEDDED_ACTIVITIES = 0x0000008000000000,
    MODERATE_MEMBERS = 0x0000010000000000
};


// Teams //

enum class MembershipStateEnum : int {
    INVITED = 1,
    ACCEPTED = 2
};


// Voice Connections //

enum class Speaking : int {
    Microphone = 1,
    Soundshare = 1,
    Priority = 1
};

} // namespace discordpp
