#include "Fuzzy.h"
#include <vector>
Fuzzy::Fuzzy(double s_min, double s_mid, double s_max)
{
    this->_Speed_Min = s_min;
    this->_Speed_Mid = s_mid;
    this->_Speed_Max = s_max;

}

Fuzzy::~Fuzzy()
{
    //nothing
}

/******************************************************
***             Similar Triangle rule              ****
*** (y2 - y1)/(x2 - x1) = (memb_deg - y1)/(x - x1) ****
******************************************************/

std::map<std::string, double> Fuzzy::Triangular_Speed(double speed)
{
    //Variable for calculating fuzzy membership degree
    double val = 0;
    //Fuzzy Set map (dictionary)
    Fuzzy_Set memb_deg;

    if(speed <= this->_Speed_Min)
    {
        //Before Low Fuzzy Set
        memb_deg.insert(std::pair<std::string, double>("Low", 1.0));
    }
    else if ( speed > this->_Speed_Min && speed < this->_Speed_Mid )
    {
        std::cout<< "Hello";
        //Low Speed Fuzzy Set
        val = ((_ymin - _ymax)*(speed - this->_Speed_Min)/(this->_Speed_Mid - this->_Speed_Min)) + _ymax;
        memb_deg.insert(std::pair<std::string, double>("Low", val));

        //Medium Speed Fuzzy Set
        val = ((_ymax - _ymin)*(speed - this->_Speed_Min)/(this->_Speed_Mid - this->_Speed_Min)) + _ymin;
        memb_deg.insert(std::pair<std::string, double>("Mid", val));
    }
    else if ( speed == this->_Speed_Mid)
    {
        //Medium Speed Fuzzy Set
        memb_deg.insert(std::pair<std::string, double>("Mid", 1.0));
    }
    else if ( speed > this->_Speed_Mid && speed < this->_Speed_Max )
    {
        //Medium Speed Fuzzy Set
        val = ((_ymin - _ymax)*(speed - this->_Speed_Mid)/(this->_Speed_Max - this->_Speed_Mid)) + _ymax;
        memb_deg.insert(std::pair<std::string, double>("Mid", val));

        //Max Speed Fuzzy Set
        val = ((_ymax - _ymin)*(speed - this->_Speed_Mid)/(this->_Speed_Max - this->_Speed_Mid)) + _ymin;
        memb_deg.insert(std::pair<std::string, double>("Max", val));
    }
    else if ( speed >= this->_Speed_Max )
    {
        //Max Speed Fuzzy Set
        memb_deg.insert(std::pair<std::string, double>("Max", 1.0));
    }


    return memb_deg;

}
