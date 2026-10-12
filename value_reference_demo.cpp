
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Joandry A. Irizarry Roman
 * Lab: 8 - Functions
 * Description: Demonstrates pass-by-value and pass-by-reference
 * using a safety inspection counter.
 * Due Date: October 12, 2026
 */

#include <iostream>
using namespace std;

// Function prototypes
void showProjectedCount(int completedInspections);
void recordCompletedInspection(int &completedInspections);

int main() {
    int completedInspections;

    cout << "Enter completed inspections: ";
    cin >> completedInspections;

    showProjectedCount(completedInspections);

    cout << "After projection: "
         << completedInspections << endl;

    recordCompletedInspection(completedInspections);

    cout << "After recording: "
         << completedInspections << endl;

    return 0;
}

// Pass-by-value function
void showProjectedCount(int completedInspections) {
    completedInspections++;

    cout << "Projected count: "
         << completedInspections << endl;
}

// Pass-by-reference function
void recordCompletedInspection(int &completedInspections) {
    completedInspections++;

    cout << "Inspection recorded." << endl;
}

/* Question 1:
 * Why does showProjectedCount not change the original count?
 *
 * Answer:
 * Because it uses pass-by-value, which creates a copy
 * of the variable. The original value stays the same.
 *
 * Question 2:
 * Why does recordCompletedInspection change the count?
 *
 * Answer:
 * Because it uses pass-by-reference (&), which allows
 * the function to change the original variable in main.
 *
 * Question 3:
 * What happens when the input is 4?
 *
 * Answer:
 * The projected count is 5, but the original stays 4.
 * After recording the inspection, the count becomes 5.
 */
