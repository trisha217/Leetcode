class Solution {
public:
    int minInsertions(string x) {
        string y = x;
        reverse(x.begin(),x.end());
        int n=x.size(),m=y.size();
        vector<int> cur(m+1,0);
        vector<int> prev(m+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])
                    cur[j]=1 + prev[j-1];
                else {
                    cur[j]=max(cur[j-1],prev[j]);
                }
            }
            prev = cur;
        }
        return n-prev[m];
    }
};