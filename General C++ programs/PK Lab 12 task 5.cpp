#include<iostream>

using namespace std;

class IslandSearch {
public:
    int countIslands(int arr[50][50], int row, int col) {
        int count = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (arr[i][j] == 1) {
                    visitIsland(arr, i, j, row, col);
                    count = count + 1;
                }
            }
        }
        return count;
    }

    void visitIsland(int arr[50][50], int x, int y, int row, int col) {
        if (x < 0 || x >= row || y < 0 || y >= col || arr[x][y] != 1)
            return;

        arr[x][y] = 2;
        visitIsland(arr, x + 1, y, row, col);
        visitIsland(arr, x, y + 1, row, col);
        visitIsland(arr, x - 1, y, row, col);
        visitIsland(arr, x, y - 1, row, col);

        visitIsland(arr, x + 1, y + 1, row, col);
        visitIsland(arr, x - 1, y - 1, row, col);
        visitIsland(arr, x - 1, y + 1, row, col);
        visitIsland(arr, x + 1, y - 1, row, col);
    }
};

int main() {
    int grid[50][50] = {{0, 1}, {1, 0}, {1, 1}, {1, 0}};
    int row = 4;
    int col = 2;

    IslandSearch islandSearch;

    int num = islandSearch.countIslands(grid, row, col);

    cout << num;

    return 0;
}

