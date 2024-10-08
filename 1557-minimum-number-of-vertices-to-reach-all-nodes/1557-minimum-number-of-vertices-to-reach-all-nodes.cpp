class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int>indeg(n,0);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};