class Solution {
public:
    // int numTrees(int n) {
    //     if(n <= 1) return 1;
    //     int ans = 0;
    //     for(int i = 1; i <= n; i++) 
    //         ans += numTrees(i-1) * numTrees(n-i);
    //     return ans;
    // }
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) 
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
};

/*observation is
      3                         
    /   \
f(2)    f(0) 
    i = 3
    
                      i
	=>              /   \ 
         numTrees(i-1)	numTrees(n-i)
    
    
*/

