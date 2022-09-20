class Solution {
    public static int solve(int n,int[] dp){
        if(n ==1){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        else{
            for(int i=1;i<n;i++){
                if(n%i==0){
                    if(solve(n-i,dp)==0){
                        return dp[n]=1;
                    }
                }
            }
            return dp[n]=0;
        }
    }
    public boolean divisorGame(int n) {
        int[] dp = new int[1001];
        Arrays.fill(dp,-1);
        int ans = solve(n,dp);
        if(ans ==1){
            return true;
        }
        else{
            return false;
        }
    }
}