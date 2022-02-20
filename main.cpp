#include "json.h"
#include "json_builder.h"

#include <fstream>
#include <iostream>
#include <cassert>

using namespace std::string_literals;

void ExampleBuildJSON() 
{
    std::ofstream output("example.json");
    if (!output.is_open())
    {
        throw std::runtime_error("Failed to open file ");
    }

    json::Builder builder;
    auto result = builder.StartDict()
            .Key("key1"s).Value(123)
            .Key("key2"s).Value("value2"s)
            .Key("key3"s).Value(true)
            .Key("key4"s).StartArray()
                .Value(1).Value("second"s)
                .EndArray()
            .EndDict()
            .Build();

    json::Print(json::Document{result}, output);

}
void ExampleReadJSON()
{
    std::ifstream input("example.json");
    json::Document json_doc = json::Load(input);
    json::Node json_node = json_doc.GetRoot();

    json::Dict main_dict = json_node.AsDict();

    assert(main_dict.at("key1"s).AsInt() == 123);
    assert(main_dict.at("key2"s).AsString() == "value2"s);

    assert(main_dict.at("key3"s).IsBool());
    assert(main_dict.at("key3"s).AsBool() == true);

    assert(main_dict.at("key4"s).IsArray());
    assert(main_dict.at("key4"s).AsArray().size() == 2);

    assert(main_dict.size() == 4);
}

int main(){

    ExampleBuildJSON();
    ExampleReadJSON();

    return 0;
}