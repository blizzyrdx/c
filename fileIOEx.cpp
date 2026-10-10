#include <fstream>
#include <iostream>

using namespace std;

int main() {
	// Variables
	ifstream iFile; // input file
	ofstream oFile; // output file

	// Open input file
	iFile.open("error.txt");
	if (!iFile.is_open()) {
		cout << "Error opening input file!\n";
		return 0;
	}
	// Open output file
	oFile.open("out.txt");
	if (!oFile.is_open()) {
		cout << "Error opening output file!\n";
		return 0;
	}

	// Read from input file
	int i_fromFile = 0;
	while (iFile >> i_fromFile) {
		// Multiply data by 2 and output to file
		oFile << i_fromFile * 2 << endl;
	}

	// Close input and output files
	iFile.close();
	oFile.close();

	return 0;
}