#ifndef FUZZY_H
#define FUZZY_H

#include <vector>
#include <iostream>
#include <map>
#include <string>


typedef std::map<std::string, double> Fuzzy_Set;


class Fuzzy
{
    public:

        double _min;
        double _mid;
        double _max;

        double _ymax = 1.0;
        double _ymin = 0.0;

        Fuzzy(double v_min, double v_mid, double v_max);
        virtual ~Fuzzy();


        std::map<std::string, double> fuzzification_triangle(double input);

        void rule_match(Fuzzy input_1, Fuzzy input_2);



};

#endif // FUZZY_H
