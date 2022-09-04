class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int min = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+= nums[i];
            if(min>nums[i]){
                min= nums[i];
            }
        }
        int ans = sum - (n*min);
        return ans;
    }
};