#include <iostream>

using namespace std;

int main() {

    double decagon = 0;
    char selection = 0;
    double area = 0;
    double perimeter = 0;

    cout << "Decagon Side Length: ";
    cin >> decagon; 

    if (cin.fail() || decagon <= 0) {
        cout << "Error\n";
        return 0;
    }

    cout << "(A/a)rea -or- (P/p)erimeter: ";
    cin >> selection;

    switch (selection)
    {
    case 'A':
    case 'a':
        area = (5.0/2.0) * pow(decagon, 2) * sqrt(5 + 2 * sqrt(5));
        cout << "Area: " << area << endl;
        break;
    
    case 'P':
    case 'p':
        perimeter = 10 * decagon;
        cout << "Perimeter: " << perimeter << endl;
        break;
    
    default:
        cout << "Invalid Selection\n";
    }


    return 0;
}