// Time Complexity - O(N * Log 10^9), The outer loop runs for N times & the inner nested loop for any value will run for max Log10^9 times.
// Detailed explanation of time complexity is documented in notion. 
// Space Complexity - O(N)


// The code implemented is based on the logic given in official editorial.

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    
	    vector<int> arr(n);
	    
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    long long ans = 0;
	    
	    for(int i = 0; i < n; i++) {
	        //if arr[i] == 1, that means for any other value pow(arr[i], arr[j]) <= arr[j]
	        if(arr[i] == 1) {
	            ans += n;//because it will form pairs with all the rest of the elements including itself so total of n
	            
	        }
	        
	        else {
	            long long powVal = 1;
	            
	            //This loop for any value will do max of 30 Iterations
	            for(int j = 0; j < n; j++) {
	                //For all other values - we know the limit of the values of array i.e, pow(2, 30)
    	            //So, lets raise any other value to its pow of 
    	            powVal *= arr[i];
    	            if(powVal > 1000000000) break;
    	            
    	            ans += (powVal <= arr[j]);
	            }
	        }
	    }
	    
	    cout << ans << endl;
	}

}
