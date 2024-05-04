// This problem uses the concepts from pythagoras theorem. The code follows the code and logic provided in the official editorial.
// Time Complexity - O(1)
// Space Complexity - O(1)


// New Concept - 
// Taking multiline input in Js
// rl.on method and line event inside which gets triggered/called whenever enter or return or cursor goes to new line  
// Destructuring Assignment
// Way around of passing variables by reference in Js

// your code goes here
const readline = require("node:readline");

const { stdin : input, stdout : output } = require("node:process");

const rl = readline.createInterface({input, output});

//Declaring Global variables
let subTaskId;
let t;

let lineNumber = 1;

function order(values) {
    //Destructuring the array values
    let [a, b, c] = values;
    
    if(a > c) {
        //Using the concept of destructuring assignment
        //part of ECMAScript 6 (ES6) and newer versions
        //Destructuring for Swapping Variables
        //Right Side [c, a]: 
        //An array is created on the fly with the current values of c and a. If c is 3 and a is 5, then [c, a] evaluates to [3, 5].
        [a, c] = [c, a];
    }
    
    if(b > c) {
        [b, c] = [c, b];//destructuring assignment
    }
    
    if(a > b) {
        [a, b] = [b, a];//destructuring assignment
    }
    
    //Returning a new sorted array
    return [a, b, c];
}

function calcSideLen(coordinate) {
    //Destructuring the array
    const [x1, y1, x2, y2, x3, y3] = coordinate;

    //Lets calculate the side lengths
    const sideLen1 = Math.pow((x1 - x2), 2) + Math.pow((y1 - y2), 2);//Using Math.pow to square the values
    const sideLen2 = Math.pow((x2 - x3), 2) + Math.pow((y2 - y3), 2);
    const sideLen3 = Math.pow((x1 - x3), 2) + Math.pow((y1 - y3), 2);
    
    return [sideLen1, sideLen2, sideLen3];
}

function getSideClassification(coordinate) {
    //Destructuring the array
    const [sideLen1, sideLen2, sideLen3] = calcSideLen(coordinate);

    //order the sides in ascending order
    //JavaScript does not support passing arguments by reference in the same way C++ does.
    //Implement it using an array since it keeps the function versatile and easy to use.
    let [a, b, c] = order([sideLen1, sideLen2, sideLen3]);
    
    //Check the condition for Isosceles
    if(a == b || b == c) {
        return "Isosceles";
    }else {
        return "Scalene";
    }
    
}


function getAngleClassification(coordinate) {
    //Destructuring the array
    const [sideLen1, sideLen2, sideLen3] = calcSideLen(coordinate);
    
    //order the sides in ascending order
    //JavaScript does not support passing arguments by reference in the same way C++ does.
    //Implement it using an array since it keeps the function versatile and easy to use.
    let [a, b, c] = order([sideLen1, sideLen2, sideLen3]);
    
    if (a + b > c) {
        return " acute";
    } else if (a + b == c) {
        return " right";
    }
    else {
        return " obtuse";
    }
}

function processInput(line) {
    //Space separated coordinates -> using space as the delimiter in split
    const testCases = line.split(' ').map(Number);
    
    //Now we can start with the logic
    if(subTaskId == 1) {
        console.log(getSideClassification(testCases) + " triangle");
    }else {
        console.log(getSideClassification(testCases) + getAngleClassification(testCases) + " triangle");
    }
    
}

rl.on('line', (line) => {
    if(lineNumber == 1) {
        //It is the subtask id
        subTaskId = parseInt(line);//Converting the string to integer
    }else if(lineNumber == 2) {
        //It is the number of testcases
        t = parseInt(line);
    }else {
        
        //Coordinates value
        processInput(line);
    }
    //Increment the line number for the logic to work
    lineNumber++;
})