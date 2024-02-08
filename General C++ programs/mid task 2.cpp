#include <iostream>
using namespace std;

const int N = 5; // Size of the maze

// Function to print the maze with the path highlighted
void printMaze(int maze[N][N], char path[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (path[i][j] == 'X') {
                cout << "X ";
            } else {
                cout << maze[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Function to check if a given cell is within the boundary of the maze
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Function to find a path from (x, y) to the middle cell using recursion
bool findPath(int maze[N][N], char path[N][N], int x, int y) {
    // If we reached the middle cell, return true
    if (x == 2 && y == 2) {
        path[x][y] = 'X'; // Mark the middle cell as part of the path
        return true;
    }

    int steps = maze[x][y];

    // Try moving right
    for (int i = 1; i <= steps; i++) {
        if (isValid(x, y + i) && findPath(maze, path, x, y + i)) {
            path[x][y] = 'X'; // Mark the current cell as part of the path
            return true;
        }
    }

    // Try moving down
    for (int i = 1; i <= steps; i++) {
        if (isValid(x + i, y) && findPath(maze, path, x + i, y)) {
            path[x][y] = 'X'; // Mark the current cell as part of the path
            return true;
        }
    }

    // If no valid move, backtrack
    return false;
}

int main() {
    int maze[N][N] = {
        {2, 2, 4, 4, 3},
        {3, 4, 4, 2, 2},
        {1, 1, 0, 3, 2},
        {3, 2, 2, 1, 1},
        {3, 3, 4, 3, 1}
    };

    char path[N][N] = {' '}; // Initialize the path array with spaces

    cout << "Maze:" << endl;
    printMaze(maze, path);

    if (findPath(maze, path, 0, 0)) {
        cout << "Path Found:" << endl;
        printMaze(maze, path); // Print the maze with the path highlighted
    } else {
        cout << "No Path Found." << endl;
    }

    return 0;
}

