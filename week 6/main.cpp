#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    string weapon1 = "Saradomin Godsword";
    string weapon2 = "Saradomin Cape";
    string weapon3 = "Zamorak Staff";
    string weapon4 = "Zamorak Rune Armor";
    string weapon5 = "Dragon Hunter Lance";

    string searchString;
    int again = 0;

    do {

        do {
            cout << "Enter a string to search weapons for: ";
            getline(cin, searchString);

            if (searchString.empty()) {
                cout << "Must enter something to search for..." << endl;
            }

        } while (searchString.empty());

        bool match1 = true;
        bool match2 = true;
        bool match3 = true;
        bool match4 = true;
        bool match5 = true;

        if (searchString.length() > weapon1.length()) {
            match1 = false;
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (tolower(weapon1[i]) != tolower(searchString[i])) {
                    match1 = false;
                    break;
                }
            }
        }

        if (searchString.length() > weapon2.length()) {
            match2 = false;
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (tolower(weapon2[i]) != tolower(searchString[i])) {
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
                if (tolower(weapon3[i]) != tolower(searchString[i])) {
                    match3 = false;
                    break;
                }
            }
        }

        if (searchString.length() > weapon4.length()) {
            match4 = false;
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (tolower(weapon4[i]) != tolower(searchString[i])) {
                    match4 = false;
                    break;
                }
            }
        }

        if (searchString.length() > weapon5.length()) {
            match5 = false;
        }
        else {
            for (int i = 0; i < searchString.length(); i++) {
                if (tolower(weapon5[i]) != tolower(searchString[i])) {
                    match5 = false;
                    break;
                }
            }
        }

        cout << endl;

        if (match1) {
            cout << weapon1 << endl;
        }

        if (match2) {
            cout << weapon2 << endl;
        }

        if (match3) {
            cout << weapon3 << endl;
        }

        if (match4) {
            cout << weapon4 << endl;
        }

        if (match5) {
            cout << weapon5 << endl;
        }

        if (!match1 && !match2 && !match3 && !match4 && !match5) {
            cout << searchString << " not found in any weapons." << endl;
        }

        cout << "Find another weapon (0)no or (1)yes? ";
        cin >> again;
        cin.ignore();

    } while (again == 1);

    return 0;
}