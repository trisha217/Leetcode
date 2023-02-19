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
    void helper(TreeNode* root, int k, vector<vector<int>> &ans){
        if(root == NULL)    return ;
        if(ans.size()==k)   ans.push_back(vector<int>());
        helper(root->left, k+1, ans);
        if(k%2==0)  
            ans[k].push_back(root->val);
        else
            ans[k].insert(ans[k].begin(), root->val);
        helper(root->right, k+1, ans);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, 0, ans);
        return ans;
    }
};