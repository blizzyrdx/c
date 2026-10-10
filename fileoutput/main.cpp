#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ifstream iFile;
    string filename;

   do {
    cout << "Filename: ";
    cin >> filename;

    iFile.open(filename);
    
    if (!iFile.is_open()) {
        cout << "Unable to open file." << endl;
    }
    if (iFile.is_open()) {
        iFile.close();
    }
    } while (!iFile.is_open());

    return 0;
}

// iFile.is_open() used to check if the file was successfully opened before reading from it.