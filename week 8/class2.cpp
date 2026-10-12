#include <iostream>

using namespace std;

int main () 
{
    const int SIZE = 10; //make it constant
    string inventory[SIZE] = {"boots", "gloves", "sword"};
    // if int arr[3] = {}, the values of the elements will be initialized to 0

    // show initial inventory
    for (int i = 0; i < SIZE; i++) 
    {
        cout << inventory[i] << endl;
    }
    return 0;

}