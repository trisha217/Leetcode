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
    bool isLeaf(TreeNode* s){
        if(s->left==NULL && s->right==NULL){
            return true;
        }
        return false;
    }
    void f1(TreeNode* root,vector<int> &ans1){
        if(!root){
            return;
        }
        if(isLeaf(root)){
            //cout<<"called";
            ans1.push_back(root->val);
        }
        if(root->left){
            f1(root->left,ans1);
        }
        if(root->right){
            f1(root->right,ans1);
        }
    }
    void f2(TreeNode* root,vector<int> &ans2){
        if(!root){
            return;
        }
        if(isLeaf(root)){
            ans2.push_back(root->val);
        }
        if(root->left){
            f2(root->left,ans2);
        }
        if(root->right){
            f2(root->right,ans2);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        f1(root1,ans1);
        f2(root2,ans2);
        // for(int i=0;i<ans1.size();i++){
        //     cout<<ans1[i];
        // }
        // cout<<endl;
        // for(int i=0;i<ans2.size();i++){
        //     cout<<ans2[i];
        // }
        if(ans1==ans2){
            return true;
        }
        return false;
        
    }
};