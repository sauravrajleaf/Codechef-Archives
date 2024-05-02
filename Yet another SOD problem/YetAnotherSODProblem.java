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
        
        //Scanner for Input: Java uses the Scanner class for handling input
        //It is a part of java.util package
        //Methods like nextInt() to read integers from standard input
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        
        while(t-- > 0) {
            //Taking long inputs in java
            //long	8 bytes	Stores whole numbers from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
            long l = scanner.nextLong();
            long r = scanner.nextLong();
            
            System.out.println((r / 3) - (l - 1) / 3);
            
        }
        
	}
}
