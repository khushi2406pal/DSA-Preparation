/*
===========================================================
Problem: Longest Substring Without Repeating Characters
LeetCode: 3
Difficulty: Medium

Description:
Given a string s, find the length of the longest substring
without repeating characters.

Example:
Input:  s = "abcabcbb"
Output: 3

Explanation:
The longest substring without repeating characters is "abc".

Input:  s = "bbbbb"
Output: 1

Input:  s = "pwwkew"
Output: 3

Explanation:
The longest substring is "wke".

Approach:
Use a Sliding Window with a last-seen index array.

1. Maintain a window from 'left' to 'right'.
2. Store the most recent index of every character.
3. If the current character has already appeared inside
   the current window, move 'left' to one position after
   its previous occurrence.
4. Update the character's latest index.
5. Track the maximum window length.

The condition:
    lastSeen[s[right]] >= left

ensures that the previous occurrence is actually inside
the current window.

Time Complexity: O(n)
Space Complexity: O(1)

===========================================================
*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastSeen(256, -1);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            if (lastSeen[s[right]] >= left) {
                left = lastSeen[s[right]] + 1;
            }

            lastSeen[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};