class Solution {
public:
    int find(vector<int>& uf, int x) {
        return (uf[x] != x) ? uf[x] = find(uf, uf[x]) : x;
    }

    void merge(vector<int>& uf, vector<int>& r, int x, int y) {
        int px = find(uf, x), py = find(uf, y);
        if (r[px] > r[py]) uf[py] = px, r[px] += r[py];
        else uf[px] = py, r[py] += r[px];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        for (auto& v : e) swap(v[0], v[2]);
        for (int i = 0; i < q.size(); ++i) swap(q[i][0], q[i][2]), q[i].push_back(i);
        sort(q.begin(), q.end()), sort(e.begin(), e.end());
        vector<bool> ans(q.size());
        vector<int> uf(n), r(n, 1);
        for (int i = 0; i < n; ++i) uf[i] = i;
        for (int i = 0, p = 0; i < q.size(); ++i) {
            while (p < e.size() && e[p][0] < q[i][0]) {
                if (find(uf, e[p][1]) != find(uf, e[p][2])) merge(uf, r, e[p][1], e[p][2]);
                ++p;
            }
            ans[q[i][3]] = (find(uf, q[i][1]) == find(uf, q[i][2]));
        }
        return ans;
    }
};