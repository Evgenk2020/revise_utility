#include "wrfile.h"

void _writefl::_write()
{
    set_url(_web_source);
    obtain_data();

    std::ofstream out;
    out.open(flname);

    if (out.is_open())
        out << _obtain_info << std::endl;

    out.close();
}

void _writefl::_clear()
{
    if (remove(flname.c_str()) != 0)
    {
        std::cout << "remove file error..." << std::endl;
        exit(1);
    }
}

_writefl::_writefl(std::string _tsource) : _web_source(_tsource) {}