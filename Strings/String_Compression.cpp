/*
===========================================================
Problem: String Compression
LeetCode: 443
Difficulty: Medium

Description:
Given an array of characters, compress it using the following
rules:

- For consecutive repeating characters, write the character
  followed by its count.
- If a character appears only once, write only the character.
- Modify the input array in-place.
- Return the new length of the compressed array.

Example:
Input:  chars = ["a","a","b","b","c","c","c"]
Output: 6

Compressed array:
["a","2","b","2","c","3"]

Input:  chars = ["a"]
Output: 1

Approach:
Use two pointers to process consecutive groups of characters.

1. 'i' marks the beginning of the current group.
2. 'j' moves forward to find the end of the group.
3. Calculate the group's frequency using:
       count = j - i
4. Write the character at the 'write' position.
5. If count > 1, convert the count to a string and write
   each digit into the array.
6. Move 'i' to the beginning of the next group.

The array is modified in-place, so no separate output array
is required.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space

===========================================================
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        int i = 0;
        int write = 0;

        while (i < n) {

            int j = i;

            // Find the end of the current group
            while (j < n && chars[j] == chars[i]) {
                j++;
            }

            int count = j - i;

            // Write the character
            chars[write++] = chars[i];

            // Write the frequency
            if (count > 1) {

                string freq = to_string(count);

                for (char c : freq) {
                    chars[write++] = c;
                }
            }

            i = j;
        }

        return write;
    }
};