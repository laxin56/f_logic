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

    std::map<string, double> l = ang_speed_set.Triangular_Speed(1);

    cout << l.size()<< endl;
    cout << "The membership Degree: " << l["Max"] << endl;
    cout << "The membership Degree: " << l["Mid"] << endl;


    return 0;
}
