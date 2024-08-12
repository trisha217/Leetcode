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
    int h(int x,TreeNode* root){
        if(root == NULL){
            return x;
        }
        int lh = h(x+1,root->left);
        int rh = h(x+1,root->right);
        return max(lh,rh);
    }
    int maxDepth(TreeNode* root) {
        int height = h(0,root);
        return height;
    }
};