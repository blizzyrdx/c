// Lab 5 Solution
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // variables
  string filename = "", headers = "";
  int characterHealth = 0, monsterHealth = 0;
  ifstream input;
  ofstream output;

  // open valid file
  input.open("fistInputs/health1.txt");

  // work through all characters
  getline(input, headers);
  input >> characterHealth >> monsterHealth;

  // done inputting so close
  input.close();

  // character attacks monster with sword
  monsterHealth -= 3;

  // monster attacks character with fireball
  characterHealth -= 1;

  // open the file that was an input file as an output file
  output.open(filename);

  // output (save) the new health to the file
  output << headers << endl
         << characterHealth << " " << monsterHealth << endl;

  // close the file now that the healths are updated
  output.close();

  return 0;
}