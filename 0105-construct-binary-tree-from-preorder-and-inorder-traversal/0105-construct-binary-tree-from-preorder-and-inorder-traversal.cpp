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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> indexMap;
        for(int i =0;i<inorder.size();i++){
            indexMap[inorder[i]] = i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,indexMap);
    }
    TreeNode* build(vector<int> &preorder,int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> &mp){
        if(preEnd<preStart || inStart>inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int indexRoot = mp[root->val];
        int numsLeft = indexRoot - inStart;
        root->left = build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,indexRoot-1,mp);
        root->right = build(preorder,preStart + numsLeft + 1,preEnd,inorder,indexRoot+1,inEnd,mp);
        return root;
    }
};