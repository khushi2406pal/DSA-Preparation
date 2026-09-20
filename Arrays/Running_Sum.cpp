#include <iostream>
#include <vector>
using namespace std;

/*
===========================================================
Problem: Running Sum of 1d Array
LeetCode: 1480
Difficulty: Easy

Description:
Given an array nums, return the running sum of the array.

Example:
Input:  [1, 2, 3, 4]
Output: [1, 3, 6, 10]

Approach:
Starting from the second element, add the previous
element to the current element.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4};

    Solution solution;

    vector<int> result = solution.runningSum(nums);

    cout << "Running Sum: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}