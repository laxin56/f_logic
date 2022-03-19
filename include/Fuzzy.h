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

        Fuzzy(double, double, double);
        virtual ~Fuzzy();

        std::map<std::string, double> Triangular_Speed(double);

};

#endif // FUZZY_H
