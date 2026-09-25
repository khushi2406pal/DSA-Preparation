/*
===========================================================
Problem: Remove Duplicates from Sorted Array
LeetCode: 26
Difficulty: Easy

Description:
Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place such that each unique element
appears only once.

Return the number of unique elements, k.

The first k elements of nums should contain the unique
elements in their original order.

Example:
Input:
nums = [1,1,2]

Output:
2

Modified nums:
[1,2,_]

Example 2:
Input:
nums = [0,0,1,1,1,2,2,3,3,4]

Output:
5

Modified nums:
[0,1,2,3,4,_,_,_,_,_]

Approach:
Use two pointers.

The pointer k keeps track of the position where the next
unique element should be placed.

Start k at 1 because the first element is always unique.

Traverse the array using i:
- If nums[i] is different from the previous element,
  it is a new unique element.
- Place it at nums[k] and increment k.

Because the array is sorted, duplicates are always adjacent.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern:
Two Pointers / In-Place Array Modification
===========================================================
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        int k = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};