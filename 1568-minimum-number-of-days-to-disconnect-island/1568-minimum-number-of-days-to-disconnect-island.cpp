class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>> &vis,int m,int n){

        if(row<0 || row>=m || col<0 || col>=n || vis[row][col]==1 || grid[row][col]==0){
            return;
        }
        vis[row][col]=1;

        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row+delR[i];
            int ncol = col+delC[i];
            dfs(nrow,ncol,grid,vis,m,n);
        }
    }
    int minDays(vector<vector<int>>& grid) {
        //The first thing that we would like to do here is that we would like to count the number of islands by doing a dfs.
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    dfs(i,j,grid,vis,m,n);                    
                    count++;
                }
            }
        }
        // cout<<count;

        //if the count of the island is 0 or greater that one than we do not need to make any removal so we return 0;
        if(count!=1)return 0;
        
        //if that is not the case then we try to convert every land cell into water and then try to find the number of island 
        //and then find the number of islands again using the above approach.
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // if the current cell is a land then set it to water and again calculate the number of islands. 
                if(grid[i][j]==1)
                {
                    //set it to zero.
                    grid[i][j]=0;
                    //and re-evaluate the number of islands.
                    int num = 0;
                    //a visited vector to keep track of visited cells.
                    vector<vector<int>> vis1(m,vector<int>(n,0));
                    for(int row=0;row<m;row++)
                    {
                        for(int col=0;col<n;col++)
                        {
                            if(grid[row][col]==1 && vis1[row][col]==0)
                            {
                                dfs(row,col,grid,vis1,m,n);                    
                                num++;
                            }
                        }
                    }
                    // If after converting one cell to water we get our number of island from 1 to 0 or greater than 1 we will return 
                    // 1 as our answer as it took us 1 removal. If that is not the case then it will surely take us 2 removal. We can
                    // say this by applying elemination. Since the answer will never be more than 2. 
                    // Why the answer will be atmost 2??.
                    // No matter how many land cell we have we only need to isolate on land cell to convert one island into 2. 
                    // To isolate 1 land cell we need at-max two removal. Because no matter the number of land cells we have there will
                    // always be a cell that is connected to land from only two side. If we remove those two side we can disconnect. 
                    
                    if(num!=1)
                    {
                        return 1;
                    }
                    grid[i][j]=1;//set it back to 1.
                    
                }
            }
        }
        return 2;
    }
};