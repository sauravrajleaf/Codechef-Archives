// Time Complexity - O(1)
// Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--) {
        long long l, r;
        cin >> l >> r;
        
        //This logic is based on the mathematical theorem that says that
        //Number of integers in the range [1,N] divisible by d is equal to floor(N/d).
        cout << (r / 3) - ((l - 1)/ 3) << endl;
    }
}
