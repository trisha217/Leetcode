class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        vector<bool> freqs(nums.size()+1);
        int n = nums.size();
        for(auto &num:nums){
            if(freqs[num]){
                ans.push_back(num);
                break;
            }else{
                freqs[num] = true;
            }
        }
        int sum1 = (n*(n+1))/2;
        int sum2 = accumulate(nums.begin(),nums.end(),0);
        ans.push_back(sum1-sum2+ans[0]);
        return ans;
    }
};