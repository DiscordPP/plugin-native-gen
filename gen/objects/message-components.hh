#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

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
        if(!t.label.is_omitted()) {j["label"] = t.label;}
        if(!t.value.is_omitted()) {j["value"] = t.value;}
        if(!t.description.is_omitted()) {j["description"] = t.description;}
        if(!t.emoji.is_omitted()) {j["emoji"] = t.emoji;}
        if(!t.default_selected.is_omitted()) {j["default"] = t.default_selected;}
    }
    friend void from_json(const nlohmann::json &j, SelectOption &t {
        if(j.contains(label)){j.at(label).get_to(t.label);}
        if(j.contains(value)){j.at(value).get_to(t.value);}
        if(j.contains(description)){j.at(description).get_to(t.description);}
        if(j.contains(emoji)){j.at(emoji).get_to(t.emoji);}
        if(j.contains(default)){j.at(default).get_to(t.default_selected);}
    }
};

// https://discord.com/developers/docs/interactions/message-components#component-object
class Component{
  public:
    Component(
        field<int> type = uninitialized
    ):
        type(type)
    {}
    
    field<int> type;

    friend void to_json(nlohmann::json &j, const Component &t) {
        if(!t.type.is_omitted()) {j["type"] = t.type;}
    }
    friend void from_json(const nlohmann::json &j, Component &t {
        if(j.contains(type)){j.at(type).get_to(t.type);}
    }
};
