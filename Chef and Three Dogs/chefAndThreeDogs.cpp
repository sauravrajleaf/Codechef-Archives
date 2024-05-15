// Time Complexity - O(1)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--) {
        int s, v;
        cin >> s >> v;
        
        double ans = (2 / 3.0) * (s / (double)v);
        
        // printf("%.16lf\n", ans);
        
        cout << fixed << setprecision(16) << ans << endl;
    }
    
    return 0;
}
