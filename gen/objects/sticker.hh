#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/resources/sticker#sticker-object-sticker-structure
class Sticker{
  public:
    Sticker(
        field<Snowflake> id = uninitialized,
        omittable_field<Snowflake> pack_id = omitted,
        field<std::string> name = uninitialized,
        nullable_field<std::string> description = uninitialized,
        field<std::string> tags = uninitialized,
        omittable_field<std::string> asset = omitted,
        field<int> type = uninitialized,
        field<int> format_type = uninitialized,
        omittable_field<bool> available = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<User> user = omitted,
        omittable_field<int> sort_value = omitted
    ):
        id(id),
        pack_id(pack_id),
        name(name),
        description(description),
        tags(tags),
        asset(asset),
        type(type),
        format_type(format_type),
        available(available),
        guild_id(guild_id),
        user(user),
        sort_value(sort_value)
    {}
    
    field<Snowflake> id;
    omittable_field<Snowflake> pack_id;
    field<std::string> name;
    nullable_field<std::string> description;
    field<std::string> tags;
    omittable_field<std::string> asset;
    field<int> type;
    field<int> format_type;
    omittable_field<bool> available;
    omittable_field<Snowflake> guild_id;
    omittable_field<User> user;
    omittable_field<int> sort_value;

    friend void to_json(nlohmann::json &j, const Sticker &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.pack_id.is_omitted()) {j["pack_id"] = t.pack_id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.tags.is_omitted()) {j["tags"] = t.tags;}
        if(!t.asset.is_omitted()) {j["asset"] = t.asset;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.format_type.is_omitted()) {j["format_type"] = t.format_type;}
        if(!t.available.is_omitted()) {j["available"] = t.available;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.sort_value.is_omitted()) {j["sort_value"] = t.sort_value;}
    }
    friend void from_json(const nlohmann::json &j, Sticker &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(pack_id)){j.at(pack_id).get_to(t.pack_id);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(description)){j.at(description).get_to(t.description);}
        if(j.contains(tags)){j.at(tags).get_to(t.tags);}
        if(j.contains(asset)){j.at(asset).get_to(t.asset);}
        if(j.contains(type)){j.at(type).get_to(t.type);}
        if(j.contains(format_type)){j.at(format_type).get_to(t.format_type);}
        if(j.contains(available)){j.at(available).get_to(t.available);}
        if(j.contains(guild_id)){j.at(guild_id).get_to(t.guild_id);}
        if(j.contains(user)){j.at(user).get_to(t.user);}
        if(j.contains(sort_value)){j.at(sort_value).get_to(t.sort_value);}
    }
};

// https://discord.com/developers/docs/resources/sticker#sticker-item-object-sticker-item-structure
class StickerItem{
  public:
    StickerItem(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<int> format_type = uninitialized
    ):
        id(id),
        name(name),
        format_type(format_type)
    {}
    
    field<Snowflake> id;
    field<std::string> name;
    field<int> format_type;

    friend void to_json(nlohmann::json &j, const StickerItem &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.format_type.is_omitted()) {j["format_type"] = t.format_type;}
    }
    friend void from_json(const nlohmann::json &j, StickerItem &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(format_type)){j.at(format_type).get_to(t.format_type);}
    }
};

// https://discord.com/developers/docs/resources/sticker#sticker-pack-object-sticker-pack-structure
class StickerPack{
  public:
    StickerPack(
        field<Snowflake> id = uninitialized,
        field<std::vector<Sticker> > stickers = uninitialized,
        field<std::string> name = uninitialized,
        field<Snowflake> sku_id = uninitialized,
        omittable_field<Snowflake> cover_sticker_id = omitted,
        field<std::string> description = uninitialized,
        omittable_field<Snowflake> banner_asset_id = omitted
    ):
        id(id),
        stickers(stickers),
        name(name),
        sku_id(sku_id),
        cover_sticker_id(cover_sticker_id),
        description(description),
        banner_asset_id(banner_asset_id)
    {}
    
    field<Snowflake> id;
    field<std::vector<Sticker> > stickers;
    field<std::string> name;
    field<Snowflake> sku_id;
    omittable_field<Snowflake> cover_sticker_id;
    field<std::string> description;
    omittable_field<Snowflake> banner_asset_id;

    friend void to_json(nlohmann::json &j, const StickerPack &t) {
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.sku_id.is_omitted()) {j["sku_id"] = t.sku_id;}
        if(!t.cover_sticker_id.is_omitted()) {j["cover_sticker_id"] = t.cover_sticker_id;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.banner_asset_id.is_omitted()) {j["banner_asset_id"] = t.banner_asset_id;}
    }
    friend void from_json(const nlohmann::json &j, StickerPack &t {
        if(j.contains(id)){j.at(id).get_to(t.id);}
        if(j.contains(stickers)){j.at(stickers).get_to(t.stickers);}
        if(j.contains(name)){j.at(name).get_to(t.name);}
        if(j.contains(sku_id)){j.at(sku_id).get_to(t.sku_id);}
        if(j.contains(cover_sticker_id)){j.at(cover_sticker_id).get_to(t.cover_sticker_id);}
        if(j.contains(description)){j.at(description).get_to(t.description);}
        if(j.contains(banner_asset_id)){j.at(banner_asset_id).get_to(t.banner_asset_id);}
    }
};

// https://discord.com/developers/docs/resources/sticker#list-nitro-sticker-packs-response-structure
class ListNitroStickerPacksResponse{
  public:
    ListNitroStickerPacksResponse(
        field<std::vector<StickerPack> > sticker_packs = uninitialized
    ):
        sticker_packs(sticker_packs)
    {}
    
    field<std::vector<StickerPack> > sticker_packs;

    friend void to_json(nlohmann::json &j, const ListNitroStickerPacksResponse &t) {
        if(!t.sticker_packs.is_omitted()) {j["sticker_packs"] = t.sticker_packs;}
    }
    friend void from_json(const nlohmann::json &j, ListNitroStickerPacksResponse &t {
        if(j.contains(sticker_packs)){j.at(sticker_packs).get_to(t.sticker_packs);}
    }
};
