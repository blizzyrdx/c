#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // variables
    int wait = 0, line = 1;
    string filename = "", ride = "", headers = "";
    ifstream iFile;

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

    // skip headers
    getline(iFile, headers);

    while (!iFile.eof())
    {
        // get ride/wait
        iFile >> ride >> wait;
        line++;
        // validate input
        if (iFile.fail() || wait < 0)
        {
            // only an error if not at blank newline at end of file
            if (!iFile.eof())
            {
                cout << "error in file on line " << line << endl;
                iFile.clear();
                iFile.ignore(256, '\n');
            }
            // get next input
            continue;
        }
        // inputs are valid
        // output ride
        cout << ride << " has a wait of " << wait << " minutes\n";
    }
    // done reading so close
    iFile.close();

    return 0;
}
