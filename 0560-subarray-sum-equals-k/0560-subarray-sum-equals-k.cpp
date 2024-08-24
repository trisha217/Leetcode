class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum = 0;
        map<int,int> mpp;
        mpp[0]++;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            presum = presum + nums[i];
            int look = presum - k;
            cnt = cnt + mpp[look];
            mpp[presum]++;
        }
        return cnt;
    }
};