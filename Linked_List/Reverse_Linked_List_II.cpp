/*
===========================================================
Problem: Reverse Linked List II
LeetCode: 92
Difficulty: Medium

Description:
Given the head of a singly linked list and two integers
left and right, reverse the nodes of the list from position
left to position right, and return the reversed list.

The reversal must be done in-place.

Example:
Input:
head = [1,2,3,4,5], left = 2, right = 4

Output:
[1,4,3,2,5]

Approach:
Use a dummy node to simplify the case where left == 1.

1. Move prev to the node immediately before position left.
2. Set curr to the first node of the section to reverse.
3. Repeatedly take the node after curr and move it to the
   front of the reversing section.
4. Continue until the required section has been reversed.

The important pointer operation is:

    temp = curr->next
    curr->next = temp->next
    temp->next = prev->next
    prev->next = temp

This reverses the section without creating new nodes.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern:
Linked List / In-Place Reversal / Pointer Manipulation
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Dummy node handles the case where left == 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Move prev to the node just before left
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // First node of the section being reversed
        ListNode* curr = prev->next;

        // Reverse the required section
        for (int i = 0; i < right - left; i++) {

            ListNode* temp = curr->next;

            // Remove temp from its current position
            curr->next = temp->next;

            // Insert temp at the front of the reversed section
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;
    }
};