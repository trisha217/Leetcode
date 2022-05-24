class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        int choice1;
        int choice2;
        int maxp= nums[0];
        int minp= nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            choice1 = maxp * nums[i];
            choice2 = minp * nums[i];
            maxp = max(nums[i],max(choice1,choice2));
            minp = min(nums[i],min(choice1,choice2));
            ans = max(maxp,ans); 
        }
        return ans;
    }
};