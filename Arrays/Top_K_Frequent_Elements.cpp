/*
===========================================================
Problem: Top K Frequent Elements
LeetCode: 347
Difficulty: Medium

Approach:
1. Count the frequency of each number using an unordered_map.
2. Create buckets where the index represents frequency.
3. Place each number into its corresponding frequency bucket.
4. Traverse the buckets from highest frequency to lowest.
5. Add elements until we have k elements.

Time Complexity: O(n)
Space Complexity: O(n)
===========================================================
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);

        for (auto &pair : freqMap) {
            int value = pair.first;
            int count = pair.second;

            buckets[count].push_back(value);
        }

        vector<int> result;

        for (int i = n; i > 0; i--) {
            for (int value : buckets[i]) {
                result.push_back(value);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};