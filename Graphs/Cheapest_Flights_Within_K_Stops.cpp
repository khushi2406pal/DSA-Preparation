
/*
===========================================================
Problem: Cheapest Flights Within K Stops
LeetCode: 787
Difficulty: Medium

Description:
There are n cities and flights[i] = [u, v, price], representing
a flight from city u to city v with the given price.

Find the cheapest price from src to dst using at most k stops.
Return -1 if no such route exists.

Example:
Input:
n = 4
flights = {{0, 1, 100}, {1, 2, 100},
           {2, 0, 100}, {1, 3, 600},
           {2, 3, 200}}
src = 0, dst = 3, k = 1

Output: 700

Approach:
Use a Bellman-Ford-style dynamic programming approach.

1. prev[u] stores the cheapest cost found using at most
   the current number of flights.
2. Initialize prev[src] = 0 and all other costs to infinity.
3. Run k + 1 iterations because at most k stops allows
   at most k + 1 flights.
4. Copy prev into curr so each iteration uses only routes
   from the previous iteration.
5. Relax every flight using prev[u] + price.
6. Return the destination cost, or -1 if unreachable.

Time Complexity: O((k + 1) * (n + m))
Space Complexity: O(n)
===========================================================
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        const int INF = 1e9;

        vector<int> prev(n, INF);
        prev[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> curr = prev;

            for (auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (prev[u] != INF) {
                    curr[v] = min(curr[v], prev[u] + price);
                }
            }

            prev = curr;
        }

        return prev[dst] == INF ? -1 : prev[dst];
    }
};