#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inputFile;
    float number;
    float total = 0;
    float sum = 0;
    float average;

    cout << "Reading values from file...\n";
    inputFile.open("C:/Users/Owner/School/C++/ex5-2/Random.txt");

    while (inputFile >> number) {
        total++;
        sum += number;
    }
    average = (sum / total);

    cout << "\nResults" << "\n-------------------\n";
    cout << "Total numbers: " << total << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << fixed << setprecision(2) << average << endl;
    
    inputFile.close();
    return 0;
}