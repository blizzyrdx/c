
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    // Define input and output file stream objects
    ifstream iFile; // reads existing data from files
    ofstream oFile; // writes updated data to files

    // Initialize variables
    int fileName = 0; // selected K/D file number
    int count = 0; // number of stored records
    int i = 0; // loop counter

    // Set the maximum number of records
    const int SIZE = 10;

    // Create arrays for kills and deaths
    int array1[SIZE]; // stores kills
    int array2[SIZE]; // stores deaths

    // Variables for calculating averages
    int killSum = 0; // total kills
    int deathSum = 0; // total deaths
    int killAverage = 0; // average kills
    int deathAverage = 0; // average deaths

    // Variables for additional records
    int newKill = 0; // kills entered by user
    int newDeath = 0; // deaths entered by user
    char again = 'c'; // determines whether user continues

    // Ask user to select one of three K/D files
    do {
        cout << "K/D File 1/2/3? ";
        cin >> fileName;

        // Validate selection and detect input failures
        if (cin.fail() || fileName < 1 || fileName > 3) {
            cout << "Error: invalid selection\n";

            cin.clear(); // clear input error flags
            cin.ignore(1000, '\n'); // discard invalid input
            fileName = 0; // reset selection
        }

    } while (fileName == 0); // repeat until valid

    // Open the corresponding kills file
    if (fileName == 1) {
        iFile.open("kills1.txt");
    }
    else if (fileName == 2) {
        iFile.open("kills2.txt");
    }
    else {
        iFile.open("kills3.txt");
    }

    // Read kills from the file into array1
    // Stop once the array is full or the file ends
    while (count < SIZE && iFile >> array1[count]) {
        count++; // increment number of records
    }

    iFile.close(); // close kills file

    // Open the corresponding deaths file
    if (fileName == 1) {
        iFile.open("deaths1.txt");
    }
    else if (fileName == 2) {
        iFile.open("deaths2.txt");
    }
    else {
        iFile.open("deaths3.txt");
    }

    // Read deaths from the file into array2
    // Use count to match the number of kills
    for (i = 0; i < count; i++) {
        iFile >> array2[i];
    }

    iFile.close(); // close deaths file

    // Check whether the arrays reached maximum size
    if (count == SIZE) {
        cout << "\nArray full\n";
    }

    // Calculate total kills and deaths
    for (i = 0; i < count; i++) {
        killSum += array1[i]; // add kills
        deathSum += array2[i]; // add deaths
    }

    // Avoid division by zero if no records exist
    if (count > 0) {
        killAverage = killSum / count;
        deathAverage = deathSum / count;
    }

    // Display initial averages from selected files
    cout << "\nFile Average k/d: "
         << killAverage << " : "
         << deathAverage << "\n";

    // Continue adding records while space remains
    while (count < SIZE) {

        // Prompt user for new kill count
        cout << "\nNew kill: ";
        cin >> newKill;

        // Prompt user for new death count
        cout << "New death: ";
        cin >> newDeath;

        // Store new values at next available index
        array1[count] = newKill;
        array2[count] = newDeath;

        count++; // increase stored record count

        // Update totals using newly entered values
        killSum += newKill;
        deathSum += newDeath;

        // Recalculate averages after adding record
        killAverage = killSum / count;
        deathAverage = deathSum / count;

        // Display updated averages
        cout << "\nAverage k/d: "
             << killAverage << " : "
             << deathAverage << "\n";

        // Stop if maximum array capacity is reached
        if (count == SIZE) {
            cout << "\nArray Full\n";
            break;
        }

        // Ask whether another record should be added
        cout << "\n(c)ontinue (any other key to quit)? ";
        cin >> again;

        // Exit loop if user chooses not to continue
        if (again != 'c') {
            break;
        }
    }

    // Open selected kills file for writing
    // Existing contents will be replaced
    if (fileName == 1) {
        oFile.open("kills1.txt");
    }
    else if (fileName == 2) {
        oFile.open("kills2.txt");
    }
    else {
        oFile.open("kills3.txt");
    }

    // Save all kills from array1 to selected file
    for (i = 0; i < count; i++) {
        oFile << array1[i] << endl;
    }

    oFile.close(); // close output kills file

    // Open selected deaths file for writing
    // Existing contents will be replaced
    if (fileName == 1) {
        oFile.open("deaths1.txt");
    }
    else if (fileName == 2) {
        oFile.open("deaths2.txt");
    }
    else {
        oFile.open("deaths3.txt");
    }

    // Save all deaths from array2 to selected file
    for (i = 0; i < count; i++) {
        oFile << array2[i] << endl;
    }

    oFile.close(); // close output deaths file

    return 0; // end program successfully
}
