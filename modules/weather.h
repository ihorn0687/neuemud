#include <string>
#include <fstream>

using namespace std;

namespace weather
{
    std::string temperature = readfile::reade("modules/data/region", "07");
    std::string condition = readfile::reade("modules/data/region", "02");
    std::string type = readfile::reade("modules/data/region", "03");
    std::string weatherOutput = condition + " " + type;
}