#include "read_file.h"

void _read_offline::obtain_data()
{
    std::ifstream in(_file_name);
    _obtain_file_info = "";

    if (in.fail())
    {
        std::cout << "read data error..." << std::endl;
        exit(1);
    }

    if (in.is_open())
    {
        std::string buffer;
        while(!in.eof())
        {
            getline(in, buffer);
            _obtain_file_info.append(buffer);
        }
    }

    in.close();
}

_read_offline::_read_offline() { _obtain_file_info = "empty"; }
void _read_offline::set_file(std::string file_name) { _file_name = file_name; }