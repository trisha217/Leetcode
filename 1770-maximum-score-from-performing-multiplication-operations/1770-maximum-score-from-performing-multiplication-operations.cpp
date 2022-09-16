// class Solution {
// public:
//     int help(vector<int>& multipliers,vector<int> nums, int ind, int start,int dp[1001][1001]){
//         if(ind == nums.size()){
//             return 0;
//         }
//         if(dp[ind][start]!=-1){
//             return dp[ind][start];
//         }
//         int end = nums.size()-(ind-start)-1;
//         int op1 = multipliers[ind]*nums[start] + help(multipliers,nums,ind+1,start+1,dp);
//         int op2 = multipliers[ind]*nums[end] + help(multipliers,nums,ind+1,start,dp);
//         return dp[ind][start] = max(op1,op2);
//     }
//     int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//         int dp[1001][1001];
//         memset(dp,-1,sizeof dp);
//         return help(multipliers,nums,0,0,dp);
//     }
// };

class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int n, int j, vector<int> &nums, vector<int> &M){
        
        if (j == M.size()) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        
        // Left Side
        int left = solve(i + 1, n, j + 1, nums, M) + (nums[i] * M[j]);
        
        // Right Side
        int right = solve(i, n, j + 1, nums, M) + (nums[(n - 1) - (j - i)] * M[j]);
        
        return dp[i][j] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& M) {   
        int n = nums.size(), m = M.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, n, 0, nums, M);
    }
};