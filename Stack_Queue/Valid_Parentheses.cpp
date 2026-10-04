/*
===========================================================
Problem: Valid Parentheses
LeetCode: 20
Difficulty: Easy

Description:
Given a string containing only the characters '(', ')',
'{', '}', '[' and ']', determine whether the input string
is valid.

A string is valid if:
1. Every opening bracket has a corresponding closing bracket.
2. Brackets are closed in the correct order.
3. Every closing bracket matches the most recent unmatched
   opening bracket.

Example:
Input:  s = "()"
Output: true

Input:  s = "()[]{}"
Output: true

Input:  s = "(]"
Output: false

Input:  s = "([{}])"
Output: true

Approach:
Use a stack to keep track of opening brackets.

1. Push every opening bracket onto the stack.
2. When a closing bracket is encountered:
   - If the stack is empty, the string is invalid.
   - Compare the closing bracket with the most recent opening
     bracket.
   - If they do not match, return false.
   - Otherwise, remove the opening bracket from the stack.
3. At the end, the stack must be empty for the string to be valid.

Time Complexity: O(n)
Space Complexity: O(n)

===========================================================
*/
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            // Store opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            else {
                // No opening bracket to match
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Check whether the brackets match
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // All opening brackets must have been matched
        return st.empty();
    }
};