#include <iostream>
#include <rapidjson/document.h>

#include "pur_test_online.h"

using namespace std;

void parse_pure_test()
{
    _read_url read_data;
    read_data.set_url(test_version);
    read_data.obtain_data();

    rapidjson::Document docs;
    docs.Parse(read_data._obtain_info.c_str());

    if (docs.GetParseError())
    {
        cout << "error... the data is corrupted or may have wrong format" << endl;
        exit(1);
    }

    cout << "-------------------------" << endl;
    assert(docs.HasMember("provider_name"));
    assert(docs["provider_name"].IsString());
    cout << "provider_name: " << docs["provider_name"].GetString() << endl;

    assert(docs.HasMember("thumbnail_height"));
    assert(docs["thumbnail_height"].IsInt());
    cout << "thumbnail_height: " << docs["thumbnail_height"].GetInt() << endl;

    assert(docs.HasMember("title"));
    assert(docs["title"].IsString());
    cout << "title: " << docs["title"].GetString() << endl;
    cout << "-------------------------" << endl;

    const string a = "html";

    for (auto &m : docs.GetObject())
    {
        if (m.value.IsString())
            if (m.name.GetString() != a)
                cout << m.name.GetString() << ' ' << m.value.GetString() << endl
                     << "****************" << endl;
    }
}