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
    int solve(int &x,TreeNode* root){
       if(root==NULL){
            return 0;
        }
        int leftd = solve(x,root->left);
        int rightd = solve(x,root->right);
        x = max(x,leftd+rightd);
        return 1 + max(leftd,rightd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        solve(maxi,root);
        return maxi;
    }
};