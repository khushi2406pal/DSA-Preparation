/*
===========================================================
Problem: Longest Palindromic Substring
LeetCode: 5
Difficulty: Medium

Description:
Given a string s, return the longest palindromic substring in s.

Example:
Input:  "babad"
Output: "bab"
        "aba" is also a valid answer.

Approach:
Use the Expand Around Center technique.

Every palindrome has a center:
1. Odd-length palindrome -> one center character
2. Even-length palindrome -> two center characters

For every index i:
- Expand from (i, i) for odd-length palindromes.
- Expand from (i, i + 1) for even-length palindromes.

During expansion, update the starting index and maximum
length whenever a longer palindrome is found.

Time Complexity: O(n^2)
Space Complexity: O(1)
===========================================================
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

    int start = 0;
    int maxLen = 1;

    void expand(string &s, int left, int right) {

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {

        int n = s.size();

        for (int i = 0; i < n; i++) {

            // Odd-length palindrome
            expand(s, i, i);

            // Even-length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};