#include <iostream>

using namespace std;

int main () 
{
    int newIdx = 0;
    const int SIZE = 10; //make it constant
    string inventory[SIZE] = {"boots", "gloves", "sword"};
    // if int arr[3] = {}, the values of the elements will be initialized to 0

    // show initial inventory
    for (int i = 0; i < SIZE; i++) 
    {
        if (inventory[i] != "") {// only print non-empty inventory items
            cout << inventory[i] << " ";
        }
        else 
        { 
            cout << "_";
        }
        if (i != SIZE - 1) {
            cout << ", ";
        }
        else {
            cout << endl;
        }
    }

    cout << "Where 0-9" << SIZE - 1 << " in the inventory do you want to place an item? ";
    cin >> newIdx;

    return 0;

}