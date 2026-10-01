/*
===========================================================
Problem: Decode String
LeetCode: 394
Difficulty: Medium

Description:
Given an encoded string, decode it using the following rule:

k[encoded_string]

The encoded_string inside the brackets is repeated k times.

Example:
Input:  s = "3[a]2[bc]"
Output: "aaabcbc"

Input:  s = "3[a2[c]]"
Output: "accaccacc"

Approach:
Use a stack to store the repetition count and the string
constructed before encountering '['.

1. Build the number when digits are encountered.
2. When '[' is encountered:
   - Store the current number and current string on the stack.
   - Reset both for the new nested section.
3. When ']' is encountered:
   - Retrieve the repeat count and previous string.
   - Repeat the current string 'repeat' times.
   - Append it to the previous string.
4. For normal characters, append them to currentString.

Time Complexity: O(n * k)
Space Complexity: O(n)

===========================================================
*/
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {

        stack<pair<int, string>> st;

        int currentNumber = 0;
        string currentString = "";

        for (char c : s) {

            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            else if (c == '[') {
                st.push({currentNumber, currentString});

                currentNumber = 0;
                currentString = "";
            }

            else if (c == ']') {

                auto [repeat, previous] = st.top();
                st.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += currentString;
                }

                currentString = previous + temp;
            }

            else {
                currentString += c;
            }
        }

        return currentString;
    }
};