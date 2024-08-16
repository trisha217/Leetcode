class Solution {
public:
//     int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
//         // Base cases
//         if (ind == 0) 
//             return arr[ind];
//         if (ind < 0)  
//             return 0;
//         // If the result for this index is already computed, return it
//         if (dp[ind] != -1)
//             return dp[ind];
//         // Choose the current element or skip it, and take the maximum
//         int pick = arr[ind] + solveUtil(ind - 2, arr, dp); // Choosing the current element
//         int nonPick = 0 + solveUtil(ind - 1, arr, dp);      // Skipping the current element

//         // Store the result in the DP table and return it
//         return dp[ind] = max(pick, nonPick);
//     }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int cur, prev=nums[0], prev2=nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1)
                pick = pick + prev2;
            int notpick = 0 + prev;
            cur= max(pick,notpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};