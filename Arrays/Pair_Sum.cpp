// Problem: Pair Sum

// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

// Note:-
// Each pair should be sorted i.e the first value should be less than or equals to the second value. 

// Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

// Sample Input 1:
// 5 5
// 1 2 3 4 5
// Sample Output 1:
// 1 4
// 2 3

// Sample Input 2:
// 5 0
// 2 -3 3 3 -2
// Sample Output 2:
// -3 3
// -3 3
// -2 2

#include <bits/stdc++.h>
using namespace std;

// Function to find pairs in the array that sum up to a given value 's'
vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;

    // Iterate through the array to find pairs
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if ((arr[i] + arr[j]) == s) {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j])); // Push the smaller element first
                temp.push_back(max(arr[i], arr[j])); // Push the larger element next
                ans.push_back(temp); // Add the pair to the answer vector
            }
        }
    }

    // Sort the answer vector for consistent output
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int s;
    cout << "Enter the target sum: ";
    cin >> s;

    vector<int> a;

    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    // Find and display pairs that sum up to 's'
    vector<vector<int>> ans = pairSum(a, s);
    for (auto it : ans) {
        for (auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
