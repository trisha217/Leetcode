class Solution {
private:
    int dp[101][101];
    
    int helper(string &s,int start,int end)
    {
        if(start == end)
        {
            return 1;
        }
        
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        
        int res = INT_MAX;
        
        for(int i = start;i < end;i++)
        {
            res = min(res, helper(s,start,i)+ helper(s,i+1,end));
        }
        
        if(s[start] == s[end])
        {
            return dp[start][end] = res - 1;
        }
        else
        {
            return dp[start][end] = res;    
        }
    }
    
public:
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        
        return helper(s,0,s.length()-1);
    }
};