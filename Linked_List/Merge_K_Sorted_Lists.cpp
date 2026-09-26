/*
===========================================================
Problem: Merge k Sorted Lists
LeetCode: 23
Difficulty: Hard

Description:
You are given an array of k linked lists, where each linked
list is sorted in ascending order.

Merge all the linked lists into one sorted linked list and
return its head.

Example:
Input:
lists = [[1,4,5],
         [1,3,4],
         [2,6]]

Output:
[1,1,2,3,4,4,5,6]

Approach:
Use Divide and Conquer.

Instead of merging all k lists at once:

1. Divide the list of linked lists into two halves.
2. Recursively merge each half.
3. Merge the two resulting sorted lists.
4. Continue until only one list remains.

The mergeTwoLists() function recursively merges two sorted
linked lists.

This is similar to Merge Sort.

Time Complexity: O(N log k)
Space Complexity: O(log k)

Where:
- N = total number of nodes across all linked lists
- k = number of linked lists

Pattern:
Linked List / Divide and Conquer / Merge Sort
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

    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (!l1) {
            return l2;
        }

        if (!l2) {
            return l1;
        }

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    // Merge k sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) {
            return nullptr;
        }

        return divideAndConquer(lists, 0, lists.size() - 1);
    }

    // Divide and conquer
    ListNode* divideAndConquer(
        vector<ListNode*>& lists,
        int left,
        int right
    ) {

        if (left == right) {
            return lists[left];
        }

        int mid = left + (right - left) / 2;

        ListNode* l1 = divideAndConquer(
            lists, left, mid
        );

        ListNode* l2 = divideAndConquer(
            lists, mid + 1, right
        );

        return mergeTwoLists(l1, l2);
    }
};