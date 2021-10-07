#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#ifndef DBUTIL
#define DBUTIL

/* DBUTILITIES
dbutil.h has two methods, both for manipulating the inventory (it's called 'dbutil' because it uses the database file).
they both use readfile.h, and make liberal use of the reade() function.
getInventory() returns a pretty inventory list
queryInventory returns a boolean result as to if an inventory item is present, using the database for querying in readable-text
This. Was. A. Pain. To. Write.
This needed a complete rework of readfile and the rest of the codebase to add getInventory(), and another to add queryInventory().
*/

namespace dbutil
{
    string getInventory(string file)
    {
    //add the file-path to your inventory file, get a pretty, readable version out.
    ifstream myFile;
    myFile.open(file);
    string result;

    if(myFile.is_open())
    {
        string line;
        string linetest;
        vector<string> names;

        while(myFile >> line)
        {
            names.push_back(line);
        }
        
        for(string name : names)
        {
            string substring = name.substr(4, name.size());
            //cout << substring + "\n";
            string fullname = readfile::reade("modules/data/functions/programdata/database", substring);
            if (fullname != "") // so that inventory comment data is conveniently ignored. Try it, you'll see
                result += "* " + fullname + "\n\n";
        }
    }
    myFile.close();
    return result;
    }

    bool queryInventory(string file, string item)
    {
    // add the file-path to your inventory file, then use a string to look within a readable version of the inventory.
    // you'll get a true/false as to whether that item is in your inventory.
    ifstream myFile;
    myFile.open(file);
    bool result = false;

    if(myFile.is_open())
    {
        string line;
        string linetest;
        vector<string> names;

        while(myFile >> line)
        {
            //getline(myFile, line, '\n');
            //cout << line + "\n";
            names.push_back(line);
            line = "";
        }

        for(string name : names)
        {
            std::cout << line + "\n";
            string substring = name.substr(4, name.size());
            string lookup = readfile::reade("modules/data/functions/programdata/database", substring);
            //cout << lookup + "\n";
            //cout << lookup;
            auto ifFound = lookup.find(item);
            //cout << ifFound;
            if(ifFound != string::npos)
            {
                result = true;
            }
        }
    }
    myFile.close();
    return result;
    }

    string getStats(string item)
    /*
        This takes the 'item' string used in queryInventory and finds the statistics of that item.
        Intended to be used with other functions and a find() function to parse the big-honking string this spits out.
        This uses the 'statsitics' file. 
     */
    {
        return item;
    }
}

#endif