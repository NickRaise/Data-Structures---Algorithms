// Problem: Find Unique

// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
// You need to find and return that number which is unique in the array/list.

// Sample Input 1:
// 9
// 1 3 1 3 6 6 7 10 7
  
// Sample Output 2:
// 10


#include <bits/stdc++.h>
using namespace std;

// Function to find the unique element in an array where all other elements appear twice
int findUnique(int *arr, int size) {
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i]; // Using bitwise XOR to find the unique element
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Find and display the unique element in the array
    cout << "The unique element is: " << findUnique(a, n);

    return 0;
}
