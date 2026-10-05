#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ifstream iFile;
    string filename = "", headers = "", rideName = "";

   do {
    cout << "Filename: ";
    cin >> filename;

    iFile.open(filename);
    if (!iFile.is_open()) {
        cout << "Unable to open file." << endl;
    }
    } while (!iFile.is_open());

    getline(iFile, headers);
    int wait = 0;
    if (iFile.fail() || wait <= 0 || rideName.empty()) {
        cout << "Error reading ride information." << endl;
        return 1;
    }
    iFile >> rideName >> wait;

    cout << rideName << " " << wait << endl;

    iFile.close(); //closes file

    return 0;
}

