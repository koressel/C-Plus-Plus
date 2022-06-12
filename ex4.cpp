#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float pennyVal = .01;
    float nickelVal = .05;
    float dimeVal = .10;
    float quarterVal = .25;
    float pennyInput, nickelInput, dimeInput, quarterInput;
    float inputTotal = 0;

    cout << "\n--------------\n| HOW TO WIN |\n--------------\nThe amount of coins the player enters are added together. The objective is to get as close as possible to $1.\n$1 = WIN, Over or under $1 = LOSE\n\n";
    cout << "How many pennies? ";
    cin >> pennyInput;
    cout << "How many nickels? ";
    cin >> nickelInput;
    cout << "How many dimes? ";
    cin >> dimeInput;
    cout << "How many quarters? ";
    cin >> quarterInput;
    
    inputTotal = (pennyInput * .01) + (nickelInput * .05) + (dimeInput * .10) + (quarterInput * .25);
    
    if (inputTotal == 1) {
        cout << "\nTotal: $" << inputTotal  << "\nYOU WIN!!!\n";
    }
    else if (inputTotal > 1 || inputTotal < 1) {
        cout << ((inputTotal > 1) ? "\nOver $1 you lose!" : "\nUnder $1 you lose!") << "\nTotal: $" << setprecision (2) << fixed << inputTotal << "\n";
    }
    
    return 0;
}