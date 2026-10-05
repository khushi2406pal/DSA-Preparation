/*
===========================================================
Problem: Reverse Integer
LeetCode: 7
Difficulty: Medium

Description:
Given a signed 32-bit integer x, return x with its digits
reversed.

If reversing x causes the value to go outside the signed
32-bit integer range [-2^31, 2^31 - 1], return 0.

Example:
Input:
x = 123

Output:
321

Example:
Input:
x = -123

Output:
-321

Approach:
Extract the last digit using x % 10 and build the reversed
number one digit at a time.

Before updating the result, check whether multiplying it by
10 and adding the next digit would cause integer overflow.

Time Complexity: O(log n)
Space Complexity: O(1)
===========================================================
*/
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for positive overflow
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            // Check for negative overflow
            if (result < INT_MIN / 10 ||
                (result == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            result = result * 10 + digit;
        }

        return result;
    }
};