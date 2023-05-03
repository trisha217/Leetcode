class Solution {
public:
    
    // Runtime 44 ms Beats 91.27% Memory 31 MB Beats 80.6%
std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
    // Hashset method
    // use two hashsets to store the unique numbers of nums1 and nums2 respectively

    // Time complexity: O(nums1.length + nums2.length)
    // Space complexity: O(nums1.length + nums2.length)

    std::vector<std::vector<int>> result(2);
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    for (int n1 : set1) {
        if (set2.count(n1)) continue;
        result[0].push_back(n1);
    }
    for (int n2 : set2) {
        if (set1.count(n2)) continue;
        result[1].push_back(n2);
    }
    return result;
}
};