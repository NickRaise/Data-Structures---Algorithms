// Problem: Sort 0 1

// You have been given an integer array/list(ARR) of size N that contains only integers, 0 and 1. Write a function to sort this array/list. Think of a solution which scans the array/list only once and don't require use of an extra array/list.

// Sample Input 1:
// 8
// 1 0 1 1 0 1 0 1
  
// Sample Output 1:
// 0 0 0 1 1 1 1 1



#include <iostream>
using namespace std;

void sortZeroesAndOne(int input[], int size) {
    int l = 0, r = size - 1;
    while (l < r) {
        // Move l to the right until it reaches a non-zero element
        while (input[l] == 0 && l < r) {
            l++;
        }
        // Move r to the left until it reaches a non-one element
        while (input[r] == 1 && l < r) {
            r--;
        }
        
        // Swap input[l] and input[r] to move zeros to the left and ones to the right
        if (l < r) {
            swap(input[l], input[r]);
            l++;
            r--;
        }
    }
}

int main() {
    int size;
    cin >> size;
    
    int input[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }
    
    sortZeroesAndOne(input, size);
    
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }
    
    return 0;
}
