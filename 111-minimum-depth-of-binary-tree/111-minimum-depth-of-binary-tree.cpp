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
        else{
            int l = solve(root->left);
            int r = solve(root->right);
            return (l==0 || r==0) ? l + r + 1 : min(l,r)+1;
        }
    }
    int minDepth(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};