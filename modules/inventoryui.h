#include <string>
#include "data/functions/dbutil.h"

namespace inventoryui
{
    string output()
    {

        string output = ""; 
        string intro = "\n\nYou open your backpack to find: \n \n";
        string inventory = dbutil::getInventory("modules/data/functions/programdata/inventory");
        output = intro + inventory;
        return output;
    }
}