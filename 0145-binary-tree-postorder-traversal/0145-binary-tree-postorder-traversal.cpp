class Solution {
private:
    vector<int> postOrder(TreeNode* root,  vector<int>&ans) {
      
        if (root == NULL) {
            return ans;
        }
        postOrder(root->left,ans);
        postOrder(root->right,ans);
        ans.push_back(root->val);

        return ans;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
       postOrder(root,result);

       return result;
    }
};