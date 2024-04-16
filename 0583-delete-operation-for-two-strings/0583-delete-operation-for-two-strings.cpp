class Solution {
public:
    int minDistance(string x, string y) {
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
        return m+n-prev[m]-prev[m];
    }
};