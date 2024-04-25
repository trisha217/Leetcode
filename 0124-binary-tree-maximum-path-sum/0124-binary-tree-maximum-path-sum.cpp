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
    int findmax(TreeNode* node, int &k){
        if(node == NULL){
            return 0;
        }
        int leftsum = max(0,findmax(node->left,k));
        int rightsum = max(0,findmax(node->right,k));
        k = max(k, leftsum+rightsum+node->val);
        return max(leftsum,rightsum) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findmax(root,maxi);
        return maxi;
        
    }
};