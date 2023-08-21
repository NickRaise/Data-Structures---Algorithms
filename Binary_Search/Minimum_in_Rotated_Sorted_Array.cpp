// Problem: Find minimum in Rotated Sorted Array

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
// For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the 
// array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements,
// return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Example 2:

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.


#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum element in a rotated sorted array
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int mid = left + (right - left) / 2;

    // Perform binary search until left and right pointers meet
    while (left < right) {
        mid = left + (right - left) / 2;

        // Check if the middle element is greater than or equal to the rightmost element
        if (nums[mid] >= nums[right]) {
            // If true, the minimum element lies in the right half, so update left pointer
            left = mid + 1;
        } else {
            // If false, the minimum element lies in the left half, so update right pointer
            right = mid;
        }

        // Update mid for the next iteration
        mid = left + (right - left) / 2;
    }

    // At this point, left and right pointers meet at the minimum element
    return nums[left];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int minElement = findMin(nums);
    cout << "The minimum element in the rotated sorted array is: " << minElement << endl;

    return 0;
}
