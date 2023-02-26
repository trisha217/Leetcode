class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>ans(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++)
            ans[i][0]=i;
        for(int j=1;j<=n;j++)
            ans[0][j]=j;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1])      
                    ans[i][j]=ans[i-1][j-1];
                else        
                    ans[i][j]=min({ans[i-1][j-1],ans[i-1][j],ans[i][j-1]})+1;
            }
        }
        return ans[m][n];
    }
};