#include <bits/stdc++.h>
using namespace std;

void Bubble_Sort(int a[], int n) {
  for(int i=0;i<n-1;i++) {
    bool flag = true;
    for(int j=0;j<n-i-1;j++) {
      if(a[j]>a[j+1]) {
        swap(a[j],a[j+1]);
        flag = false;
      }
    }
    if (flag) break;
  }
}

int main() {
  int n;
  cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Bubble_Sort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}