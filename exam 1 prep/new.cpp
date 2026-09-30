#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double length = 0;
    char expression = 0;
    cout << "Decagon Side Length: ";
    cin >> length;

    if (cin.fail() || length < 0) {
        cout << "Error, Invalid Input.\n";
        return 0;
    }

    cout << "(A/a)rea -or (P/p)erimeter ";
    cin >> expression;

    double area = (3 * sqrt(3))/20 * pow(length, 2);
    double perimeter = 6 * length;

    switch (expression) {
        case 'A':
        case 'a':
            cout << "Area: " << area << endl;
            break;

        case 'P':
        case 'p':
            cout << "Perimeter: " << perimeter << endl;
            break;

        default:
            cout << "Invalid seletion\n";
    }
    return 0;
}