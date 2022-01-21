class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        while(r<nums.size())
        {
            if(nums[r]==0){
                r++;
            }
            else
            {
                int tmp = nums[r];
                nums[r] = nums[l];
                nums[l] = tmp;            
                r++;
                l++;
            }
        }
    }
};