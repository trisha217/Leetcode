class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
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