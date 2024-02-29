/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* clone, TreeNode* target) {
        int value = target->val;
        // Base Case
        if (clone->val == value)
            return clone;
        //level order traversal
        queue<TreeNode*> q;
        q.push(clone);
        while (!q.empty()) 
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == value){
                return node;
            }
            else{
                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);  
            }
        }
        return clone;
    }
};