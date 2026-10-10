#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int characterHealth = 0, monsterHealth = 0;
    string filename = "", firstHeader = "", secondHeader = "";
    ifstream iFile;
    ofstream oFile;

    // get the file name from the user
    while (!iFile.is_open())
    {
        // get file name
        cout << "Health file name: ";
        cin >> filename;
        // open the file
        iFile.open(filename);
        // verify the file opened
        if (!iFile.is_open())
        {
            cout << "error: invalid filename\n";
        }
    }

    // read from the health file
    iFile >> firstHeader >> secondHeader;
    iFile >> characterHealth >> monsterHealth;
    iFile.close();

    // if out order swap
    if (firstHeader == "monster")
    {
        // swap healths
        int savedHealth = characterHealth;
        characterHealth = monsterHealth;
        monsterHealth = savedHealth;
        // swap headers
        string savedHeader = firstHeader;
        firstHeader = secondHeader;
        secondHeader = savedHeader;
    }

    // damage the monster
    monsterHealth = monsterHealth - 3;

    // damage the player
    characterHealth = characterHealth - 1;

    // save the new healths
    oFile.open(filename);
    oFile << firstHeader << " " << secondHeader << endl
          << characterHealth << " " << monsterHealth << endl;
    oFile.close();

    return 0;
}
