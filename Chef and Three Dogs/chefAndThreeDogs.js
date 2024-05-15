// Time Complexity - O(1)
// Space Complexity - O(1)

// your code goes here
const readline = require("node:readline");

const { stdin: input, stdout: output } = require("node:process");

const rl = readline.createInterface({ input });

function promptForTestCases() {
  rl.question("", function (t) {
    t = parseInt(t);

    handleTestCases(t);
  });
}

function handleTestCases(testCaseCount) {
  if (testCaseCount === 0) {
    rl.close();
    return;
  }

  rl.question("", function (input) {
    // console.log(testCaseCount, input);
    const nums = processInput(input);

    console.log(findAnswer(nums)); // Print the result for the current test case

    handleTestCases(testCaseCount - 1); // Then handle the next test case
  });
}

function processInput(input) {
  let [s, v] = input.split(" ").map(Number);

  //returning in the form of object
  return { s, v };
}

//De-structuring the object in the function param
function findAnswer({ s, v }) {
  let ans = (2 / 3.0) * (s / v);

  // Printing the result with 16 decimal places
  return ans.toFixed(16);
}

promptForTestCases();
