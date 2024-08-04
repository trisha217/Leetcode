class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1 && grid[0][0]!=1){
            return 1;
        }
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        dist[0][0]=1;
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        while(!q.empty()){
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for(int i = 0; i < 8; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = dis + 1;
                    if (newr == n-1 && newc == n-1)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};