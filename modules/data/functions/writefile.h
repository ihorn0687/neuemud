#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <iostream>
#include <cstdio>

#ifndef WRTIEFILE
#define WRITEFILE

/* WRITEFILE: MOREEEEEE

writefile.h is a modification to readfile.h.
It allows server.cpp to find and replace values within the gamedata.
This makes it a pretty powerful tool. Don't randomly call it to gamedata.
Definitely don't call it to source code.
*/

using namespace std;

namespace writefile
{
    void write(string file, string readString, string writeString)
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
        /*stream myFile;
        myFile.open(file, ios::in | ios::out);
        cout << "file open \n";
        string result;*/

        //if(myFile.is_open())
        string textToFind = readString;
        string replacementText = writeString;
        string fileToParse = file;
        string fileToWrite = file+".txt";

        ifstream inputFileStream(fileToParse, ifstream::in);
        ofstream outputFileStream(fileToWrite);
        cout << "file opened!";

        string fileLine;
        while (getline(inputFileStream, fileLine))
        {
            size_t substringPos = fileLine.find(textToFind);
            if (substringPos != string::npos)
            {
                cout << "line found!";
                fileLine.replace(substringPos+3, fileLine.size(), replacementText);
            }       
            outputFileStream << fileLine + "\n";
        }
        outputFileStream.close();
        inputFileStream.close();
        
        char oldname[] ="region.txt";
        char newname[] ="region";
        rename(oldname, newname);
    
    }
}

#endif