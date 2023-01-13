class Solution {
public:
    int n, ans = 0;
    vector<int> best, children;
    vector<vector<int>> adj;
    queue<int> q;

    void dfs(int node) {
        if (children[node] == 0) q.push(node);
        for (int i : adj[node]) dfs(i);
        return;
    }

    int longestPath(vector<int>& par, string s) {
        n = par.size();
        best.resize(n);
        children.resize(n);
        adj.resize(n);
        for (int i = 1; i < n; i++) {
            adj[par[i]].push_back(i);
            children[par[i]]++;
        }
        dfs(0);
        while (not q.empty()) {
            int cur = q.front(), mxx = 0, mx = 0;
            q.pop();
            for (int i : adj[cur]) {
                if (s[i] == s[cur]) continue;
                mx = max(best[i], mx);
                if (mxx < mx) swap(mx, mxx);
            }
            mxx++;
            ans = max(mxx + mx, ans);
            best[cur] = mxx;
            if (par[cur] == -1) continue;
            children[par[cur]]--;
            if (children[par[cur]] == 0) q.push(par[cur]);
        }
        return ans;
    }
};