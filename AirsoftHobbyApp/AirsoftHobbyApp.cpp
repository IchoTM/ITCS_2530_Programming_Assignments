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

//Enum Definition(NEW)
enum SkillLevel {BEGINNER = 1, INTERMEDIATE, ADVANCED};

// --- FUNCTION PROTOTYPES ---
void displayBanner();
void setConsoleColor(string colorCode);
void getValidatedInputs(string& favoriteReplica, string& playStyle, double& costPerBb, SkillLevel& skill);
void calculateTacticalMetrics(double averageHours, double costPerBb, string playStyle,
    double& estimatedBbsPerMonth, double& totalMonthlyCost,
    string& operatorTier, string& budgetWarning);
void runTacticalMenu(string favoriteReplica, string playStyle,
    double estimatedBbsPerMonth, double costPerBb, double totalMonthlyCost,
    string operatorTier, string budgetWarning);
void saveReportToFile(string favoriteReplica, string playStyle, double averageHours,
    double estimatedBbsPerMonth, double costPerBb, double totalMonthlyCost,
    string operatorTier, string budgetWarning, SkillLevel userSkill);
double getMonthlyHoursAverage(double monthlyHours[], int months);
// --- MAIN FUNCTION ---
int main() {
    displayBanner();

    setConsoleColor("green");

    string favoriteReplica = "";
    string playStyle = "";
    const int months = 3;
    double costPerBb = 0.0;
    double estimatedBbsPerMonth = 0.0;
    double totalMonthlyCost = 0.0;
    double averageHours = 0.0;
    string operatorTier = "";
    string budgetWarning = "";
    SkillLevel userSkill = BEGINNER;

    //Array variables(NEW)
    double monthlyHours[months] = {};

    getValidatedInputs(favoriteReplica, playStyle, costPerBb, userSkill);

    //Call/collect averageHours from getMonthlyHoursAverage function. (NEW)
    averageHours = getMonthlyHoursAverage(monthlyHours, months);

    calculateTacticalMetrics(averageHours, costPerBb, playStyle,
        estimatedBbsPerMonth, totalMonthlyCost,
        operatorTier, budgetWarning);

    runTacticalMenu(favoriteReplica, playStyle,
        estimatedBbsPerMonth, costPerBb, totalMonthlyCost,
        operatorTier, budgetWarning);

    saveReportToFile(favoriteReplica, playStyle, averageHours,
        estimatedBbsPerMonth, costPerBb, totalMonthlyCost,
        operatorTier, budgetWarning, userSkill);

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
void getValidatedInputs(string& favoriteReplica, string& playStyle, double& costPerBb, SkillLevel& skill) {
    cout << "Enter your favorite airsoft replica/platform (e.g., MP7 GBB): ";
    getline(cin, favoriteReplica);

    cout << "Enter your preferred play style (e.g., CQB, Milsim): ";
    getline(cin, playStyle);

    //Skill Input(NEW)
    int skillChoice = 1;
    cout << "Enter Your Skill Level (1. Beginner 2. Intermediate 3. Advanced): ";
    cin >> skillChoice;
    while (!cin || skillChoice < 1 || skillChoice > 3) {
        cout << "Input Error: Please enter a valid integer for SkillChoice: (1-3) ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> skillChoice;
    }
    skill = static_cast<SkillLevel>(skillChoice);

    cout << "Enter cost per individual BB (e.g., 0.025): ";
    cin >> costPerBb;
    // While loop for input validation
    while (!cin || costPerBb < 0) {
        cout << "Input Error: Please enter a valid numeric value for cost: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> costPerBb;
    }
    cout << endl;
}

// Function to perform calculations and evaluate compound condition if/else statements
void calculateTacticalMetrics(double averageHours, double costPerBb, string playStyle,
    double& estimatedBbsPerMonth, double& totalMonthlyCost,
    string& operatorTier, string& budgetWarning) {
    // Compute derived values
    estimatedBbsPerMonth = averageHours * 600.0;
    totalMonthlyCost = estimatedBbsPerMonth * costPerBb;

    // Compound if/else block 1: Determines Operator Tier
    if (averageHours >= 15 && costPerBb >= 0.03) {
        operatorTier = "Tier-1 Heavy Operator (High Engagement & Precision Ammo)";
    }
    else if (averageHours >= 5 && costPerBb >= 0.02) {
        operatorTier = "Veteran Skirmisher (Moderate Activity)";
    }
    else {
        operatorTier = "Casual Weekend Operative (Light Activity)";
    }

    // Compound if/else block 2: Determines Budget Risk
    if (averageHours > 40.0 && (playStyle == "Milsim" || playStyle == "milsim" || playStyle == "CQB" || playStyle == "cqb")) {
        budgetWarning = "High Consumption Warning: High expenditure rate detected for intensive play style.";
    }
    else {
        budgetWarning = "Expense Level: Operating within standard budgetary thresholds.";
    }
}

// Function to run the interactive menu using a do-while loop and switch statement
void runTacticalMenu(string favoriteReplica, string playStyle,
    double estimatedBbsPerMonth, double costPerBb, double totalMonthlyCost,
    string operatorTier, string budgetWarning){
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

//Function to get montly hours average
double getMonthlyHoursAverage(double monthlyHours[], int months) {

    double totalHours = 0.0;

    cout << "Enter your hours for the last "<< months << " MONTHS:" << endl;

    for (int i = 0; i < months; i++) {

        cout << "Enter hours played for Month " << i + 1 << ": ";
        cin >> monthlyHours[i];

        // Array Based Validation 
        while (!cin || monthlyHours[i] < 0) {
            cout << "Invalid input. Enter zero or more hours: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> monthlyHours[i];
        }

        totalHours += monthlyHours[i];
    }

    cin.ignore(10000, '\n');

    // Return the calculated average
    return totalHours / months;
}

// Function to display the summary table and save the formatted report to "report.txt"
void saveReportToFile(string favoriteReplica, string playStyle, double averageHours,
    double estimatedBbsPerMonth, double costPerBb, double totalMonthlyCost,
    string operatorTier, string budgetWarning, SkillLevel userSkill) {

    //If/Else Strucure for userSkill enum(NEW)
    string skillName = "";
    if (userSkill == BEGINNER) {
        skillName = "Beginner";
    }
    else if (userSkill == INTERMEDIATE) {
        skillName = "Intermediate";
    }
    else {
        skillName = "Advanced";
    }


    // --- Formatted Console Output Table ---
    cout << fixed << showpoint << setprecision(2);
    cout << "========================================================" << endl;
    cout << "               AIRSOFT TACTICAL SUMMARY REPORT          " << endl;
    cout << "========================================================" << endl;
    cout << setw(30) << left << "Favorite Replica:" << setw(20) << right << favoriteReplica << endl;
    cout << setw(30) << left << "Preferred Play Style:" << setw(20) << right << playStyle << endl;
    cout << setw(30) << left << "Skill Level:" << setw(20) << right << skillName << endl;
    cout << setw(30) << left << "Average Hours Played/Month:" << setw(20) << right << averageHours << endl;
    cout << setw(30) << left << "Estimated BBs/Month:" << setw(20) << right << estimatedBbsPerMonth << endl;
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
    reportFile << setw(30) << left << "Favorite Replica:" << setw(20) << right << favoriteReplica << endl;
    reportFile << setw(30) << left << "Preferred Play Style:" << setw(20) << right << playStyle << endl;
    reportFile << setw(30) << left << "Skill Level:" << setw(20) << right << skillName << endl;//
    reportFile << setw(30) << left << "Average Hours Played/Month:" << setw(20) << right << averageHours << endl;
    reportFile << setw(30) << left << "Estimated BBs/Month:" << setw(20) << right << estimatedBbsPerMonth << endl;
    reportFile << setw(30) << left << "Cost Per BB:" << setw(20) << right << "$" << costPerBb << endl;
    reportFile << setw(30) << left << "Estimated Monthly Expense:" << setw(20) << right << "$" << totalMonthlyCost << endl;
    reportFile << setw(30) << left << "Operator Classification:" << setw(20) << right << operatorTier << endl;
    reportFile << setw(30) << left << "Budget Warning:" << setw(20) << right << budgetWarning << endl;
    reportFile << "========================================================" << endl;

    reportFile.close();

    cout << endl << "Success: Formatted report saved to 'report.txt'." << endl;
}