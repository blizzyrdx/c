#include <iostream>
#include <iomanip>
 
using namespace std;

int main () {

    int inches = 0;

    cout << "Inches: ";
    cin >> inches;

    double feet = static_cast<double>(inches)/12;
    double yards = feet/3;

    cout << setprecision(3) << fixed << left << setw(20) << "Inches -> Feet " << right << setw(10) << feet << endl;
    cout << left << setw(20) << "Feet -> Yards" << right << setw(10) << yards << endl;

    return 0;
}