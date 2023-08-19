#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i =0; i<n;i++) {
    cin>>a[i];
  }

  //PreStoring
  map <int,int> mp;
  for(int i=0;i<n;i++) {
    mp[a[i]]++;
  }

  //Test cases
  int t;
  cin>>t;
  while(t--) {
    int num;
    cin>>num;
    cout<<mp[num]<<endl;
  }
  
  return 0;
}