// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// student struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// prototypes
void addStudent(vector<Student> &students);
void displayStudents(vector<Student> &students);
void calculateAverage(vector<Student> &students);
double getAverage(Student &s);
void showMenu();

int main() {
    vector<Student> students;
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayStudents(students);
        } else if (choice == 3) {
            calculateAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!\n";
        } else {
            // invalid choice
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

// print menu
void showMenu() {
    cout << "\n================================\n";
    cout << "   STUDENT RECORD SYSTEM MENU\n";
    cout << "================================\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
}

// average helper
double getAverage(Student &s) {
    if (s.scores.empty()) {
        return 0.0;
    }

    double sum = 0;
    for (int i = 0; i < (int)s.scores.size(); i++) {
        sum += s.scores[i];
    }
    return sum / s.scores.size();
}

// add student
void addStudent(vector<Student> &students) {
    Student s;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int count;
    cout << "How many scores? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n";
}

// display all
void displayStudents(vector<Student> &students) {
    if (students.empty()) {
        // empty list
        cout << "No students have been added yet.\n";
        return;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < (int)students.size(); i++) {
        Student &s = students[i];
        cout << "\nName: " << s.name << "\n";
        cout << "ID: " << s.id << "\n";
        cout << "Scores: ";
        for (int j = 0; j < (int)s.scores.size(); j++) {
            cout << s.scores[j] << " ";
        }
        cout << "\nAverage: " << getAverage(s) << "\n";
    }
}

// average by id
void calculateAverage(vector<Student> &students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].id == id) {
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score: "
                 << getAverage(students[i]) << "\n";
            return;
        }
    }

    // not found
    cout << "Error: student ID not found.\n";
}
