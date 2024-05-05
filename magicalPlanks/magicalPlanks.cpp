// Even though the implementation is different from the official editorial. The logic still remains the same.
// We are counting the number of discontinuity for both the colors.
// For ex - 
// BBWWWB - 'B' occurs at 2 places, All the 'W' occurs at only 1 place
// WWBBBBBWW - 'W' occurs at 2 places, 'B' All of them are the same place

// The number of planks to be colored will be the one who has minimum dicontinuity. As if we paint one, all its 
// neighbors will be get automatically colored. So the more the less discontinuous neighbors one color has, the more 
// suitable it is for the being the solution.

// Time Complexity - O(1)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        
        //Count of dicontinuity
        int cnt_black = 0, cnt_white = 0;
        int len_black = 0, len_white = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B') {
                if(len_white != 0) {
                    cnt_white++;
                    len_white = 0;
                }
                len_black++;
            }
            
            if(s[i] == 'W') {
                if(len_black != 0) {
                    cnt_black++;
                    len_black = 0;
                }
                len_white++;
            }
        }
        if(len_black != 0) cnt_black++;
        else if(len_white != 0) cnt_white++;
        
        cout << min(cnt_black, cnt_white) << endl; 
        // cout << cnt_black << " " << cnt_white << endl;
    }
}
