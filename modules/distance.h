#include <string>

namespace distance
{
    string output(){
    std::string member2 = readfile::reade("modules/data/session", "01");
    std::string member3 = readfile::reade("modules/data/session", "02");
    std::string member4 = readfile::reade("modules/data/session", "03");

    string distanceTotal = readfile::reade("modules/data/region", "05");
    string distanceTo = readfile::reade("modules/data/region", "06");
    string placeName= readfile::reade("modules/data/region", "04");
    //string placeName= "Sovernetsky";

    
    //"take stock of"
    //"forage"
    //"repair"
    std::string useOne = "take stock of";
    std::string useTwo = " food";
    std::string useThree = " equipment";
    std::string placeUsage = useOne + " your" + useTwo + " and" + useThree;
    
    std::string distance = "\n \nYou, " + member2 + ", " + member3 + ", and " + member4 + " have walked " + distanceTo + " km so far. You are " + distanceTotal + " km away from a place your guide called " + placeName + ", where you can " + placeUsage + ".";
    return distance;
    }
}