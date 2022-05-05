class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int ans1=1,ans2=1;
        for(int i=0;i<3;i++){
            ans1=ans1* nums[i];
        }
        if(nums[nums.size()-1]<0 && nums[nums.size()-2]<0){
            ans2 = ans2*nums[nums.size()-1]*nums[nums.size()-2]*nums[0];
        }
        else{
            ans2=0;
        }
        return max(ans1,ans2);
    }
};