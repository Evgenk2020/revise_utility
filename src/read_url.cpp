
#include "read_url.h"

size_t _read_url::fn_write(char *data, size_t size, size_t n_member, std::string *buffer)
{
    size_t result = 0;

    if (buffer != NULL)
    {
        buffer->append(data, size * n_member);
        result = size * n_member;
    }

    return result;
}

void _read_url::obtain_data()
{
    char _error_buffer[CURL_ERROR_SIZE];
    CURL *_curl = curl_easy_init();

    if (_curl)
    {
        curl_easy_setopt(_curl, CURLOPT_ERRORBUFFER, _error_buffer);
        curl_easy_setopt(_curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(_curl, CURLOPT_URL, _source.c_str());
        curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &f_buffer);
        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, fn_write);

        CURLcode res = curl_easy_perform(_curl);
        curl_easy_cleanup(_curl);

        if (res == CURLE_OK)
            _obtain_info = f_buffer;

        else
        {
            std::cout << "error " << res << ' ' << _error_buffer << std::endl;
            exit(1);
        }
    }
}

void _read_url::set_url(std::string temp_url) { _source = temp_url; }
_read_url::_read_url() { _obtain_info = "empty"; }