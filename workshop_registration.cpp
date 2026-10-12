
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Joandry A. Irizarry Roman
 * Lab: 8 - Functions
 * Description: Manages workshop registrations using
 * functions, switch, loops, and reference parameters.
 * Due Date: October 12, 2026
 */

#include <iostream>
using namespace std;

// Function prototypes
void showMenu();
void registerAttendee(int &availableSeats);
void cancelRegistration(int &availableSeats, int maxSeats);

int main() {
    int maxSeats;
    int availableSeats;
    int menuChoice;

    // Ask for workshop capacity
    cout << "Enter maximum number of seats: ";
    cin >> maxSeats;

    // Validate capacity
    while (maxSeats <= 0) {
        cout << "Invalid capacity. Enter a positive number: ";
        cin >> maxSeats;
    }

    availableSeats = maxSeats;

    // Repeat menu until user exits
    do {
        showMenu();

        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                registerAttendee(availableSeats);
                break;

            case 2:
                cancelRegistration(availableSeats, maxSeats);
                break;

            case 3:
                cout << "Ending session." << endl;
                break;

            default:
                cout << "Invalid option. Try again." << endl;
        }

        cout << "Available seats: "
             << availableSeats << endl;

    } while (menuChoice != 3);

    return 0;
}

// Displays the menu
void showMenu() {
    cout << "\n=== Workshop Registration ===" << endl;
    cout << "1. Register attendee" << endl;
    cout << "2. Cancel registration" << endl;
    cout << "3. Exit" << endl;
}

// Registers an attendee
void registerAttendee(int &availableSeats) {
    if (availableSeats > 0) {
        availableSeats--;
        cout << "Registration successful." << endl;
    }
    else {
        cout << "No seats available." << endl;
    }
}

// Cancels a registration
void cancelRegistration(int &availableSeats, int maxSeats) {
    if (availableSeats < maxSeats) {
        availableSeats++;
        cout << "Registration canceled." << endl;
    }
    else {
        cout << "No registrations to cancel." << endl;
    }
}

/*
 * Analysis:
 *
 * Question 1:
 * Why does registerAttendee use pass-by-reference?
 *
 * Answer:
 * Because it needs to change the original number
 * of available seats in main.
 *
 * Question 2:
 * Why does maxSeats not need &?
 *
 * Answer:
 * Because maxSeats is only used to check the
 * maximum capacity and does not need to change.
 *
 * Question 3:
 * Why do we use a do-while loop?
 *
 * Answer:
 * Because the menu needs to appear at least once
 * and repeat until the user selects option 3.
 *
 * Question 4:
 * Why do we use switch?
 *
 * Answer:
 * Because it allows the program to perform
 * different actions depending on the user's choice.
 */
