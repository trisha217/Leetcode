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
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        return solve(root,root->val);
    }
    int solve(TreeNode* root, int maxValue){
        
        if(!root){
            return 0;
        }
        int goodnodes=0;
        if(root->val>=maxValue){
            maxValue = root->val;
            goodnodes++;
        }
        return goodnodes + solve(root->left,maxValue) + solve(root->right,maxValue);
    }
};