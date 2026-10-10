
/*
===========================================================
Problem: Daily Temperatures
LeetCode: 739
Difficulty: Medium

Description:
Given an array of daily temperatures, return an array answer
where answer[i] is the number of days until a warmer
temperature occurs. If no warmer day exists, answer[i] = 0.

Example:
Input:
temperatures = {73, 74, 75, 71, 69, 72, 76, 73}

Output:
{1, 1, 4, 2, 1, 1, 0, 0}

Approach:
Use a monotonic decreasing stack to store indices of
temperatures that have not yet found a warmer day.

1. Traverse the temperatures from left to right.
2. While the current temperature is warmer than the
   temperature at the stack's top index:
   - Pop that index.
   - Calculate the waiting days using i - prev.
3. Push the current index onto the stack.
4. Indices left in the stack retain answer 0 because no
   warmer day occurs afterward.

Time Complexity: O(n)
Space Complexity: O(n)
===========================================================
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> answer(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {
                int prev = st.top();
                st.pop();

                answer[prev] = i - prev;
            }

            st.push(i);
        }

        return answer;
    }
};
