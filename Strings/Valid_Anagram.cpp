/*
===========================================================
Problem: Valid Anagram
LeetCode: 242
Difficulty: Easy

Description:
Given two strings s and t, return true if t is an anagram
of s, and false otherwise.

An anagram is a word or phrase formed by rearranging the
letters of another word or phrase using all the original
characters exactly once.

Example:
Input:  s = "anagram", t = "nagaram"
Output: true

Input:  s = "rat", t = "car"
Output: false

Approach:
Use a frequency array of size 26.

1. If the strings have different lengths, they cannot be
   anagrams.
2. For every character in s, increase its frequency.
3. For every character in t, decrease its frequency.
4. If all frequencies are zero, both strings contain the
   same characters with the same frequencies.

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
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};