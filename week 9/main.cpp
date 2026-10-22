#include <fstream>
#include <iostream>

using namespace std;

int main() {

    // Open the CSV file for reading
    ifstream iFile("trees.csv");

    const int row = 10; 
    const int column = 15;

    // Create a 2D character array initialized to null
    char matrix[row][column] = {};

    // Variables for CSV coordinates
    int x = 0, y = 0;
    char comma;

    // Variables to store the player's position
    int playerRow = 9;
    int playerCol = 0;

    // Variables for user input
    int moveRow = 0;
    int moveCol = 0;
    char option = ' ';

    // Check if CSV file was opened successfully
    if (!iFile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Skip the CSV header
    iFile.ignore(1000, '\n');

    // Read coordinates from the CSV file
    while (iFile >> x >> comma >> y) {

        // Validate coordinates and comma
        if (comma == ',' &&
            x >= 0 && x < column &&
            y >= 0 && y < row) {

            // x represents column and y represents row
            matrix[y][x] = 't';
        }
    }

    // Close the CSV file
    iFile.close();

    // Place player at row 9, column 0
    matrix[playerRow][playerCol] = 'p';

    // Continue running until user quits
    while (true) {

        // Display the map
        for (int count = 0; count < row; count++) {
            for (int count2 = 0; count2 < column; count2++) {

                // Print underscore if position is empty
                if (matrix[count][count2] == '\0') {
                    cout << "_ ";
                }
                else {
                    // Print tree or player
                    cout << matrix[count][count2] << " ";
                }
            }

            cout << endl;
        }

        // Prompt user to move or quit
        cout << "(m)ove -or- (q)uit? ";
        if (!(cin >> option)) {
            break;
        }

        // Validate option
        while (option != 'm' && option != 'q') {
            cout << "Error: Invalid option\n";

            cout << "(m)ove -or- (q)uit? ";
            if (!(cin >> option)) {
                return 0;
            }
        }

        // Quit the program
        if (option == 'q') {
            cout << "\nQuitting...\n";
            break;
        }

        // Prompt user for row
        cout << "\nMove Row: ";
        cin >> moveRow;

        // Validate row input
        if (cin.fail() || moveRow < 0 || moveRow >= row) {
            cout << "\nError: Move must be between 0 and 9\n\n";

            // Clear input errors
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Prompt user for column
        cout << "Move Column: ";
        cin >> moveCol;

        // Validate column input
        if (cin.fail() || moveCol < 0 || moveCol >= column) {
            cout << "\nError: Move must be between 0 and 14\n\n";

            // Clear input errors
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Check if tree is blocking the location
        if (matrix[moveRow][moveCol] == 't') {
            cout << "\nThere's a tree in your way\n\n";
            continue;
        }

        // Remove player from the old position
        matrix[playerRow][playerCol] = '\0';

        // Update player's position
        playerRow = moveRow;
        playerCol = moveCol;

        // Place player in the new position
        matrix[playerRow][playerCol] = 'p';

        // Display movement confirmation
        cout << "\n\nMoved to row "
             << playerRow << " column "
             << playerCol << "\n\n";
    }

    // End program
    return 0;
}