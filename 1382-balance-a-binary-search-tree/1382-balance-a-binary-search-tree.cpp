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
    vector<TreeNode* > arr;
    void helper(TreeNode* root){
        if(root == NULL)return;
        helper(root->left);
        arr.push_back(root);
        helper(root->right);
    }
    TreeNode* makeBST(int l, int r){
        if (l > r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(arr[mid]->val);
        root->left = makeBST(l, mid-1);
        root->right = makeBST(mid+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        helper(root);
        TreeNode* newRoot = makeBST(0, arr.size()-1);
        return newRoot;
    }
};