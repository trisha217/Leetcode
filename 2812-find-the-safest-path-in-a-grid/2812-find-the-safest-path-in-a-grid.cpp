class Solution {
public:
    bool checkPath(vector<vector<int>>&grid,int val) {
        int n = grid.size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        q.push({0,0});
        visited[0][0] = true;
        if(grid[0][0]<val) {
            return false;
        }
        while(!q.empty()) {
            pair<int,int>p = q.front();
            q.pop();
            int row = p.first;int col = p.second;
            if(row==n-1 && col==n-1) {
                return true;
            }
            for(int i=0;i<4;i++) {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=n || visited[nrow][ncol] || grid[nrow][ncol]<val) {
                    continue;
                }
                visited[nrow][ncol] = true;
                q.push({nrow,ncol});
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //First of all let us calculate manhattan distance from all the cells to the nearest thief cells
        int n = grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        int level = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                pair<int,int>p = q.front();
                int row = p.first; int col = p.second;
                q.pop();
                dist[row][col] = level;
                for(int i=0;i<4;i++) {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !visited[nrow][ncol]) {
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = true;
                }else continue;
            }
            }
            level++;
        }
        int l = 0;
        int r = 400;
        int res = 0;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(checkPath(dist,mid)) {
                res = mid;
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
        return res;
    }
};