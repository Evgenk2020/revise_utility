#include "help.h"

void help()
{
    std::cout << "*** Check for enable versions (demo) ***" << std::endl << std::endl <<
    "Usage: " <<
    "revise [-s|-b]" << std::endl << /*std::endl <<*/
    "-s -- check for stable version revision" << std::endl <<
    "-b -- check for beta version revision" << std::endl << std::endl <<
    "Additional keys:" << std::endl <<
    "-stable-given -- read data from original source for stable (read error will appear)" << std::endl <<
    "-beta-given -- read data from original source for beta (read error will appear)" << std::endl;

    exit(0);
}

void errors()
{
    std::cout << "No input data... Enter -h or --help for more information" << std::endl;
}