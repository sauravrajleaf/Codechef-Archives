// This problem uses the concepts from pythagoras theorem. The code follows the code and logic provided in the official editorial.
// Time Complexity - O(1)
// Space Complexity - O(1)

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static int square(int x) {
        return x * x;    
    }
    
    public static void swap(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
    
    public static void order(int[] arr) {
        if(arr[0] > arr[2]) {
            swap(arr, 0, 2);
        }
        if(arr[1] > arr[2]) {
            swap(arr, 1, 2);
        }
        if(arr[0] > arr[1]) {
            swap(arr, 0, 1);
        }
    }
    
    private static String getSideClassification(int a, int b, int c) {
        int[] sides = {a, b, c};
        
        //First we have to order a, b, c in ascending order of their size
        order(sides);
        
        //After ordering lets check the condition using pythagoras theorem
        if(sides[0] == sides[1] || sides[1] == sides[2]) {
            return "Isosceles";
        }else {
            return "Scalene";
        }
    }
    
    private static String getAngleClassification(int a, int b, int c) {
        int[] sides = {a, b, c};
        //First we have to order a, b, c in ascending order of their size
        
        order(sides);
        
        //After ordering lets check the condition using pythagoras theorem
        if(sides[0] + sides[1] > sides[2]) {
            return " acute";
        }
        else if(sides[0] + sides[1] == sides[2]) {
            return " right";
        }
        else {
            return " obtuse";
        }
    }
    
    
    private static void solve(Scanner scanner, int subTaskId) {
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        int x3 = scanner.nextInt();
        int y3 = scanner.nextInt();
        
        int sideLen1 = square(x1 - x2) + square(y1 - y2);
        int sideLen2 = square(x2 - x3) + square(y2 - y3);
        int sideLen3 = square(x1 - x3) + square(y1 - y3);
        
        if(subTaskId == 1) {
            System.out.println(getSideClassification(sideLen1, sideLen2, sideLen3) + " triangle");
        }else {
            System.out.println(getSideClassification(sideLen1, sideLen2, sideLen3) + getAngleClassification(sideLen1, sideLen2, sideLen3) + " triangle");
        }
        
        
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
        Scanner scanner = new Scanner(System.in);
        
        int subTaskId = scanner.nextInt();
        int t = scanner.nextInt();
        
        while(t-- > 0) {
            solve(scanner, subTaskId);
        }
        
        scanner.close();
	}
}
