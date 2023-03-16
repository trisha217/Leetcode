class Solution {

    unordered_map<int, int> mp;

    TreeNode* Tree(vector<int> in, vector<int> post, int start, int end, int& postIdx) {
        if(start > end) return nullptr;

        TreeNode* root = new TreeNode(post[postIdx--]);
        int idx = mp[root->val];

        root->right = Tree(in, post, idx+1, end, postIdx);
        root->left = Tree(in, post, start, idx-1, postIdx);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i=0; i<inorder.size(); i++) 
            mp[inorder[i]] = i;

        int n = inorder.size();
        int postIdx = n-1;

        return Tree(inorder, postorder, 0, n-1, postIdx);
        
    }
};