#include <bits/stdc++.h>
using namespace std;

void Insertion_Sort(int a[], int n) {
  for(int i=0;i<n;i++) {
    int index = i;
    while(index>0 && a[index]<a[index-1]) {
      swap(a[index],a[index-1]);
      index--;
    }
  }
}

int main() {
  int n;
  cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Insertion_Sort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}