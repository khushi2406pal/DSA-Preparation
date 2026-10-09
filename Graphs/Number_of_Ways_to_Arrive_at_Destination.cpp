
/*
===========================================================
Problem: Number of Ways to Arrive at Destination
LeetCode: 1976
Difficulty: Medium

Description:
Given n cities and an array roads, where roads[i] =
[u, v, time] represents a bidirectional road between cities
u and v that takes time units to travel, return the number
of different shortest paths from city 0 to city n - 1.

Return the answer modulo 1e9 + 7.

Example:
Input:
n = 7
roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3},
         {1, 3, 3}, {6, 3, 3}, {3, 5, 1},
         {6, 5, 1}, {2, 5, 1}, {0, 4, 5},
         {4, 6, 2}}

Output: 4

Approach:
Use Dijkstra's algorithm while maintaining a ways array.

1. Build an adjacency list for the undirected weighted graph.
2. Initialize dist[0] = 0 and ways[0] = 1.
3. Use a min-heap to process the city with the smallest
   known distance.
4. If a shorter route to a neighbor is found:
   - Update its distance.
   - Set its number of ways to ways[u].
   - Push the updated distance into the heap.
5. If an equally short route is found, add ways[u] to
   ways[v], modulo 1e9 + 7.
6. Return ways[n - 1].

Time Complexity: O((n + m) log n)
Space Complexity: O(n + m)

Here, m is the number of roads.
===========================================================
*/
#include <vector>
#include <queue>
#include <climits>
using namespace std;


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adjList(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        vector<ll> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<pair<ll, int>>
        > minHeap;

        minHeap.push({0, 0});

        while (!minHeap.empty()) {
            auto [d, u] = minHeap.top();
            minHeap.pop();

            if (d > dist[u]) {
                continue;
            }

            for (auto [v, w] : adjList[u]) {
                ll newDist = d + w;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    minHeap.push({newDist, v});
                }
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};