#include <stdio.h>
#include <iostream>
#include "modules/data/functions/coreutil.h"
#include "modules/walkui.h"
#include "modules/inventoryui.h"
#include "modules/messenger.h"
#include "modules/use.h"

int main()
{
    int quit = 0;
    coreutil::showwarning();
    //cout << walkui::output;
    while( quit == 0)
    {
        string query;
        cout << "\n\n\n[Console: ";
        //cout << inventoryui::output;
        getline(cin, query);
        if (query == "inventory" || query == "backpack" || query == "i")
        {
            coreutil::wipe();
            cout << inventoryui::output();
        }
        else if (query == "quit" || query == "q")
        {
            coreutil::wipe();
            quit = 1;
        }
        else if (query == "walk" || query == "w" || query == "move")
        {
            coreutil::wipe();
            cout << walkui::output();
        }
        else if (query == "help" || query == "h" || query == "manual")
        {
            coreutil::wipe();
            coreutil::showmanual();
        }
        else if (query == "credits")
        {
            coreutil::wipe();
            coreutil::showcredits();
            coreutil::showwarning();
        }
        else if (query.find("msg") != string::npos || query.find("say") != string::npos)
        {
            coreutil::wipe();
            cout << msg::commitMessage(query.substr(4, query.size()));
        }
        else if (query.find("message") != -1)
        {
            coreutil::wipe();
            cout << msg::commitMessage(query.substr(8, query.size()));
        }
        else if (query.find("use") != -1)
        {
            coreutil::wipe();
            cout << use::useItem(query.substr(4, query.size()));
        }
        else { coreutil::wipe(); cout << "\nCommand Unknown";}
    }

}