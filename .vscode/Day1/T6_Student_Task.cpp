/*
 * =====================================================================
 * 💻 STUDENT TASK: UPGRADE TO C++!
 * =====================================================================
 * 
 * YOUR MISSION:
 * Below is a program written in old C syntax. It uses <stdio.h>, 
 * printf, and scanf.
 * 
 * Your job is to completely rewrite it using modern C++ syntax!
 * 1. Change the library to <iostream>.
 * 2. Add the 'using namespace std;' line.
 * 3. Change the 'printf' statements to 'cout <<'.
 * 4. Change the 'scanf' statement to 'cin >>' (remember to remove the &!).
 */

// --- OLD C CODE (FIX THIS!) ---
#include <stdio.h>

int main() {
    int userAge;

    // Old C Output
    printf("Welcome to the C program!\n");
    printf("Please enter your age: ");

    // Old C Input (Look how ugly the %d and & are!)
    scanf("%d", &userAge);

    // Old C Output
    printf("Wow, you are %d years old!\n", userAge);

    return 0;
}
