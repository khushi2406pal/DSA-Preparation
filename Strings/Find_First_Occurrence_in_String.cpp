/*
===========================================================
Problem: Find the Index of the First Occurrence in a String
LeetCode: 28
Difficulty: Easy

Description:
Given two strings `haystack` and `needle`, return the index
of the first occurrence of `needle` in `haystack`.

If `needle` is not part of `haystack`, return -1.

Example:
Input:  haystack = "sadbutsad", needle = "sad"
Output: 0

Input:  haystack = "leetcode", needle = "leeto"
Output: -1

Approach:
Try every possible starting position in `haystack`.

For each position:
1. Compare characters of `haystack` with `needle`.
2. Continue while the characters match.
3. If all characters of `needle` match, return the
   current starting index.
4. If no match is found, return -1.

Time Complexity: O(n * m)
Space Complexity: O(1)

Where:
n = length of haystack
m = length of needle
===========================================================
*/
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};