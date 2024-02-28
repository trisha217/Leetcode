class Solution {
    int maxDepth = -1, res;
    void dfs(TreeNode *curr, int depth = 0) {
        // left first
        if (curr->left) dfs(curr->left, depth + 1);
        // first time we reach a new depth
        if (depth > maxDepth) maxDepth = depth, res = curr->val;
        // right last
        if (curr->right) dfs(curr->right, depth + 1);
    }
public:
    int findBottomLeftValue(TreeNode *root) {
        dfs(root);
        return res;
    }
};