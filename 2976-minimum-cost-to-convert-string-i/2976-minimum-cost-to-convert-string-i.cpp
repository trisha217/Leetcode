class Solution {
// Find me on : https://leetcode.com/u/watch-this/
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int INF = 1e9;

        // Initialize the cost matrix with INF
        vector<vector<int>> minCost(26, vector<int>(26, INF));
        
        // Distance to self is zero
        for (int i = 0; i < 26; ++i) {
            minCost[i][i] = 0;
        }

        // Build the initial cost matrix from given transformations
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            minCost[u][v] = min(minCost[u][v], cost[i]);
        }

        // Apply Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (minCost[i][k] < INF && minCost[k][j] < INF) {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;

        // Calculate the total minimum cost to convert source to target
        for (int i = 0; i < n; ++i) {
            if (source[i] == target[i]) continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (minCost[u][v] == INF) return -1; // Transformation is not possible
            totalCost += minCost[u][v];
        }

        return totalCost;
    }
};