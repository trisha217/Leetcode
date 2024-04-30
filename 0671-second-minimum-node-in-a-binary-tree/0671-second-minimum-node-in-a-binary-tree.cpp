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
    void solve(TreeNode *root, set<int> &s){
        if(root==NULL){
            return;
        }
        solve(root->left,s);
        s.insert(root->val);
        solve(root->right,s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        solve(root,s);
        if(s.size()<2){
            return -1;
        }
        auto it = next(s.begin(),1);
        return *it;
    }
};