/*
===========================================================
Problem: Remove Nth Node From End of List
LeetCode: 19
Difficulty: Medium

Description:
Given the head of a linked list, remove the nth node from
the end of the list and return its head.

Example:
Input:
head = [1,2,3,4,5], n = 2

Output:
[1,2,3,5]

Explanation:
The 2nd node from the end is 4, so it is removed.

Approach:
Use two pointers, fast and slow, along with a dummy node.

1. Create a dummy node pointing to head.
2. Initialize both fast and slow at the dummy node.
3. Move fast n steps forward.
4. Move both fast and slow together until fast reaches
   the last node.
5. At this point, slow is positioned just before the node
   that needs to be removed.
6. Remove the node using:
       slow->next = slow->next->next
7. Return dummy->next.

The dummy node makes it easy to handle the case where the
head itself needs to be removed.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern:
Two Pointers / Fast & Slow Pointer
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove nth node from the end
        slow->next = slow->next->next;

        return dummy->next;
    }
};