
/*
===========================================================
Problem: Next Greater Element I
LeetCode: 496
Difficulty: Easy

Description:
Given two distinct-element arrays nums1 and nums2, where
nums1 is a subset of nums2, find the next greater element
for each element in nums1.

The next greater element is the first element to its right
in nums2 that is greater than the current element.
If none exists, return -1.

Example:
Input:
nums1 = {4, 1, 2}
nums2 = {1, 3, 4, 2}

Output:
{-1, 3, -1}

Approach:
1. Traverse nums2 using a stack.
2. While the current number is greater than the stack's
   top, it is the next greater element for that top.
3. Store each result in a hash map.
4. Assign -1 to elements left in the stack.
5. Build the answer for nums1 using the hash map.

Time Complexity: O(n + m)
Space Complexity: O(n + m)

Here, n = nums2.size() and m = nums1.size().
===========================================================
*/
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Find next greater elements in nums2
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        // Remaining elements have no next greater element
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Build the answer for nums1
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};
