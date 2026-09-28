/*
===========================================================
Problem: Linked List Cycle
LeetCode: 141
Difficulty: Easy

Description:
Given the head of a linked list, determine if the linked list
contains a cycle.

A cycle exists if a node can be reached again by continuously
following the next pointer.

Example:
Input: head = [3,2,0,-4], pos = 1
Output: true

Input: head = [1,2], pos = -1
Output: false

Approach:
Use Floyd's Cycle Detection Algorithm with two pointers:

- slow moves one node at a time.
- fast moves two nodes at a time.
- If there is a cycle, fast will eventually meet slow.
- If fast reaches nullptr or fast->next reaches nullptr,
  there is no cycle.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/
#include<vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};