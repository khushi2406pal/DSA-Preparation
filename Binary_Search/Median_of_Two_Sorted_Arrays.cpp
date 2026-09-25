/*
===========================================================
Problem: Median of Two Sorted Arrays
LeetCode: 4
Difficulty: Hard

Description:
Given two sorted arrays nums1 and nums2, return the median
of the two sorted arrays.

The overall run time complexity must be O(log(m + n)).

Example 1:
Input:
nums1 = [1,3]
nums2 = [2]

Output:
2.00000

Example 2:
Input:
nums1 = [1,2]
nums2 = [3,4]

Output:
2.50000

Approach:
Use binary search on the smaller array.

Instead of merging the two arrays, divide both arrays into
a left half and a right half.

Let i be the partition position in nums1.
The corresponding partition position in nums2 is:

    j = (m + n + 1) / 2 - i

A correct partition satisfies:

    nums1[i-1] <= nums2[j]
    nums2[j-1] <= nums1[i]

When these conditions are satisfied, the median can be
calculated from the largest element on the left and the
smallest element on the right.

If nums1's left element is too large, move the binary
search to the left.

Otherwise, move it to the right.

INT_MIN and INT_MAX are used as boundary values when the
partition reaches either end of an array.

Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)

Pattern:
Binary Search on Partition
===========================================================
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        int half = (m + n + 1) / 2;

        while (left <= right) {

            int i = (left + right) / 2;
            int j = half - i;

            int Aleft = (i == 0)
                        ? INT_MIN
                        : nums1[i - 1];

            int Aright = (i == m)
                         ? INT_MAX
                         : nums1[i];

            int Bleft = (j == 0)
                        ? INT_MIN
                        : nums2[j - 1];

            int Bright = (j == n)
                         ? INT_MAX
                         : nums2[j];

            // Correct partition
            if (Aleft <= Bright && Bleft <= Aright) {

                // Odd total length
                if ((m + n) % 2 == 1) {
                    return max(Aleft, Bleft);
                }

                // Even total length
                return (max(Aleft, Bleft) +
                        min(Aright, Bright)) / 2.0;
            }

            // Move partition in nums1 to the left
            else if (Aleft > Bright) {
                right = i - 1;
            }

            // Move partition in nums1 to the right
            else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};