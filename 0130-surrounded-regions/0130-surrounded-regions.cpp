class Solution {
public:
    int newrow[4]= {-1,0,+1,0};
    int newcol[4]= {0,+1,0,-1};
    void dfs(int row, int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<4;i++){
            int nr = row + newrow[i];
            int nc = col + newcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        //traverse rows
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            //last row
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }
        //traverse columns
        for(int j=0;j<n;j++){
            //first col
            if(!vis[j][0] && board[j][0]=='O'){
                dfs(j,0,vis,board);
            }
            //last col
            if(!vis[j][m-1] && board[j][m-1]=='O'){
                dfs(j,m-1,vis,board);
            }
        }
        //travese whole
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};