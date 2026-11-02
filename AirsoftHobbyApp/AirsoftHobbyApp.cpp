// ============================================================================
// Program Name: Airsoft Loadout & Tactical Profile (Expanded)
// Description: Welcomes the user, collects mixed-type inputs, 
//              validates stream state, calculates monthly BB 
//              expenditures and estimated ammo costs, outputs a formatted 
//              summary table to the console, and saves it to "report.txt".
// ============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // --- Introduction Banner ---
    cout << "========================================================" << endl;
    cout << "        WELCOME TO THE AIRSOFT OPERATIONS COMMAND       " << endl;
    cout << "========================================================" << endl << endl;

    // --- Variable Declarations ---
    string favoriteReplica = "";
    string playStyle = "";
    int hoursPerMonth = 0;
    double costPerBb = 0.0;
    double estimatedBbsPerMonth = 0.0;
    double totalMonthlyCost = 0.0;
    int menuChoice = 0;
    string operatorTier = "";
    string budgetWarning = "";

    // --- Prompt User for Inputs ---
    cout << "Enter your favorite airsoft replica/platform (e.g., MP7 GBB): ";
    getline(cin, favoriteReplica);

    cout << "Enter your preferred play style (e.g., CQB, Milsim): ";
    getline(cin, playStyle);

    cout << "Enter your average hours played on the field per month (whole hours): ";
    cin >> hoursPerMonth;

    cout << "Enter cost per individual BB (e.g., 0.025): ";
    cin >> costPerBb;
    cout << endl;

    // --- Input Validation ---
    if (!cin) {
        cout << "Input Error: Invalid data type entered! Program terminating." << endl;
        return 1; // Exit program with error code
    }

    // --- Compute Derived Values ---
    estimatedBbsPerMonth = hoursPerMonth * 600.0;
    totalMonthlyCost = estimatedBbsPerMonth * costPerBb;

    // --- Determines Operator Tier based on hours played and BB quality cost ---
    if (hoursPerMonth >= 15 && costPerBb >= 0.03) {
        operatorTier = "Tier-1 Heavy Operator (High Engagement & Precision Ammo)";
    }
    else if (hoursPerMonth >= 5 && costPerBb >= 0.02) {
        operatorTier = "Veteran Skirmisher (Moderate Activity)";
    }
    else {
        operatorTier = "Casual Weekend Operative (Light Activity)";
    }

    // --- Determines Budget Risk using compound logical operators ---
    if (totalMonthlyCost > 40.0 && (playStyle == "Milsim" || playStyle == "milsim" || playStyle == "CQB" || playStyle == "cqb")) {
        budgetWarning = "High Consumption Warning: High expenditure rate detected for intensive play style.";
    }
    else {
        budgetWarning = "Expense Level: Operating within standard budgetary thresholds.";
    }
   
    // --- User Input Options Menu (Switch Statement) ---
    cout << "========================================================" << endl;
    cout << "               TACTICAL OPERATIONS MENU                 " << endl;
    cout << "========================================================" << endl;
    cout << "1. Standard Tactical Report Summary" << endl;
    cout << "2. Operator Tier & Experience Analysis" << endl;
    cout << "3. Financial & Ammo Consumption Breakdown" << endl;
    cout << "Enter your menu selection (1-3): ";
    cin >> menuChoice;
    cout << endl;

    // Validate menu input
    if (!cin) {
        cout << "Input Error: Invalid menu selection type! Program terminating." << endl;
        return 1;
    }

    // Switch statement handling menu options
    switch (menuChoice) {
    case 1:
        cout << "[Menu Selection 1]: Generating Standard Report..." << endl << endl;
        break;
    case 2:
        cout << "[Menu Selection 2]: Generating Tier & Experience Analysis..." << endl;
        cout << "Assessed Classification: " << operatorTier << endl << endl;
        break;
    case 3:
        cout << "[Menu Selection 3]: Generating Financial & Consumption Breakdown..." << endl;
        cout << "Advisory Notice: " << budgetWarning << endl << endl;
        break;
    default:
        cout << "[Invalid Selection]: Defaulting to Standard Report Summary." << endl << endl;
        break;
    }
   
    // --- Formatted Console Output ---
    cout << fixed << showpoint << setprecision(2);

    cout << "========================================================" << endl;
    cout << "               AIRSOFT TACTICAL SUMMARY REPORT          " << endl;
    cout << "========================================================" << endl;
    cout << setw(30) << left << "Favorite Replica:" << setw(15) << right << favoriteReplica << endl;
    cout << setw(30) << left << "Preferred Play Style:" << setw(15) << right << playStyle << endl;
    cout << setw(30) << left << "Hours Played/Month:" << setw(15) << right << hoursPerMonth << endl;
    cout << setw(30) << left << "Estimated BBs/Month:" << setw(15) << right << estimatedBbsPerMonth << endl;
    cout << setw(30) << left << "Cost Per BB:" << setw(15) << right << "$" << costPerBb << endl;
    cout << setw(30) << left << "Estimated Monthly Expense:" << setw(15) << right << "$" << totalMonthlyCost << endl;
    cout << "========================================================" << endl;

    // --- File Output ---
    ofstream reportFile;
    reportFile.open("report.txt");

    // Check if file opened successfully
    if (!reportFile) {
        cout << "Error: Could not create or open 'report.txt'!" << endl;
        return 1;
    }

    // Write formatted report to file
    reportFile << fixed << showpoint << setprecision(2);
    reportFile << "========================================================" << endl;
    reportFile << "               AIRSOFT TACTICAL SUMMARY REPORT          " << endl;
    reportFile << "========================================================" << endl;
    reportFile << setw(30) << left << "Favorite Replica:" << setw(15) << right << favoriteReplica << endl;
    reportFile << setw(30) << left << "Preferred Play Style:" << setw(15) << right << playStyle << endl;
    reportFile << setw(30) << left << "Hours Played/Month:" << setw(15) << right << hoursPerMonth << endl;
    reportFile << setw(30) << left << "Estimated BBs/Month:" << setw(15) << right << estimatedBbsPerMonth << endl;
    reportFile << setw(30) << left << "Cost Per BB:" << setw(15) << right << "$" << costPerBb << endl;
    reportFile << setw(30) << left << "Estimated Monthly Expense:" << setw(15) << right << "$" << totalMonthlyCost << endl;
    reportFile << setw(30) << left << "Operator Classification:" << setw(15) << right << operatorTier << endl;
    reportFile << setw(30) << left << "Budget Warning:" << setw(15) << right << budgetWarning << endl;
    reportFile << "========================================================" << endl;

    reportFile.close();

    cout << endl << "Success: Formatted report saved to 'report.txt'." << endl;

    return 0;
}