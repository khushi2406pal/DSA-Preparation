/*
===========================================================
Problem: Number of Substrings Containing All Three Characters
LeetCode: 1358
Difficulty: Medium

Description:
Given a string s consisting only of characters 'a', 'b', and
'c', return the number of substrings containing at least one
occurrence of all three characters.

Example:
Input:  s = "abcabc"
Output: 10

Input:  s = "aaacb"
Output: 3

Approach:
Use the last-seen index of each character.

1. Maintain the latest position of 'a', 'b', and 'c'.
2. As we move the right pointer through the string, update
   the last position of the current character.
3. Find the minimum last-seen position among 'a', 'b', and 'c'.
4. If the minimum position is minIndex, then every substring
   ending at the current right index and starting from
   index 0 through minIndex contains all three characters.
5. Therefore, add:
       minIndex + 1
   to the answer.

Initially, all last-seen positions are -1. This naturally
contributes 0 until all three characters have appeared.

Time Complexity: O(n)
Space Complexity: O(1)

===========================================================
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        int abc[3] = {-1, -1, -1};

        int count = 0;
        int right = 0;

        while (right < s.length()) {

            // Update the latest position of the current character
            abc[s[right] - 'a'] = right;

            int minIndex = INT_MAX;

            // Find the earliest last-seen position
            for (int i = 0; i < 3; i++) {
                minIndex = min(minIndex, abc[i]);
            }

            // All starts from 0 to minIndex form valid substrings
            count += minIndex + 1;

            right++;
        }

        return count;
    }
};