/*
===========================================================
Problem: Maximum Subarray
LeetCode: 53
Difficulty: Medium

Description:
Given an integer array nums, find the contiguous subarray
with the largest sum and return its sum.

Example:
Input:  [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

Explanation:
The subarray [4,-1,2,1] has the largest sum = 6.

Approach:
Use Kadane's Algorithm.

At every element, we have two choices:
1. Start a new subarray from the current element.
2. Add the current element to the existing subarray.

Therefore:

    currentSum = max(nums[i], currentSum + nums[i])

We also maintain maxSum to store the maximum subarray
sum found so far.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

class Solution {
public:

    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < n; i++) {

            // Start a new subarray or extend the current one
            currentSum = max(nums[i], currentSum + nums[i]);

            // Update the maximum sum found so far
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};