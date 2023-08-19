#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i = 0; i<n; i++) {
    cin>>a[i];
  }

  //Prestoring the data of the array in Hash array
  int hash[13] = {0};
  for(int i=0; i<n; i++) {
    hash[a[i]]++;
  }

  //Repeating for different no. of test cases
  int t;
  cin>>t;
  while(t--)
    {
      //Fetching data from Hash Array
      int num;
      cin>>num;
      cout<<hash[num]<<endl;
    }


  return 0;
}