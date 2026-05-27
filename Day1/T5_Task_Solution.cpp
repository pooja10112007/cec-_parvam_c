/*
 * =====================================================================
 * ✅ SOLUTION FILE: CLASS SYNTAX
 * =====================================================================
 * Trainer Note: Use this to show the correct syntax formatting.
 * Point out the colons (:) after public/private, and the semicolon (;) 
 * after the class closing bracket.
 */

// Dictionary for printing
#include <iostream>
// Dictionary for text words
#include <string>
// Standard C++ dialect
using namespace std;

// 1. The Blueprint Syntax
class Student {
// The locked safe (notice the colon!)
private:
    // Hidden data type integer
    int examScore;

// The front yard (notice the colon!)
public:
    // Visible data type string
    string name;
    
    // A visible method
    void takeExam() {
        examScore = 100;
        // 'cout' prints to screen, 'endl' hits enter
        cout << name << " took the exam and scored " << examScore << "%!" << endl;
    }

}; // <-- The mandatory Class staple (semicolon)!

// The execution envelope
int main() {
    
    // 2. Object Creation Syntax
    Student myStudent;
    
    // 3. Dot Operator Syntax for public variables
    myStudent.name = "Priya";
    
    // 4. Dot Operator Syntax for public methods
    myStudent.takeExam();

    // Success
    return 0;
}
