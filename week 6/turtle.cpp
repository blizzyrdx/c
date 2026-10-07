#include <iostream>

using namespace std;

int main() {

    //loop!

    // remember to initialize variable
    // attack variable
    int attack = 0;

    // define variables
    // initialize
    int monster_health = 10;
    int player_health = 10;

    //initialize i
    int i = 1;

    // Output the monster and player's health
    // loop

    do {
    cout << "Player Health: " << player_health << endl;
    cout << "Monster Health: " << monster_health << endl;
    cout << endl;

    // Inner loop for input validation
    do {
        cout << "1-Stab -or- 2-Slash: ";
        cin >> attack;

        if (cin.fail() || attack < 1 || attack > 2) {
            cout << "Error: Invalid selection" << endl;

            cin.clear();
            cin.ignore(1000, '\n');

            continue;
        }

        break;

    } while (true);

    cout << endl;

    if (i % 2 != 0) {
    cout << "The monster blocks your attack" << endl;
    cout << endl;
    }
    else if (attack == 1) {
        cout << "You stab the monster causing 2 damage" << endl;
        cout << "The monster shoots a fire ball at you causing 2 damage" << endl;
        cout << endl;
        monster_health--; // subtract twice!
        monster_health--; //must subtract monster health
        player_health--;
        player_health--; // health
    }

    else if (attack == 2) {
        cout << "You slash the monster causing 3 damage" << endl;
        cout << "The monster shoots a fire ball at you causing 2 damage" << endl;
        cout << endl;
        monster_health--;
        monster_health--; // three times now
        monster_health--;
        player_health--; //repeat
        player_health--;
    }
    i++;
} while (player_health > 0 && monster_health > 0); //while statmeent
 
if (player_health <= 0 && monster_health > 0) { //if player dies
    cout << "The monster killed you";
}

if (monster_health <= 0 && player_health > 0) { //if monster dies
     cout << "You killed the monster";
}

if (monster_health <= 0 && player_health <= 0) { // if both die
    cout << "The player and monster killed eachother";
}

    return 0;
}