// Time Complexity - O(1)
// Space Complexity - O(1)

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
            int s = scanner.nextInt();
            int v = scanner.nextInt();
            
            double ans = (2 / 3.0) * (s / (double) v);

            System.out.printf("%.16f\n", ans);
        }
	}
}
