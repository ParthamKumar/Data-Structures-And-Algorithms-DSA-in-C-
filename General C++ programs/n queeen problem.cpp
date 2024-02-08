#include <iostream>

using namespace std;

bool isSafe(int row, int col, int board[][10], int n) {
    // Check for queens in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check for queens in the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check for queens in the right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printBoard(int board[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int board[][10], int n, int row) {
    if (row == n) {
        // All queens are placed successfully
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1; // Place queen
            solveNQueens(board, n, row + 1);
            board[row][col] = 0; // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    int board[10][10] = {0};

    cout << "Solutions for " << n << "-Queens problem:" << endl;
    solveNQueens(board, n, 0);

    return 0;
}

