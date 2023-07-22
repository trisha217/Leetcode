class Solution {
public:

int rows[8] = {-2,-1,1,2,2,1,-1,-2};
int cols[8] = {1,2,2,1,-1,-2,-2,-1};

bool isPossible(int i, int j, int n){
    return ((i >= 0) && (j >= 0) && (i<n) && (j<n));
}

double dp[101][26][26];

double possibleWays(int n, int k, int r, int c){
    if(!isPossible(r,c,n))
         return 0;
    if(k == 0){
        return 1;
    }
    if(dp[k][r][c])
        return dp[k][r][c];
    double ans = 0;
    for(int i=0;i<8;i++){
        ans += possibleWays(n,k-1,r+rows[i],c+cols[i]);
    }
    dp[k][r][c] = ans;
    return dp[k][r][c];
}

double knightProbability(int n, int k, int row, int column) {
    if(k == 0) return 1;
    double totalCases = pow(8,k);
    memset(dp,0,sizeof(dp));
    return (possibleWays(n,k,row,column))/totalCases;
}
};