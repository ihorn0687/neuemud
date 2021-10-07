#include <iostream>

namespace coreutil
{
    std::string versionnumber = "0.50";
    std::string manual = "Welcome to the neueMUD manual for \"TheZone\"! \nType \"inventory\" to check your inventory. \nType \"quit\" to quit the game. \nType \"walk\" to maintain progress on your journey towards the current goal. \nType \"msg\", \"message\", or \"say\" together with some words to chat. \nType \"use\" together with an item from your inventory (two words or more) to use that item. \nType \"manual\" or \"help\" to get this same message.";
    std::string credits = "neueMUD made by Baph! (Isaac Horn) in 2021. This version: " + versionnumber + "b (Beta).";
    std::string warning = "\n\bWarning! This version (" + versionnumber + ") is incomplete! Expect frequent bugs and missing features!";
    
    void showmanual()
    {
        std::cout << manual;
    }

    void showcredits()
    {
        std::cout << credits;
    }

    void showwarning()
    {
        std::cout << warning;
    }
    void wipe()
    {
        std::system("cls"); // for Windows
        std::system("clear"); // for Linux
    }
}