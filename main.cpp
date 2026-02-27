#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// File names
const string APPLIANCE_FILE = "appliances.txt";
const string BILLING_FILE   = "billing_summary.txt";

// Structure
struct Appliance {
    string name;
    float power;
    float hours;
};

// Global list
vector<Appliance> appliances;


// Load appliances from file
// ---------------------------
void loadAppliances() {

    ifstream file(APPLIANCE_FILE);

    string name;
    float power, hours;

    while (file >> name >> power >> hours) {
        Appliance a;
        a.name = name;
        a.power = power;
        a.hours = hours;
        appliances.push_back(a);
    }

    file.close();
}


// ---------------------------
// Save appliances to file
// ---------------------------
void saveAppliances() {

    ofstream file(APPLIANCE_FILE);

    for (int i = 0; i < appliances.size(); i++) {
        file << appliances[i].name << " "
             << appliances[i].power << " "
             << appliances[i].hours << endl;
    }

    file.close();
}


// ---------------------------
// Register appliance
// ---------------------------
void registerAppliance() {

    Appliance a;

    cout << "Enter appliance name: ";
    cin >> a.name;

    cout << "Enter power rating (W): ";
    cin >> a.power;

    cout << "Enter usage hours per day: ";
    cin >> a.hours;

    appliances.push_back(a);

    cout << "Appliance registered successfully.\n";
}


// ---------------------------
// View appliances
// ---------------------------
void viewAppliances() {

    if (appliances.size() == 0) {
        cout << "No appliances available.\n";
        return;
    }

    cout << "\nAppliance List\n";
    cout << left << setw(15) << "Name"
         << setw(12) << "Power(W)"
         << setw(12) << "Hours"
         << setw(12) << "Energy(kWh)" << endl;

    for (int i = 0; i < appliances.size(); i++) {

        float energy = (appliances[i].power * appliances[i].hours) / 1000;

        cout << left << setw(15) << appliances[i].name
             << setw(12) << appliances[i].power
             << setw(12) << appliances[i].hours
             << setw(12) << energy << endl;
    }
}


// ---------------------------
// Calculate total energy
// ---------------------------
float calculateTotalEnergy() {

    float total = 0;

    for (int i = 0; i < appliances.size(); i++) {
        total = total + 
        (appliances[i].power * appliances[i].hours) / 1000;
    }

    return total;
}


// ---------------------------
// Calculate billing + Save summary
// ---------------------------
void calculateBilling() {

    float tariff;

    cout << "Enter tariff per kWh: ";
    cin >> tariff;

    float totalEnergy = calculateTotalEnergy();
    float totalCost = totalEnergy * tariff;

    cout << "\n===== BILLING SUMMARY =====\n";
    cout << "Total Energy: " << totalEnergy << " kWh\n";
    cout << "Tariff: " << tariff << endl;
    cout << "Total Cost: " << totalCost << endl;

    // Save to billing_summary.txt
    ofstream billFile(BILLING_FILE, ios::app);

    billFile << "Total Energy: " << totalEnergy << " kWh | ";
    billFile << "Tariff: " << tariff << " | ";
    billFile << "Total Cost: " << totalCost << endl;

    billFile.close();

    cout << "Billing summary saved to file.\n";
}


// ---------------------------
// Main
// ---------------------------
int main() {

    loadAppliances();

    int choice;

    do {

        cout << "\n===== SMART ENERGY SYSTEM =====\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Calculate Total Energy\n";
        cout << "4. Calculate Billing\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            registerAppliance();
            break;

        case 2:
            viewAppliances();
            break;

        case 3:
            cout << "Total Energy: "
                 << calculateTotalEnergy()
                 << " kWh\n";
            break;

        case 4:
            calculateBilling();
            break;

        case 5:
            saveAppliances();
            cout << "Data saved. Goodbye.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}