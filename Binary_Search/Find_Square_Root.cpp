// Problem: Square Root of a number

// You are given a positive integer 'n'
// Your task is to find and return its square root.
// If ‘n’ is not a perfect square, then return the floor value of sqrt(n).
// Try solving this in O(log(n)).

#include <iostream>

using namespace std;

// Function to find the floor square root of a given integer n
int floorSqrt(int n) {
    // Handle base cases where n is 0 or 1
    if (n == 0 || n == 1) return n;

    int left = 1, right = n; // Initialize the search range
    long long mid; // To store the middle value

    // Perform binary search to find the floor square root
    while (left <= right) {
        mid = left + (right - left) / 2; // Calculate middle value

        // If mid^2 is greater than n, search in the left half
        if (mid * mid > n) {
            right = mid - 1;
        }
        // If mid^2 is less than or equal to n and (mid+1)^2 is greater than n, then mid is the floor square root
        else if (mid * mid <= n && (mid + 1) * (mid + 1) > n) {
            return mid;
        }
        // Otherwise, search in the right half
        else {
            left = mid + 1;
        }
    }

    return -1; // If no valid floor square root is found
}

int main() {
    int n;
    cin >> n;

    int result = floorSqrt(n);
    if (result != -1) {
        cout << "Floor square root of " << n << " is: " << result << endl;
    } else {
        cout << "No valid floor square root found for " << n << endl;
    }

    return 0;
}
