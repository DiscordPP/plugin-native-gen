#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/interactions/message-components#button-object-button-structure
class Button{
  public:
    Button(
        field<int> type = uninitialized,
        field<int> style = uninitialized,
        omittable_field<std::string> label = omitted,
        omittable_field<Emoji> emoji = omitted,
        omittable_field<std::string> custom_id = omitted,
        omittable_field<std::string> url = omitted,
        omittable_field<bool> disabled = omitted
    ): 
        type(type),
        style(style),
        label(label),
        emoji(emoji),
        custom_id(custom_id),
        url(url),
        disabled(disabled)
    {}
    
    field<int> type;
    field<int> style;
    omittable_field<std::string> label;
    omittable_field<Emoji> emoji;
    omittable_field<std::string> custom_id;
    omittable_field<std::string> url;
    omittable_field<bool> disabled;

    friend void to_json(nlohmann::json &j, const Button &t) {
        //ToJsonExtra
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.style.is_omitted()) {j["style"] = t.style;}
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.url.is_omitted()) {j["url"] = t.url;}
        if(!t.disabled.is_omitted()) {j["disabled"] = t.disabled;}
    }
};
// https://discord.com/developers/docs/interactions/message-components#select-menu-object-select-menu-structure
class SelectMenu{
  public:
    SelectMenu(
        field<int> type = uninitialized,
        field<std::string> custom_id = uninitialized,
        omittable_field<std::vector<SelectOption> > options = omitted,
        omittable_field<std::vector<ChannelType> > channel_types = omitted,
        omittable_field<std::string> placeholder = omitted,
        omittable_field<int> min_values = omitted,
        omittable_field<int> max_values = omitted,
        omittable_field<bool> disabled = omitted
    ): 
        type(type),
        custom_id(custom_id),
        options(options),
        channel_types(channel_types),
        placeholder(placeholder),
        min_values(min_values),
        max_values(max_values),
        disabled(disabled)
    {}
    
    field<int> type;
    field<std::string> custom_id;
    omittable_field<std::vector<SelectOption> > options;
    omittable_field<std::vector<ChannelType> > channel_types;
    omittable_field<std::string> placeholder;
    omittable_field<int> min_values;
    omittable_field<int> max_values;
    omittable_field<bool> disabled;

    friend void to_json(nlohmann::json &j, const SelectMenu &t) {
        //ToJsonExtra
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.channel_types.is_omitted()) {j["channel_types"] = t.channel_types;}
        if(!t.placeholder.is_omitted()) {j["placeholder"] = t.placeholder;}
        if(!t.min_values.is_omitted()) {j["min_values"] = t.min_values;}
        if(!t.max_values.is_omitted()) {j["max_values"] = t.max_values;}
        if(!t.disabled.is_omitted()) {j["disabled"] = t.disabled;}
    }
};
// https://discord.com/developers/docs/interactions/message-components#select-menu-object-select-option-structure
class SelectOption{
  public:
    SelectOption(
        field<std::string> label = uninitialized,
        field<std::string> value = uninitialized,
        omittable_field<std::string> description = omitted,
        omittable_field<Emoji> emoji = omitted,
        omittable_field<bool> default_selected = omitted
    ): 
        label(label),
        value(value),
        description(description),
        emoji(emoji),
        default_selected(default_selected)
    {}
    
    field<std::string> label;
    field<std::string> value;
    omittable_field<std::string> description;
    omittable_field<Emoji> emoji;
    omittable_field<bool> default_selected;

    friend void to_json(nlohmann::json &j, const SelectOption &t) {
        //ToJsonExtra
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
        if(!t.default_selected.is_omitted()) {j["default"] = t.default_selected;}
    }
};
// https://discord.com/developers/docs/interactions/message-components#text-inputs-text-input-structure
class TextInput{
  public:
    TextInput(
        field<int> type = uninitialized,
        field<std::string> custom_id = uninitialized,
        field<int> style = uninitialized,
        field<std::string> label = uninitialized,
        omittable_field<int> min_length = omitted,
        omittable_field<int> max_length = omitted,
        omittable_field<bool> required = omitted,
        omittable_field<std::string> value = omitted,
        omittable_field<std::string> placeholder = omitted
    ): 
        type(type),
        custom_id(custom_id),
        style(style),
        label(label),
        min_length(min_length),
        max_length(max_length),
        required(required),
        value(value),
        placeholder(placeholder)
    {}
    
    field<int> type;
    field<std::string> custom_id;
    field<int> style;
    field<std::string> label;
    omittable_field<int> min_length;
    omittable_field<int> max_length;
    omittable_field<bool> required;
    omittable_field<std::string> value;
    omittable_field<std::string> placeholder;

    friend void to_json(nlohmann::json &j, const TextInput &t) {
        //ToJsonExtra
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.style.is_omitted()) {j["style"] = t.style;}
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.min_length.is_omitted()) {j["min_length"] = t.min_length;}
        if(!t.max_length.is_omitted()) {j["max_length"] = t.max_length;}
        if(!t.required.is_omitted()) {j["required"] = t.required;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.placeholder.is_omitted()) {j["placeholder"] = t.placeholder;}
    }
};
