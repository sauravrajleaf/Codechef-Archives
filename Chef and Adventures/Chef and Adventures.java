// The solution follows the logic as given in official editorial.
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
            
            long n, m, x, y;
            n = scanner.nextInt();
            m = scanner.nextInt();
            x = scanner.nextInt();
            y = scanner.nextInt();
            
            n--;
            m--;
            
            if(n % x == 0 && m % y == 0) System.out.println("Chefirnemo");
            else if((n - 1) % x == 0 && (m - 1) % y == 0 && Math.min(n, m) > 0) System.out.println("Chefirnemo");
            else System.out.println("Pofik");
            
            
        }
	}
}
