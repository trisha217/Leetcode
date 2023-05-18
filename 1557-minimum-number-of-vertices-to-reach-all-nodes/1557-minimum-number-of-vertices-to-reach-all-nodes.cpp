class Solution {
public:
 vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> parent(n),ans ;
        for(int i=0;i<n;i++) parent[i] = i ;
        for(int i=0;i<edges.size();i++) 
            parent[edges[i][1]] = edges[i][0] ;
        for (int i=0;i<n;i++) 
            if (parent[i]==i)ans.push_back(i) ;
        return ans ;
    }
};