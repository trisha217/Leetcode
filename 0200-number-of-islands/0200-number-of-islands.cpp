class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y){
        //if out of bounds
        if(x<0 ||y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]!='1'){
            return;
        }
        //marking the grid so we don't visit again
        grid[x][y] = '*';
        dfs(grid,x-1,y);
        dfs(grid,x+1,y);
        dfs(grid,x,y-1);
        dfs(grid,x,y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};