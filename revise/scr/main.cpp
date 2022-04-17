#include <iostream>

#include "help.h"
#include "url_version.h"
#include "analizer.h"
#include "read_url.h"
#include "keys.h"

using namespace std;


//------------------------------------------------------------------
//get json info
class json_info
{
private:
    read_url read_url_t;
    analizer analizer_t;

public:
    void compare(string url_path, string status);
    ~json_info() {}
};

void json_info::compare(string url_path, string status)
{
    read_url_t.set_url(url_path);
    read_url_t.obtain_data();
    analizer_t.set_data(read_url_t.st_obtain_info);
    analizer_t.detect(status);
}
//------------------------------------------------------------------

int main(int argc, char *argv[])
{
    if (argc < 2)
        errors();

    if (argc == 2)
    {
        const string stvr = "stable";
        const string btvr = "beta";
        string similar = (string)argv[1];
        json_info json_info_t;

        bool help_t = (similar == k_help_one || similar == k_help_two);

        if (help_t)
            help();

        if (similar == k_stable) // stable
            json_info_t.compare(correct_online, stvr);

        if (similar == k_beta) // beta
            json_info_t.compare(correct_online, btvr);

        /*
        additional keys

        The data below is containing the original format given on https://dev.raveos.com/api/versions/
        As far as it might be broken data there the error report will appear running this program
        */
        if (similar == k_test_stable_err)
            json_info_t.compare(original_online, stvr);
        
        if (similar == k_test_beta_err)
            json_info_t.compare(original_online, btvr);
    }

    return 0;
}