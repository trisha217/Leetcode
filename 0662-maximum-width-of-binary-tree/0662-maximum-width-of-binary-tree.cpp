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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        //node, index
        q.push({root,0});
        while(!q.empty()){
            int mini = q.front().second;
            int size = q.size();
            int f=0,l=0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int cur_ind = q.front().second - mini;
                q.pop();
                if (i == 0) {
                    f = cur_ind;
                }
                if (i == size - 1) {
                    l = cur_ind;
                }
                if (node->left) {
                    q.push({node->left, (long long)cur_ind * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, (long long)cur_ind * 2 + 2});
                }
            }
            ans = max(ans, l - f + 1);
        }
        return ans;
    }
};