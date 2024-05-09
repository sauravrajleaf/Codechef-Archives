// your code goes here
const readline = require("node:readline");

const { stdin: input, stdout: output } = require("node:process");

const rl = readline.createInterface({ input });

let numberOfTestCases = null;
let sizeOfArray = null;
let target = null;
let arrayVals = [];

rl.on("line", function (line) {
  if (numberOfTestCases == null) {
    //First line is the number of test cases
    numberOfTestCases = parseInt(line);
  } else {
    if (!sizeOfArray && !target) {
      //Second line input
      [sizeOfArray, target] = line.split(" ").map(Number);
    } else {
      //Input consists of the array values
      arrayVals = line.split(" ").map(Number);

      //Now implement the logic for the problem

      let ans = findAns(arrayVals, target);

      //Using spread operator to output multiple variables
      console.log(...ans);

      //Using for each loop and stdout stream to output multiple variables
      // ans.forEach((val) => {
      //     // console.log(val + "\t");
      //     process.stdout.write(`${val} `);

      // });
      // console.log();

      //Setting variables to null for the next test case
      sizeOfArray = null;
      target = null;
      arrayVals = [];
      numberOfTestCases--;
    }
  }
});

function findAns(arrayVals, target) {
  let ans = Number.MAX_SAFE_INTEGER;
  let cnt = 0;

  for (let i = 0; i < arrayVals.length; i++) {
    for (let j = i + 1; j < arrayVals.length; j++) {
      let currentDiff = Math.abs(arrayVals[i] + arrayVals[j] - target);

      if (currentDiff < ans) {
        ans = currentDiff; // Update the minimum difference found
        cnt = 1; // Reset the count as we found a new minimum difference
      } else if (currentDiff === ans) {
        cnt++; // Increment count if current difference is the same as the minimum found
      }
    }
  }

  return [ans, cnt];
}
