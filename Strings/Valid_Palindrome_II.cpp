/*
===========================================================
Problem: Valid Palindrome II
LeetCode: 680
Difficulty: Easy

Description:
Given a string s, return true if the string can become a
palindrome after deleting at most one character.

Example:
Input:  s = "aba"
Output: true

Input:  s = "abca"
Output: true

Explanation:
Delete 'c' to obtain "aba".

Input:  s = "abc"
Output: false

Approach:
Use the Two Pointers technique.

1. Start with pointers at both ends of the string.
2. If the characters match, move both pointers inward.
3. When a mismatch is found, we have only one deletion
   available.
4. Try both possibilities:
   - Delete the left character.
   - Delete the right character.
5. Check whether either remaining substring is a palindrome.

Since only one deletion is allowed, we only need to make
this decision at the first mismatch.

Time Complexity: O(n)
Space Complexity: O(1)

===========================================================
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            if (s[left] == s[right]) {
                left++;
                right--;
            }

            else {
                // Try deleting either the left or right character
                return isPalindrome(s, left, right - 1) ||
                       isPalindrome(s, left + 1, right);
            }
        }

        return true;
    }
};