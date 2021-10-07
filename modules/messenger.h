#include <string>
#include <vector>
#include "data/functions/readfile.h"

namespace msg
{
    std::string commitMessage(std::string message)
    {
        std::string timeData = readfile::reade("modules/data/region", "01");
        std::string nameData = readfile::reade("modules/data/session", "04");
        std::string fullMessage = timeData + " -- message {" + nameData + " : \"" + message + "\"}";


        //The Boulevard of Broken Dreams
        //This is what you try to do when you don't know ios::app exists
        //Use ios::app. Don't use this horrible rat's-nest of code.

        /*ifstream readFile;
        readFile.open("modules/data/messagequeue");

        string line;
        vector<string> names;

        if(readFile.is_open())
    {

        while(!readFile.eof())
        {
        getline(readFile, line, '\n');
        names.push_back(line);
        //std::cout << line + "line end";
        line = "";
        }
    }
    readFile.close();
        names.push_back(fullMessage);
        ofstream writeFile;
        writeFile.open("modules/data/messagequeue");
        if(writeFile.is_open())
    {

        for(string name : names)
        {
            writeFile <<  std::noskipws << "\n" + name;
        }
    }*/
    fstream writeFile("modules/data/messagequeue", ios::out | ios::in | ios::app); //need to append because trying to r/w the whole file sucks.
    //writeFile.open("modules/data/messagequeue");
        if(writeFile.is_open())
    {
        writeFile << fullMessage + "\n";
    }
    else cout << "failed sending message";
    writeFile.close();
        return fullMessage; //See, 21 lines saved by not being an idiot. Works gud.
    }
}