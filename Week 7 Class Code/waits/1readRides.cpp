#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // variables
    int wait = 0;
    string filename = "", ride = "", headers = "";
    ifstream iFile;

    // get the file name from the user
    while (!iFile.is_open())
    {
        // get file name
        cout << "Ride file name: ";
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
        // validate input
        if (iFile.fail())
        {
            // only an error if not at blank newline at end of file
            if (!iFile.eof())
            {
                cout << "error in file" << endl;
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
