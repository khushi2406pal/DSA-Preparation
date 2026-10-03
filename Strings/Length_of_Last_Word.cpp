/*
===========================================================
Problem: Length of Last Word
LeetCode: 58
Difficulty: Easy

Description:
Given a string consisting of words and spaces, return the
length of the last word in the string.

A word is a maximal substring consisting of non-space
characters only.

Example:
Input:  s = "Hello World"
Output: 5

Input:  s = "   fly me   to   the moon  "
Output: 4

Input:  s = "luffy is still joyboy"
Output: 6

Approach:
Use two pointers and traverse the string from right to left.

1. Start from the last character.
2. Skip all trailing spaces.
3. Mark the position of the last word.
4. Continue moving left until a space or the beginning
   of the string is reached.
5. The length of the word is right - left.

Time Complexity: O(n)
Space Complexity: O(1)

===========================================================
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.length();
        int right = n - 1;

        // Skip trailing spaces
        while (right >= 0 && s[right] == ' ') {
            right--;
        }

        int left = right;

        // Find the beginning of the last word
        while (left >= 0 && s[left] != ' ') {
            left--;
        }

        return right - left;
    }
};