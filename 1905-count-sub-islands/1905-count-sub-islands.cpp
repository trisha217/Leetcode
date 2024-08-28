class Solution {
public:
    bool dfs(int x, int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(x<0||y<0||x>=grid1.size()||y>=grid1[0].size()||grid2[x][y]==0)
        {
            return true;
            
        }
        if(grid1[x][y]==0 && grid2[x][y]==1){
            return false;
        }
        grid2[x][y]=0;
        bool b1 = dfs(x+1,y,grid1,grid2);
        bool b2 = dfs(x-1,y,grid1,grid2);
        bool b3 = dfs(x,y+1,grid1,grid2);
        bool b4 = dfs(x,y-1,grid1,grid2);
        return b1&&b2&&b3&&b4;
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] == 1){
                    cnt = cnt + (dfs(i,j,grid1,grid2)?1:0);
                }
            }
        }
        return cnt;
    }
};