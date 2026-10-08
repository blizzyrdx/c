#include <iostream>
#include <string> // library for strings

using namespace std; // use the standard namespace

int main() { //entry

    string weapon1 = "saradomin godsword"; //weapon 1
    string weapon2 = "saradomin cape"; // makes sure to only have sara
    string weapon3 = "zamorak staff"; // z
    string weapon4 = "zamorak rune armor";
    string weapon5 = "dragon hunter lance"; //dragon hunter weapon selection

    string searchString; //search string entered by the user
    int again = 0;

    do { 

        do { // do while loop until a non-empty string is entered
            cout << "Enter a string to search weapons for: "; 
            getline(cin, searchString); //includes whitespaces

            if (searchString.empty()) { //error check for empty input
                cout << "Must enter something to search for..." << endl; // prompt the user to enter a non-empty string
            }

        } while (searchString.empty()); // if the search string is empty, repeat the loop

        for (int i = 0; i < searchString.length(); i++) { // for loop 
            if (searchString[i] >= 'A' && searchString[i] <= 'Z') { // keeps uppercase letters consistent by converting to lowercase
                searchString[i] = searchString[i] + 32; // by adding 32 it turns into lowercase
            }
        }

        bool match1 = true; // assumes weapon1 matches the search string
        bool match2 = true; // assumes weapon2 matches the search string
        bool match3 = true; // assumes weapon3 matches the search string
        bool match4 = true; // assumes weapon4 matches the search string
        bool match5 = true; // assumes weapon5 matches the search string

        if (searchString.length() > weapon1.length()) { // checks for how long character is
            match1 = false;
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (weapon1[i] != searchString[i]) { // matches them one and a time
                    match1 = false;
                    break;
                }
            }
        }

        if (searchString.length() > weapon2.length()) { // checks for weapon2
            match2 = false; // flag that weapon2 does not match the search string
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (weapon2[i] != searchString[i]) { // matches them one and a time
                    match2 = false;
                    break;
                }
            }
        }

        if (searchString.length() > weapon3.length()) {
            match3 = false;
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (weapon3[i] != searchString[i]) { // matches them one and a time
                    match3 = false;
                    break; // exit the loop if a character does not match
                }
            }
        }

        if (searchString.length() > weapon4.length()) {
            match4 = false;
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (weapon4[i] != searchString[i]) { // matches them one and a time
                    match4 = false; // flag that weapon4 does not match the search string
                    break; // exit the loop if a character does not match
                }
            }
        }

        if (searchString.length() > weapon5.length()) {
            match5 = false;
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (weapon5[i] != searchString[i]) { // matches them one and a time
                    match5 = false; // flag that weapon5 does not match the search string
                    break; // exit the loop if a character does not match
                }
            }
        }
        
        if (match1 || match2 || match3 || match4 || match5) { //only print a newline if at least one weapon matches
        cout << endl;
}

        if (match1) { // if weapon1 matches the search string
            cout << weapon1 << endl;
        }

        if (match2) { // if weapon2 matches the search string
            cout << weapon2 << endl;
        }

        if (match3) { // if weapon3 matches the search string
            cout << weapon3 << endl;
        }

        if (match4) { // if weapon4 matches the search string
            cout << weapon4 << endl;
        }

        if (match5) { // if weapon5 matches the search string
            cout << weapon5 << endl;
        }

        if (!match1 && !match2 && !match3 && !match4 && !match5) { // if no weapons match the search string
            cout << endl;
            cout << searchString << " not found in any weapons." << endl; // error message
        }

        do {
            cout << "Find another weapon (0)no or (1)yes? "; // prompt the user to find another weapon
            cin >> again;

            if (cin.fail()) { // check if the input failed
                cin.clear(); //clears to prevent
                cin.ignore(10000, '\n'); // ignores
                cout << "Invalid selection..." << endl; // invalid input message
                again = -1;
            }
            else if (again != 0 && again != 1) { // if the input is not 0 or 1
                cout << "Invalid selection..." << endl; // error message for invalid selection
            }

        } while (again != 0 && again != 1); // do while statement

        cin.ignore(10000, '\n');

    } while (again == 1);

    return 0;
}