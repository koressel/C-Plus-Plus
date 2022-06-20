// 7. Name Search

// This exercise will use the following files available in Canvas:

// GirlNames.txt—This file contains a list of the 200 most popular names given to girls born in the United States from 2000 to 2009.

// BoyNames.txt—This file contains a list of the 200 most popular names given to boys born in the United States from 2000 to 2009.

// Write a program that reads the contents of the two files into two separate arrays or vectors. The user should be able to enter a boy’s name, a girl’s name, or both, and the application should display messages indicating whether the names were among the most popular.


#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string boyNames[200], girlNames[200];
    ifstream boyNameFile, girlNameFile;
    string currentBoyName, currentGirlName;
    string boyNameInput, girlNameInput;
    bool isBoyNameOnList, isGirlNameOnList = false;
    bool isAppRunning = true;
    string repeatInput;

    boyNameFile.open("C:/Users/Owner/School/C++/ex7/BoyNames.txt");
    girlNameFile.open("C:/Users/Owner/School/C++/ex7/GirlNames.txt");

    // Populate name arrays
    for (int i = 0; i < 200; i++) {
        boyNameFile >> currentBoyName;
        boyNames[i] = currentBoyName;
    }

    for (int i = 0; i < 200; i++) {
        girlNameFile >> currentGirlName;
        girlNames[i] = currentGirlName;
    }

    // Get user input
    while (isAppRunning) {
        system("cls");
        cout << "\nEnter the name of a boy, girl, or both and hit enter to see if they are on among the 200 most popular names given to boys born in the United States from 2000 to 2009." << endl;
        cout << "\nA boy's name: ";
        cin >> boyNameInput;
        cout << "A girl's name: ";
        cin >> girlNameInput;

        for (int k = 0; k < 200; k++) {
            if (boyNameInput == boyNames[k]) {
                isBoyNameOnList = true;
            }
            if (girlNameInput == girlNames[k]) {
                isGirlNameOnList = true;
            }
        }

         cout << "\nResults" << "\n-------------------\n";
        if (isBoyNameOnList) {
            cout << boyNameInput << " is on the list!" << endl;
        }
        else {
            cout << boyNameInput << " is not on the list!" << endl;
        }

        if (isGirlNameOnList) {
            cout << girlNameInput << " is on the list!" << endl;
        }
        else {
            cout << girlNameInput << " is not on the list!" << endl;
        }

        cout << "\nTry again? (type y for yes or n for no) ";
        cin >> repeatInput;

        if (repeatInput == "n" || repeatInput == "N") {
            isAppRunning = false;
        }
    }

    boyNameFile.close();
    girlNameFile.close();
    return 0;
}