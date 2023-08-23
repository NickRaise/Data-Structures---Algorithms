// You have been given a sorted array/list 'arr' consisting of 'n' elements. 
// You are also given an integer 'k'.

// Now the array is rotated at some pivot point unknown to you.

// Now, your task is to find the index at which ‘k’ 
// is present in 'arr'.

// Sample Input 1:
// 4 3
// 8 9 4 5
// Sample Output 1:
// -1 

// Sample Input 2:
// 4 3
// 2 3 5 8
// Sample Output 2:
// 1




#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search on a sorted array
int binary_search(vector<int>& arr, int left, int right, int k) {
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Function to search for an element in a rotated sorted array
int search__Approach1(vector<int>& arr, int n, int k) {
    int left = 0, right = n - 1;
    int mid;

    // Perform a modified binary search to find the pivot index
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // The pivot index indicates the point where the array is rotated
    int pivot_index = left;

    // Reset the pointers for binary search on the two segments
    right = n - 1;
    left = 0;
    int ans;

    // Determine which segment to search based on pivot and target value
    if (arr[pivot_index] <= k && k <= arr[right]) {
        // Search in the right segment
        ans = binary_search(arr, pivot_index, right, k);
    } else {
        // Search in the left segment
        ans = binary_search(arr, left, pivot_index - 1, k);
    }

    return ans;
}

int search__Approach2(vector<int>& arr, int n, int k)
{
    int left = 0, right = n - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;

        // If the middle element is equal to the target 'k', return its index
        if (arr[mid] == k) {
            return mid;
        }
        else if (arr[mid] >= arr[left]) {
            // If the left half of the array is sorted

            // Check if the target 'k' lies within the sorted range of the left half
            if (arr[left] <= k && k <= arr[mid - 1]) {
                right = mid - 1; // Update 'right' to search in the left half
            }
            else {
                left = mid + 1; // Update 'left' to search in the right half
            }
        }
        else {
            // If the right half of the array is sorted

            // Check if the target 'k' lies within the sorted range of the right half
            if (arr[mid] <= k && k <= arr[right]) {
                left = mid + 1; // Update 'left' to search in the right half
            }
            else {
                right = mid - 1; // Update 'right' to search in the left half
            }
        }
    }
    return -1; // Return -1 if the target 'k' is not found in the array
}



int main() {
    int n, k;
    cin >> n;

    cin >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int index = search__Approach1(arr, n, k);
    if (index != -1) {
        cout << "Element " << k << " found at index " << index << endl;
    } else {
        cout << "Element " << k << " not found in the array." << endl;
    }
    
    return 0;
}
