//Detailed notes written in hardcopy & notion
// Problem Link - https://www.codechef.com/problems/FIX?tab=statement

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    
	    vector<int> arrA;
	    int data;
	    for(int i=0; i<n; i++){
	        cin>>data;
	        arrA.push_back(data);
	    }
	       
	   int mx = INT_MIN;
	    //find the max element
	    for(int i=0;i<n;i++) {
	        mx = max(mx,arrA[i]);
	    }
	    
	    set<int> ans;
	    
	    //detailed notes for the algorithm written in hardcopy and notion
	    //check its editorial, the explanation is great
	    for(int i=0; i<n; i++) {
	        //if the element is not present in the set
	       if(ans.find(arrA[i]) == ans.end()) {
	           cout<<arrA[i]<<" ";
	       }
	       //if the current element of array A is already present in the set
	       else {
	           cout<<mx<<" ";
	       }
	       
	       //inserting all array A elements as set will store unique values only
	       ans.insert(arrA[i]);
	    }
	    cout<<endl;
	    
	}
	return 0;
}