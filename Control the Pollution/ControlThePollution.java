// This solution is based on the logic given in official editorial.
// Time Complexity - O(1)
// Space Complexity - O(1)

import java.util.*;
import java.lang.*;
import java.io.*;

//The filename and the class name should be the same otherwise it throws error
//ClassNotFoundException when you try to run the program.
class ControlThePollution
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes 
        //Scanner for Input: Java uses the Scanner class for handling input. 
        //It is part of the java.util package and provides methods like nextInt() to read integers 
        //from standard input.
		Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // Number of test cases

        while (t-- > 0) {
            int n = scanner.nextInt(); // Number of people
            int x = scanner.nextInt(); // Smoke per bus
            int y = scanner.nextInt(); // Smoke per car

            int smoke = 0;

            // Calculate the number of buses and cars if people go in batches of 100
            int buses = n / 100;
            int cars = buses * 25; // Since 1 bus = 100 people and 1 car = 4 people

            // Calculate the total smoke for buses and cars
            int busSmoke = buses * x;
            int carSmoke = cars * y;

            // Find the minimum smoke for batches of 100
            smoke = Math.min(busSmoke, carSmoke);

            // Calculate the number of people remaining after maximum batches of 100
            n = n % 100;

            if (n > 0) {
                // Calculate number of cars needed for the remaining people
                // Using ceil to ensure all people are transported even if n % 4 != 0
                // In Java, where Math.ceil always returns a double regardless of the input type
                // Math.ceil in Java returns a double so type conversion to int is necessary
                int remainingCars = (int) Math.ceil(n / 4.0);
                int remainingCarSmoke = remainingCars * y;

                // Only one bus needed for the remaining people, as n < 100
                int remainingBusSmoke = x;

                // Find the minimum smoke for the remaining people
                smoke += Math.min(remainingBusSmoke, remainingCarSmoke);
            }

            System.out.println(smoke);
        }

        scanner.close();

	}
}
