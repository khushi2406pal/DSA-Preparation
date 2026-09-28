/*
===========================================================
Problem: Reorder List
LeetCode: 143
Difficulty: Medium

Description:
Given the head of a singly linked list, reorder the list so that
the nodes are rearranged in the following order:

L0 → L1 → L2 → ... → Ln

becomes:

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

You must reorder the list in-place without modifying the values
inside the nodes.

Example:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Approach:
The solution is divided into three steps:

1. Find the middle of the linked list:
   - Use slow and fast pointers.
   - slow moves one node at a time.
   - fast moves two nodes at a time.

2. Reverse the second half:
   - Reverse the list starting from slow.
   - This gives the second half in reverse order.

3. Merge the two halves alternately:
   - Take one node from the first half.
   - Then take one node from the reversed second half.
   - Continue until the second half is exhausted.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

#include <vector>
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
    void reorderList(ListNode* head) {

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* second = reverseList(slow);
        ListNode* first = head;

        // Step 3: Merge the two halves alternately
        while (second->next != nullptr) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }

private:
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* temp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};