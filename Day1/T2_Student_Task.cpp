/*
 * =====================================================================
 * 💻 STUDENT TASK: CONVERT TO OOP!
 * =====================================================================
 * 
 * Below is a messy, PROCEDURAL Bank Account program. 
 * The data (balance) is floating around loosely, and the functions 
 * just modify it. 
 * 
 * YOUR MISSION:
 * 1. Create a `class BankAccount { ... };`.
 * 2. Move the `balance` variable INSIDE the class (under public:).
 * 3. Move the `depositMoney` and `withdrawMoney` functions INSIDE the class.
 * 4. In `main()`, create a BankAccount object using the class blueprint.
 * 5. Test it out using the dot operator (e.g., myAccount.depositMoney(100);)!
 */

// Required for printing to the screen
#include <iostream>
// So we don't have to type std::cout
using namespace std;

// =====================================================================
// --- MESSY PROCEDURAL CODE (YOUR JOB IS TO FIX THIS!) ---
// =====================================================================

// Loose Data floating globally! Very dangerous!
// 'double' is a data type for numbers with decimals.
double accountBalance = 0.0;

// Loose Function 1: Depositing money
// 'void' means it returns nothing. It takes a decimal number as input.
void depositMoney(double amount) {
    // Add the amount to the loose global variable
    accountBalance += amount;
    // Print the result
    cout << "Deposited: $" << amount << ". New Balance: $" << accountBalance << endl;
}

// Loose Function 2: Withdrawing money
void withdrawMoney(double amount) {
    // Check if we have enough money using an 'if' statement
    if (amount <= accountBalance) {
        accountBalance -= amount;
        cout << "Withdrew: $" << amount << ". New Balance: $" << accountBalance << endl;
    } else {
        cout << "Error: Not enough money!" << endl;
    }
}

// The main program where execution starts
int main() {
    cout << "--- Procedural Bank ---" << endl;
    
    // We are micromanaging the loose functions.
    depositMoney(100.0);
    withdrawMoney(30.0);
    withdrawMoney(100.0); // Should trigger error

    /* 
     * TODO: Erase the procedural code above and rewrite it using an OOP BankAccount Class!
     * Write your new main() function down here to test your new Object.
     */

    // Return 0 means no errors
    return 0;
}
