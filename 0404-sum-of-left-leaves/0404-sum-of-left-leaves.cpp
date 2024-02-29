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
    bool isLeaf(TreeNode* p){
        if(p->left== NULL && p->right==NULL){
            return true;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){
            return 0;
        }
        else if(root->left!=NULL && isLeaf(root->left)){
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        else{
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        } 
    }
};