class Solution {
public:
    int f(int i, int j1, int j2,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n){
        //base case - out of bounds
        if(j1<0 || j1>=n || j2<0 || j2>=n){
            return -1e9;
        }
        //base case - destination
        if(i == m-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = INT_MIN;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ans;
                if (j1 == j2)
                    ans = grid[i][j1] + f(i + 1, j1 + di, j2 + dj, grid, dp, m, n);
                else
                    ans = grid[i][j1] + grid[i][j2] + f(i + 1, j1 + di, j2 + dj, grid, dp, m, n);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return f(0,0,n-1,grid,dp,m,n);
    }
};