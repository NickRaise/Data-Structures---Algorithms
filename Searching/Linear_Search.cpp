#include <iostream>
#include <vector>

using namespace std;

// Linear search function to find the index of target in the vector
int linearSearch(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i; // Target found at index 'i'
        }
    }
    return -1; // Target not found in the array
}

int main() {
    vector<int> nums = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target;

    cout << "Enter the target number to search: ";
    cin >> target;

    int index = linearSearch(nums, target);

    if (index != -1) {
        cout << "Target found at index " << index << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
