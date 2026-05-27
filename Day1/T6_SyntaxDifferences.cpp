/*
 * C++ VS C: KEY SYNTAX DIFFERENCES
 * This file compares the old C way of doing things with the modern, 
 * much easier C++ way.
 */

// 1. THE LIBRARY
// OLD C: #include <stdio.h> (Standard Input/Output)
// NEW C++: <iostream> (Input/Output Stream)
#include <iostream>

// NEW C++: We use standard namespace to avoid typing std::cout
using namespace std;

int main() {
    cout << "--- C vs C++ SYNTAX ---" << endl;

    // A variable to hold an integer (whole number)
    int age = 25;

    // =====================================================================
    // 2. PRINTING TO THE SCREEN (OUTPUT)
    // =====================================================================
    
    // OLD C WAY (printf):
    // You had to use "%d" as a placeholder to tell the computer an integer was coming.
    // If you accidentally used "%f", the program would crash!
    // Code: printf("Old C: I am %d years old.\n", age);

    // NEW C++ WAY (cout):
    // 'cout' is smart. It automatically knows 'age' is an integer! 
    // The arrows '<<' push the text and the variable to the screen.
    cout << "New C++: I am " << age << " years old." << endl;

    // =====================================================================
    // 3. READING FROM THE KEYBOARD (INPUT)
    // =====================================================================
    int luckyNumber;
    
    cout << "Enter your lucky number: ";
    
    // OLD C WAY (scanf):
    // You had to use "%d" AND you had to put an '&' in front of the variable 
    // to point to its exact memory address. Very confusing for beginners!
    // Code: scanf("%d", &luckyNumber);

    // NEW C++ WAY (cin):
    // 'cin' (Character Input) is smart. No '%d', no '&' memory pointers!
    // The arrows '>>' point INWARD, shoving the user's typing into the variable.
    cin >> luckyNumber;
    
    // Print it back out
    cout << "Your lucky number is " << luckyNumber << "!" << endl;

    // Return success
    return 0;
}
