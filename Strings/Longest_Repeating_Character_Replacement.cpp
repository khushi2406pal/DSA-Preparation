/*
===========================================================
Problem: Longest Repeating Character Replacement
LeetCode: 424
Difficulty: Medium

Description:
You are given a string `s` containing uppercase English
letters and an integer `k`.

You can replace at most `k` characters in the string.

Return the length of the longest substring containing the
same letter after performing at most `k` replacements.

Example:
Input:  s = "ABAB", k = 2
Output: 4

Input:  s = "AABABBA", k = 1
Output: 4

Approach:
Use a sliding window with two pointers.

- `left` and `right` represent the current window.
- `count` stores the frequency of each character.
- `maxFreq` stores the highest frequency of any character
  inside the current window.

For a valid window:

    windowLength - maxFreq <= k

The difference represents the number of characters that need
to be replaced to make the entire window consist of the same
character.

If the window becomes invalid, move `left` forward until
the window becomes valid again.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            count[s[right] - 'A']++;

            maxFreq = max(maxFreq, count[s[right] - 'A']);

            int windowLen = right - left + 1;

            // Number of replacements needed
            if (windowLen - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};