class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edgeList(n), ans(n);
        for(const auto &i : edges)
            edgeList[i[0]].push_back(i[1]);
        
        for(int i = 0;i < n;i++){
            vector<int> vis(n);
            dfs(i, i, vis, ans, edgeList);
        }

        return ans;
    }

    void dfs(int node, int p, vector<int> &vis, vector<vector<int>> &ans, vector<vector<int>> &edgeList){
        vis[node] = true;
        for(const int &ch : edgeList[node]){
            if(!vis[ch]){
                ans[ch].push_back(p);
                dfs(ch, p, vis, ans, edgeList);
            }
        }
    }
};