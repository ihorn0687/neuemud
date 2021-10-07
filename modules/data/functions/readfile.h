#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <iostream>

#ifndef READFILE
#define READFILE

/* READFILE: THE FINAL FRONTIER

readfile.h has one notable method called reade (why is it called read? Scars from development without file-guards, that's why.)
While there is only this one function, it's possibly one of the most complex and definitely the most modular/reusable piece of code I've written to date.
(Note: this is as of August 19th, 2021)
I'm putting in documentation both for posterity (I hope to put this code on, idk, Github or something) and so that my eyes don't cross.
This was embarassingly hard to put together (call it being a little green when it comes to C++).
*/

using namespace std;

namespace readfile
{
    string reade(string file, string readString)
    /* 
        reade takes a string as a file path, and a string to query the file for.
        it then returns the latter part of a string
        eg. a01:aa01 -> aa01. 
        note: as of update 0.26, prefixes and postfixes have now been decoupled
        now you can match pretty much any prefix with any postfix
        provided that the database id name is changed
        this makes working with files infinitely more enjoyable, and allows comments to be added.
    */
    {
    ifstream myFile;
    myFile.open(file);
    string result;

    if(myFile.is_open())
    {
        string line;
        string linetest;
        vector<string> names;

        //std::cout << "reading file";

        while(!myFile.eof())
        {
        getline(myFile, line, '\n'); //getLine, so that spaces function.
        //cout << line + "\n";
        names.push_back(line);
        line = "";
        }
        
        for(string name : names)
        {
            auto ifFound = name.find(readString);
            if(ifFound != string::npos)
            {
                //cout << "found";
                string substring = name.substr(readString.size()+1, name.size());
                result += substring;
                break;
            }
        }
    }
    myFile.close();
    return result;
    }
}

#endif