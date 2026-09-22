/*
===========================================================
Problem: Climbing Stairs
LeetCode: 70
Difficulty: Easy

Description:
You are climbing a staircase with n steps.

You can climb either 1 step or 2 steps at a time.
Return the number of distinct ways to reach the top.

Example:
Input:  n = 5
Output: 8

Explanation:
There are 8 distinct ways to reach the top.

Approach:
This problem follows the Fibonacci pattern.

To reach step i:
- We can come from step i-1 by taking 1 step.
- We can come from step i-2 by taking 2 steps.

Therefore:

    dp[i] = dp[i-1] + dp[i-2]

Instead of storing the entire DP array, we only keep
the previous two values because each state only depends
on the previous two states.

Base cases:
n = 1 -> 1 way
n = 2 -> 2 ways

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

class Solution {
public:

    int climbStairs(int n) {

        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {

            int current = prev1 + prev2;

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};