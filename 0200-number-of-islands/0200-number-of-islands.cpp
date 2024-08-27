class Solution {
public:
    void dfs(vector<vector<char>>& grid, int y, int x){
        //if out of bounds
        if(x<0 ||y<0 || y>=grid.size() || x>=grid[0].size() || grid[y][x]!='1'){
            return;
        }
        //marking the grid so we don't visit again
        grid[y][x] = '*';
        dfs(grid,y-1,x);
        dfs(grid,y+1,x);
        dfs(grid,y,x-1);
        dfs(grid,y,x+1);
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