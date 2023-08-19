#include <iostream>
#include <vector>

using namespace std;

// Binary search function to find the index of target in the sorted vector
int search(vector<int> &nums, int target) {
    int mid;
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        mid = left + ((right - left) / 2); // Calculate the mid index to split the search range
        
        if (nums[mid] == target)
            return mid; // Target found at index 'mid'
        else if (nums[mid] < target) {
            left = mid + 1; // Adjust the left pointer to narrow the search range
        } else {
            right = mid - 1; // Adjust the right pointer to narrow the search range
        }
    }
    
    return -1; // Target not found in the array
}

int main() {
    vector<int> nums = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target;

    cout << "Enter the target number to search: ";
    cin >> target;

    int index = search(nums, target);

    if (index != -1) {
        cout << "Target found at index " << index << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
