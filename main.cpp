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

    std::map<string, double> fuzzy_1 = ang_speed_set.fuzzification_triangle(3);

    cout << fuzzy_1.size()<< endl;
    cout << "The membership Degree: " << fuzzy_1["Max"] << endl;
    cout << "The membership Degree: " << fuzzy_1["Mid"] << endl;

    /*
    * Angular Angle Fuzzy Set Calculation
    */

    Fuzzy ang_set(-15,0,15);

    std::map<string, double> fuzzy_2 = ang_set.fuzzification_triangle(4);

    cout << fuzzy_2.size()<< endl;
    cout << "The membership Degree: " << fuzzy_2["Mid"] << endl;
    cout << "The membership Degree: " << fuzzy_2["Max"] << endl;


    return 0;
}
