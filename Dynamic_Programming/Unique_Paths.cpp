/*
===========================================================
Problem: Unique Paths
LeetCode: 62
Difficulty: Medium

Description:
There is an m x n grid. A robot starts at the top-left
corner and wants to reach the bottom-right corner.

The robot can only move:
- Right
- Down

Return the number of possible unique paths.

Example:
Input:  m = 3, n = 7
Output: 28

Approach:
Use 2D Dynamic Programming.

Define:

    dp[row][col] = number of unique paths to reach
                   cell (row, col).

For every cell, the robot can arrive from:
1. The cell above it.
2. The cell to its left.

Therefore:

    dp[row][col] =
        dp[row - 1][col] + dp[row][col - 1]

Base cases:
- Every cell in the first row has only one possible path:
  moving right.
- Every cell in the first column has only one possible path:
  moving down.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
===========================================================
*/

#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n));

        // First column
        for (int row = 0; row < m; row++) {
            dp[row][0] = 1;
        }

        // First row
        for (int col = 0; col < n; col++) {
            dp[0][col] = 1;
        }

        // Fill the remaining cells
        for (int row = 1; row < m; row++) {

            for (int col = 1; col < n; col++) {

                dp[row][col] =
                    dp[row - 1][col] +
                    dp[row][col - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};