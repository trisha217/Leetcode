class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int i=0 ,j = nums.size()-1;
        int ans = INT_MIN;
        while(i<j){
            int sum =nums[i++] + nums[j--];
            ans = max(ans , sum);
        }
        return ans;
        
    }
};