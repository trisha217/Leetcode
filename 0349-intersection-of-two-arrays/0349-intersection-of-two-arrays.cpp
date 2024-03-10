#include <unordered_map>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums1) {
            frequencyMap[num] = 2;
        }
        int count = 0;
        for (int num : nums2) {
            if (frequencyMap[num] == 2) {
                count++;
                frequencyMap[num] = 1;
            }
        }
        vector<int> result(count);
        int index = 0;
        for (int num : nums2) {
            if (frequencyMap[num] == 1) {
                frequencyMap[num] = 0;
                result[index++] = num;
            }
        }
        return result;
    }
};