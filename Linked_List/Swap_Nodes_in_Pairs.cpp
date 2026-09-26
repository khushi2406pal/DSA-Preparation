/*
===========================================================
Problem: Swap Nodes in Pairs
LeetCode: 24
Difficulty: Medium

Description:
Given a linked list, swap every two adjacent nodes and
return its head.

You must solve the problem by modifying the nodes themselves
rather than changing their values.

Example:
Input:
head = [1,2,3,4]

Output:
[2,1,4,3]

Example 2:
Input:
head = [1,2,3]

Output:
[2,1,3]

Approach:
Use a dummy node and a pointer prev.

For every pair of nodes:
    first  = prev->next
    second = first->next

Rearrange their pointers:

    prev -> second -> first -> nextPair

After swapping, move prev to first, which is now the end
of the swapped pair.

The dummy node makes it easier to handle swapping when the
first pair includes the original head.

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
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != nullptr &&
               prev->next->next != nullptr) {

            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the two nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the end of the swapped pair
            prev = first;
        }

        return dummy->next;
    }
};