/*
===========================================================
Problem: Remove Duplicates from Sorted List II
LeetCode: 82
Difficulty: Medium

Description:
Given the head of a sorted linked list, delete all nodes
that have duplicate numbers, leaving only distinct numbers.

Return the linked list sorted as well.

Example 1:
Input:
head = [1,2,3,3,4,4,5]

Output:
[1,2,5]

Example 2:
Input:
head = [1,1,1,2,3]

Output:
[2,3]

Approach:
Use a dummy node and two pointers:

- prev points to the last node that is confirmed unique.
- curr scans through the linked list.

When curr and curr->next have the same value, skip all
nodes with that duplicate value.

Then connect prev directly to the first node after the
duplicate group.

If curr is not part of a duplicate group, move prev forward.

The dummy node handles cases where duplicate nodes occur
at the beginning of the list.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern:
Linked List / Pointer Manipulation
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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {

            // Found a duplicate group
            if (curr->next != nullptr &&
                curr->val == curr->next->val) {

                // Skip all nodes with the same value
                while (curr->next != nullptr &&
                       curr->val == curr->next->val) {
                    curr = curr->next;
                }

                // Remove the entire duplicate group
                prev->next = curr->next;
                curr = curr->next;
            }
            else {
                // Current node is unique
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};