class Solution {
public:
    string shortestCommonSupersequence(string x, string y) {
        int n=x.size(),m=y.size();
        string s;
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        // for printing longest common subsequence
        int i=n,j=m;
        while(i>0 && j>0){    // if any of this i and j becomes 0 means one string is empty 
            if(x[i-1]==y[j-1]){
                s+=x[i-1];    //if character matches then add that to result string and move diagonally up
                i--;j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                s+=y[j-1];
                j--;    // else find the max of up and right position of dp table and move accordingly to up or left
            }
            else{
                s+=x[i-1];
                i--; 
            }
        }
        while(i>0){
            s+=x[i-1];
            i--;
        }
        while(j>0){
            s+=y[j-1];
            j--; 
        }
        reverse (s.begin(),s.end());    // reverse the string as we started from last
        return s;
    }
};