// Problem: First and Last Position of an Element In Sorted Array

// You have been given a sorted array/list 'ARR' consisting of ‘N’ elements. You are also given an integer ‘K’.
// Now, your task is to find the first and last occurrence of ‘K’ in 'ARR'.

// Note:
// If ‘K’ is not present in the array, then the first and the last occurrence will be -1.
// ARR may contain duplicate elements.

// Sample Input 1:
// 8 2
// 0 0 1 1 2 2 2 2

// Sample Output 1: 
// 4 7


#include <bits/stdc++.h> 
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = -1, second = -1;
    int mid;
    int left = 0, right = n - 1;

    // Finding the first occurrence of the element
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == k) {
            first = mid; // Update the first occurrence
            right = mid - 1; // Search in the left half
        }
        else if (arr[mid] < k) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }

    // Reset the pointers for the second binary search
    left = 0;
    right = n - 1;

    // Finding the last occurrence of the element
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == k) {
            second = mid; // Update the last occurrence
            left = mid + 1; // Search in the right half
        }
        else if (arr[mid] < k) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }

    return {first, second};
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = firstAndLastPosition(arr, n, k);

    cout << "First Occurrence: " << result.first << endl;
    cout << "Last Occurrence: " << result.second << endl;

    return 0;
}
