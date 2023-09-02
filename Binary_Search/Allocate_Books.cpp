// Problem: Allocate Books

// Given an array ‘arr’ of integer numbers,
// ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
// There are ‘m’ number of students, and the task is to allocate all the books to the students.

// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.

// You have to allocate the book to ‘m’ students such that the maximum number 
// of pages assigned to a student is minimum.

// return -1, if not possible

// Sample Input 1:
// 4 2
// 12 34 67 90

// Sample Output 1:
// 113


// Solution:

// Binary Search Allocation: Use binary search to efficiently find the minimum maximum pages allocated 
// to any student while ensuring contiguous allocation and minimum one book per student.


// * Define isPossible to check if allocation with a given maximum (mid) is feasible.
// * In findPages, perform binary search between left (max book pages) 
// and right (sum of all pages).
// * If allocation is possible, update ans and search in the left half; else, 
// search in the right half.
// * Return ans as the minimum maximum pages assigned.





#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int sum = 0;
    int studentCount = 1;
    for(int i = 0; i < n; i++) {
        if(sum + arr[i] <= mid) {
            sum += arr[i];
        }
        else {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    int mid;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(isPossible(arr, n, m, mid)) {
            right = mid - 1;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of books (n): ";
    cin >> n;
    cout << "Enter the number of students (m): ";
    cin >> m;
    
    vector<int> arr(n);
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = findPages(arr, n, m);
    
    if (result != -1) {
        cout << "The maximum number of pages that can be allocated is: " << result << endl;
    } else {
        cout << "It's not possible to allocate pages to all students within the given constraints." << endl;
    }
    
    return 0;
}
