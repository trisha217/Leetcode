class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
        }
        for(int i=n-1;i>0;i--){
            if((sum-nums[i])>nums[i]){
                return sum;
            }
            else{
                sum = sum - nums[i];
            }
        }
        return -1;
    }
};