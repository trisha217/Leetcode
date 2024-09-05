class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean*(rolls.size() + n);
        long long sum2 = 0;
        for(auto i : rolls){
        sum2 = sum2 + i;
        }
        int rsum = sum - sum2;
        if(n*6<rsum || n*1>rsum) return {};
        vector<int> ans(n,rsum/n);
        for(int i =0;i<rsum%n;i++){
            ans[i]++;
        }
        return ans;
    }
};