#include <fstream>

using namespace std;

int main()
{
    ifstream iFile;
    ofstream oFile;
    double i = 0.0, j = 0.0;

    iFile.open("firstData.txt");
    oFile.open("main2.cpp");

    iFile >> i;
    iFile >> j;

    oFile << i << " - " << j << " = " << i - j << endl;

    iFile.close();
    oFile.close();

    return 0;
}
