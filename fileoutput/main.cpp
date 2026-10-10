#include <iostream> //for cin/cout operations
#include <fstream> //new preprocessory directive for file input/output operations

using namespace std;

int main () {

    // define variables
    ifstream iFile; //input file stream object for reading from files
    string filename; //variable to store the name of the file to be opened
    string headers = ""; //variable to store the headers of the file
    string character = ""; //variable to store each character read from the file
    int breaktime = 0; //variable to store the break time, initialized to 0
    int downtime = 0; //variable to store the downtime, initialized to 0
    int delaytime = 0; //variable to store the delay time, initialized to 0

   do {
    cout << "Character Break File:";
    cin >> filename;

    iFile.open(filename);
    
    if (!iFile.is_open()) { //checks if file is open successfully
        cout << "Error: Invalid filename " << endl; //if not output
    }
    if (iFile.is_open()) { //if open successfully
          getline(iFile, headers); //read the headers from the file

        iFile >> character; //read each character from the file
        iFile >> breaktime; //read the break time from the file
        iFile >> downtime; //read the downtime from the file
        iFile >> delaytime; //read the delay time from the file

        cout << "Character: " << character << ", Break Time: " << breaktime << ", Downtime: " << downtime << ", Delay Time: " << delaytime << endl;

        iFile.close(); //close the file after reading from it
    }
    } while (!iFile.is_open());

    return 0;
}

// iFile.is_open() used to check if the file was successfully opened before reading from it.