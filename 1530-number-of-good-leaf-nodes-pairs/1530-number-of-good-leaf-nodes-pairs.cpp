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
    int ans = 0;
public:

    vector<int> f(TreeNode* root, int &d){
        if(!root) return {};
        
        auto l = f(root->left,d);
        auto r = f(root->right,d);
        if(l.size() + r.size() == 0) return {1};

        for(auto x : l)
            for(auto y : r)
                if(x + y <= d) ans++;

        vector<int> ret(l.size()+r.size());
        merge(l.begin(),l.end(), r.begin(), r.end(), ret.begin());
        for(int i = 0; i < ret.size(); i++)
            ret[i]++;
        return ret;
    }

    int countPairs(TreeNode* root, int distance) {
        f(root,distance);
        return ans;
    }
};