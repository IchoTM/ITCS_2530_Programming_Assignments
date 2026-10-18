#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declare variables
    string favoriteReplica;
    string playStyle;
    double hoursPerMonth = 0.0;
    double estimatedBbsPerMonth = 0.0;

    // Prompt the user for input
    cout << "=== AIRSOFT LOADOUT & TACTICAL PROFILE ===" << endl;
    cout << "Enter your favorite airsoft replica/platform (e.g., MP7 GBB, M4 AEG): ";
    getline(cin, favoriteReplica);

    cout << "Enter your preferred play style (e.g., CQB, Milsim, Outdoor Field): ";
    getline(cin, playStyle);

    cout << "Enter your average hours played on the field per month: ";
    cin >> hoursPerMonth;

    // Calculate estimated monthly BB expenditure assuming an average rates
    estimatedBbsPerMonth = hoursPerMonth * 600.0;

    // Display the personalized message
    cout << "\n=== OPERATOR TACTICAL SUMMARY ===" << endl;
    cout << "Operator Intel: You love running your " << favoriteReplica
        << " in high-speed " << playStyle
        << " environments! Logging around " << hoursPerMonth
        << " hours on the field each month means you are laying down an estimated "
        << estimatedBbsPerMonth << " BBs downrange. Time to check your inventory and stock up on ammo!" << endl;

    return 0;
}