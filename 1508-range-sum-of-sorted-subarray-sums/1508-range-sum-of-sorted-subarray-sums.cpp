class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefixsum(n+1,0);
        for(int i=0;i<n;i++){
            prefixsum[i+1] = prefixsum[i] + nums[i];
        }
        vector<int> sum;
        for(int l=0;l<n;l++){
            for(int r=l;r<n;r++){
               sum.push_back(prefixsum[r+1]-prefixsum[l]); 
            }
        }
        sort(sum.begin(),sum.end());
        int ans = 0;
        for (int i=left-1; i<right; i++) {
            ans += sum[i];
            ans %= 1000000007;
        }
        return ans;
    }
};