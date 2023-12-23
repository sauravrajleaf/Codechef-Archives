//Detailed notes written in hardcopy & notion
// Problem Link - https://www.codechef.com/problems/BEAUTYSTR

#include <bits/stdc++.h>

using namespace std;


bool checkValid(int n) {
    
    if(n == 0) {
        return true;
    }    
    
    
    if(n < 0) {
        return false;
    }
    
    return checkValid(n-4) || checkValid(n-3);
    
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--) {
        int n;cin>>n;
        if(checkValid(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
	
	return 0;
}
