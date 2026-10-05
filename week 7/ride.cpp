#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ifstream iFile;
    string filename = "", headers = "", rideName = "";
    int wait = 0; //initialize wait time to 0


   do {
    cout << "Filename: ";
    cin >> filename;

    iFile.open(filename);
    if (!iFile.is_open()) {
        cout << "Unable to open file." << endl;
    }
    } while (!iFile.is_open());

    getline(iFile, headers);
    
    while (!iFile.eof()) { //new syntax for reading until end of file
        
        if (iFile.fail() || wait <= 0 || rideName.empty()) {
            cout << "Error reading ride information." << endl;
            break;
        }
        iFile >> rideName >> wait;
        cout << rideName << " " << wait << endl;
    }
    iFile.close(); //closes file

    return 0;
}

// iFile.eof() new syntax
// you can use cd .. to get to cs135 main file
