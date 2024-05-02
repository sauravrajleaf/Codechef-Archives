//The node:readline module provides an interface for reading data from a Readable stream (such as process.stdin) one line at a time.
const readline = require('node:readline');

// The process object provides information about, and control over, the current Node.js process.
// The process object is an instance of EventEmitter.
// Ths step is not mandatory as process module is globally available and we don't need to explicitly require it.
const { stdin: input, stdout: output } = require('node:process');

// Instances of the InterfaceConstructor class are constructed using the readlinePromises.createInterface() or 
// readline.createInterface() method. Every instance is associated with a single input Readable stream and a single output Writable stream. 
// The output stream is used to print prompts for user input that arrives on, and is read from, the input stream.
const rl = readline.createInterface({ input, output });


function promptForTestCases() {
    rl.question('', function(t) {
    // Using parseInt(t) in your JavaScript code is necessary to convert the input received from the user into an integer. 
    //This conversion is important because inputs received through readline are treated as strings by default, and you typically need to work with numbers in mathematical calculations or comparisons.
        t = parseInt(t);
        
        //Function call
        handleTestCases(t);
    });
}


function handleTestCases(testCaseCount) {
    //Handling edgecase
    if (testCaseCount === 0) {
        rl.close(); // Close the readline interface if there are no more test cases
        return;
    }

    rl.question('', function(input) {
        const results = processInput(input);
        
        // console.log(results);
        
        console.log(calculateMinimumSmoke(results));
        handleTestCases(testCaseCount - 1); // Recursively process the next test case
    });
}

function processInput(input) {
    //input is in the form of string
    //input is space separated so we are using split ' ' to 
    // The .split(' ') method in JavaScript is used to divide a string into an array of substrings based on a specified delimiter. 
    // string s = "1 2 3 4 5" input is space separated. So, after doing s.split(' ') => s = [1, 2, 3, 4]. Using space as the delimiter.
    // This method is particularly useful for parsing input where multiple values are provided in a single line separated by spaces.
    let [n, x, y] = input.split(' ').map(Number);
    
    //returning in the form of an array
    return { n, x, y };
}

// De-structuring the array in the function parameter
function calculateMinimumSmoke({ n, x, y }) {
    let smoke = 0;
    // The Math.floor() static method always rounds down and returns the largest integer less than or equal to a given number.
    // Here we are using floor because for the remaining people for n < 100 we will be covering that case explicitly
    //  it returns the result as an integer
    let buses = Math.floor(n / 100);
    // Equivalent Number of cars wrt buses
    let cars = buses * 25;

    let busSmoke = buses * x;
    let carSmoke = cars * y;
    
    //This case handles the case for all people in the batches of 100 should all go in cars or in buses
    smoke = Math.min(busSmoke, carSmoke);

    //Calculating for the remaining people < 100
    n %= 100;

    if (n > 0) {
        //Finding the required number of cars for the remaining people
        //Using ceil here as we want to make sure to calculate the value for every remaining person
        let remainingCars = Math.ceil(n / 4);
        let remainingCarSmoke = remainingCars * y;

        let remainingBusSmoke = x;

        //Adding the value to previous calculated smoke value
        smoke += Math.min(remainingBusSmoke, remainingCarSmoke);
    }
    return smoke;
}

//Execution starts from the function call
promptForTestCases();
