/*
 * OBJECT-ORIENTED PROGRAMMING (OOP) EXAMPLE: The Smart Chef
 * Notice how the data and behaviors are bundled securely inside the 'Chef' class.
 * The main() function doesn't need to micromanage! It just calls ONE method.
 */

// Grab the library for printing text to the screen (Input/Output Stream)
#include <iostream>

// Grab the library for using text variables
#include <string>

// Use the standard dictionary so we don't have to type std::cout
using namespace std;

// =====================================================================
// --- THE BLUEPRINT (CLASS) ---
// =====================================================================
// 'class' creates a blueprint. We name it 'Chef'.
// We bundle the data AND the cooking logic into this single, smart object.
class Chef {

// 'private:' means the outside world (like the main function) CANNOT touch these variables. 
// They are hidden, secure, and safe from accidental changes! (This is called Encapsulation)
private:
    // Attributes (Data)
    // 'bool' is true/false. 'int' is a whole number.
    bool isStoveOn;
    int waterAmount;
    bool hasPasta;

// 'public:' means the outside world CAN use the methods below this line.
public:
    // This special method has the EXACT same name as the class. It is called a 'Constructor'.
    // It runs automatically the exact moment a Chef object is created.
    Chef() {
        // We set the default starting values for the kitchen.
        isStoveOn = false;
        waterAmount = 0;
        hasPasta = false;
    }

    // 'void' means it performs an action but doesn't return data.
    // This is the ONLY method the customer (main function) cares about!
    void cookPasta() {
        // 'cout' prints text to the screen. 'endl' moves to the next line.
        cout << "Chef: 'I am taking care of the pasta!'" << endl;
        
        // The object micromanages its OWN data internally. The customer doesn't have to!
        isStoveOn = true;
        waterAmount = 4;
        hasPasta = true;
        
        cout << "Chef: 'Stove is on, water is boiling, pasta is cooking...'" << endl;
        cout << "Chef: 'Your pasta is ready!'" << endl;
    }
}; // ALWAYS end a class definition with a semicolon in C++!

// =====================================================================
// MAIN PROGRAM EXECUTION
// =====================================================================
// The starting point of the program.
int main() {
    cout << "--- OOP RESTAURANT ---" << endl;
    
    // 1. Create the 'Chef' object from the blueprint. We named our object 'myChef'.
    Chef myChef;
    
    // 2. You (the customer) just order the pasta using the Dot Operator (.).
    // The Dot Operator is like a remote control. We point it at 'myChef' and press the 'cookPasta' button.
    // You don't tell the chef HOW to cook it. Look how incredibly clean and short this main function is!
    myChef.cookPasta();

    // End the program successfully.
    return 0;
}
