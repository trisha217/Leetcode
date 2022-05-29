class Solution {
    public int countSquares(int[][] a) {
          int max = 0, n = a.length, m = a[0].length;
  int[][] dp = new int[n + 1][m + 1];
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1][j - 1] == 1) {
        dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
        max = dp[i][j] + max;
      }
    }
  }
        
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= m; j++) {
  //       System.out.print(dp[i][j]);
  //       System.out.print(" ");
  //   }
  //      System.out.println();
  // }
        
  
  // return the area
  return max;
    
    }
}