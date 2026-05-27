/*
 * =====================================================================
 * ✅ SOLUTION FILE: PROCEDURAL TO OOP CONVERSION
 * =====================================================================
 * Trainer Note: Show this to the students at the end of the activity.
 * Emphasize how much safer and more organized the class structure is!
 */

// Preprocessor directive for input/output printing
#include <iostream>
// Use the standard namespace to avoid typing std:: everywhere
using namespace std;

// 1. We create a clean, organized Class (Blueprint) named 'BankAccount'
class BankAccount {
// 'public:' means we can access these from the main() function
public:
    // 2. Data is now safely INSIDE the object!
    // 'double' is a data type used for numbers with decimals (like money: 100.50).
    double balance = 0.0; // Starting balance

    // 3. Methods (Behaviors) are now INSIDE the object!
    // 'void' means it doesn't return a value. It requires an input 'amount'.
    void deposit(double amount) {
        // '+=' adds the amount to the current balance.
        balance += amount;
        
        // 'cout' prints the text and the variables to the screen. 'endl' hits enter.
        cout << "Deposited: $" << amount << ". New Balance: $" << balance << endl;
    }

    // A method to take money out.
    void withdraw(double amount) {
        // The object manages its own logic to protect its data!
        // 'if' statement ensures we don't withdraw more than we have.
        if (amount <= balance) {
            // '-=' subtracts the amount from the balance.
            balance -= amount;
            cout << "Withdrew: $" << amount << ". New Balance: $" << balance << endl;
        } else {
            // 'else' runs if the amount is greater than the balance.
            cout << "Error: Not enough money to withdraw $" << amount << "!" << endl;
        }
    }
}; // Crucial semicolon at the end of the class!

// The starting point of the program
int main() {
    cout << "--- OOP Bank ---" << endl;
    
    // 4. Create an actual physical Bank Account object from our blueprint!
    // We named it 'myAccount'.
    BankAccount myAccount;
    
    // 5. Interact with it cleanly using the Dot Operator (.).
    // The main function doesn't need to know HOW the bank does the math,
    // it just uses the methods provided!
    
    // Deposit $100
    myAccount.deposit(100.0);
    
    // Withdraw $30
    myAccount.withdraw(30.0);
    
    // Try to withdraw $100 (This will trigger our safety 'if' statement error)
    myAccount.withdraw(100.0); 

    // End the program successfully
    return 0;
}
