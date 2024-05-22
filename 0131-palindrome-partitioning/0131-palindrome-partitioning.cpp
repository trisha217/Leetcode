class Solution {
public:
    
    bool is_palindrome(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(int i,string& s,vector<string>& v,vector<vector<string>>& ans,vector<vector<int>>& dp)
    {
        if(i>=s.size())
        {
            ans.push_back(v); return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(dp[i][j])
            {
                v.push_back(s.substr(i,j-i+1));
                solve(j+1,s,v,ans,dp);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(is_palindrome(i,j,s)) dp[i][j]=1;
            }
        }
        vector<vector<string>> ans;
        if(s.empty()) return ans;
        vector<string> v;
        solve(0,s,v,ans,dp);
        return ans;
    }
};
