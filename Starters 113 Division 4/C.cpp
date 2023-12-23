//Detailed notes written in hardcopy & notion
// Problem Link - https://www.codechef.com/problems/BEAUTYSTR

#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--) {
    int n;cin>>n;

    vector<int> arr;
    for(int i=0; i<n; i++) {
      int data;cin>>data;
      arr.push_back(data);
    }
    
    int cnt_zero = 0;
    int cnt_one = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) cnt_zero++;
        else cnt_one++;
    }
    
    
    

    cout<<min(cnt_one,cnt_zero)<<endl;
  }
	
	return 0;
}
