#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int printCalendar(long calendar[100][12][42]) {
    string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string weekdayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    for (int year = 2000; year < 2100; year++) {
        cout << year << "\n---------------------------------\n\n";
        for (int month = 0; month < 12; month++) {
            cout << monthNames[month] << "\n";
            for (int weekday = 0; weekday < 7; weekday++) {
                cout << setw(4) << weekdayNames[weekday];
            }
            cout << "\n";
            for (int day = 0; day < 42; day++) {
                cout << setw(3) << calendar[year-2000][month][day] << " ";
                if(day==6 || day==13 || day==20 || day==27 || day==34) {
                    cout << "\n";
                }
            }
            cout << "\n\n";
        }
    }
    
    
    return 0;
}

int getYearInput() {
    int year;
    cout << "\nEnter a 4 digit year between 2000 and 2100: ";
    cin >> year;
    return year;
}

int printMainMenu(int year) {
    // std::system("clear");
    cout << "\nMain Menu (Year " << year << ")\n";
    cout << "-------------------------\n";
    cout << "(1) Month View\n";
    cout << "(2) Print appointments\n";
    cout << "(3) Write appointments to a file\n";
    cout << "(4) Quit program\n\n";
    cout << "Type a number to select an option: ";
    return 0;
}


int printMonthSelectMenu(int year) {
    std::system("clear");
    cout << setw(15) << "\nMonth Select Menu (Year " << year << ")\n";
    cout << "-------------------------\n";
    cout << setw(5) << "(1) " << "January\n";
    cout << setw(5) << "(2) " << "February\n";
    cout << setw(5) << "(3) " << "March\n";
    cout << setw(5) << "(4) " << "April\n";
    cout << setw(5) << "(5) " << "May\n";
    cout << setw(5) << "(6) " << "June\n";
    cout << setw(5) << "(7) " << "July\n";
    cout << setw(5) << "(8) " << "August\n";
    cout << setw(5) << "(9) " << "September\n";
    cout << setw(5) << "(10) " << "October\n";
    cout << setw(5) << "(11) " << "November\n";
    cout << setw(5) << "(12) " << "December\n\n";
    cout << "Type a number to select a month: ";
    
    return 0;
}

int printCalendarMonth(int year, int month, long century[100][12][42], string appts[100][12][42]) {
    int y = year; int m = month;
    string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string weekdayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    string modifier = "";
    
    std::system("clear");
    cout << "\n" << monthNames[month-1] << " " << year << "\n";
    cout << "----------------------------\n";
    
    for (int weekday = 0; weekday < 7; weekday++) {
        cout << setw(4) << weekdayNames[weekday];
    }
    cout << "\n";
    
    for (int day = 0; day < 42; day++) {
        if (appts[year-2000][month-1][day] != "XX") {
            modifier = "*";
        }
        cout << setw(4) << century[year-2000][month-1][day] << modifier;
        if(day==6 || day==13 || day==20 || day==27 || day==34) {
            cout << "\n";
        }
    }
    
    return 0;
}

int printMonthMenu() {
    cout << "\n\nMenu\n";
    cout << "----------------------------\n";
    cout << "(1) Create a new appointment\n";
    cout << "(2) Back to main menu\n";
    cout << "(3) Quit program\n\n";
    cout << "Type a number to select an option: ";
    return 0;
}

// int printApptInfoForDay(int year, int month, int day, long calendar[100][12][42], string appts[100][12][42]) {
//     // Todo: break monthNames out into a function
//     string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//     printCalendarMonth(year, (month+1), calendar);
//     cout << "\n\nAppointment notes for " << monthNames[month] << " " << day << ", " << year << "\n------------------------------\n";
//     cout << appts[year-2000][month][day];
//     return 0;
// }

int main()
{
    bool runCalendarApp = true;
    long calendar[100][12][42] = {0};
    string appointments[100][12][42];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 12; j++) {
            for (int l = 0; l < 42; l++) {
                appointments[i][j][l] = "XX";
            }
        }
    }
    int startDay = 6; // Saturday 1/1/2000
    int lastDay = 33; // Friday 12/31/1999
    int numDaysInEachMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int numDaysInCurrentMonth, previousNumDaysInCurrentMonth;
    bool isLeapYear = false;
    int leapYearCounter = 3;
    int mainMenuChoice, monthSelectMenuChoice, monthMenuChoice;
    int apptDayInput;
    string apptInfo;
    bool isInMonthMenu = false;
    
    // Generate calendar array
    // Todo: break this out into a function that returns the array
     for (int year=2000; year < 2100; year++) {
        if (leapYearCounter == 3) {
            isLeapYear = true;
            leapYearCounter = 0;
        }
        else {
            isLeapYear = false;
            leapYearCounter++;
        }
        
        for(int month = 0; month < 12; month++) {
            if (isLeapYear && month == 1) {
                numDaysInCurrentMonth = numDaysInEachMonth[month] + 1;
            }
            else {
                numDaysInCurrentMonth = numDaysInEachMonth[month];
            }
            
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
                startDay = (lastDay - 7) + 1;
            }
            if(lastDay >= 14 && lastDay < 21) {
                startDay = (lastDay - 14) + 1;
            }
            if(lastDay >= 21 && lastDay < 27) {
                startDay = (lastDay - 21) + 1;
            }
            if(lastDay >= 27 && lastDay < 34) {
                startDay = (lastDay - 28) + 1;
            }
            if(lastDay >= 34) {
                startDay = (lastDay - 35) + 1;
            }
            
            lastDay = (startDay - 1) + numDaysInCurrentMonth;
           
            for(int day = 0; day < 42; day++) {
                if (day >= startDay && day <= (startDay + numDaysInCurrentMonth) - 1) {
                    calendar[year-2000][month][day] = (day - startDay) + 1;
                }
            }
        }
    }
    
    // Menu functionality 
    // int yearInput;
    // cout << "\nEnter a 4 digit year between 2000 and 2100: ";
    // cin >> yearInput;
    int yearInput = 2000;
    
    while (runCalendarApp) {
        printMainMenu(yearInput);
        cin >> mainMenuChoice;
        isInMonthMenu = true;
        
        switch(mainMenuChoice) {
            case 1: // Month view
                printMonthSelectMenu(yearInput);
                cin >> monthSelectMenuChoice;
                
                while (isInMonthMenu) {
                    printCalendarMonth(yearInput, monthSelectMenuChoice, calendar, appointments);
            
                    printMonthMenu();
                    cin >> monthMenuChoice;
                    
                    if (monthMenuChoice == 1) {
                        // Print month calendar
                        
                        printCalendarMonth(yearInput, monthSelectMenuChoice, calendar, appointments);
                        
                        cout << "\n\nType a date to add an appointment: ";
                        cin >> apptDayInput;
                        
                        cout << "Type any appointment information below then hit enter.\n";
                        cin.ignore();
                        getline (cin, apptInfo);
                        
                        appointments[yearInput-2000][monthSelectMenuChoice-1][apptDayInput] = apptInfo;
                        
                    }
                    if (monthMenuChoice == 2) {
                        isInMonthMenu = false;
                        continue;
                    }
                    if (monthMenuChoice == 3) {
                        cout << "Quitting the program...";
                        isInMonthMenu = false;
                        runCalendarApp = false;
                        continue;
                    }
                }
                break;
            case 2: // Print appointments
                break;
            case 3: // Write appointments to file
                break;
            case 4: // Quit calendar app
                runCalendarApp = false;
                break;
        }
    }
    return 0;
}