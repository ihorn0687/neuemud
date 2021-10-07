#include <string>
#include "times.h"
#include "weather.h"
#include "distance.h"
#include "condition.h"

namespace walkui
{
    string output()
    {

        //std::string distanceTo = "5.6";
        //std::string distanceAway = "1.2";
        std::string time = "\n\nThe time is " + times::output() + ".";
        std::string distance = distance::output();
        std::string weather = "\n \nIt is currently " + weather::temperature + " degrees Celsius outside, and it is " + weather::weatherOutput + ".";
        std::string condition = " You are " + condition::getWaterLog() + ". In regards to your temperature, you feel like you are " + condition::findTemperatureQuip() + " You feel " + condition::findSleepQuip() + " You are also " + condition::findHungerQuip() + ".. You could probably walk for about " + condition::getRemainHunger() + " more hours.";
        std::string output = time + distance + weather + condition;

        return output;
    }
}