#include <iostream>
#include "Fuzzy.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Fuzzy logic(0,2,4);

    std::map<string, double> l = logic.Triangular_Speed(-1);

    cout << l.size()<< endl;
    cout << "The membership Degree: " << l["Max"] << endl;
    cout << "The membership Degree: " << l["Mid"] << endl;


    return 0;
}
