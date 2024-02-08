#include <iostream>
using namespace std;

int main() {
    int arr[][4] = {
        {2, 3, 2, 8},
        {9, 4, 54, 5},
        {1, 7, 4, 11},
        {6, 1, 9, 2}
    };

    int row = 4;
    int col = 4;

    for (int i = 0; i < col; i++) {  // Loop over each column
        for (int j = 0; j < row - 1; j++) {  // Bubble sort for the current column
            for (int k = 0; k < row - j - 1; k++) {
                if (arr[k][i] > arr[k + 1][i]) {
                    // Swap elements in the current column
                    int temp = arr[k][i];
                    arr[k][i] = arr[k + 1][i];
                    arr[k + 1][i] = temp;
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

