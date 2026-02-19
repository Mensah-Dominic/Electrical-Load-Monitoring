#include <iostream>
using namespace std;

class Appliance {
private:
    string name;
    double powerRating;
    double usageHours;

public:
    Appliance(string n, double p, double u) {
        name = n;
        powerRating = p;
        usageHours = u;
    }

    string getName() {
        return name;
    }

    double calculateEnergy() {
        return (powerRating * usageHours) / 1000.0;
    }
};

int main() {
    Appliance a1("Fan", 75, 8);
    cout << "Energy: " << a1.calculateEnergy() << " kWh" << endl;

    return 0;
}
