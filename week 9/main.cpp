#include <fstream>
#include <iostream>

using namespace std;

int main () {
    // Open the CSV file for reading
    ifstream iFile("trees.csv");
    iFile.open("trees.csv");
    const int row = 10;
    const int column = 15;
    int matrix[row][column] = {}; // Initialize a 2D array to store the data from the CSV file

    string headers = "x,y"; // Read the headers from the CSV file
    int x = 0, y = 0; // Initialize variables to store the x and y values
    iFile >> headers;

    // Read the data from the CSV file into the matrix
    for (int count = 0; count < row; count++) {
        for (int count2 = 0; count2 < column; count2++) {
            char comma; // Variable to store the comma separator
            iFile >> x >> comma >> y; // Read the x and y values from the CSV file
        }
    }
    // Close the CSV file
    iFile.close();
    
    // Print the values of trees in the matrix as t and the none values as underscores
    cout << "Tree Matrix:\n";
    for (int count = 0; count < row; count++) {
        for (int count2 = 0; count2 < column; count2++) {
            if (matrix[count][count2] == 1) { // Check if the value in the matrix is 1
                cout << "t "; // Print t to indicate a tree is present
            } else {
                cout << "_ "; // Print _ to indicate no tree is present
            }
        }
        cout << endl; // Print a new line after each row
    }
   
    
    // this is the trees

    // Print the underscores
    
    // Prompt user

    // Read in from user column and row input

    // Validate if its okay and if good loop  

    // end program
    return 0;
}

// do bubble sort and other sorting algorithms 