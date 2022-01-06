#include "analizer.h"

void analizer::detect(std::string s_value)
{
    rapidjson::Document docs;

    docs.Parse(data.c_str());

    if (docs.GetParseError())
    {
        std::cout << "error... the data is corrupted or may have wrong format" << std::endl;
        exit(1);
    }

    
    int found = 0;

    if (docs.IsArray())
    {
        int temp = 0;

        for (auto &m : docs.GetArray())
        {
            if (m.IsObject())
            {
                for (auto &n : m.GetObject())
                {
                    if (n.value.IsString())
                    {
                        if (n.name.GetString() == s_state && n.value.GetString() == s_value)
                            found = temp;
                    }
                }
            }

            temp++;
        }
    }

    rapidjson::Value _state;
    _state = docs[found][s_state.c_str()];
    assert(_state.IsString());

    rapidjson::Value _log;
    _log = docs[found][s_change.c_str()];
    assert(_log.IsArray());

    std::cout << _state.GetString() << " update features:" << std::endl;

    for (auto &m : _log.GetArray())
        std::cout << m.GetString() << std::endl;
}

void analizer::set_data(std::string t_data) {data = t_data;}