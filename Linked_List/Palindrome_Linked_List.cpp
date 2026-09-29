/*
===========================================================
Problem: Palindrome Linked List
LeetCode: 234
Difficulty: Easy

Description:
Given the head of a singly linked list, determine whether
the linked list is a palindrome.

A palindrome reads the same forward and backward.

Example:
Input: 1 → 2 → 2 → 1
Output: true

Input: 1 → 2
Output: false

Approach:
1. Use slow and fast pointers to find the middle of the list.
2. Reverse the second half of the linked list.
3. Compare the first half with the reversed second half.
4. If all corresponding values are equal, the list is a
   palindrome.

The slow pointer moves one step at a time while the fast
pointer moves two steps at a time.

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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Find the middle of the linked list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* secondHalf = reverseList(slow);

        // Compare both halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;

        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }

private:
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