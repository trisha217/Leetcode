class Solution {
public:
    void bfs1(int src, vector<vector<int>> &adj, vector<int> &distance, vector<bool> &visited) {
        queue<int> q;

        q.push(src);
        distance[src] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            visited[u] = true;

            for (auto &v : adj[u]) {
                if (visited[v])
                    continue;

                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    int bfs2(int src, int n, vector<vector<int>> &adj, vector<int> &dist_node1, vector<bool> &visited_node1) {
        vector<int> distance(n, INT_MAX);
        vector<bool> visited(n, false);

        queue<int> q;

        q.push(src);
        distance[src] = 0;

        int answer = INT_MAX;
        int minimum = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            visited[u] = true;

            for (auto &v : adj[u]) {
                if (visited[v])
                    continue;

                distance[v] = distance[u] + 1;
                q.push(v);
            }

            if (!visited_node1[u])
                continue;

            int max_dist = max(distance[u], dist_node1[u]);

            if (max_dist < minimum) {
                minimum = max_dist;
                answer = u;
                continue;
            }
            
            if (max_dist == minimum)
                answer = min(answer, u);
        }

        if (answer == INT_MAX)
            return -1;

        return answer;
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        int n = edges.size();

        vector<vector<int>> adj(n);

        for (int u = 0; u < n; u++) {
            int v = edges[u];

            if (v == -1)
                continue;

            adj[u].push_back(v);
        }

        vector<int> dist_node1(n, INT_MAX);
        vector<bool> visited_node1(n, false);

        bfs1(node1, adj, dist_node1, visited_node1);

        return bfs2(node2, n, adj, dist_node1, visited_node1);
    }
};