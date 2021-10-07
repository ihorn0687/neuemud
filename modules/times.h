#include <string>
#include <fstream>
#include "data/functions/readfile.h"

using namespace std;
//using namespace readfile;

namespace times
{
    string output()
    {
    string regionData = readfile::reade("modules/data/region", "01");
    string time = regionData;
    //string time = "14:30";
    return time;
    }
}