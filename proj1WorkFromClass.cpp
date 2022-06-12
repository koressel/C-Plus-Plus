/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int year[12][42] = {0};
    int startDay = 6; // Saturday 1/1/2000
    int lastDay = 33; // Friday 12/31/1999
    int numDaysInEachMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int numDaysInCurrentMonth, previousNumDaysInCurrentMonth;
    
    for(int month = 0; month < 12; month++) {
        numDaysInCurrentMonth = numDaysInEachMonth[month];
        
        // get the number of days that the previous month contained 
        if (month == 0) {
            previousNumDaysInCurrentMonth = numDaysInEachMonth[11];
        }
        else {
            previousNumDaysInCurrentMonth = numDaysInEachMonth[(month - 1)];
        }
        
        if(lastDay < 7) {
            startDay = lastDay + 1;
        }
        if(lastDay >= 7 && lastDay < 14) {
            startDay = lastDay - 6;
        }
        if(lastDay >= 14 && lastDay < 21) {
            startDay = lastDay - 12;
        }
        if(lastDay >= 21 && lastDay < 27) {
            startDay = lastDay - 18;
        }
        if(lastDay >= 27 && lastDay < 34) {
            startDay = lastDay - 24;
        }
        if(lastDay >= 34) {
            startDay = lastDay - 30;
        }
        
        lastDay = startDay + numDaysInCurrentMonth;
       
        for(int day = 0; day < 42; day++) {
            if (day >= startDay && day <= (startDay + numDaysInCurrentMonth)) {
                year[month][day] = (day - startDay);
            }
        }
    }
    
    for (int i = 0; i < 12; i++) {
        for (int y = 0; y < 42; y++) {
            cout << year[i][y] << " ";
            if(y==6 || y==13 || y==20 || y==27 || y==34) {
                cout << "\n";
            }
        }
        cout << "\n\n";
    }

    return 0;
}
