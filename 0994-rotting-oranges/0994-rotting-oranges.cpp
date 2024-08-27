class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        //{{row,col},time}
        queue<pair<pair<int,int>,int>> q;
        int time = 0;
        int fresh = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    //start rotting at '0' time
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int delrow[4] = {-1,0,+1,0};
        int delcol[4] = {0,+1,0,-1};
        int cnt =0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for(int i=0;i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc]!=2){
                    grid[nr][nc] = 2;
                    vis[nr][nc] = 2;
                    cnt++;
                    q.push({{nr, nc}, t + 1});
                }
            }
        }
        if(cnt!=fresh){
            return -1;
        }
        return time;
    }
};