class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string newS=s+"#"+rev;
        int len=findnp(newS);
        string add=s.substr(len,s.size()-len);
        reverse(add.begin(),add.end());
        string ans=add+s;
        return ans;
    }
    int findnp(string str){
        int n=str.size();
        vector<int>lps(n,0);
        int len=0;
        int i=1;
        while(i<n){
            if(str[i]==str[len]){
                lps[i++]=++len;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i++]=0;
                }
            }
        }
        return lps[n-1];
    }
};