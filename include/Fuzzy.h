#ifndef FUZZY_H
#define FUZZY_H

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

typedef std::map<std::string, double> Fuzzy_Set;
typedef std::map<std::string, std::string> m1;
typedef std::map<std::string, m1> Rules;

typedef std::map<double, double> double_set;
typedef std::map<std::string, double_set> Output_rules;

/*******************************************************************
******************** Rules for Output function *********************
********    angle\speed|Low|Mid|Max|         ***********************
********           Left|FR | FR| R |         *********************
********           Zero| R | Z | Z |         *********************
********          Right| FL| FL| L |         *********************
********************************************************************/


class Fuzzy
{
    public:

        double _min;
        double _mid;
        double _max;

        double _ymax = 1.0;
        double _ymin = 0.0;

        Rules rules_set;
        Output_rules crisp_val;


        Fuzzy(double v_min, double, double);
        virtual ~Fuzzy();

        Fuzzy_Set fuzzification_triangle(double);

        double check_lower(double, double);

        Fuzzy_Set rule_match(Fuzzy_Set, Fuzzy_Set);

        double defuzzification_triangle(Fuzzy_Set);

};

#endif // FUZZY_H
