
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Define variables
    ifstream iFile;
    ofstream ofile("purchases.txt");
    ofstream ofile2("errors.txt");

    string filename = "";
    string item = "";
    long long amount = 0;
    string currency = "";
    int line = 0;

    // Prompt the user for a filename until a valid file is opened
    do {
        cout << "Filename: ";
        getline(cin >> ws, filename);

        iFile.open(filename);

        if (!iFile.is_open()) {
            cout << "Invalid filename" << endl;
            iFile.clear();
        }

    } while (!iFile.is_open());

    // Loop until the end of file is reached
    while (iFile >> item) {
        line++;

        // Read monetary amount
        iFile >> amount;

        // Validate monetary amount
        if (iFile.fail()) {
            ofile2 << "line " << line
                   << " error: Invalid monetary amount\n";

            iFile.clear();
            iFile.ignore(256, '\n');
            continue;
        }

        // Read currency type
        iFile >> currency;

        // Validate currency type
        if (currency != "gold" && currency != "platinum") {
            ofile2 << "line " << line
                   << " error: Invalid monetary type\n";

            iFile.ignore(256, '\n');
            continue;
        }

        // Convert platinum to gold
        long long gold = amount;

        if (currency == "platinum") {
            gold = amount * 1000;
        }

        // Validate item type
        if (item != "scimitar" &&
            item != "bow" &&
            item != "armor" &&
            item != "whip") {

            ofile2 << "line " << line
                   << " error: Invalid weapon\n";

            iFile.ignore(256, '\n');
            continue;
        }

        // Determine item price
        long long price = 0;

        if (item == "scimitar") {
            price = 30000;
        }
        else if (item == "bow") {
            price = 200000;
        }
        else if (item == "armor") {
            price = 500000;
        }
        else if (item == "whip") {
            price = 2500000;
        }

        // Check if player has enough money
        if (gold < price) {
            ofile2 << "line " << line
                   << " error: not enough "
                   << currency << " to buy ";

            if (item != "armor") {
                ofile2 << "a ";
            }

            ofile2 << item << "\n";

            iFile.ignore(256, '\n');
            continue;
        }

// Successful purchase
gold = gold - price;

// Convert remaining balance to original currency
if (currency == "platinum") {
    amount = gold / 1000;
}
else {
    amount = gold;
}

// Output remaining balance
ofile << "purchasing " << item
      << ": " << amount << " "
      << currency << " remaining\n";

        // Skip to next line
        iFile.ignore(256, '\n');
    }

    // Close files
    iFile.close();
    ofile.close();
    ofile2.close();

    return 0;
}
