#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // variables
    int wait = 0, line = 1, sum = 0, validRides = 0, minWait = 2147483647, maxWait = -2147483648;
    string filename = "", ride = "", headers = "", rideMin = "", rideMax = "";
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
        // summing for average
        validRides++;
        sum += wait;
        // min
        if (wait < minWait)
        {
            minWait = wait;
            rideMin = ride;
        }
        // max
        if (wait > maxWait)
        {
            maxWait = wait;
            rideMax = ride;
        }
    }
    // done reading so close
    iFile.close();

    // average/min/max
    cout << "Average wait: " << sum / validRides << endl
         << "Minimum wait: " << rideMin << " wait: " << minWait << endl
         << "Maximum wait: " << rideMax << " wait: " << maxWait << endl;

    return 0;
}
