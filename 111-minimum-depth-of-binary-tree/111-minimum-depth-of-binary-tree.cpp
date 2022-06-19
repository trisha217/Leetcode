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
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        return (left==0 || right==0) ? left + right + 1 : min(left,right) + 1;
    }
    int minDepth(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};