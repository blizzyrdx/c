
#include <fstream>
#include <iostream>

using namespace std;

int main() {

    // Open the CSV file for reading
    ifstream iFile("trees.csv");

    const int row = 10;
    const int column = 15;

    // Initialize a 2D array with all zeros
    int matrix[row][column] = {};

    int x = 0, y = 0;
    char comma;

    // Check if the file opened successfully
    if (!iFile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Skip the first line containing the CSV headers
    iFile.ignore(1000, '\n');

    // Read coordinate pairs from the CSV file
    while (iFile >> x >> comma >> y) {

        // Check if the coordinates are valid
        if (x >= 0 && x < row &&
            y >= 0 && y < column &&
            comma == ',') {

            // Place a tree at the given coordinates
            matrix[x][y] = 1;
        }
    }

    // Close the CSV file
    iFile.close();

    // Display the tree matrix
    cout << "Tree Matrix:\n";

    for (int count = 0; count < row; count++) {
        for (int count2 = 0; count2 < column; count2++) {

            // Check whether a tree exists
            if (matrix[count][count2] == 1) {
                cout << "t ";
            }
            else {
                cout << "_ ";
            }
        }

        cout << endl;
    }

    return 0;
}
