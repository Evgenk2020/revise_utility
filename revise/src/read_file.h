#ifndef READ_FILE_H
#define READ_FILE_H

#include <fstream>
#include <iostream>
#include <string>

class _read_offline
{
private:
    std::string _file_name;

public:
    std::string _obtain_file_info;
    _read_offline();
    void set_file(std::string file_name);
    void obtain_data();
    ~_read_offline() {}
};

#endif // READ_FILE_H