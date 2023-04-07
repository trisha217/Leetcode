class Solution {
public:
    int count=0;
    void solve(vector<vector<int>>& grid,int n,int m,int i,int j){
        if(i>=n || j>=m || i<0 ||j<0 || grid[i][j]==0)return;
        grid[i][j]=0;
        solve(grid,n,m,i+1,j);
        solve(grid,n,m,i,j+1);
        solve(grid,n,m,i-1,j);
        solve(grid,n,m,i,j-1);
    }
        
        
        
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        int count=0;
        for(int i=0; i<n; i++)
            solve(grid,n,m,i,0), solve(grid,n,m,i,m-1);
        for(int j=0; j<m; j++)
            solve(grid,n,m,0,j), solve(grid,n,m,n-1,j);
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};