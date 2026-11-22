// ============================================================================
// Program Name: Airsoft Loadout & Tactical Profile (Modularized)
// Description: Welcomes the user with customized console colors and a banner, 
//              collects and validates mixed-type inputs using functions, 
//              computes tactical expenditures, runs an interactive menu, 
//              outputs a formatted summary table, and saves it to "report.txt".
// ============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// --- FUNCTION PROTOTYPES ---
void displayBanner();
void setConsoleColor(string colorCode);
void getValidatedInputs(string& favoriteReplica, string& playStyle, int& hoursPerMonth, double& costPerBb);
void calculateTacticalMetrics(int hoursPerMonth, double costPerBb, string playStyle,
    double& estimatedBbsPerMonth, double& totalMonthlyCost,
    string& operatorTier, string& budgetWarning);
void runTacticalMenu(string favoriteReplica, string playStyle, int hoursPerMonth,
    double estimatedBbsPerMonth, double costPerBb, double totalMonthlyCost,
    string operatorTier, string budgetWarning);
void saveReportToFile(string favoriteReplica, string playStyle, int hoursPerMonth,
    double estimatedBbsPerMonth, double costPerBb, double totalMonthlyCost,
    string operatorTier, string budgetWarning);

// --- MAIN FUNCTION ---
int main() {
    displayBanner();

    setConsoleColor("green");

    string favoriteReplica = "";
    string playStyle = "";
    int hoursPerMonth = 0;
    double costPerBb = 0.0;
    double estimatedBbsPerMonth = 0.0;
    double totalMonthlyCost = 0.0;
    string operatorTier = "";
    string budgetWarning = "";

    getValidatedInputs(favoriteReplica, playStyle, hoursPerMonth, costPerBb);

    calculateTacticalMetrics(hoursPerMonth, costPerBb, playStyle,
        estimatedBbsPerMonth, totalMonthlyCost,
        operatorTier, budgetWarning);

    runTacticalMenu(favoriteReplica, playStyle, hoursPerMonth,
        estimatedBbsPerMonth, costPerBb, totalMonthlyCost,
        operatorTier, budgetWarning);

    saveReportToFile(favoriteReplica, playStyle, hoursPerMonth,
        estimatedBbsPerMonth, costPerBb, totalMonthlyCost,
        operatorTier, budgetWarning);

    setConsoleColor("reset");

    return 0;
}

// --- FUNCTION DEFINITIONS ---

// Function to display the banner and simulated diagnostics (Includes fixed for-loop)
void displayBanner() {
    cout << "========================================================" << endl;
    cout << "        WELCOME TO THE AIRSOFT OPERATIONS COMMAND       " << endl;
    cout << "========================================================" << endl << endl;

    cout << "Initializing tactical system diagnostics..." << endl;
    // Fixed for-loop running a predetermined number of times
    for (int i = 1; i <= 3; i++) {
        cout << " [Diagnostic Check " << i << "/3] - Subsystems nominal." << endl;
    }
    cout << endl;
}

// Function to change console text color using ANSI escape codes
void setConsoleColor(string colorCode) {
    if (colorCode == "green") {
        cout << "\033[32m"; // Bright Green text
    }
    else if (colorCode == "cyan") {
        cout << "\033[36m"; // Cyan text
    }
    else if (colorCode == "reset") {
        cout << "\033[0m";  // Reset to default
    }
}

// Function to collect inputs and handle stream validation using while loops
void getValidatedInputs(string& favoriteReplica, string& playStyle, int& hoursPerMonth, double& costPerBb) {
    cout << "Enter your favorite airsoft replica/platform (e.g., MP7 GBB): ";
    getline(cin, favoriteReplica);

    cout << "Enter your preferred play style (e.g., CQB, Milsim): ";
    getline(cin, playStyle);

    cout << "Enter your average hours played on the field per month (whole hours): ";
    cin >> hoursPerMonth;
    // While loop for input validation
    while (!cin) {
        cout << "Input Error: Please enter a valid integer for hours: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> hoursPerMonth;
    }

    cout << "Enter cost per individual BB (e.g., 0.025): ";
    cin >> costPerBb;
    // While loop for input validation
    while (!cin) {
        cout << "Input Error: Please enter a valid numeric value for cost: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> costPerBb;
    }
    cout << endl;
}

