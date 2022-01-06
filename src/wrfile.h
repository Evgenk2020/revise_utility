#ifndef WRFILE_H
#define WRFILE_H

#include <iostream>
#include <fstream>
#include "read_url.h"

class _writefl : private _read_url
{
private:
    std::string _web_source;
    const std::string flname = "temp.json";

public:
    _writefl(std::string _tsource);
    void _write();
    void _clear();
    ~_writefl() {}
};

#endif // WRFILE_H