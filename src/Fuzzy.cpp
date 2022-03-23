#include "Fuzzy.h"

Fuzzy::Fuzzy(double v_min, double v_mid, double v_max)
{
    this->_min = v_min;
    this->_mid = v_mid;
    this->_max = v_max;

    // First element of second map is angle, second is speed

    //this->rules_set["FR"].insert(std::map<std::string, std::string>("Low", "Low"));

    this->rules_set.insert(std::make_pair("FR1",m1()));
    this->rules_set["FR1"].insert(std::make_pair("Low", "Mid"));
    this->rules_set.insert(std::make_pair("FR2",m1()));
    this->rules_set["FR2"].insert(std::make_pair("Low", "Mid"));
    this->rules_set.insert(std::make_pair("R1",m1()));
    this->rules_set["R1"].insert(std::make_pair("Low", "Max"));

    this->rules_set.insert(std::make_pair("R2",m1()));
    this->rules_set["R2"].insert(std::make_pair("Mid", "Low"));
    this->rules_set.insert(std::make_pair("Z1",m1()));
    this->rules_set["Z1"].insert(std::make_pair("Mid", "Mid"));
    this->rules_set.insert(std::make_pair("Z2",m1()));
    this->rules_set["Z2"].insert(std::make_pair("Mid", "Max"));

    this->rules_set.insert(std::make_pair("FL1",m1()));
    this->rules_set["FL1"].insert(std::make_pair("Max", "Low"));
    this->rules_set.insert(std::make_pair("FL2",m1()));
    this->rules_set["FL2"].insert(std::make_pair("Max", "Mid"));
    this->rules_set.insert(std::make_pair("L1",m1()));
    this->rules_set["L1"].insert(std::make_pair("Max", "Max"));

    this->crisp_val.insert(std::make_pair("FL",double_set()));
    this->crisp_val["FL"].insert(std::make_pair(-100, -50));
    this->crisp_val.insert(std::make_pair("L",double_set()));
    this->crisp_val["L"].insert(std::make_pair(-100, 0));
    this->crisp_val.insert(std::make_pair("Z",double_set()));
    this->crisp_val["Z"].insert(std::make_pair(-50, 50));
    this->crisp_val.insert(std::make_pair("R",double_set()));
    this->crisp_val["R"].insert(std::make_pair(0, 100));
    this->crisp_val.insert(std::make_pair("FR",double_set()));
    this->crisp_val["FR"].insert(std::make_pair(50, 100));
}

Fuzzy::~Fuzzy()
{
    //nothing
}

/******************************************************
***             Similar Triangle rule              ****
*** (y2 - y1)/(x2 - x1) = (memb_deg - y1)/(x - x1) ****
******************************************************/

Fuzzy_Set Fuzzy::fuzzification_triangle(double speed)
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


double Fuzzy::check_lower(double input1, double input2)
{
    if(input1 <= input2)
        return input1;
    else
        return input2;
}



/*******************************************************************
******************** Rules for Output function *********************
********    angle\speed|Low|Mid|Max|         ***********************
********           Left|FR | FR| R |         *********************
********           Zero| R | Z | Z |         *********************
********          Right| FL| FL| L |         *********************
********************************************************************/


Fuzzy_Set Fuzzy::rule_match(Fuzzy_Set angle, Fuzzy_Set speed)
{
    Fuzzy_Set::iterator it_a;
    Fuzzy_Set::iterator it_s;
    Rules::iterator it_in;
    m1::iterator it_out;

    Fuzzy_Set::iterator it_1;
    Fuzzy_Set::iterator it_2;
    Fuzzy_Set out_1;
    Fuzzy_Set out_2;
    std::string rule;

    out_2.insert(std::make_pair("Z", 2.0));
    out_2.insert(std::make_pair("FR", 2.0));
    out_2.insert(std::make_pair("FL", 2.0));
    out_2.insert(std::make_pair("R", 2.0));
    out_2.insert(std::make_pair("L", 2.0));

    for(it_a = angle.begin(); it_a != angle.end(); it_a++)
    {
        for(it_s = speed.begin(); it_s != speed.end(); it_s++)
        {
            for(it_in = this->rules_set.begin(); it_in != this->rules_set.end(); it_in++)
            {
                for(it_out = it_in->second.begin(); it_out != it_in->second.end(); it_out++)
                {
                    if(it_a->first == it_out->first && it_s->first == it_out->second)
                    {
                        if(it_s->second < it_a->second)
                            out_1.insert(std::make_pair(it_in->first,it_s->second));
                        else
                            out_1.insert(std::make_pair(it_in->first,it_a->second));
                    }
                }
            }
        }
    }


    for(it_1 = out_1.begin(); it_1 != out_1.end(); it_1++)
    {
        rule = it_1->first;
        if(it_1->first.size() == 3)
            rule = rule.erase(2,1);
        else if (it_1->first.size() == 2)
            rule = rule.erase(1,1);

        it_2 = out_2.lower_bound(rule);

        if(it_2 != out_2.end())
            it_2->second = this->check_lower(it_1->second, it_2->second);


    }

    return out_2;

}

/*
* This method is using weightened average method for defuzzification
*/
double Fuzzy::defuzzification_triangle(Fuzzy_Set input)
{
    Fuzzy_Set::iterator it;
    Output_rules::iterator it_rules;
    double_set::iterator it_in;

    double denominator = 0;
    double nominator = 0;
    double temp = 1.0;

    for(it = input.begin(); it != input.end(); it++)
    {
        if(it->second != 2.0)
        {
            it_rules = this->crisp_val.lower_bound(it->first);
            for(it_in = it_rules->second.begin(); it_in != it_rules->second.end(); it_in++)
            {
                temp = abs((it_in->first + it_in->second)/2);
                std::cout << temp << std::endl;
                nominator += it->second * temp;
                denominator += temp;
            }
        }
    }
    std::cout << nominator << " " << denominator << std::endl;
    return nominator/denominator;
}
