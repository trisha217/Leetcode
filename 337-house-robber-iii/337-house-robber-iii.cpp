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
    map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(mp.find(root) != mp.end()){
            return mp[root];
        }
        int sum = root->val;
        
        if(root->left!=NULL){
            sum+= rob(root->left->left);
            sum+= rob(root->left->right);
        }
        
        if(root->right!=NULL){
            sum+= rob(root->right->left);
            sum+= rob(root->right->right);
        }
        
        int sum2 = rob(root->left) + rob(root->right);
        int res = max(sum,sum2);
        mp[root] = res;
        return res;
    }
};