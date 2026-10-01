/*
===========================================================
Problem: Minimum Window Substring
LeetCode: 76
Difficulty: Hard

Description:
Given two strings s and t, return the minimum window substring
of s that contains every character from t, including duplicate
characters.

If no such substring exists, return an empty string.

Example:
Input:  s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Approach:
Use the Sliding Window technique with frequency arrays.

1. Build a frequency map for characters required from t.
2. Expand the window by moving the right pointer.
3. Track how many required characters currently satisfy their
   required frequency using 'formed'.
4. Once the window contains all required characters, move the
   left pointer to shrink the window as much as possible.
5. Keep track of the smallest valid window.
6. Return the minimum window found.

Time Complexity: O(n)
Space Complexity: O(1)

===========================================================
*/

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        int required = 0;

        // Build frequency map
        for (char c : t) {
            if (need[c] == 0)
                required++;

            need[c]++;
        }

        int formed = 0;
        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            window[c]++;

            if (need[c] > 0 &&
                window[c] == need[c]) {
                formed++;
            }

            // Try to shrink the window
            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char remove = s[left];
                window[remove]--;

                if (need[remove] > 0 &&
                    window[remove] < need[remove]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};