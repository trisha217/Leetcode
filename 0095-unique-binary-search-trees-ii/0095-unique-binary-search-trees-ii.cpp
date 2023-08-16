/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    vector<TreeNode*> generateTrees(int n) {
      vector<vector<vector<TreeNode*>>> dp(n+2, vector<vector<TreeNode*>>(n+2));
      helper(dp, 1, n+1);
      return dp[1][n+1];
    }
  private:
    vector<TreeNode*> helper(vector<vector<vector<TreeNode*>>>& dp, int l, int r) {
      if (l == r)
        return {nullptr};
      if (dp[l][r].size())
        return dp[l][r];
      vector<TreeNode*> ret;
      for (int i = l; i < r; i++) {
        auto left = helper(dp, l, i);
        auto right = helper(dp, i+1, r);
        for (auto& lt : left)
          for (auto& rt: right)
            ret.push_back(new TreeNode(i, lt, rt));
      }
      dp[l][r] = ret;
      return ret;
    }
};