/*
===========================================================
Problem: Pascal's Triangle II
LeetCode: 119
Difficulty: Easy

Description:
Given an integer rowIndex, return the rowIndex-th row of
Pascal's Triangle.

The row index is 0-indexed.

Example:
Input:  rowIndex = 3
Output: [1,3,3,1]

Approach:
Use 1D Dynamic Programming.

Initialize the row with all 1s.

For each row, update the elements from right to left:

    row[j] = row[j] + row[j - 1]

Updating from right to left is important because it prevents
the current iteration from overwriting values that are still
needed for calculating the next elements.

Example:

row = [1, 2, 1]

To build the next row:
j = 2:
    row[2] = 1 + 2 = 3

j = 1:
    row[1] = 2 + 1 = 3

Result:
[1,3,3,1]

Time Complexity: O(n^2)
Space Complexity: O(n)
===========================================================
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:

    vector<int> getRow(int rowIndex) {

        vector<int> row(rowIndex + 1, 1);

        for (int i = 2; i <= rowIndex; i++) {

            // Update from right to left
            for (int j = i - 1; j >= 1; j--) {

                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};