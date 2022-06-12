#include <iostream>
using namespace std;

int main() {
   float exemption = 5000;
    float taxablePercentage = .6; 
    float taxRate; // per each $100 of the taxable value
    float propertyValue, assessmentValue, taxableValue, taxOwed, quarterlyTaxOwed;

    cout << "\n---------------------------\n| Property Tax Calculator |\n---------------------------\n\n";
    cout << "Property value: $";
    cin >> propertyValue;
    cout << "Property tax rate (per $100 of the assessed value): $";
    cin >> taxRate;

    assessmentValue = propertyValue * taxablePercentage; 
    taxableValue = assessmentValue - exemption;
    taxOwed = (taxableValue / 100) * taxRate; 
    quarterlyTaxOwed = taxOwed / 4; 

    cout << "\nResults \n---------------------------";
    cout << "\nProperty value: $" << propertyValue;
    cout << "\nAssessment value: $" << assessmentValue;
    cout << "\nHomeowner exemption: -$" << exemption;
    cout << "\nTaxable value: $" << taxableValue;
    cout << "\nTax rate: $" << taxRate << " / $100";
    cout << "\nYearly property tax: $" << taxOwed;
    cout << "\nQuarterly property tax: $" << quarterlyTaxOwed << "\n";
    
    return 0;
}