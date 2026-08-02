// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// prototypes
void addTask(vector<string> &tasks);
void viewTasks(vector<string> &tasks);
void deleteTask(vector<string> &tasks);
void showMenu();

int main() {
    vector<string> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();   // clear leftover newline

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
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
    cout << "     TASK MANAGER MENU\n";
    cout << "1. Add task\n";
    cout << "2. View your tasks\n";
    cout << "3. Delete task\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
}

// add task
void addTask(vector<string> &tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin, task);

    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"\n";
}

// view tasks
void viewTasks(vector<string> &tasks) {
    if (tasks.empty()) {
        // empty list
        cout << "You have no current tasks.\n";
        return;
    }

    cout << "Your Tasks:\n";
    for (int i = 0; i < (int)tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// delete task
void deleteTask(vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "You have no current tasks.\n";
        return;
    }

    viewTasks(tasks);

    int num;
    cout << "Enter task number to delete: ";
    cin >> num;
    cin.ignore();

    if (num < 1 || num > (int)tasks.size()) {
        // bad number
        cout << "Error: invalid task number.\n";
        return;
    }

    string removed = tasks[num - 1];
    tasks.erase(tasks.begin() + (num - 1));
    cout << "Task \"" << removed << "\" has been removed.\n";
}

