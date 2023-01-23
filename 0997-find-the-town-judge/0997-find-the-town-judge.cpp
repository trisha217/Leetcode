 class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        int inDegree[n+1];
        int outDegree[n+1];
        
        memset(inDegree, 0, sizeof(inDegree));
        memset(outDegree, 0, sizeof(outDegree));
        
        for(vector<int> &v : trust)
            inDegree[v[1]]++, outDegree[v[0]]++;
        
        for(int i=1;i<=n;i++)
            if(outDegree[i] == 0 && inDegree[i] == n-1)
                return i;
        
        return -1;
        
    }
};