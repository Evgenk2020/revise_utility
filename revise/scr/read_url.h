#ifndef READ_URL_H
#define READ_URL_H

#include <iostream>

//------------------------------------------
//class for url reading
class read_url
{
private:
    std::string st_source; 
    std::string f_buffer;
    static size_t fn_write(char *data, size_t size, size_t n_member, std::string *buffer);

public:
    std::string st_obtain_info;
    read_url();
    void set_url(std::string temp_url);
    void obtain_data();
    ~read_url() {}
};
//------------------------------------------

#endif // READ_URL_H