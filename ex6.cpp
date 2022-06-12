#include <iostream>
using namespace std;

int main() {
    int rooms;
    float paintPricePerGallon;
    float totalSurfaceArea = 0;
    bool isValidRoomNum = false;
    bool isValidPrice = false;
    bool isValidSurfaceArea = false;
    int tmp = 0;

    float totalGallons;
    float totalLaborHours;
    float paintCost;
    float laborCharge;
    float totalJobEstimate;

    while (!isValidRoomNum) {
        cout << "\nHow many rooms do you want painted? ";
        cin >> rooms;

        if (rooms >= 1) {
           isValidRoomNum = true; 
        }
        else {
            cout << "Error: The number of rooms entered must be at least 1. Please try again.\n\n";
        }
    }

    while (!isValidPrice) {
        cout << "\nHow much does the paint cost per gallon? $";
        cin >> paintPricePerGallon;

        if (paintPricePerGallon >= 10) {
            isValidPrice = true;
        }
        else {
            cout << "Error: The minimum accepted price per gallon is $10. Please try again.\n\n";
        }
    }
    
    for (int room = 0; room < rooms; room++) {
        isValidSurfaceArea = false;
        while (!isValidSurfaceArea) {
            tmp = 0;
            cout << "\nWhat is the surface area of room #" << (room+1) << "? (sq. ft): ";
            cin >> tmp;

            if (tmp >= 0) {
                totalSurfaceArea += tmp; 
                isValidSurfaceArea = true;
            }
            else {
                cout << "Error: Surface area must be 0 or more. Please try again.\n\n";
            } 
        }
    }

    totalGallons = (totalSurfaceArea/110);
    totalLaborHours = (totalSurfaceArea/110) * 8;
    paintCost = totalGallons * paintPricePerGallon;
    laborCharge = totalLaborHours * 25;
    totalJobEstimate = paintCost + laborCharge;

    cout << "\nResults\n---------------------\n";
    cout << "Paint required (gal): " << totalGallons << "\n";
    cout << "Total labor hours: " << totalLaborHours << "\n";
    cout << "Total paint cost: $" << paintCost << "\n";
    cout << "Labor charge: $" << laborCharge << "\n";
    cout << "Total job estimate: $" << totalJobEstimate << "\n";

    return 0;
}