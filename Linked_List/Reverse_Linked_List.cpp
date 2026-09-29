/*
===========================================================
Problem: Reverse Linked List
LeetCode: 206
Difficulty: Easy

Description:
Given the head of a singly linked list, reverse the list
and return the new head.

Example:
Input: 1 → 2 → 3 → 4 → 5
Output: 5 → 4 → 3 → 2 → 1

Approach:
Use three pointers:

- prev stores the previous node.
- curr stores the current node.
- temp temporarily stores curr->next before changing
  the link.

For each node:
1. Store the next node.
2. Reverse the current node's pointer.
3. Move prev forward.
4. Move curr forward.

At the end, prev points to the new head.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
