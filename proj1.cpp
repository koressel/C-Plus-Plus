// COP 2224 Section 1877 Project 1 - Appointment Calendar
// ================================

// See due date in Canvas

// You are going to create a simple appointment calendar program using the skills that you have picked up in class so far. You are not to use any libraries that import calendar information -- please use only those elements that are found in Chapters 1-7 of your textbook. 

// _Functionality__

// 1. When the program starts, the user should be asked to enter a four-digit year from 2000 to 2100. If the user inputs an invalid year, then the program should tell them that and allow them to choose another. Once a year is chosen, they do not ever have to chose another for this run of the program.

// 2. After the user has successfully entered a year, they should be shown a menu whose choices include (1) Picking a month (this can be by number or by name -- programmer choice). (2) Printing out all appointments to screen (see below) (3) Writing appointments to file (see below) or (4) Quitting the program.  Invalid input should again prompt the user to re-enter a value.

// 3. Upon choosing a month, the program should print to the screen a simple and ACCURATE text calendar similar to those found at  https://beautifuldingbats.com/calendar-generator/ (a sample is below) showing month, year, days of the week, and a grid with all of the days of that particular month. It must be correct for leap years (remember the rules -- 2000 is different from 2100). Your program should generate the month dynamically based upon knowing how many days there are in each month and what day a given month starts (functions will help to determine starting day, and the modulus operator will help in printing the grid).

// ┌────────────────────┐
// │ February ▒▒▒▒ 2020 │
// ├──┬──┬──┬──┬──┬──┬──┤
// │Su│Mo│Tu│We│Th│Fr│Sa│
// ├──┼──┼──┼──┼──┼──┼──┤
// │▒▒│▒▒│▒▒│▒▒│▒▒│▒▒│01│
// ├──┼──┼──┼──┼──┼──┼──┤
// │02│03│04│05│06│07│08│
// ├──┼──┼──┼──┼──┼──┼──┤
// │09│10│11│12│13│14│15│
// ├──╔══╗──┼──┼──┼──┼──┤
// │16║17║18│19│20│21│22│
// ├──╚══╝──┼──┼──┼──┼──┤
// │23│24│25│26│27│28│29│
// └──┴──┴──┴──┴──┴──┴──┘

// 4. After the visual calendar, the user should be presented with a menu showing three choices: (1) To go back to the previous menu that will allow them to pick a month (2) To create an appointment for a given day of the current month. (3) To quit the program. 

// 5. If they choose to create an appointment, they should be able to pick a day to set the appointment. Once they pick a day, they should be able to type some short text for the appointment. It is *not* necessary to choose a time. If they have already written some text into an appointment for that day, they should be able to see the previous entry and add to it but not delete or edit it. When they finish writing their appointment note, they should be taken back to that month's menu and the text calendar should now indicate that the chosen day has an appointment. A given month should be able to have an appointment for any given day. Once a month has any appointments, the menu should add an option to print them to screen.

// 6. The menu in #2 above should have an option to print all appointments for a given year to screen at once. This could simply be the same call as for a single month in #5 but called twelve times (once for each month).

// 7. The menu in #2 above should also have an option to write all the appointments to files --one for each month. The file names should reflect month and year.


// _Grading_

// This assignment is worth 100 points and will be graded based upon how well it implements the features listed above. A program that implements all of them will get 100 points, and the instructor reserves the right to compensate for points marked off with additional points if other features are implemented beyond the bar minimum listed. 

// You should turn in a single .cpp file that I can compile and run. The filename should include your name and that it belongs to project 1. The same information should be in comments at the top of the code. 

// _Helpful Hints_

// We strongly suggest sitting down and designing this program on paper before writing the code. Everything you need is in the book. Menus are probably best accomplished with switch statements. Holding year, month, and appointment data probably involved multiple arrays (even nested or "three dimensional" arrays). The input, output, and file options can all be accomplished using the basic methods you have already encountered. Breaking down the different tasks into functions is highly advised as there are many parts of this program that should be reused. Do not use global variables, but keep as many arrays in your "main" function as you need to have appointment data always available. Above all, do not overthink this program -- the functionality we are asking for is quite simple and can be built piece-by-piece. 

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include<vector>
#include <algorithm>
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

int printCalendarMonth(int year, int month, long century[100][12][42], string appointments[100][12][42]) {
    
    int y = year;
    int m = month;
    string modifier = "*";
    int target;
    int offset = 0;
    
    string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string weekdayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    std::system("clear");
    cout << "\n" << monthNames[month] << " " << year << "\n";
    cout << "----------------------------\n";
    
    for (int weekday = 0; weekday < 7; weekday++) {
        cout << setw(6) << weekdayNames[weekday];
    }
    
    cout << "\n";
    
    for (int day = 0; day < 42; day++) {
        if (century[year-2000][month -1][day] == 0) {
            offset++;
            cout << setw(5) << century[year-2000][month-1][day] << " ";
        }
        else {
            if (!appointments[year-2000][month][day-offset].empty()) {
                cout << setw(5) << century[year-2000][month-1][day] << "*";
            }
            else {
                cout << setw(5) << century[year-2000][month-1][day] << " ";
            }
        }
        
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
    
    // Populate the calendar array
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
            
            // this gets the number of days from the previous month 
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
                    printCalendarMonth(yearInput, monthSelectMenuChoice-1, calendar, appointments);
            
                    printMonthMenu();
                    cin >> monthMenuChoice;
                    
                    if (monthMenuChoice == 1) {
                        // Print month calendar
                        
                        printCalendarMonth(yearInput, monthSelectMenuChoice-1, calendar, appointments);
                        
                        cout << "\n\nType a date to add an appointment: ";
                        cin >> apptDayInput;
                        
                        if (!appointments[yearInput-2000][monthSelectMenuChoice-1][apptDayInput-1].empty()) {
                            cout << "\nAppointment Notes " << "\n---------------------\n";
                            cout << appointments[yearInput-2000][monthSelectMenuChoice-1][apptDayInput-1] << endl;
                        }
                        
                        cout << "\nType any appointment information below then hit enter.\n";
                        cin.ignore();
                        getline (cin, apptInfo);
                        
                        // save appt info to appointment array
                        int y = (yearInput - 2000);
                        int m = (monthSelectMenuChoice - 1);
                        int d = apptDayInput - 1;
                        appointments[y][m][d] = appointments[y][m][d] + "\n" + apptInfo;
                        
                        // printCalendarMonth(yearInput, m, calendar, appointments);
                        
                        isInMonthMenu = true;
                        
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