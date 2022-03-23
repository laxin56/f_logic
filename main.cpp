#include <iostream>
#include "Fuzzy.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    /*
    * Angular Speed Fuzzy Set Calculation
    */
    Fuzzy ang_speed_set(0,2,4);

    std::map<string, double> fuzzy_1 = ang_speed_set.fuzzification_triangle(1);

    cout << fuzzy_1.size()<< endl;
    cout << "The membership Degree: " << fuzzy_1["Max"] << endl;
    cout << "The membership Degree: " << fuzzy_1["Mid"] << endl;

    /*
    * Angular Angle Fuzzy Set Calculation
    */

    Fuzzy ang_set(-15,0,15);

    std::map<string, double> fuzzy_2 = ang_set.fuzzification_triangle(5);

    cout << fuzzy_2.size()<< endl;
    cout << "The membership Degree: " << fuzzy_2["Mid"] << endl;
    cout << "The membership Degree: " << fuzzy_2["Max"] << endl;

    //Rules rules_set;

    Fuzzy_Set matched_rules;

    matched_rules = ang_set.rule_match(fuzzy_1, fuzzy_2);

    Fuzzy_Set::iterator it_n;

    for(it_n = matched_rules.begin(); it_n != matched_rules.end(); it_n ++)
    {
        cout << it_n->first << it_n->second<< endl;
    }

    double end_1;

    end_1 = ang_set.defuzzification_triangle(matched_rules);

    cout << end_1 << endl;


    return 0;
}
