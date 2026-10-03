/*
===========================================================
Problem: First Unique Character in a String
LeetCode: 387
Difficulty: Easy

Description:
Given a string s, find the first non-repeating character
and return its index.

If no unique character exists, return -1.

Example:
Input:  s = "leetcode"
Output: 0

Explanation:
'l' appears only once and is the first unique character.

Input:  s = "loveleetcode"
Output: 2

Explanation:
'v' is the first character that appears only once.

Input:  s = "aabb"
Output: -1

Approach:
Use a frequency array to count how many times each
character appears.

1. Traverse the string and count the frequency of each
   character.
2. Traverse the string again from left to right.
3. Return the index of the first character whose frequency
   is exactly 1.
4. If no such character exists, return -1.

Time Complexity: O(n)
Space Complexity: O(1)

===========================================================
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {

        vector<int> count(26, 0);

        // Count frequency of each character
        for (char c : s) {
            count[c - 'a']++;
        }

        // Find the first character appearing once
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};