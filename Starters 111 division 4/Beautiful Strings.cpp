//Detailed notes written in hardcopy & notion
// Problem Link - https://www.codechef.com/problems/BEAUTYSTR

#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    const int mod = 1e9 + 7;
	    
	    
	    
	    //make a freq array
	    
	    vector<int> freq(26,0);
	    

	    //index hashing
	    //count of a will be index 0
	    //count of b will be at index 1
	    //.....count of z will be at index 25
	    for(int i=0; i<n; i++) {
	        freq[s[i]-'a']++;//if s[i] == b , s[i] - 'a' == 1
	    }
	   
	   int ans = 1;
	    for(int i=0; i<26; i++) {
	        if(freq[i]!=0) {
	            ans =( 1LL*ans*(freq[i]+1))%mod;
	        }
	    }
	    ans--; //remove the empty string rearrangement count
	    
	    //if by any chance the value of ( 1LL*ans*(f[i]+1)) was 1e9+7 in the last iteration
	    //then ans = 0 (mod value)
	    //and ans-- will give ans =  -1
	    //this if condition handles that edgecase
	    if(ans<0) ans+= mod;
	    
	    cout<<ans<<endl;
	}
	
	return 0;
}
