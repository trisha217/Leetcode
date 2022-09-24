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
    void solve(TreeNode* root, int sum, vector<int> temp, vector<vector<int>> &ans){
        //if root is null
        if(!root){
            return;
        }
        //checking if the leaf node is equal to the value of the node then store the path.
        if(!root->left && !root->right && sum==root->val){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        //store the nodes in temp
        temp.push_back(root->val);
        //go left and decrease the value of node from targetsum
        solve(root->left,sum-root->val,temp,ans);
        //go right and decrease the value of node from targetsum
        solve(root->right,sum-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,targetSum,temp,ans);
        return ans;
    }
};