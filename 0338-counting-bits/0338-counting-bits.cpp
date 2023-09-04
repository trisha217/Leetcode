class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for (int i = 1; i <= n; ++i) {
            // To compute ans[i], we use the fact that ans[i] = ans[i / 2] + (i % 2).
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};