/*
===========================================================
Problem: Merge Two Sorted Lists
LeetCode: 21
Difficulty: Easy

Description:
Given the heads of two sorted linked lists, merge them into
one sorted linked list.

The merged list should be created by splicing together the
nodes of the given lists.

Example:
Input:
list1 = [1,2,4]
list2 = [1,3,4]

Output:
[1,1,2,3,4,4]

Approach:
Use a dummy node and a tail pointer.

1. Create a dummy node to simplify list construction.
2. Compare the current nodes of list1 and list2.
3. Attach the smaller node to the merged list.
4. Move the corresponding list pointer forward.
5. Move the tail pointer forward.
6. When one list becomes empty, attach the remaining
   nodes of the other list.
7. Return dummy->next.

The existing nodes are reused, so no new nodes are required
apart from the dummy node.

Time Complexity: O(m + n)
Space Complexity: O(1)

Pattern:
Linked List / Two Pointers
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Attach the remaining nodes
        if (list1 != nullptr) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        return dummy->next;
    }
};