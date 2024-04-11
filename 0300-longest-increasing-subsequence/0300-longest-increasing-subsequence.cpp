class Solution {
public:
    int lengthOfLIS(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> dp(n,1);
        for(int ind=0;ind<n;ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++)
            {
                if(arr[prev_ind]<arr[ind]){
                    dp[ind] = max(1+dp[prev_ind],dp[ind]);
                }
            }
        }
        int maxi = 1;
        for(int i=0;i<n;i++){
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};