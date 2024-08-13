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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both nodes are null, so they are the same
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // One of the nodes is null, but not the other, so they are not the same
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};