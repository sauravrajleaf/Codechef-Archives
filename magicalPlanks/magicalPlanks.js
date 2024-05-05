// Even though the implementation is different from the official editorial. The logic still remains the same.
// We are counting the number of discontinuity for both the colors.
// For ex - 
// BBWWWB - 'B' occurs at 2 places, All the 'W' occurs at only 1 place
// WWBBBBBWW - 'W' occurs at 2 places, 'B' All of them are the same place

// The number of planks to be colored will be the one who has minimum dicontinuity. As if we paint one, all its 
// neighbors will be get automatically colored. So the more the less discontinuous neighbors one color has, the more 
// suitable it is for the being the solution.

// Time Complexity - O(1)
// Space Complexity - O(1)

const readline = require("node:readline");
const { stdin: input } = require("node:process");

// In this script, console.log() is used to output results. There is no need to manage or reference the output stream 
// separately because console.log() handles all interactions with stdout internally. This approach is typical in many 
// Node.js applications where input is read and processed, and results are simply outputted back to the terminal.

const rl = readline.createInterface({ input });

let numberOfTestCases = null;
let currentTestCase = 0;
let readingPlanks = false;
let n = 0;

rl.on('line', (line) => {
    if (numberOfTestCases === null) {
        // First line is the number of test cases
        numberOfTestCases = parseInt(line);
    } else {
        if (!readingPlanks) {
            // Read number of planks, which we actually do not use separately
            n = parseInt(line);
            readingPlanks = true;
        } else {
            // Line is the colors of planks
            console.log(findAnswer(n, line));
            currentTestCase++;
            readingPlanks = false;

            // Check if all test cases have been processed
            if (currentTestCase === numberOfTestCases) {
                rl.close();
            }
        }
    }
});

function findAnswer(n, s) {
    let cnt_black = 0, cnt_white = 0;
    let len_black = 0, len_white = 0;
    
    for (let i = 0; i < n; i++) {
        if (s[i] === 'B') {
            if (len_white > 0) {
                cnt_white++;
                len_white = 0;
            }
            len_black++;
        } else if (s[i] === 'W') {
            if (len_black > 0) {
                cnt_black++;
                len_black = 0;
            }
            len_white++;
        }
    }
    if (len_black > 0) cnt_black++;
    if (len_white > 0) cnt_white++;
    
    return Math.min(cnt_black, cnt_white);
}