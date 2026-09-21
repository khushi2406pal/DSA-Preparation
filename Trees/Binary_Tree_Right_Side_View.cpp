/*
===========================================================
Problem: Binary Tree Right Side View
LeetCode: 199
Difficulty: Medium

Description:
Given the root of a binary tree, imagine standing on the
right side of the tree. Return the values of the nodes
visible from the right side, from top to bottom.

Approach:
1. Use Breadth-First Search (BFS) with a queue.
2. Process the tree level by level.
3. For each level, the last node processed is the node
   visible from the right side.
4. Add that node's value to the result.

Time Complexity: O(n)
Space Complexity: O(n)
===========================================================
*/

#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if (root == nullptr)
            return {};

        vector<int> result;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Last node of this level is visible
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }

                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }
        }

        return result;
    }
};

