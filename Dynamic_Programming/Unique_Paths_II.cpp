/*
===========================================================
Problem: Unique Paths II
LeetCode: 63
Difficulty: Medium

Description:
You are given an m x n grid where:
- 0 represents an empty cell
- 1 represents an obstacle

A robot starts at the top-left corner and wants to reach
the bottom-right corner.

The robot can only move either right or down.

Return the number of unique paths to reach the destination
without passing through any obstacles.

Example:
Input:
obstacleGrid = [[0,0,0],
                [0,1,0],
                [0,0,0]]

Output:
2

Approach:
Use Dynamic Programming.

dp[row][col] represents the number of ways to reach
cell (row, col).

For an obstacle:
    dp[row][col] = 0

For an empty cell:
    dp[row][col] =
        dp[row-1][col] + dp[row][col-1]

The first row and first column need special handling
because they can only be reached from one direction.

Time Complexity: O(m * n)
Space Complexity: O(m * n)

Pattern:
2D Grid DP
===========================================================
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        // First column
        for (int row = 0; row < m; row++) {
            if (obstacleGrid[row][0] == 1) {
                dp[row][0] = 0;
            }
            else if (row == 0) {
                dp[row][0] = 1;
            }
            else {
                dp[row][0] = dp[row - 1][0];
            }
        }

        // First row
        for (int col = 0; col < n; col++) {
            if (obstacleGrid[0][col] == 1) {
                dp[0][col] = 0;
            }
            else if (col == 0) {
                dp[0][col] = 1;
            }
            else {
                dp[0][col] = dp[0][col - 1];
            }
        }

        // Rest of the grid
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {

                if (obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                }
                else {
                    dp[row][col] =
                        dp[row - 1][col] + dp[row][col - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};