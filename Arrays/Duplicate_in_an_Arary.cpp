// Problem: Duplicate in an Arary

// You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

// Sample Input 1:
// 7
// 6 3 1 5 4 3 2
// Sample Output 1:
// 3

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr) {
  int ans = 0;

  // XOR ing all the data of the array
  for (int i = 0; i < arr.size(); i++) {
    ans = ans ^ arr[i];
  }

  // Canceling the numbers in the array by XOR ing it with its own values from range 1 to (N-1)
  for (int i = 1; i < arr.size(); i++) {
    ans = ans ^ i;
  }

  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int temp;
    cin>>temp;
    a.push_back(temp);
  }
  cout << findDuplicate(a);
  return 0;
}