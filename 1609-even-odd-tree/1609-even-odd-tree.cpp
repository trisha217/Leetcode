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
    bool isEvenOddTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;
            
            for(int i=0;i<size;i++){
                
                TreeNode * top = q.front();
                q.pop();
                
                if ((level % 2 == 0 && top->val % 2 == 0) || (level % 2 == 1 && top->val % 2 != 0))
                    return false;

                if ((level % 2 == 0 && prev >= top->val) || (level % 2 == 1 && prev <= top->val))
                    return false;
                
                if(top->left!=NULL){
                    q.push(top->left);
                 }
                if(top->right!=NULL){
                    q.push(top->right);
                }
                prev = top->val;
            }
            level++;
        }
        return true;
    }
};