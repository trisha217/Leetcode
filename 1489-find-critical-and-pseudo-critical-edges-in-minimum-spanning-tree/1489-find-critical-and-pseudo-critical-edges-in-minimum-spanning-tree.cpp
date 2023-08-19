class UnionFind {
public:
    vector<int> parents;
    int weight;
    int edgeCount;

    UnionFind(int n) : parents(n), weight(0), edgeCount(0) {
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void unionSet(int x, int y, int w) {
        int r1 = find(x);
        int r2 = find(y);

        if (r1 != r2) {
            parents[r2] = r1;
            weight += w;
            edgeCount++;
        }
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<tuple<int, int, int, int>> edgesWithIndex;
        int m = edges.size();

        for (int i = 0; i < m; ++i) {
            edgesWithIndex.push_back({edges[i][2], edges[i][0], edges[i][1], i});
        }

        sort(edgesWithIndex.begin(), edgesWithIndex.end());

        UnionFind uf1(n);
        for (const auto& [w, a, b, _] : edgesWithIndex) {
            uf1.unionSet(a, b, w);
        }

        int minWeight = uf1.weight;

        vector<int> ce;  
        vector<int> pce; 

        for (int i = 0; i < m; ++i) {
            UnionFind uf2(n);
            for (int j = 0; j < m; ++j) {
                if (i == j) {
                    continue;
                }
                int w, a, b;
                tie(w, a, b, ignore) = edgesWithIndex[j];
                uf2.unionSet(a, b, w);
            }

            if (uf2.weight > minWeight || uf2.edgeCount < n - 1) {
                ce.push_back(get<3>(edgesWithIndex[i]));
            } else {
                UnionFind uf3(n);
                int w, a, b;
                tie(w, a, b, ignore) = edgesWithIndex[i];
                uf3.unionSet(a, b, w);

                for (int j = 0; j < m; ++j) {
                    tie(w, a, b, ignore) = edgesWithIndex[j];
                    uf3.unionSet(a, b, w);
                }

                if (uf3.weight == minWeight) {
                    pce.push_back(get<3>(edgesWithIndex[i]));
                }
            }
        }

        return {ce, pce};
    }
};