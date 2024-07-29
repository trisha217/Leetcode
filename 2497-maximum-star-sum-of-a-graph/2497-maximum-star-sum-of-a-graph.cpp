class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        int ans = INT_MIN;
        // Create the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            vector<int> neighbourVals;
            for(auto it: adj[i]){
                neighbourVals.push_back(vals[it]);
            }
            sort(neighbourVals.rbegin(),neighbourVals.rend());
            int sum = vals[i];
            for(int j=0;j<min(k,(int)neighbourVals.size());j++){
                if (neighbourVals[j] > 0) {  // Only include positive values from neighbors
                    sum += neighbourVals[j];
                }
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};