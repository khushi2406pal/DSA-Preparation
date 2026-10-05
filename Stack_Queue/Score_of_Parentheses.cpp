/*
===========================================================
Problem: Score of Parentheses
LeetCode: 856
Difficulty: Medium

Description:
Given a balanced parentheses string s, calculate its score.

Rules:
1. "()" has score 1.
2. AB has score A + B, where A and B are balanced strings.
3. "(A)" has score 2 * A.

Example:
Input:
s = "(()(()))"

Output:
6

Explanation:
"()" = 1
"(())" = 2
"(()(()))" = 2 * (1 + 2) = 6

Approach:
Use a stack to store the score of each level of parentheses.

1. Push 0 for every opening parenthesis.
2. When a closing parenthesis is found:
   - Get the score inside the current pair.
   - If the inner score is 0, the pair is "()" and scores 1.
   - Otherwise, its score is 2 * innerScore.
   - Add this score to the previous level.
3. The score at the bottom of the stack is the final answer.

Time Complexity: O(n)
Space Complexity: O(n)
===========================================================
*/
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            }
            else {
                int innerScore = st.top();
                st.pop();

                int score;

                if (innerScore == 0) {
                    score = 1;
                }
                else {
                    score = 2 * innerScore;
                }

                st.top() += score;
            }
        }

        return st.top();
    }
};