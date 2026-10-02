/*
===========================================================
Problem: Permutation in String
LeetCode: 567
Difficulty: Medium

Description:
Given two strings s1 and s2, return true if s2 contains a
permutation of s1 as a substring.

In other words, check whether there exists a substring of s2
that contains exactly the same characters and frequencies as s1.

Example:
Input:  s1 = "ab", s2 = "eidbaooo"
Output: true

Explanation:
"ba" is a permutation of "ab".

Input:  s1 = "ab", s2 = "eidboaoo"
Output: false

Approach:
Use a fixed-size sliding window of length s1.length().

1. Count the frequency of characters in s1.
2. Count the characters in the first window of s2.
3. Compare both frequency arrays.
4. Slide the window one character at a time:
   - Add the new character entering the window.
   - Remove the character leaving the window.
5. If the frequency arrays match, the current window is a
   permutation of s1.

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
    bool checkInclusion(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();

        if (m > n)
            return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // Build frequency counts for the first window
        for (int i = 0; i < m; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        if (s1Count == s2Count)
            return true;

        // Slide the window across s2
        for (int right = m; right < n; right++) {

            // Add the new character
            s2Count[s2[right] - 'a']++;

            // Remove the character leaving the window
            s2Count[s2[right - m] - 'a']--;

            if (s1Count == s2Count)
                return true;
        }

        return false;
    }
};