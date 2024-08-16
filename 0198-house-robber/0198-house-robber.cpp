class Solution {
public:
    int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
        // Base cases
        if (ind == 0) 
            return arr[ind];
        if (ind < 0)  
            return 0;
        // If the result for this index is already computed, return it
        if (dp[ind] != -1)
            return dp[ind];
        // Choose the current element or skip it, and take the maximum
        int pick = arr[ind] + solveUtil(ind - 2, arr, dp); // Choosing the current element
        int nonPick = 0 + solveUtil(ind - 1, arr, dp);      // Skipping the current element

        // Store the result in the DP table and return it
        return dp[ind] = max(pick, nonPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // Edge case: empty array
        if (n == 1) return nums[0];  // Edge case: single element array
        vector<int> dp(n, -1); // Initialize the DP table with -1
        return solveUtil(n - 1, nums, dp); 
    }
};