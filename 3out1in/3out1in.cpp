// Time Complexity - O(N * LogN + q), where q is the number of queries
// Space Complexity - O(N), Space used up by both the multisets

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        
        int a[n];//array of size n
        
        //using range based loop
        for(auto &x : a) {
            cin >> x;
        }
        
        //ans array will store the pre-computed answer for each prefix length or odd length of given array
        long long ans[n];
        
        
        //multiset - contains elements in sorted order but not unique(can contain duplicates)
        //multiset - supports fast insertion, deletion and lookup all in LogN
        //s1 - will contain the (n - 1)/2 elements which should be summed and subtracted, s1 will contain min elements
        //s2 - will contain the (n + 1)/2 elements which has to be summed - s2 will contain the max elements
        multiset<int> s1, s2;
        
        long long sum1 = 0, sum2 = 0;//the sum can be large so using long long
        
        int i = -1;
        
        //iterating over the array
        // O(N)
        for(auto u : a) {
            // i - denotes the index or prefix length for the answer array
            i++;
            
            //inserting the value first into s1
            s1.insert(u);//logN
            
            sum1 += u;//adding the value to sum1
            
            //s1 size should always be smaller than s2 size
            //because at any instance, s1 should contain (n - 1)/2 elements and s2 should contain (n + 1)/2
            //So, size of s1 should always be lesser than size of s2
            while(s1.size() >= s2.size()) {
                int x = *s1.rbegin();//taking the last element from s1 or the max element from s1
                s1.erase(s1.find(x));//erasing the last element or the max element LogN
                
                s2.insert(x);//inserting the max element of s1 into s2
                
                sum1 -= x;//subtracting the deleted value from sum1
                sum2 += x;//adding the inserted value to sum2
                
            }
            
            //When both s1 and s2 is not empty
            //And when the last element of s1 is greater than the first element of s2 enter inside the loop
            while(s1.size() && s2.size() && *s1.rbegin() > *s2.begin()) {
                int x1 = *s1.rbegin();//taking the last element from s1 which is larger
                int x2 = *s2.begin();//taking the first element from s2 which is smaller
                
                s1.erase(s1.find(x1));//erasing the last element from s1 LogN
                s2.erase(s2.find(x2));//erasing the first element from s2
                
                s1.insert(x2);//inserting the smaller element of s2 into s1
                s2.insert(x1);//inserting the larger element of s1 into s2
                
                sum1 += x2 - x1;//x2 - x1 will be negative, so subtracting the value taken out from s1
                sum2 += x1 - x2;//x1 - x2 will be positive, so summing the extra value added to s2
            }
            
            //For index of length i or for prefix of length i, we have got the answer
            ans[i] = sum2 - sum1;//difference of the values to be added(+ signs) and values to subtracted(- signs)
        }
        
        // O(q)
        //For each query we have to log the answer
        while(q--) {
            int j;//array index
            cin  >> j;
            j--;//as we are having 0-based indexing
            
            cout << ans[j] << " ";
            
        }
        cout << endl;
        
        
    }
}
