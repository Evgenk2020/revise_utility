#include "help.h"

void help()
{
    std::cout << "*** Check for enable versions ***" << std::endl <<
    "revise [-s | -b]" << std::endl << std::endl <<
    "-s -- check for stable version revision" << std::endl <<
    "-b -- check for beta version revision" << std::endl << std::endl <<
    "Additional keys:" << std::endl <<
    "-test -- test reading from the odd news url source" << std::endl << std::endl <<
    "-tstable -- show valid stable version revision from the alternative url" << std::endl <<
    "-tbeta -- show valid beta version revision from the alternative url" << std::endl <<
    "-terr -- show the original version from the alternative url" << std::endl << std::endl <<
    "-trs -- show the original amiss stable revision using disc caching" << std::endl <<
    "-trb -- show the original amiss beta revision using disc caching" << std::endl;

    
    exit(0);
}

void errors()
{
    std::cout << "No input data... Enter -h or --help for more information" << std::endl;
}