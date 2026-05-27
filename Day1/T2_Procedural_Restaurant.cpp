/*
 * PROCEDURAL PROGRAMMING EXAMPLE: The Micromanaged Kitchen
 * In procedural programming, we write loose instructions (functions) that 
 * pass around loose data (variables). 
 * The main() function has to micromanage every single step in the exact correct order.
 */

// '#include' tells the compiler to fetch a library before building the code.
// '<iostream>' stands for Input/Output Stream. It gives us the ability to use 'cout' to print to the screen.
#include <iostream>

// '<string>' gives us the ability to store text words, rather than just single letters.
#include <string>

// 'using namespace std;' tells the computer to use the standard C++ dictionary.
// Without this, we would have to type 'std::cout' every time we wanted to print!
using namespace std;

// =====================================================================
// --- LOOSE DATA (GLOBAL VARIABLES) ---
// =====================================================================
// These variables are floating around loosely outside of any secure object.
// ANY function can accidentally change them! This is bad for security.

// 'bool' holds a True or False value. We use it to track if the stove is on.
bool isStoveOn = false;

// 'int' holds a whole number. We use it to track cups of water.
int waterAmount = 0;

// Another 'bool' to track if we put the pasta in yet.
bool hasPasta = false;

// =====================================================================
// --- LOOSE FUNCTIONS (PROCEDURES) ---
// =====================================================================
// These functions just do steps. They have to manually reach out and modify the loose data.

// 'void' means this function does an action but does not return any answer back to us.
void turnOnStove() {
    // We reach out and change the loose global variable.
    isStoveOn = true;
    
    // 'cout' (Character Output) prints text. '<<' pushes the text to the screen. 
    // 'endl' means End Line (moves the cursor down).
    cout << "Procedural Step: Stove is turned on." << endl;
}

// This function requires an input: an integer named 'amount'.
void boilWater(int amount) {
    // 'if' checks a condition. If the stove is ON, we can boil water.
    if (isStoveOn) {
        waterAmount = amount; // Set the loose variable
        cout << "Procedural Step: Boiling " << waterAmount << " cups of water." << endl;
    } else {
        // 'else' happens if the 'if' condition is false (stove is off).
        cout << "ERROR: Cannot boil water, stove is off!" << endl;
    }
}

// Function to add pasta
void addPasta() {
    // Only add pasta if we have more than 0 cups of water
    if (waterAmount > 0) {
        hasPasta = true; // Set the loose variable
        cout << "Procedural Step: Pasta added to boiling water. Cooking..." << endl;
    } else {
        cout << "ERROR: No water to cook pasta!" << endl;
    }
}

// =====================================================================
// MAIN PROGRAM EXECUTION
// =====================================================================
// 'int main()' is where the computer STARTS reading your code. Every program must have one.
int main() {
    cout << "--- PROCEDURAL RESTAURANT ---" << endl;
    
    // In procedural programming, YOU (the main function) have to micromanage the chef.
    // You have to call every single step in the exact correct order.
    
    // Step 1: Call the function to turn on the stove.
    turnOnStove();
    
    // Step 2: Call the function to boil water, passing '4' as the amount.
    // If you swapped step 1 and 2 by accident, the program would throw an error!
    boilWater(4);
    
    // Step 3: Call the function to add pasta.
    addPasta();
    
    cout << "Finally, the pasta is ready!" << endl;

    // 'return 0' tells Windows/Mac that the program ran perfectly with zero errors.
    return 0;
}