// Function to perform calculations and evaluate compound condition if/else statements
void calculateTacticalMetrics(int hoursPerMonth, double costPerBb, string playStyle,
    double& estimatedBbsPerMonth, double& totalMonthlyCost,
    string& operatorTier, string& budgetWarning) {
    // Compute derived values
    estimatedBbsPerMonth = hoursPerMonth * 600.0;
    totalMonthlyCost = estimatedBbsPerMonth * costPerBb;

    // Compound if/else block 1: Determines Operator Tier
    if (hoursPerMonth >= 15 && costPerBb >= 0.03) {
        operatorTier = "Tier-1 Heavy Operator (High Engagement & Precision Ammo)";
    }
    else if (hoursPerMonth >= 5 && costPerBb >= 0.02) {
        operatorTier = "Veteran Skirmisher (Moderate Activity)";
    }
    else {
        operatorTier = "Casual Weekend Operative (Light Activity)";
    }

    // Compound if/else block 2: Determines Budget Risk
    if (totalMonthlyCost > 40.0 && (playStyle == "Milsim" || playStyle == "milsim" || playStyle == "CQB" || playStyle == "cqb")) {
        budgetWarning = "High Consumption Warning: High expenditure rate detected for intensive play style.";
    }
    else {
        budgetWarning = "Expense Level: Operating within standard budgetary thresholds.";
    }
}

// Function to run the interactive menu using a do-while loop and switch statement
void runTacticalMenu(string favoriteReplica, string playStyle, int hoursPerMonth,
    double estimatedBbsPerMonth, double costPerBb, double totalMonthlyCost,
    string operatorTier, string budgetWarning) {
    int menuChoice = 0;

    do {
        cout << "========================================================" << endl;
        cout << "              EXTRA TACTICAL OPERATIONS MENU            " << endl;
        cout << "========================================================" << endl;
        cout << "1. Financial & Ammo Consumption Breakdown" << endl;
        cout << "2. Operator Tier & Experience Analysis" << endl;
        cout << "3. Proceed to Final Report File Generation" << endl;
        cout << "Enter your menu selection (1-3): ";
        cin >> menuChoice;
        cout << endl;

        // Validation loop for menu choice
        while (!cin) {
            cout << "Input Error: Invalid selection type! Enter a number (1-3): ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> menuChoice;
        }

        // Switch statement handling menu navigation
        switch (menuChoice) {
        case 1:
            cout << "[Menu Selection 1]: Generating Financial & Consumption Breakdown..." << endl;
            cout << "Estimated Monthly Expense: $" << fixed << setprecision(2) << totalMonthlyCost << endl;
            cout << "Advisory Notice: " << budgetWarning << endl << endl;
            break;
        case 2:
            cout << "[Menu Selection 2]: Generating Tier & Experience Analysis..." << endl;
            cout << "Assessed Classification: " << operatorTier << endl << endl;
            break;
        case 3:
            cout << "[Menu Selection 3]: Exiting menu and finalizing report..." << endl << endl;
            break;
        default:
            cout << "[Invalid Selection]: Please choose an option between 1 and 3." << endl << endl;
            break;
        }
    } while (menuChoice != 3);
}

// Function to display the summary table and save the formatted report to "report.txt"
void saveReportToFile(string favoriteReplica, string playStyle, int hoursPerMonth,
    double estimatedBbsPerMonth, double costPerBb, double totalMonthlyCost,
    string operatorTier, string budgetWarning) {

    // --- Formatted Console Output Table ---
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

    // --- File Output Stream ---
    ofstream reportFile;
    reportFile.open("report.txt");

    if (!reportFile) {
        cout << "Error: Could not create or open 'report.txt'!" << endl;
        return;
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
}