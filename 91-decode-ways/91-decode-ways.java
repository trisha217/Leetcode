class Solution {
    public int numDecodings(String s) {
        int n= s.length();
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = s.charAt(0) == '0' ? 0 : 1;
        for(int i = 2;i<=n;i++){
            int oneD = Integer.valueOf(s.substring(i-1,i));
            int twoD = Integer.valueOf(s.substring(i-2,i));
            if(oneD>=1){
                dp[i] = dp[i] + dp[i-1];
            }
            if(twoD>=10 && twoD<=26){
                dp[i] = dp[i] + dp[i-2];
            } 
        }
        return dp[n];
    }
}