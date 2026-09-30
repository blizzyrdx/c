#include <iostream>
#include <iomanip>
 
using namespace std;

int main () {

    int inches = 0;

    cout << "Inches: ";
    cin >> inches;

    double feet = inches /12.0 ;
    double yards = feet/ 3.0 ;

    cout << left << setw(20) << "Inches -> Feet " << setw(10) << right << fixed << setprecision(3) << feet << endl;
    cout << left << setw(20) << "Feet -> Yards" << right << fixed << setprecision(3) << setw(10) << yards << endl;

    return 0;
}