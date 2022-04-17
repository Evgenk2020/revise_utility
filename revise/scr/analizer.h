#include <rapidjson/document.h>
#include <iostream>

class analizer
{
private:
    std::string data;
    const std::string s_state = "state";
    const std::string s_change = "changelog";

public:
    void set_data(std::string t_data);
    void detect(std::string s_value);
    ~analizer() {}
};