/*
===========================================================
Problem: Odd Even Linked List
LeetCode: 328
Difficulty: Medium

Description:
Given the head of a singly linked list, group all nodes
at odd indices together followed by the nodes at even
indices.

The relative order within the odd and even groups should
remain the same.

Note:
The first node is considered to have index 1 (odd).

Example:
Input:  1 → 2 → 3 → 4 → 5
Output: 1 → 3 → 5 → 2 → 4

Input:  2 → 1 → 3 → 5 → 6 → 4 → 7
Output: 2 → 3 → 6 → 7 → 1 → 5 → 4

Approach:
Maintain two separate linked lists:

- odd points to the last node in the odd-indexed list.
- even points to the last node in the even-indexed list.
- evenHead stores the beginning of the even-indexed list.

For each iteration:
1. Connect the current odd node to the next odd node.
2. Move the odd pointer forward.
3. Connect the current even node to the next even node.
4. Move the even pointer forward.

Finally, attach the even list after the odd list.

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
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {

            // Connect odd nodes
            odd->next = even->next;
            odd = odd->next;

            // Connect even nodes
            even->next = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};