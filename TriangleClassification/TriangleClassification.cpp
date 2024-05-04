// This problem uses the concepts from pythagoras theorem. The code follows the code and logic provided in the official editorial.
// Time Complexity - O(1)
// Space Complexity - O(1)

#include <bits/stdc++.h>

using namespace std;

int square(int x) {
    return x * x;
}

//The order function will handle a, b & c in ascending order
//We need the sides to be in ascending order
//a < b < c
void order(int & a, int & b, int & c) {
    if (a > c) {
        swap(a, c);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
}


string get_side_classification(int a, int b, int c) {

    //Order the square of sides in ascending order
    order(a, b, c);

    if (a == b || b == c) {
        return "Isosceles";
    } else {
        return "Scalene";
    }
}

string get_angle_classification(int a, int b, int c) {
    order(a, b, c);

    if (a + b > c) {
        return "acute";
    } else if (a + b == c) {
        return "right";
    }
    else {
        return "obtuse";
    }
}

void solve(int subTaskId) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    //first lets handle the case of subtask id 1
    //we just have to calculate side lengths
    int sideLen1 = square(x1 - x2) + square(y1 - y2);
    int sideLen2 = square(x1 - x3) + square(y1 - y3);
    int sideLen3 = square(x2 - x3) + square(y2 - y3);
    if (subTaskId == 1) {
        cout << get_side_classification(sideLen1, sideLen2, sideLen3) << " triangle" << endl;
    } else {
        cout << get_side_classification(sideLen1, sideLen2, sideLen3) << " " 
        << get_angle_classification(sideLen1, sideLen2, sideLen3) << " triangle" << endl;
    }
}

int main() {
    // your code goes here
    int subTaskId;
    cin >> subTaskId;
    int t;
    cin >> t;

    while (t--) {
        solve(subTaskId);
    }

}