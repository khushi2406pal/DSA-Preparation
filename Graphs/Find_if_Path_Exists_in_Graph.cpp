/*
===========================================================
Problem: Find if Path Exists in Graph
LeetCode: 1971
Difficulty: Easy

Description:
Given an undirected graph with n nodes labeled from 0 to n-1
and a list of edges, determine whether there is a valid path
from the source node to the destination node.

Example:
Input:
n = 3
edges = [[0,1],[1,2]]
source = 0
destination = 2

Output:
true

Approach:
1. Build an adjacency list from the given edges.
2. Since the graph is undirected, add each node to the
   other's adjacency list.
3. Use DFS starting from the source node.
4. Maintain a visited array to avoid visiting the same node
   repeatedly.
5. If DFS reaches the destination, return true.
6. If all reachable nodes are explored without finding the
   destination, return false.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
===========================================================
*/
using namespace std;
#include<vector>
#include <iostream>

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adjList(n);

        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);

        return dfs(source, destination, adjList, visited);
    }

private:
    bool dfs(int node, int destination,
             vector<vector<int>>& adjList,
             vector<bool>& visited) {

        if (node == destination) {
            return true;
        }

        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, adjList, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};