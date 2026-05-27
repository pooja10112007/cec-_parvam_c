/*
 * THE FOUR PILLARS OF OOP - QUICK OVERVIEW
 * This code demonstrates a brief look at Encapsulation, Abstraction, 
 * Inheritance, and Polymorphism working together.
 * We will dive much deeper into these in Days 4 and 5!
 */

// Include the standard input/output library for printing
#include <iostream>
// Include string library for text
#include <string>
// Use the standard namespace so we don't have to type std::
using namespace std;

// =====================================================================
// 1. INHERITANCE: Creating a "Parent" Class
// =====================================================================
class Animal {
// 'protected:' is like private, but it allows "child" classes to use the data!
protected:
    string name;

public:
    // This is the constructor (runs when created)
    Animal(string n) {
        name = n;
    }

    // 2. POLYMORPHISM: The 'virtual' keyword allows child classes to override this behavior!
    virtual void speak() {
        cout << name << " makes a mysterious animal sound." << endl;
    }
};

// 3. INHERITANCE: The Dog class 'inherits' (gets everything) from Animal!
// The syntax ': public Animal' means "Dog is a child of Animal"
class Dog : public Animal {
// 4. ENCAPSULATION: We hide the Dog's energy level inside the 'private' section.
private:
    int energyLevel;

public:
    // The Dog constructor passes the name up to the Animal parent
    Dog(string n) : Animal(n) {
        energyLevel = 100; // Starting energy
    }

    // POLYMORPHISM: The Dog overrides the generic speak() method with a specific Bark!
    void speak() override {
        cout << name << " says: WOOF WOOF!" << endl;
    }

    // 5. ABSTRACTION: We just call 'play()'. 
    // The complex math of how energy decreases is hidden from the user.
    void play() {
        if (energyLevel > 0) {
            energyLevel -= 20; // Internal math hidden from user
            cout << name << " runs around playing! Energy is now: " << energyLevel << endl;
        } else {
            cout << name << " is too tired to play." << endl;
        }
    }
}; // Don't forget the semicolon!

// =====================================================================
// MAIN PROGRAM EXECUTION
// =====================================================================
int main() {
    cout << "--- FOUR PILLARS EXAMPLE ---" << endl;
    
    // We create a Dog object. 
    // Notice how Dog inherited the 'name' attribute from Animal!
    Dog myDog("Buddy");
    
    // Polymorphism: Calling speak() triggers the Dog's version, not the Animal's!
    myDog.speak();
    
    // Abstraction: We just press the 'play' button. We don't worry about the energy math.
    myDog.play();
    myDog.play();

    // End program without errors
    return 0;
}
