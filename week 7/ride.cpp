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
    getline(iFile, rideName);
    cout << "Headers: " << headers << endl;
    cout << "Ride Name: " << rideName << endl;
    int wait = 0;
    iFile >> wait;
    iFile.close();
    if (wait <= 0) {
        cout << rideName << "" << wait << endl;
    }
    return 0;
}

