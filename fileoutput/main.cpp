#include <iostream> //for cin/cout operations
#include <fstream> //new preprocessory directive for file input/output operations

//namespace
using namespace std;

//main function
int main () {

    // define variables
    ifstream iFile; //input file stream object for reading from files
    ofstream oFile("howLongTilCharacter.txt"); //open the output file for writing
    string filename = ""; //variable to store the name of the file to be opened
    string headers = ""; //variable to store the headers of the file
    string character = ""; //variable to store each character read from the file
    int breaktime = 0; //variable to store the break time, initialized to 0
    int downtime = 0; //variable to store the downtime, initialized to 0
    int delaytime = 0; //variable to store the delay time, initialized to 0
    int line = 1; // line 

   do { // repeats until a valid file is opened
    cout << "Character Break File: "; // initial cout
    cin >> filename; //input filename

    // open the input file for reading
    iFile.open(filename); //opens file
    
    // check if the file was successfully opened
    if (!iFile.is_open()) { //checks if file is open successfully
        cout << "Error: Invalid filename" << endl; //if not output
   } //end if
       } while (!iFile.is_open()); //repeat until a valid file is opened

        getline(iFile, headers); //read the headers from the file

            //do loop
    while (iFile >> character) {
    //loop until the end of the file is reached
        line++; //increment the line counter for each line read from the file
        iFile >> breaktime; //read the break time from the file
        iFile >> downtime; //read the downtime from the file
        iFile >> delaytime; //read the delay time from the file


        // validate the input numbers
        if (iFile.fail() || breaktime <= -1 || downtime <= -1 || delaytime <= -1) { //make sure its -1
            // if its zero then it wont work
            // negative numbers are not allowed
            cout << "Error: Invalid number detected on line " << line << endl;
            iFile.clear(); //clear the error flag
            iFile.ignore(256, '\n'); //ignore the rest of the line
            continue; //skip to the next iteration of the loop
        }
        
        //equation
        int Backin = (breaktime - downtime) + delaytime;
    
            //output the result to the file
        oFile << character << " will be back in " << Backin << " minutes" << endl;
    } //repeat until the end of the file is reached
    //while

    // closes the files
        iFile.close(); //close the file after reading from it
        oFile.close(); //close the output file after writing to it

        //return
    return 0;
} // iFile.is_open() used to check if the file was successfully opened before reading from it.