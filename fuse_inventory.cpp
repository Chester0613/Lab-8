
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Joandry A. Irizarry Roman
 * Lab: 8 - Functions
 * Description: Manages a fuse inventory using functions
 * and pass-by-reference.
 * Due Date: October 12, 2026
 */

#include <iostream>
using namespace std;

// Function prototypes
void showHeading();
void reportDecision(char usedFuse);
void updateInventory(int &fuseCount);

int main() {
    int fuseCount;
    char usedFuse;

    showHeading();

    cout << "Enter the number of spare fuses: ";
    cin >> fuseCount;

    cout << "Did you use a fuse? (Y/N): ";
    cin >> usedFuse;

    reportDecision(usedFuse);

    if (usedFuse == 'Y' || usedFuse == 'y') {
        updateInventory(fuseCount);
    }
    else {
        cout << "Inventory was not changed." << endl;
    }

    cout << "Final number of spare fuses: "
         << fuseCount << endl;

    return 0;
}

// Displays the heading
void showHeading() {
    cout << "=== Fuse Inventory ===" << endl;
}

// Reports the technician's decision
void reportDecision(char usedFuse) {
    if (usedFuse == 'Y' || usedFuse == 'y') {
        cout << "A fuse was used." << endl;
    }
    else {
        cout << "No fuse was used." << endl;
    }
}

// Updates the original inventory
void updateInventory(int &fuseCount) {
    if (fuseCount > 0) {
        fuseCount--;
        cout << "Inventory updated." << endl;
    }
    else {
        cout << "No fuses available." << endl;
    }
}

/*
 * Analysis:
 *
 * Question 1:
 * Why does reportDecision use pass-by-value?
 *
 * Answer:
 * Because it only needs to read the technician's
 * answer and does not change the original variable.
 *
 * Question 2:
 * Why does updateInventory use pass-by-reference (&)?
 *
 * Answer:
 * Because it needs to change the original fuseCount
 * variable in main when a fuse is used.
 *
 * Question 3:
 * Why do we check if fuseCount is greater than 0?
 *
 * Answer:
 * To make sure the inventory does not become negative.
 */
