#include <iostream>

using namespace std;

// Non-recursive (iterative) Fibonacci function
void fibonacci_iterative(int n) {
    if (n <= 0) return;

    unsigned long long a = 0, b = 1; // Initialize the first two Fibonacci numbers

    cout << "Fibonacci Sequence (Iterative): ";
    for (int i = 0; i < n; ++i) {
        cout << a << " ";
        unsigned long long next = a + b; // Calculate the next Fibonacci number
        a = b; // Move to the next number
        b = next;
    }
    cout << endl;
    cout << "Time Complexity: O(n)\n";     // Linear time complexity
    cout << "Space Complexity: O(1)\n";   // Constant space complexity
}

// Recursive Fibonacci function
void fibonacci_recursive(int n, int a = 0, int b = 1) {
    if (n <= 0) return;
    cout << a << " "; // Print the current Fibonacci number
    fibonacci_recursive(n - 1, b, a + b); // Recursive call for the next Fibonacci number
}

int main() {
    int n, choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Calculate Fibonacci using Iterative Method\n";
        cout << "2. Calculate Fibonacci using Recursive Method\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of Fibonacci numbers to calculate: ";
                cin >> n;
                fibonacci_iterative(n);
                break;
            case 2:
                cout << "Enter the number of Fibonacci numbers to calculate: ";
                cin >> n;
                cout << "Fibonacci Sequence (Recursive): ";
                fibonacci_recursive(n);
                cout << endl;
                cout << "Time Complexity: O(2^n)\n";  // Exponential time complexity
                cout << "Space Complexity: O(n)\n";  // Due to recursion stack
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
