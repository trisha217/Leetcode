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
// minus denotes that coins are needed by that node
// positive denotes extra coins on a particular node
class Solution {
public:
    int ans = 0;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftCoins = solve(root->left);
        int rightCoins = solve(root->right);
        ans = ans + abs(leftCoins) + abs(rightCoins);
        return (leftCoins + rightCoins + root->val -1);
        // left will tell coins required by left node
        //right will tell u coins required by right node
        // we have done (left+right+root->val-1) coz:-
        // imagine a tree[0,0,null,0,0] and the root node has 4 coins and now try to solve for the minimum steps.
        //solve for coins required by each node, the value for each node will be equal to (left+right+root->val-1)
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};