// Problem: Find All Duplicates in an Array

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

#include <bits/stdc++.h>
using namespace std;

// Function to find duplicates in an array
vector<int> findDuplicates(vector<int> &nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        // Calculate the index to access based on the current element's value
        int Index = abs(nums[i]) - 1;

        // Mark the element at the calculated index as seen by making it negative
        nums[Index] = -nums[Index];

        // If the element at the calculated index is already negative,
        // then it has been seen before, indicating a duplicate
        if (nums[Index] > 0) {
            ans.push_back(Index + 1); // Add the value to the result vector
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;

    // Input array elements
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    // Find and display duplicate elements in the array
    vector<int> ans = findDuplicates(a);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}


