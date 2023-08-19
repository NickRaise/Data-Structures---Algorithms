// Problem: Intersection Of Two Sorted Arrays

// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both
// these arrays are sorted in non-decreasing order. You have to find the
// intersection of these two arrays. Intersection of two arrays is an array that
// consists of all the common elements occurring in both arrays.

// Sample Input 1 :
// 6 4
// 1 2 2 2 3 4
// 2 2 3 3

// Sample Output 1 :
// 2 2 3

#include <bits/stdc++.h>
using namespace std;

// Function to find the intersection of two sorted arrays
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    vector<int> ans;
    int i = 0, j = 0;

    // Compare elements from both arrays while neither array is fully traversed
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++; // Move to the next element in arr1
        } else if (arr1[i] > arr2[j]) {
            j++; // Move to the next element in arr2
        } else if (arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]); // Found a common element, add it to the answer
            i++; // Move to the next element in arr1
            j++; // Move to the next element in arr2
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;
    cout << "Enter the size of the second array: ";
    cin >> m;

    vector<int> a1, a2;

    // Input elements for the first array
    cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a1.push_back(temp);
    }

    // Input elements for the second array
    cout << "Enter elements of the second array: ";
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        a2.push_back(temp);
    }

    // Find and display the intersection of the two arrays
    vector<int> ans = findArrayIntersection(a1, n, a2, m);
    cout << "Intersection of the arrays: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}
