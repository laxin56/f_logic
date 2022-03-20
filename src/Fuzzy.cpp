#include "Fuzzy.h"

Fuzzy::Fuzzy(double v_min, double v_mid, double v_max)
{
    this->_min = v_min;
    this->_mid = v_mid;
    this->_max = v_max;

}

Fuzzy::~Fuzzy()
{
    //nothing
}

/******************************************************
***             Similar Triangle rule              ****
*** (y2 - y1)/(x2 - x1) = (memb_deg - y1)/(x - x1) ****
******************************************************/

std::map<std::string, double> Fuzzy::fuzzification_triangle(double speed)
{
    //Variable for calculating fuzzy membership degree
    double val = 0;
    //Fuzzy Set map (dictionary)
    Fuzzy_Set memb_deg;

    if(speed <= this->_min)
    {
        //Before Low Fuzzy Set
        memb_deg.insert(std::pair<std::string, double>("Low", 1.0));
    }
    else if ( speed > this->_min && speed < this->_mid )
    {
        std::cout<< "Hello";
        //Low Speed Fuzzy Set
        val = ((_ymin - _ymax)*(speed - this->_min)/(this->_mid - this->_min)) + _ymax;
        memb_deg.insert(std::pair<std::string, double>("Low", val));

        //Medium Speed Fuzzy Set
        val = ((_ymax - _ymin)*(speed - this->_min)/(this->_mid - this->_min)) + _ymin;
        memb_deg.insert(std::pair<std::string, double>("Mid", val));
    }
    else if ( speed == this->_mid)
    {
        //Medium Speed Fuzzy Set
        memb_deg.insert(std::pair<std::string, double>("Mid", 1.0));
    }
    else if ( speed > this->_mid && speed < this->_max )
    {
        //Medium Speed Fuzzy Set
        val = ((_ymin - _ymax)*(speed - this->_mid)/(this->_max - this->_mid)) + _ymax;
        memb_deg.insert(std::pair<std::string, double>("Mid", val));

        //Max Speed Fuzzy Set
        val = ((_ymax - _ymin)*(speed - this->_mid)/(this->_max - this->_mid)) + _ymin;
        memb_deg.insert(std::pair<std::string, double>("Max", val));
    }
    else if ( speed >= this->_max )
    {
        //Max Speed Fuzzy Set
        memb_deg.insert(std::pair<std::string, double>("Max", 1.0));
    }


    return memb_deg;
}


void Fuzzy::rule_match(Fuzzy_Set input1, Fuzzy_Set input2)
{

    //iterate through existing rules in nested loop
    //output must be returned output fuzzy set with the strongest membership degree

}

