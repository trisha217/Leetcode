class Solution {
       vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // code here
        int res = 0;
        int N= grid.size();
        int M = grid[0].size();
        if (grid[0][0] != 0 | grid[N-1][M-1] != 0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<bool>> visit(N,vector<bool>(M,false));
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        dist[0][0] = 1;
        
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            int x = u.first;
            int y = u.second;
            visit[x][y] = true;
            
            for(auto d: dir) {
                int r = x + d[0];
                int c = y + d[1];
               
                if(r >=0 && r < N && c >=0 && c < M && grid[r][c]==0) {
                    if(!visit[r][c] && dist[r][c] > dist[x][y]+1) {
                       dist[r][c] = dist[x][y] +1;
                        q.push({r,c});
                    }
                }
            }
        }
        return dist[N-1][M-1] != INT_MAX ? dist[N-1][M-1]:-1;
    }
};