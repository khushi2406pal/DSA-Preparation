/*
===========================================================
Problem: Target Sum
LeetCode: 494
Difficulty: Medium

Description:
Given an integer array nums, assign either '+' or '-' to
each number and return the number of different ways to
make the resulting sum equal to target.

Example:
Input:  nums = [1,1,1,1,1], target = 3
Output: 5

Approach:
Use recursion with memoization.

For every number, we have two choices:
1. Add the current number.
2. Subtract the current number.

The same (index, currentSum) states can occur multiple
times. Instead of solving the same state repeatedly,
store its result in a memoization table.

State:

    helper(index, currentSum)

represents the number of ways to reach target using the
remaining elements.

Time Complexity: O(n * S)
Space Complexity: O(n * S)

where S is the possible range of sums.
===========================================================
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int helper(vector<int>& nums,
               int target,
               int index,
               int sum,
               vector<vector<int>>& memo,
               int offset) {

        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }

        // Convert sum into a valid memo array index
        int memoIndex = sum + offset;

        if (memo[index][memoIndex] != -1) {
            return memo[index][memoIndex];
        }

        int subtract = helper(
            nums,
            target,
            index + 1,
            sum - nums[index],
            memo,
            offset
        );

        int add = helper(
            nums,
            target,
            index + 1,
            sum + nums[index],
            memo,
            offset
        );

        return memo[index][memoIndex] = subtract + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;

        for (int num : nums) {
            total += num;
        }

        // Target is outside the possible sum range
        if (target > total || target < -total) {
            return 0;
        }

        int offset = total;

        vector<vector<int>> memo(
            nums.size(),
            vector<int>(2 * total + 1, -1)
        );

        return helper(nums, target, 0, 0, memo, offset);
    }
};