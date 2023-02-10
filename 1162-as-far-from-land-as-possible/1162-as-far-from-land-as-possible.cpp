class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int m = grid.size();

        int n = grid[0].size();

        queue<pair<int,int>> q;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==1)
                    q.push(make_pair(i,j));
            }
        }

        if (q.empty()|| q.size()==m*n)
            return -1;

        int dis = 0;
        int dx[]= {0,1,-1,0};
        int dy[]={1,0,0,-1};

        while(!q.empty()) {
            int qs = q.size();

            for (int j=0;j<qs;j++){
                pair<int,int> p = q.front();
                q.pop();
                for (int i=0;i<4;i++) {
                    int dr = p.first + dx[i];
                    int dc = p.second + dy[i];
                    if (dr>=0&&dr<m&&dc>=0&&dc<n&&grid[dr][dc]==0)
                        {   grid[dr][dc]=1;
                            q.push(make_pair(dr,dc));
                        }
                }
            }
            if (!q.empty()) dis++;

        }

        return dis;
        
    }
};