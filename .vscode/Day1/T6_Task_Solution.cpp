/*
 * =====================================================================
 * ✅ SOLUTION FILE: UPGRADE TO C++
 * =====================================================================
 * Trainer Note: Show students how much cleaner the new code is. 
 * Point out the absence of the confusing '%d' and '&' symbols.
 */

// 1. Upgraded Library
#include <iostream>
// 2. Added namespace
using namespace std;

int main() {
    int userAge;

    // 3. Upgraded Output (cout << )
    // 'cout' pushes text to the screen. 'endl' hits enter.
    cout << "Welcome to the C++ program!" << endl;
    cout << "Please enter your age: ";

    // 4. Upgraded Input (cin >> )
    // 'cin' pulls text from the keyboard INTO the variable.
    // Notice we don't need "%d" or "&" anymore!
    cin >> userAge;

    // 5. Upgraded Output combining text and variables
    cout << "Wow, you are " << userAge << " years old!" << endl;

    // Return success
    return 0;
}
