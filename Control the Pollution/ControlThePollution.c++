// This solution is based on the logic given in official editorial.
// Time Complexity - O(1)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; 
	cin >> t;
	
	while(t--) {
	    int n; cin >> n;
	    int x, y;
	    cin >> x >> y;
	    
	    int smoke = 0;
	    
	    //For batches of 100
	    int buses = n / 100;//Count the number of buses if all go into bus
	    
	    //Count of cars for the same n will be 25 times of number of buses as
	    //1 bus can carry 100 people and 1 car can carry 4,
	    //Number of cars equivalent for n people = 25* number of buses
	    int cars = buses * 25;//Count the number of cars needed if all go into car
	    
	    //Calculate all the bus smoke
	    int busSmoke = buses * x;
	    
	    //Calculate all the car smoke
	    int carSmoke = cars * y;
	    
	    //Find the minimum smoke, if the people in batches of 100, all go into buses or all go into cars
	    smoke = min(busSmoke, carSmoke);
	    
	    //Find the number of people left after we have cleared all the people in batches of 100
	    //or after n >= 100 has been cleared
	    n = n % 100;
	    
	    //For all the people left after we have completed batches of 100
	    if(n > 0) {
	        //Reason for writing 4.0 and not just 4?
            //The key takeaway is that using 4.0 causes the division to retain its fractional part, which can change the result of ceil, potentially leading to a higher value in cars compared to using integer division where the fractional part is lost before ceil is applied.
	        
	        //Count the number of cars needed for the remaining people
	        int cars = ceil(n / 4.0);
	        
	        int carSmoke = cars * y;
	        
	        // We will be needing just one bus for the remaining people as n < 100
	        int busSmoke = x;
	        
	        //Find the minimum b/w the cars smoke and bus smoke for the remaining people
	        smoke += min(busSmoke, carSmoke);//Add the value to previous value
	    }
	    
	    cout << smoke << endl;
	}
	
	return 0;

}
