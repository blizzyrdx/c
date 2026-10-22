#include <iostream>
#include <fstream>

using namespace std;

int main () {

    // headers, input file, etc
    string fileName; //initialize filename first
    ifstream iFile(fileName);

    // inventory file
    cout << "Inventory File: ";
    cin >> fileName;
    iFile.open(fileName);

    // loop to check if inventory file is good 
    do {
        cout << "Error: Invalid inventory file name\n";

    } while (!iFile.good());

    // bank file
    cout << "Bank File: ";
    cin >> fileName;
    iFile.open(fileName);

    // loop to check if bank file is good
    do {
        cout << "Error: Invalid bank file name\n";

    } while (!iFile.good());

    /* Read the inventory file. First read the headers, then loop reading the index the item should be 
    placed in the inventory and name of the item to be placed, then saving the name of the item into the 
    inventory array at the index read from the file. The inventory array should be of size 5. */
    string headers = "";
    const int SIZE = 5;
    int inventory[SIZE] = {};

    if (fileName == "bank1.txt" || fileName == "bank2.txt") {
        getline(iFile, headers);

        for (int i = 0; i < SIZE; i++) {
            int position = 0;
            string name = "";
            iFile >> position >> name;
        }

    }
    

    return 0;
}