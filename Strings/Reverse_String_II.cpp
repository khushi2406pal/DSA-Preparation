/*
===========================================================
Problem: Reverse String II
LeetCode: 541
Difficulty: Easy

Description:
Given a string s and an integer k, reverse the first k
characters for every 2k characters from the beginning
of the string.

Rules:
- If fewer than k characters remain, reverse all of them.
- If at least k but fewer than 2k characters remain,
  reverse only the first k characters.

Example:
Input:  s = "abcdefg", k = 2
Output: "bacdfeg"

Input:  s = "abcd", k = 2
Output: "bacd"

Approach:
Process the string in blocks of 2k characters.

For each block:
1. Start at index i.
2. Reverse the first k characters.
3. If fewer than k characters remain, reverse all
   remaining characters.
4. Move to the next block by increasing i by 2k.

The right boundary is calculated using min() so that
it never goes beyond the end of the string.

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
    string reverseStr(string s, int k) {

        int n = s.length();

        for (int i = 0; i < n; i += 2 * k) {

            int left = i;
            int right = min(i + k - 1, n - 1);

            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};