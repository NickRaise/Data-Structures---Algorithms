// Problem: Peak Index in a Mountain Array

// An array arr is a mountain if the following properties hold: arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

// Example 1:
// Input:
// 7
// 1 3 5 4 2 0 -1

// Output: Peak element found at index: 2 with value: 5



#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int low = 0, high = arr.size() - 1; // Initialize the search range: [0, n-1]
    int mid = low + (high - low) / 2;    // Calculate the initial middle index

    // Perform binary search as long as the range [low, high] is valid
    while (low < high) {
        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1; // Move the low pointer to the right of mid
        } else {
            high = mid;    // Move the high pointer to mid or left of mid
        }

        mid = low + (high - low) / 2; // Calculate the new middle index
    }
    
    return mid; // Return the index of the peak element
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int peakIndex = peakIndexInMountainArray(arr);
    
    cout << "Peak element found at index: " << peakIndex << " with value: " << arr[peakIndex] << endl;
    
    return 0;
}
