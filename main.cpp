#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Appliance {
    string name;
    float power;
    float hours;
};

vector<Appliance> appliances;

void registerAppliance() {
    Appliance a;

    cout << "Enter appliance name: ";
    cin >> a.name;

    cout << "Enter power (W): ";
    cin >> a.power;

    cout << "Enter hours/day: ";
    cin >> a.hours;

    appliances.push_back(a);
}

void viewAppliances() {

    if (appliances.size() == 0) {
        cout << "No appliances available.\n";
        return;
    }

    cout << left << setw(15) << "Name"
         << setw(12) << "Power"
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

float calculateTotalEnergy() {

    float total = 0;

    for (int i = 0; i < appliances.size(); i++) {
        total += (appliances[i].power * appliances[i].hours) / 1000;
    }

    return total;
}

void calculateBilling() {

    float tariff;

    cout << "Enter tariff per kWh: ";
    cin >> tariff;

    float totalEnergy = calculateTotalEnergy();
    float cost = totalEnergy * tariff;

    cout << "\n===== BILLING SUMMARY =====\n";
    cout << "Total Energy: " << totalEnergy << " kWh\n";
    cout << "Tariff: " << tariff << endl;
    cout << "Total Cost: " << cost << endl;
}

int main() {

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
            cout << "Goodbye\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
