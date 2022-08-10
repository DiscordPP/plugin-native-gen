#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
        //ToJsonExtra
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
};
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
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.format_type.is_omitted()) {j["format_type"] = t.format_type;}
    }
};
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
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.stickers.is_omitted()) {j["stickers"] = t.stickers;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.sku_id.is_omitted()) {j["sku_id"] = t.sku_id;}
        if(!t.cover_sticker_id.is_omitted()) {j["cover_sticker_id"] = t.cover_sticker_id;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.banner_asset_id.is_omitted()) {j["banner_asset_id"] = t.banner_asset_id;}
    }
};
