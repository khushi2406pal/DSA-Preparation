/*
===========================================================
Problem: Best Time to Buy and Sell Stock
LeetCode: 121
Difficulty: Easy

Description:
Given an array prices where prices[i] is the price of a
stock on the ith day, find the maximum profit that can be
achieved by buying on one day and selling on a later day.

Example:
Input:  [7,1,5,3,6,4]
Output: 5

Explanation:
Buy at price 1 and sell at price 6.
Maximum profit = 6 - 1 = 5.

Approach:
Use a greedy approach.

Maintain:
1. minPrice  -> lowest stock price seen so far.
2. maxProfit -> maximum profit found so far.

For every price:
- Calculate the profit if we sell today:
      prices[i] - minPrice
- Update maxProfit.
- Update minPrice if the current price is smaller.

This guarantees that we always consider buying at the
lowest price before selling.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            // Profit if we sell today
            maxProfit = max(maxProfit, prices[i] - minPrice);

            // Update the minimum buying price
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};