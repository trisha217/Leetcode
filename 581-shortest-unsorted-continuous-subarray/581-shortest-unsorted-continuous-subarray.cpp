class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ans = nums;
        sort(nums.begin(),nums.end());
        int firstsame=0,lastsame=nums.size()-1;
        while(firstsame<nums.size() && ans[firstsame]==nums[firstsame]){
            firstsame++;   
        }
        while(lastsame>=0 && ans[lastsame]==nums[lastsame]){
            lastsame--;
        }
        if(firstsame<lastsame){
            return (lastsame-firstsame+1);
        }
        return 0;   
    }
};