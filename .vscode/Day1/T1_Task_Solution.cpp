/*
 * =====================================================================
 * ✅ SOLUTION FILE: SUPERHERO TASK
 * =====================================================================
 * Trainer Note: You can use this file to show the students the correct 
 * answer if they get stuck. It includes detailed line-by-line comments.
 */

#include <iostream>
#include <string>
using namespace std;

// 1. We create the Blueprint for a Superhero
class Superhero {
public:
    // --- ATTRIBUTES (DATA) ---
    string name;
    string power;
    int powerLevel;
    
    // --- METHODS (BEHAVIOR) ---
    // Method 1: Using their power
    void usePower() {
        cout << name << " uses " << power << "!" << endl;
    }
    
    // Method 2: Training to get stronger
    void train() {
        // Increase the power level by 10
        powerLevel += 10;
        cout << name << " trained! Power level is now " << powerLevel << "." << endl;
    }
}; // The all-important semicolon!

int main() {
    
    // 2. We instantiate (create) our first superhero object
    Superhero hero1;
    hero1.name = "Spider-Man";
    hero1.power = "Web Shooting";
    hero1.powerLevel = 80;
    
    // 3. We instantiate our second superhero object
    Superhero hero2;
    hero2.name = "Iron Man";
    hero2.power = "Laser Beams";
    hero2.powerLevel = 90;
    
    // 4. We interact with the objects using the Dot Operator
    cout << "--- Hero 1 Action ---" << endl;
    hero1.usePower();
    hero1.train();
    
    cout << "\n--- Hero 2 Action ---" << endl;
    hero2.usePower();
    hero2.train();

    return 0;
}
