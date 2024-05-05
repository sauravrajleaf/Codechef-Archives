// The solution follows the logic as given in official editorial.
// Time Complexity - O(1)
// Space Complexity - O(1)


// your code goes here
const readline = require("node:readline");

const { stdin : input, stdout : output } = require("node:process");

const rl = readline.createInterface({input, output});

function promptForTestCases() {
    
    rl.question('', function(t) {
        t = parseInt(t);
        
        handleTestCases(t);
    })
}

function handleTestCases(testCaseCount) {
    if (testCaseCount === 0) {
        rl.close();
        return;
    }
    
    rl.question('', function(input) {
        
        // console.log(testCaseCount, input);
        const nums = processInput(input);
        
        console.log(findAnswer(nums)); // Print the result for the current test case
        
        handleTestCases(testCaseCount - 1); // Then handle the next test case
    })
}


function processInput(input) {
    let [n, m, x, y] = input.split(' ').map(Number);
    // console.log("hey ",n, m, x, y);
    return {n, m, x, y};
}

function findAnswer({n, m, x, y}) {
        n--;//Initially knowledge = 1
	    m--;//Initially power = 1
	   // console.log("hey ",n, m, x, y);
	    if(n % x == 0 && m % y == 0)return "Chefirnemo";
	    //1 2 1 100 - for such testcases min(n,m)>0 this condition is required
	    else if((n - 1) % x == 0 && (m - 1) % y == 0 && Math.min(n, m) > 0)return "Chefirnemo";
	    else return "Pofik";
}

promptForTestCases();