class Solution {
private:
    int atmostk(vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        int count = 0;
        int n = nums.size();
        int freq[20005] = {0};
        
        while(right < n){
            if(freq[nums[right]]++ == 0){
                k--;
            }
            while(k < 0){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) k++;
                left++;
            }

            count += right - left + 1;

            right++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atmostk(nums,k) - atmostk(nums,k-1);
    }
};