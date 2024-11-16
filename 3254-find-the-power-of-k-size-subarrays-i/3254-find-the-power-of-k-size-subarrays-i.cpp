class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(nums.size()==1)return {nums[0]};
        if(k==1)return nums;
        vector<int> result(nums.size() - k + 1, -1);
        int left = 0, right = 0;
        int cons_element = 1;
        int maxi = nums[0];
        while (right < nums.size()-1) {
            if (nums[right + 1] == nums[right] + 1) {
                maxi = max(nums[right + 1], maxi);
                cons_element++;
            } else {
                maxi = INT_MIN;
                cons_element = 1;
                left = right + 1;
            }
            if (cons_element == k) {
                result[left] = maxi;
                left++;
                cons_element--;
            }
            right++;
        }
        return result;
    }
};