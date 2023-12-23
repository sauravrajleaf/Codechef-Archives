// Check editorial for better undersanding.

#include <iostream>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--) { 
	    long long x,y; cin>>x>>y;
	   // ideal array structure for minimum sum A=[1,−2,1,−2,1,…].
	   // 1ll+(x>(y+1)) - This part handles the case for y >= x-1 and 2y >= x-1
	   // if 2y < x-1 this case is handled by x-2*y, this gives us the count of all adjacent pairs of 1s at the endl
	    
        long long ans=max(x-2*y,1ll+(x>(y+1)));
        cout<<ans<<endl;
	}
	return 0;
}
