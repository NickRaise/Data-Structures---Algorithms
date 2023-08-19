#include <bits/stdc++.h>
using namespace std;

void Selection_Sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min])
        min = j;
    }
    swap(a[min], a[i]);
  }
}

int main() {
  int n;
  cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Selection_Sort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}