#include <iostream>
using namespace std;

bool isWinnerLinear(int lNums[10], int wNums) {
    for (int i = 0; i < 10; i ++) {
        if (lNums[i] == wNums) {
            return true;
        }
    }
    return false;
}

bool isWinnerBinary(int lNums[10], int size, int wNums) {
    int first = 0;
    int last = size - 1;
    int middle, position = -1;
    bool found = false;

    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (lNums[middle] == wNums) { // if value is found at mid
            found = true;
            position = middle;
        }
        else if (lNums[middle] > wNums) {
            last = middle - 1; // if value is in lower half
        }
        else {
            first = middle + 1; // if value is in upper half
        }
    }

    return found;
}

int main()
{
    int luckyNums[10] = {
        {13579},
        {26791},
        {26792},
        {33445},
        {55555},
        {62483},
        {77777},
        {79422},
        {85647},
        {93121}
    };
    int thisWeeksWinningNums;
    int SIZE = 10;

    cout << "\nEnter this weeks winning 5-digit number then hit enter to see if you won: ";
    cin >> thisWeeksWinningNums;

    // Linear search
    if (isWinnerLinear(luckyNums, thisWeeksWinningNums)) {
        cout << "\nYou won! \nCongratulations!" << endl;
    }
    else {
        cout << "\nYou lost! \nSorry!" << endl;
    }

    // Binary search
    if (isWinnerBinary(luckyNums, SIZE, thisWeeksWinningNums)) {
        cout << "\nYou won even faster! \nCongratulations!" << endl;
    }
    else {
       cout << "\nYou lost even faster! \nSorry!" << endl; 
    }

    return 0;
}