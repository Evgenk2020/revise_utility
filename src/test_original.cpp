#include "test_original.h"

void test_with_original(std::string in_state)
{
    const std::string r_file = "temp.json";
    int select;

    if (in_state == "stable")
        select = 0;

    else if (in_state == "beta")
        select = 1;

    else
    {
        std::cout << "correct variant must be selected..." << std::endl;
        exit(1);
    }

    _writefl wrtf(source_version);
    wrtf._write();

    _read_offline readf;
    readf.set_file(r_file);
    readf.obtain_data();

    rapidjson::Document jss;
    jss.Parse(readf._obtain_file_info.c_str());

    if (jss.GetParseError())
    {
        std::cout << "processing test error..." << std::endl;
        exit(1);
    }

    rapidjson::Value info_t;

    info_t = jss[select]["state"];
    assert(info_t.IsString());
    std::cout << info_t.GetString() << " version:" << std::endl;

    info_t = jss[select]["changelog"];
    assert(info_t.IsString());
    std::cout << info_t.GetString() << std::endl;

    wrtf._clear();
}