#include <string>

namespace use
{
    std::string useItem(std::string item)
    {
        std::string result;
        bool inInventory = dbutil::queryInventory("modules/data/functions/programdata/inventory", item);
        if(item.find(" ") != string::npos)
        {
            if(inInventory)
            {
                {
                    result = "object " + item + " found!";
                }
            }
            else {result = "object " + item + " not found!";}
        }
        else {result = "query not specific enough";}
        return result;
    }
}