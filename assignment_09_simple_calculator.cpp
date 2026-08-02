// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
bool divide(double a, double b, double &result);
bool computeModulus(double a, double b, double &result);
double power(double a, double b);
void showMenu();

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        cout << fixed << setprecision(2);

        if (choice >= 1 && choice <= 6) {
            double a, b;
            cout << "Enter first number : ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;

            if (choice == 1) {
                cout << "Result: " << a << " + " << b << " = " << add(a, b) << "\n";
            } else if (choice == 2) {
                cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << "\n";
            } else if (choice == 3) {
                cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << "\n";
            } else if (choice == 4) {
                double result;
                if (divide(a, b, result)) {
                    cout << "Result: " << a << " / " << b << " = " << result << "\n";
                } else {
                    // div by zero
                    cout << "Error: Cannot divide by zero.\n";
                }
            } else if (choice == 5) {
                double result;
                if (computeModulus(a, b, result)) {
                    cout << "Result: " << a << " % " << b << " = " << result << "\n";
                } else {
                    cout << "Error: Cannot divide by zero.\n";
                }
            } else if (choice == 6) {
                cout << "Result: " << a << " ^ " << b << " = " << power(a, b) << "\n";
            }
        } else if (choice == 7) {
            cout << "Goodbye!\n";
        } else {
            // invalid choice
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}

// print menu
void showMenu() {
    cout << "\n============================\n";
    cout << "     SIMPLE CALCULATOR\n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
    cout << "Select an operation (1-7): ";
}

// add
double add(double a, double b) {
    return a + b;
}

// subtract
double subtract(double a, double b) {
    return a - b;
}

// multiply
double multiply(double a, double b) {
    return a * b;
}

// divide
bool divide(double a, double b, double &result) {
    if (b == 0) {
        return false;   // div by zero
    }
    result = a / b;
    return true;
}

// modulus
bool computeModulus(double a, double b, double &result) {
    if (b == 0) {
        return false;   // div by zero
    }
    result = fmod(a, b);
    return true;
}

// exponent
double power(double a, double b) {
    return pow(a, b);
}
