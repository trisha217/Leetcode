class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<int>indeg(n, 0);
        int ans=-1, c=0;
        for(int i=0;i<edges.size();i++)
        {
            indeg[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                ans=i;
                c++;
            }
        }
        if(c>1)
        {
            return -1;
        }
        return ans;
    }
};