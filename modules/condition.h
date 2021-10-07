#include <string>
#include <sstream>

using namespace std;

namespace condition
{    
    //Water is a percentage that is decreased per hour
    int currentWater = stoi(readfile::reade("modules/data/status", "a03"));
    int currentWaterExpenditure = stoi(readfile::reade("modules/data/status", "a04"));

    std::string staminas = readfile::reade("modules/data/status", "a08");
    std::string staminaEffect = "should probably rest";

    string findTemperatureQuip()
    {
        //Temperature is a value that is changed by weather.h
        // values below 75.0 and above 110.0 are instant death
        // values below 96.5 are moderate hypothermia
        double temperature = stod(readfile::reade("modules/data/status", "a06"));


        string temperatures = readfile::reade("modules/data/status", "a06");
        string quip;

        if(temperature < 76.0)
        {
            quip = "deathly cold.";
        }
        else if(temperature < 85.7)
        {
            quip = "freezing, in danger of frostbite.";
        }
        else if(temperature < 90.0)
        {
            quip = "much colder than usual. Staying at this temperature will harm you in the long run.";
        }
        else if(temperature < 95.0)
        {
            quip = "mildly hypothermic, and you should heat up soon.";
        }
        else if(temperature <= 98.6)
        {
            quip = "colder than the average, but that doesn't mean much.";
        }
        else if(temperature <= 100.6)
        {
            quip = "hotter than average, but not any higher than a mild fever or moderate physical exertion.";
        }
        else if(temperature < 105.8)
        {
            quip = "hot enough to know you are sick.";
        }
        else if(temperature <= 110.0)
        {
            quip = "in severe fever. If you do not seek medical attention immediately, you will most certainly die.";
        }
        else
        {
            quip = "unable to properly read your own temperature.";
        }
        
        return quip;
    }

    string findSleepQuip()
    {
        //Sleep is measured in ( hours / 12 ).
        double sleep = stod(readfile::reade("modules/data/status", "a05"));
        string quip;

        if(sleep <= (0.1))
        {
            quip = "barely rested.";
        }
        else if(sleep <= (0.2))
        {
            quip = "very poorly rested.";
        }
        else if(sleep <= (0.3))
        {
            quip = "poorly rested.";
        }
        else if(sleep <= (0.5))
        {
            quip = "half-rested.";
        }
        else if(sleep <= (0.6))
        {
            quip = "pretty well rested.";
        }
        else if (sleep <= 1)
        {
            quip = "very well rested.";
        }
        else
        {
            quip = "like you don't exactly know when you've slept.";
        }
        return quip;
    
    }

    string findHungerQuip()
    {
        //Kcal is a value that is decreased per hour
        int currentKCal = stoi(readfile::reade("modules/data/status", "a01"));
        int hunger = currentKCal;
        int currentKCalExpenditure = stoi(readfile::reade("modules/data/status", "a02"));
        string quip;

        if(hunger >= 2000)
        {
            quip = "very well fed.";
        }
        else if(hunger > 1500)
        {
            quip = "pretty well fed";
        }
        else if(hunger > 1000)
        {
            quip = "getting hungry";
        }
        else if(hunger > 500)
        {
            quip = "very hungry";
        }
        else if(hunger >= 1)
        {
            quip = "starving";
        }
        else{ quip = "not sure what your hunger is.";}
        return quip;
    }

    string getRemainHunger()
    {
        //Kcal is a value that is decreased per hour
        int currentKCal = stoi(readfile::reade("modules/data/status", "a01"));
        int currentKCalExpenditure = stoi(readfile::reade("modules/data/status", "a02"));
        string hunger = to_string(currentKCal / currentKCalExpenditure);
        return hunger;
    }

    string getWaterLog()
    {
        string waterLogged = readfile::reade("modules/data/status", "a07");
        return waterLogged;
    }

    string queryContents()
    {
        std::string staminas = readfile::reade("modules/data/status", "a01");
        return staminas;
    }
}