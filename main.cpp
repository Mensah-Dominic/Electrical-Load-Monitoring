#include <iostream>
#include <string>
using namespace std;

class Appliance {
private:
    string name;
    double powerRating;
    double usageHours;

public:
    Appliance() {
        name = "";
        powerRating = 0;
        usageHours = 0;
    }

    void setAppliance(string n, double p, double u) {
        name = n;
        powerRating = p;
        usageHours = u;
    }

    string getName() {
        return name;
    }

    double getPower() {
        return powerRating;
    }

    double getUsage() {
        return usageHours;
    }

    double calculateEnergy() {
        return (powerRating * usageHours) / 1000.0;
    }
};

int main() {

    Appliance appliances[10];
    int count = 0;
    int choice;

    do {
        cout << "\n=== Electrical Load Monitoring ===\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                if(count >= 10) {
                    cout << "Storage full!\n";
                    break;
                }

                string name;
                double power, hours;

                cout << "Enter appliance name: ";
                cin >> name;

                cout << "Enter power rating (Watts): ";
                cin >> power;

                cout << "Enter daily usage hours: ";
                cin >> hours;

                appliances[count].setAppliance(name, power, hours);
                count++;

                cout << "Appliance registered successfully!\n";
                break;
            }

            case 2: {
                if(count == 0) {
                    cout << "No appliances registered.\n";
                    break;
                }

                for(int i = 0; i < count; i++) {
                    cout << "\nAppliance " << i+1 << endl;
                    cout << "Name: " << appliances[i].getName() << endl;
                    cout << "Power: " << appliances[i].getPower() << " W" << endl;
                    cout << "Usage: " << appliances[i].getUsage() << " hrs" << endl;
                    cout << "Energy: " << appliances[i].calculateEnergy() << " kWh" << endl;
                }
                break;
            }

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}