/*
===========================================================
Problem: Search Insert Position
LeetCode: 35
Difficulty: Easy

Description:
Given a sorted array of distinct integers and a target value,
return the index if the target is found.

If the target is not present, return the index where it would
be inserted to maintain the sorted order.

Example:
Input:  nums = [1,3,5,6], target = 5
Output: 2

Input:  nums = [1,3,5,6], target = 2
Output: 1

Input:  nums = [1,3,5,6], target = 7
Output: 4

Approach:
Use binary search on the sorted array.

- If nums[mid] == target, return mid.
- If nums[mid] < target, search the right half.
- If nums[mid] > target, search the left half.

When the loop ends, `left` points to the first position
where the target can be inserted while maintaining the
sorted order.

Time Complexity: O(log n)
Space Complexity: O(1)
===========================================================
*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // left is the correct insertion position
        return left;
    }
};