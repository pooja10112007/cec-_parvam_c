/*
 * CLASS AND OBJECT SYNTAX
 * This file demonstrates the exact C++ grammar needed to create 
 * a Class (blueprint) and instantiate an Object (the real thing).
 */

// Dictionary for printing
#include <iostream>
// Dictionary for text words
#include <string>
// Standard C++ dialect
using namespace std;

// =====================================================================
// 1. THE CLASS SYNTAX (The Blueprint)
// =====================================================================
// Keyword 'class' followed by the name (capitalized by convention).
// Open curly bracket '{' starts the blueprint.
class House {

// 'private:' is the locked safe. The main() function CANNOT see this.
// Notice the colon ':' after the word!
private:
    int secretPasscode; // Hidden data

// 'public:' is the front yard. The main() function CAN see and use these.
// Notice the colon ':' after the word!
public:
    string ownerName; // Visible data
    
    // A special method (Constructor) that sets the default values when built.
    House() {
        secretPasscode = 1234;
        ownerName = "Unknown";
    }

    // A visible method (behavior) that the main() function can call.
    // 'void' means it returns nothing.
    void ringDoorbell() {
        // 'cout' prints text to the screen. 'endl' is a new line.
        cout << "DING DONG! Welcome to " << ownerName << "'s house!" << endl;
    }
    
    // A visible method that safely interacts with the hidden private data.
    void checkPasscode(int guess) {
        // 'if' statement checks if the guess matches the secret
        if (guess == secretPasscode) {
            cout << "Access Granted! Safe opened." << endl;
        } else {
            cout << "Access Denied! Intruder alert!" << endl;
        }
    }

}; // <-- THE MOST IMPORTANT SEMICOLON IN C++! Without this, the program crashes!

// =====================================================================
// 2. THE OBJECT SYNTAX (The Construction Worker)
// =====================================================================
// Execution starts here
int main() {
    cout << "--- SYNTAX DEMO ---" << endl;
    
    // SYNTAX TO CREATE AN OBJECT:
    // ClassName objectName;
    House myHouse; 
    
    // SYNTAX TO ACCESS PUBLIC DATA (The Dot Operator):
    // objectName.publicVariable = value;
    myHouse.ownerName = "Rahul";
    
    // SYNTAX TO ACCESS PUBLIC METHODS (The Dot Operator):
    // objectName.methodName();
    myHouse.ringDoorbell();
    
    // Notice: We CANNOT type 'myHouse.secretPasscode = 9999;' 
    // It will cause a massive error because it is PRIVATE!
    
    // Instead, we use the public method to interact with the private data:
    myHouse.checkPasscode(1234);

    // Return 0 means success
    return 0;
}
