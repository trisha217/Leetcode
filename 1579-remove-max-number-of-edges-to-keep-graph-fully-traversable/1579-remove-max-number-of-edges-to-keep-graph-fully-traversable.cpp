class Solution {
public:
    int find(vector<int>& root, int i)
    {
        if (i != root[i])
        {
            root[i] = find(root, root[i]);
        }
        return root[i];
    }
    bool uni(vector<int>& root, int x, int y)
    {
        x = find(root, x);
        y = find(root, y);
        if(x == y)
        {
            return 0;
        }
        root[x] = y;
        return 1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0, e1 = 0, e2 = 0;
        vector<int> root(n + 1);
        iota(root.begin(), root.end(), 0);
        for (int i = 0; i < edges.size(); i++)
        {
            int t = edges[i][0], x = edges[i][1], y = edges[i][2];
            if (t == 3)
            {
                if (uni(root, x, y))
                {
                    e1++;
                    e2++;
                }
                else
                {
                    ans++;
                }
            }
        }
        vector<int> root1 = root;
        for (int i = 0; i < edges.size(); i++)
        {
            int t = edges[i][0], x = edges[i][1], y = edges[i][2];
            if (t == 1)
            {
                if (uni(root, x, y))
                {
                    e1++;
                }
                else
                {
                    ans++;
                }
            }
        }
        root = root1;
        for (int i = 0; i < edges.size(); i++)
        {
            int t = edges[i][0], x = edges[i][1], y = edges[i][2];
            if (t == 2)
            {
                if (uni(root, x, y))
                {
                    e2++;
                }
                else
                {
                    ans++;
                }
            }
        }
        if (e1 == n - 1 && e2 == n - 1)
        {
            return ans;
        }
        return -1;
    }
};