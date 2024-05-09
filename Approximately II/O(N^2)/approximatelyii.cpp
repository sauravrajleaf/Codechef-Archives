#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int k; cin >> k;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        //int
        int min_val = INT_MAX, cnt_min = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // cout << "min_val " << min_val << endl;
                if(abs(arr[i] + arr[j] - k) < min_val) {
                    cnt_min = 1;
                    min_val = min(min_val, abs(arr[i] + arr[j] - k));
                    // cout << "min_val " << min_val << endl;

                }
                else if(abs(arr[i] + arr[j] - k) == min_val) {
                    cnt_min++;
                }
                
            }
        }
        
        cout << min_val << " " << cnt_min << endl;
    }
}