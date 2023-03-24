class Solution {
public:
    unordered_map<int, vector<pair<int, bool>>> G;
    bool visited[(int) 1e5 + 1];
    int solve(int node) {
        if(visited[node]) {
            return 0;
        }
        visited[node] = true;
        int ans = 0;
        for(auto &edge: G[node]) {
            int child = edge.first;
            int direction = edge.second;
            if(direction == false && !visited[child]) {
                // cout << node << " - " << child << " - " <<  direction << endl;
                ans += 1 + solve(child);
            } else {
                ans += solve(child);
            }
        }
        return ans;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto &connection : connections) {
            G[connection[0]].push_back({connection[1], false}); // away false;
            G[connection[1]].push_back({connection[0], true}); // towards true
        }
        memset(visited, false, sizeof(visited));
        return solve(0);
    }
};
