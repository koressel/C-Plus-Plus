#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int floorNum;
    int currentRoomTotal;
    int currentOccupied;
    bool isValidFloorNum = false;
    int hotelRooms[100][100];
    bool isValidRoomTotal = false;
    bool isValidOccupied = false;

    float totalRooms = 0;
    float totalOccupied;
    float totalUnoccupied;
    float percentageOccupied;

    while (!isValidFloorNum) {
        cout << "\nHow many floors does the hotel have? ";
        cin >> floorNum;

        if (floorNum >= 1) {
            isValidFloorNum = true;
        }
        else {
            cout << "Error: The number of floors entered must be greater than 0.\nPlease try again.\n\n";
        }
    }

    for (int floor = 0; floor < floorNum; floor++) {
        // "Skip" 13th floor
        if (floor == (13-1)) {
            continue;
        }
        else {
            isValidRoomTotal = false;
            isValidOccupied = false;
            while (!isValidRoomTotal) {
                cout << "How many rooms are on floor " << floor+1 << ": ";
                cin >> currentRoomTotal;

                if (currentRoomTotal >= 10) {
                    totalRooms += currentRoomTotal;
                    isValidRoomTotal = true;
                }
                else {
                    cout << "Error: The number of rooms per floor must be at least 10. Please try again.\n\n";
                }
            }
            while (!isValidOccupied) {
                cout << "How many rooms are occupied on floor " << floor+1 << ": ";
                cin >> currentOccupied;

                if (currentOccupied <= currentRoomTotal) {
                    totalOccupied += currentOccupied;
                    isValidOccupied = true;
                }
                else {
                    cout << "Error: The number of occupied rooms must be less than the total number of rooms per floor. Please try again.\n\n";
                }
            }
        }      
    }

    totalUnoccupied = (totalRooms - totalOccupied);
    percentageOccupied = (totalOccupied / totalRooms) * 100;

    cout << "\nTotal rooms: " << totalRooms << "\n";
    cout << "Occupied: " << totalOccupied << "\n";
    cout << "Unoccupied: " << totalUnoccupied << "\n";
    cout << "Percantage Occupied: %" << percentageOccupied << "\n";

    return 0;
}