#include <iostream>
using namespace std;
int main() {
  //String Initialization
  string s;
  cin>>s;
  
  //Prestoring of data in Hash
  int hash[26] = {0};
  for(int i =0;i<s.size();i++) {
    hash[s[i]-'a']++;
  }

  //Test cases
  int t;
  cin>>t;
  while(t--) {
    char c;
    cin>>c;
    cout<<hash[c-'a']<<endl;
  }  
  return 0;
}