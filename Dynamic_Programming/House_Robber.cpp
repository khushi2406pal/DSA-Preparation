/*
===========================================================
Problem: House Robber
LeetCode: 198
Difficulty: Medium

Description:
You are a robber planning to rob houses along a street.
Each house has a certain amount of money.

You cannot rob two adjacent houses.

Return the maximum amount of money you can rob.

Example:
Input:  [2,7,9,3,1]
Output: 12

Explanation:
Rob houses with amounts 2, 9, and 1.
Total = 12.

Approach:
Use 1D Dynamic Programming with the Take-or-Skip pattern.

For every house, we have two choices:

1. Skip the current house:
       prev1

2. Rob the current house:
       nums[i] + prev2

Therefore:

    current = max(prev1, nums[i] + prev2)

where:
- prev1 = maximum money up to the previous house
- prev2 = maximum money up to two houses before

We only keep the previous two DP states, so we use
constant extra space.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {

            // Either skip or rob the current house
            int current = max(prev1, nums[i] + prev2);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};