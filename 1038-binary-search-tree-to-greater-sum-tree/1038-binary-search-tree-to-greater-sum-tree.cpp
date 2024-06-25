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
    void f(TreeNode* root, int &val) {
        if (!root) return;  // Base case: if the node is null, do nothing
        if (root->right) f(root->right, val);  // Traverse the right subtree
        root->val += val;  // Update the current node's value
        val = root->val;  // Update the accumulated sum
        if (root->left) f(root->left, val);  // Traverse the left subtree
    }

    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;  // Initialize the accumulated sum to 0
        f(root, val);  // Call the helper function with the root and initial sum
        return root;  // Return the modified tree
    }
};