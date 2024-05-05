// Time Complexity - O(1)
// Space Complexity - O(1)

// New Concept - 
// Taking string inputs in java
// Traversing string and using accessing a char in string using charAt(index)

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        
        while(t-- > 0) {
            int n = scanner.nextInt();
            String s = scanner.next();
            
            //Count of dicontinuity
            int cnt_black = 0, cnt_white = 0;
            int len_black = 0, len_white = 0;
            
            for(int i = 0; i < n; i++) {
                if(s.charAt(i) == 'B') {
                    if(len_white != 0) {
                        cnt_white++;
                        len_white = 0;
                    }
                    len_black++;
                }
                
                if(s.charAt(i) == 'W') {
                    if(len_black != 0) {
                        cnt_black++;
                        len_black = 0;
                    }
                    len_white++;
                }
            }
            if(len_black != 0) cnt_black++;
            else if(len_white != 0) cnt_white++;
            
            System.out.println(Math.min(cnt_black, cnt_white)); 
            // cout << cnt_black << " " << cnt_white << endl;
        }
	}
}
