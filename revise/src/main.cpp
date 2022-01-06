#include <iostream>
#include <string.h>
#include <stdio.h>

#include "help.h"
#include "url_version.h"
#include "analizer.h"
#include "read_url.h"
#include "pur_test_online.h"
#include "test_original.h"
#include "keys.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
        errors();

    if (argc == 2)
    {
        const string stvr = "stable";
        const string btvr = "beta";
        string simile = (string)argv[1];
        
        _read_url readurl;
        analizer _analizer;

        bool _help = (simile == k_help_one || simile == k_help_two);

        if (_help)
            help();

        if (simile == k_stable) //stable
        {
            readurl.set_url(source_version);
            readurl.obtain_data();
            _analizer.set_data(readurl._obtain_info);
            _analizer.detect(stvr);
        }

        if (simile == k_beta)   //beta
        {
            readurl.set_url(source_version);
            readurl.obtain_data();
            _analizer.set_data(readurl._obtain_info);
            _analizer.detect(btvr);
        }

        //-----------------------------------------------------------------------
        //дополнительные ключи
        if (simile == k_test)
            parse_pure_test();

        if (simile == k_test_stable_err)
            test_with_original(stvr);

        if (simile == k_test_beta_err)
            test_with_original(btvr);

        if (simile == k_tstable)
        {
            readurl.set_url(correct_online);
            readurl.obtain_data();
            _analizer.set_data(readurl._obtain_info);
            _analizer.detect(stvr);
        }

        if (simile == k_tbeta)
        {
            readurl.set_url(correct_online);
            readurl.obtain_data();
            _analizer.set_data(readurl._obtain_info);
            _analizer.detect(btvr);
        }

        if (simile == k_test_norm_err)
        {
            readurl.set_url(original_online);
            readurl.obtain_data();
            _analizer.set_data(readurl._obtain_info);
            _analizer.detect(stvr);
        }
        //-----------------------------------------------------------------------
    }

    return 0;
}
