
/*
===========================================================
Problem: Construct Smallest Number From DI String
LeetCode: 2375
Difficulty: Medium

Description:
Given a pattern containing 'I' and 'D', construct the
lexicographically smallest number using digits 1 to n + 1
such that:
- 'I' means the next digit is greater than the current digit.
- 'D' means the next digit is smaller than the current digit.

Example:
Input:
pattern = "IIIDIDDD"

Output:
"123549876"

Approach:
Use a stack and push numbers in increasing order.

1. Iterate from 0 to n.
2. Push i + 1 onto the stack.
3. When the current pattern character is 'I', or the end
   of the pattern is reached, pop all stack elements into
   the result.
4. Consecutive 'D' characters remain on the stack until
   an 'I' or the end, so they are emitted in reverse order.

Time Complexity: O(n)
Space Complexity: O(n)
===========================================================
*/
#include<vector>
#include <string>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string result = "";
        vector<int> st;

        for (int i = 0; i <= n; i++) {
            st.push_back(i + 1);

            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.back());
                    st.pop_back();
                }
            }
        }

        return result;
    }
};
