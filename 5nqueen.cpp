#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int board[][20], int row, int col, int n) {
    // Check the column above this position
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false; // Conflict with another queen in the same column
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false; // Conflict with another queen on the left diagonal
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return false; // Conflict with another queen on the right diagonal
        }
    }

    return true; // No conflict, position is safe
}

// Function to solve the N-Queens problem and print all solutions
void solveNQueens(int board[][20], int row, int n) {
    if (row == n) {
        // All queens are placed, print the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] ? "Q" : ".") << " ";
            }
            cout << endl;
        }
        cout << endl; // Separate different solutions
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            solveNQueens(board, row + 1, n);

            board[row][col] = 0; // Backtrack: remove the queen
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (n): ";
    cin >> n;

    int board[20][20] = {0}; // Initialize the board

    cout << "All possible solutions for " << n << "-Queens problem:\n";
    solveNQueens(board, 0, n); // Start solving from the first row

    return 0;
}
