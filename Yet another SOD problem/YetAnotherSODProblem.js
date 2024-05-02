// Time Complexity - O(1)
// Space Complexity - O(1)

// New Concept - BigInt -> https://blog.logrocket.com/how-to-use-javascript-bigint/#:~:text=BigInt%20vs.,-Number&text=It%20includes%20values%20that%20range,MAX_SAFE_INTEGER%20and%20Number.
// your code goes here

//The node:readline module provides and interface for reading data from a readable stream
const readline = require("node:readline");

//The process object provides information about, and control over the current nodejs process
//This process is not mandatory and can be skipped using other syntaxes as 
//process module is globally avaialable and we don't need to explicitly require it.
const { stdin : input, stdout : output} = require("node:process");

//Instances of the InterfaceConstructor class are constructed using the readlinePromises.createInterface() or readline.createInterface() method.
//Every instance is associated with a single input stream and a single output writable stream.
const rl = readline.createInterface({input, output});

function promptForTestCases() {
    
    //Passing a callback function inside
    rl.question('', function(t) {
        t = parseInt(t);
        // console.log("t", t);
        //This function will take care of each testcase
        handleTestCases(t);
    })
}

function handleTestCases(testCaseCount) {
    //Handling edgecase
    if(testCaseCount == 0) {
        //Close the readline interface if there are no more test cases
        rl.close();
        
        return;
    }
    
    //Using the input stream provided by the process object
    rl.question('', function(input) {
        
        //processInput function will take care of converting the input into the required types
        const results = processInput(input);
        
        console.log(countDivisibleBy3(results).toString());
        
        //Recursively process the next test case
        handleTestCases(testCaseCount - 1);
    })
}

function processInput(input) {
    //current input is in the form of the string
    //we need to convert the given input into number
    //given input is space separated
    //Since we are dealing here with very large numbers we will be using Js BigInt which
    //ranges from > 2^53 and  < -2^53
    let [l, r] = input.split(' ').map(BigInt);
    
    //returing the result in the form of an array
    return {l, r};
}


function countDivisibleBy3({l, r}) {
    // console.log(l, r);
    //Converting the number to BigInt to perfrom arithmetic operations as
    //It can have precision errors if both are not of the same data types
    return (r / BigInt(3)) - ((l - BigInt(1)) / BigInt(3));
}

//Calling the function to execute the code
promptForTestCases();
