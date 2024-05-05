// The solution follows the logic as given in official editorial.
// Time Complexity - O(1)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
    int t; cin >> t;
    while(t--) {
       int n,m,x,y;
	    cin>>n>>m>>x>>y;
	 
	    n--;//Initially knowledge = 1
	    m--;//Initially power = 1
	    
	    if(n % x == 0 and m % y == 0)cout << "Chefirnemo"<< endl;
	    //1 2 1 100 - for such testcases min(n,m)>0 this condition is required
	    else if((n - 1) % x == 0 and (m - 1) % y == 0 and min(n, m) > 0)cout << "Chefirnemo" << endl;
	    else cout << "Pofik" << endl;
        
    }
}
