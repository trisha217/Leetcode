class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long ans=0;
        int cnt=0;
        while(k>0)
        {
            int val=happiness.back()-cnt;
            if(val>0)
            ans+=val;
            cnt++;
            happiness.pop_back();
            k--;
        }
        return ans;
    }
};