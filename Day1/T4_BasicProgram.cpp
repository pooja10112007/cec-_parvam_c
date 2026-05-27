/*
 * BASIC STRUCTURE OF A C++ PROGRAM
 * Every C++ program needs this "skeleton" to run.
 * Without this exact structure, the computer will refuse to read your code.
 */

// 1. THE DICTIONARY (#include)
// '#' tells the computer to do this BEFORE running the program.
// 'include' means fetch a library.
// '<iostream>' stands for Input/Output Stream. It gives us the power to use 'cout' (print).
#include <iostream>

// 2. THE DIALECT (using namespace std;)
// 'std' stands for Standard. We are telling the computer we are using standard C++ words.
// If we delete this line, we would have to type 'std::cout' instead of just 'cout'.
using namespace std;

// 3. THE ENVELOPE (int main)
// 'int' means this function will return an integer (whole number) when it finishes.
// 'main()' is the EXACT spot the computer starts reading. It ignores everything else!
int main() { 
    // The opening curly bracket '{' marks the start of our instructions.

    // 4. THE INSTRUCTIONS
    // 'cout' (Character Output) pushes text to the screen.
    // '<<' are the directional arrows pushing the text into cout.
    // "Hello World!" is the string of text.
    // 'endl' drops the cursor to a new line (End Line).
    // ';' (semicolon) is the period at the end of our sentence. It is MANDATORY.
    cout << "Welcome to the world of C++!" << endl;

    // 5. THE SIGNATURE (return 0)
    // We promised 'int main()' would return an integer. Here we return the number 0.
    // In computer science, 0 means "Success, no errors!"
    return 0;

} // The closing curly bracket '}' marks the end of our instructions. The program dies here.
