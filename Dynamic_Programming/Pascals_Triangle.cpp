/*
===========================================================
Problem: Pascal's Triangle
LeetCode: 118
Difficulty: Easy

Description:
Given an integer numRows, return the first numRows rows
of Pascal's Triangle.

Each number in a row is the sum of the two numbers directly
above it.

Example:
Input:  numRows = 5

Output:
[
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]
]

Approach:
Build the triangle row by row.

For every row:
- The first element is always 1.
- The last element is always 1.
- Every middle element is calculated using the previous row:

    triangle[i][j] =
        triangle[i-1][j-1] + triangle[i-1][j]

This uses previously calculated rows to construct the
current row.

Time Complexity: O(n^2)
Space Complexity: O(n^2)
===========================================================
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {

            vector<int> row(i + 1);

            // First and last elements are always 1
            row[0] = 1;
            row[i] = 1;

            // Calculate middle elements
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1]
                       + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};