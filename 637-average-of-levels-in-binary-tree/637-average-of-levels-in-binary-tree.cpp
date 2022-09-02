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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        if(!root)
            return {0.0};
        while(!q.empty()){
            double temp =0;
            int x = q.size();
            for(int i=0;i<x;i++){
                TreeNode* g = q.front();
                q.pop();
                if(g->left){
                    q.push(g->left);
                }
                if(g->right){
                    q.push(g->right);
                }
                temp+=g->val;
            }
            ans.push_back((double)temp/x);
        }
        return ans;
    }
};