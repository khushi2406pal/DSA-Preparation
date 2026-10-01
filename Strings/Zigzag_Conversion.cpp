/*
===========================================================
Problem: Zigzag Conversion
LeetCode: 6
Difficulty: Medium

Description:
Given a string `s` and an integer `numRows`, arrange the
characters in a zigzag pattern on the given number of rows
and then read the characters row by row.

Example:
Input:  s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Input:  s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"

Approach:
Simulate the zigzag traversal using a vector of strings.

- `currentRow` keeps track of the current row.
- `goingDown` determines the direction of movement.
- When we reach the first or last row, reverse the direction.
- Store each character in its corresponding row.
- Finally, concatenate all rows to form the answer.

If `numRows == 1` or `numRows >= s.size()`, the string
remains unchanged.

Time Complexity: O(n)
Space Complexity: O(n)
===========================================================
*/
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        string ans;

        for (string& row : rows) {
            ans += row;
        }

        return ans;
    }
};