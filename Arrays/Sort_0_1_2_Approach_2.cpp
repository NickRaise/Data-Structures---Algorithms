// Problem: Sort 0 1 2
// You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

// Sample Input 1 :
// 6
// 0 1 2 2 1 0
  
// Sample Output 1 :
// 0 0 1 1 2 2

// This is solved using Dutch National Flag algorithm


#include <bits/stdc++.h> 
using namespace std;

// Function to sort an array of 0s, 1s, and 2s in non-decreasing order
void sort012(int *arr, int n)
{
    int one = 0, curr = 0, two = n - 1;

    while (curr <= two) {
        if (arr[curr] == 0) {
            swap(arr[curr], arr[one]); // Swap current element with the element at 'one'
            one++; // Increment 'one' index as we have placed a '0' element
            curr++; // Move to the next element
        } else if (arr[curr] == 1) {
            curr++; // Move to the next element (no swapping needed for '1')
        } else if (arr[curr] == 2) {
            swap(arr[curr], arr[two]); // Swap current element with the element at 'two'
            two--; // Decrement 'two' index as we have placed a '2' element
        }
    }   
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the sorting function
    sort012(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
