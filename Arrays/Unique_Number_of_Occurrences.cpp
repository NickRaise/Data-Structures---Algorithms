// Problem: Unique Number of Occurrences

// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

// Constraints:
// 1 <= arr.length <= 1000
// -1000 <= arr[i] <= 1000

  
#include <bits/stdc++.h>
using namespace std;

// Function to check if the occurrences of elements in the array are unique
bool uniqueOccurrences(vector<int> &arr) {
    // Create a hash map to store the frequency of each element
    unordered_map<int, int> mpp;

    // Count the frequency of each element
    for (auto it : arr) {
        mpp[it]++;
    }

    // Create a hash set to keep track of unique frequencies
    unordered_set<int> s;

    // Iterate through the frequency map and check for uniqueness
    for (auto it : mpp) {
        if (s.count(it.second)) {
            // If the frequency is already present in the set, it's not unique
            return false;
        } else {
            // Otherwise, add the frequency to the set
            s.insert(it.second);
        }
    }

    // If all frequencies are unique, return true
    return true;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a;

    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    // Check if occurrences of elements are unique and display the result
    bool result = uniqueOccurrences(a);
    if (result) {
        cout << "Occurrences of elements are unique.";
    } else {
        cout << "Occurrences of elements are not unique.";
    }

    return 0;
}
