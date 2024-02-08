#include <iostream>

const int MAX = 10000; // Assuming a maximum possible value for array elements

int countPairsWithSum(int arr[], int N, int K) {
    int frequency[MAX] = {0};

    int count = 0;

    for (int i = 0; i < N; ++i) {
        int complement = K - arr[i];

        // Check if complement exists in the frequency array
        if (complement >= 0 && complement < MAX) {
            count += frequency[complement];
        }

        // Increment the frequency of the current element
        frequency[arr[i]]++;
    }

    return count;
}

int main() {
    // Example
    int arr[] = {1, 5, 7,7};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 6;

    // Find and output the number of pairs
    int result = countPairsWithSum(arr, N, K);
    std::cout << "Number of pairs with sum " << K << ": " << result << std::endl;

    return 0;
}

