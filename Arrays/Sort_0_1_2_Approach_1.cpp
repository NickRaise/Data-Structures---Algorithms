// Problem: Sort 0 1 2
// You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

// Sample Input 1 :
// 6
// 0 1 2 2 1 0
  
// Sample Output 1 :
// 0 0 1 1 2 2


#include <bits/stdc++.h> 

using namespace std;

// Function to sort an array of 0s, 1s, and 2s in non-decreasing order
void sort012(int *arr, int n)
{
   // Count the occurrences of 0s, 1s, and 2s in the array
   int zero = 0, one = 0, two = 0;

   // Count the occurrences of each element in the array
   for(int i = 0; i < n; i++) {
      if(arr[i] == 0) zero++;
      else if(arr[i] == 1) one++;
      else two++;
   }

   // Overwrite the array with the sorted elements
   for(int i = 0; i < n; i++) {
      if(zero > 0) {
         arr[i] = 0; // Fill with 0 as long as there are 0s remaining
         zero--;
      }
      else if(one > 0) {
         arr[i] = 1; // Fill with 1 as long as there are 1s remaining
         one--;
      }
      else if(two > 0) {
         arr[i] = 2; // Fill with 2 as long as there are 2s remaining
         two--;
      }
   }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the sorting function
    sort012(arr, n);

    // Print the sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
