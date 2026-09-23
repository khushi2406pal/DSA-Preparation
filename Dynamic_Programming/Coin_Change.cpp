/*
===========================================================
Problem: Coin Change
LeetCode: 322
Difficulty: Medium

Description:
Given an array of coin denominations and an integer amount,
return the fewest number of coins needed to make up that
amount.

If the amount cannot be made using the given coins, return -1.

Example:
Input:  coins = [1,2,5], amount = 11
Output: 3

Explanation:
11 = 5 + 5 + 1

Approach:
Use 1D Dynamic Programming.

Define:

    dp[i] = minimum number of coins required to make amount i.

Base case:

    dp[0] = 0

For every amount i, try using every available coin.

If coin c can be used:

    dp[i] = min(dp[i], dp[i - c] + 1)

We initialize dp with INT_MAX to represent an amount that
cannot currently be formed.

If dp[amount] is still INT_MAX after processing all amounts,
the target amount cannot be formed.

Time Complexity: O(amount * number of coins)
Space Complexity: O(amount)
===========================================================
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, INT_MAX);

        // 0 coins are needed to make amount 0
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {

            for (int c : coins) {

                if (c <= i && dp[i - c] != INT_MAX) {

                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        if (dp[amount] == INT_MAX) {
            return -1;
        }

        return dp[amount];
    }
};