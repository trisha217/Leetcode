#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tempList;
        backtrack(res, tempList, nums, 0);
        return res;
    }
    
private:
    void backtrack(vector<vector<int>>& res, vector<int>& tempList, vector<int>& nums, int start) {
        res.push_back(tempList); // Add the current subset to the results
        for (int i = start; i < nums.size(); i++) { // Iterate over the elements starting from 'start'
            tempList.push_back(nums[i]); // Include the element in the current subset
            backtrack(res, tempList, nums, i + 1); // Recur with the next index
            tempList.pop_back(); // Remove the element to backtrack
        }
    }
};