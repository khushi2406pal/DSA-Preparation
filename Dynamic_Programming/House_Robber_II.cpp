/*
===========================================================
Problem: House Robber II
LeetCode: 213
Difficulty: Medium

Description:
You are a robber planning to rob houses arranged in a
circle. Each house contains a certain amount of money.

You cannot rob two adjacent houses.

Because the houses form a circle, the first and last
houses are also adjacent.

Return the maximum amount of money you can rob.

Example:
Input:  [2,3,2]
Output: 3

Explanation:
You cannot rob both the first and last houses because
they are adjacent.

Approach:
Since the houses form a circle, we cannot rob both the
first and last house.

Therefore, there are two possible cases:

1. Rob houses from index 0 to n-2
   -> Exclude the last house.

2. Rob houses from index 1 to n-1
   -> Exclude the first house.

Calculate the maximum robbery amount for both cases
using the same linear House Robber DP.

For each house:

    current = max(prev1, nums[i] + prev2)

where:
- prev1 = maximum amount up to the previous house
- prev2 = maximum amount up to two houses before

Finally, return the maximum of the two cases.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // Case 1: Exclude the last house
        int result1 = robLinear(nums, 0, n - 2);

        // Case 2: Exclude the first house
        int result2 = robLinear(nums, 1, n - 1);

        return max(result1, result2);
    }

    int robLinear(vector<int>& nums, int start, int end) {

        int prev1 = 0;
        int prev2 = 0;

        for (int i = start; i <= end; i++) {

            // Skip or rob the current house
            int current = max(prev1, nums[i] + prev2);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};