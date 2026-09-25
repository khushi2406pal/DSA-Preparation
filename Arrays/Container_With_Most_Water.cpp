/*
===========================================================
Problem: Container With Most Water
LeetCode: 11
Difficulty: Medium

Description:
Given an array of heights where each element represents
the height of a vertical line, find two lines that,
together with the x-axis, form a container that holds
the most water.

Return the maximum amount of water the container can hold.

Example:
Input:
height = [1,8,6,2,5,4,8,3,7]

Output:
49

Approach:
Use the Two Pointer technique.

Start with two pointers:
- left at the beginning
- right at the end

The amount of water between them is:

    Area = min(height[left], height[right]) * (right - left)

After calculating the area, move the pointer pointing to
the shorter line.

Why?
The shorter line limits the amount of water. Moving the
taller line cannot increase the height of the container,
while moving the shorter line gives a chance to find a
taller boundary.

Continue until the two pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern:
Two Pointers
===========================================================
*/

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {

            int h = min(height[left], height[right]);
            int width = right - left;

            int area = h * width;
            maxWater = max(maxWater, area);

            // Move the pointer with the smaller height
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxWater;
    }
};