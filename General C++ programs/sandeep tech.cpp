#include<iostream>
using namespace std;

bool isValid(int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

void print(int path[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (path[i][j] == 1) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

bool solve(int maze[5][5], int path[5][5], int x, int y) {
    if (x == 2 && y == 2) {
        print(path);
        return true;
    }

    int steps = maze[x][y];
    for (int i = 1; i <= steps; i++) {
        if (isValid(x, y + i)) {
            path[x][y + i] = 1;
            if (solve(maze, path, x, y + i)) {
                return true;
            }
            path[x][y + i] = 0; 
        }
    }
    for (int i = 1; i <= steps; i++) {
        if (isValid(x + i, y)) {
            path[x + i][y] = 1;
            if (solve(maze, path, x + i, y)) {
                return true;
            }
            path[x + i][y] = 0;
        }
    }

    return false;
}

int main() {
    int maze[5][5] = {
        {2, 2, 4, 4, 3},
        {3, 4, 4, 2, 2},
        {1, 1, 0, 3, 2},
        {3, 2, 2, 1, 1},
        {3, 3, 4, 3, 1}
    };
    int path[5][5] = {0}; 

    path[0][0] = 1;
    solve(maze, path, 0, 0);

    return 0;
}

