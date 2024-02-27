class Solution {
public:
    /*
    The answer should be 
    max(length(left) + length(right), 
        diameter(left),
        diameter(right))
    
    */

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root->left && !root->right){
            root->val = 1;
            return 0;
        }
        else if(!root->left){
            int tmp = diameterOfBinaryTree(root->right);
            root->val = root->right->val + 1;
            return max(root->right->val, tmp);
        }
        else if(!root->right){
            int tmp = diameterOfBinaryTree(root->left);
            root->val = root->left->val + 1;
            return max(root->left->val, tmp);
        }
        else{
            int tmp_1 = diameterOfBinaryTree(root->left);
            int tmp_2 = diameterOfBinaryTree(root->right);
            root->val = max(root->right->val, root->left->val) + 1;
            return max(root->left->val + root->right->val, max(tmp_1, tmp_2));
        }

    }
};