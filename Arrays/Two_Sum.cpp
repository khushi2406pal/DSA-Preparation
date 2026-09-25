/*
===========================================================
Problem: Two Sum
LeetCode: 1
Difficulty: Easy

Description:
Given an array of integers nums and an integer target,
return the indices of the two numbers such that they add
up to target.

Each input is guaranteed to have exactly one solution,
and the same element cannot be used twice.

Example:
Input:
nums = [2,7,11,15], target = 9

Output:
[0,1]

Explanation:
nums[0] + nums[1] = 2 + 7 = 9

Approach:
Use a hash map to store each number and its index.

For every element nums[i], calculate its complement:

    complement = target - nums[i]

If the complement already exists in the hash map,
we have found the required pair.

Otherwise, store nums[i] and its index in the map.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern:
Hash Map / Complement Lookup
===========================================================
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};