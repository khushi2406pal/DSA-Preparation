/*
===========================================================
Problem: Find Pivot Index
LeetCode: 724
Difficulty: Easy

Description:
Given an integer array nums, find the pivot index.

The pivot index is the index where the sum of all
elements to the left is equal to the sum of all
elements to the right.

If no pivot index exists, return -1.

Example:
Input:  [1, 7, 3, 6, 5, 6]
Output: 3

At index 3:
Left Sum  = 1 + 7 + 3 = 11
Right Sum = 5 + 6 = 11

Approach:
1. Calculate the total sum of the array.
2. Traverse the array while maintaining leftSum.
3. Calculate rightSum using:

   rightSum = totalSum - leftSum - nums[i]

4. If leftSum == rightSum, return the current index.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;

        // Calculate total sum
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;

        // Find pivot index
        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};

int main() {

    vector<int> nums = {1, 7, 3, 6, 5, 6};

    Solution solution;

    int result = solution.pivotIndex(nums);

    cout << "Pivot Index: " << result << endl;

    return 0;
}