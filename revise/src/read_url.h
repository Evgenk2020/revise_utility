#ifndef READ_URL_H
#define READ_URL_H

#include <curl/curl.h>
#include <iostream>

class _read_url
{
private:
    std::string _source;
    std::string f_buffer;
    static size_t fn_write(char *data, size_t size, size_t n_member, std::string *buffer);

public:
    std::string _obtain_info;
    _read_url();
    void set_url(std::string temp_url);
    void obtain_data();
    ~_read_url() {}
};

#endif // READ_URL_H