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
    void Traverse(TreeNode* root, int &sum,string str){
        if(root->right==NULL and root->left==NULL){
            str.push_back(root->val+'0');
            cout<<str[0];
            int Num=stoi(str);
            sum+=Num;
            str.pop_back();
            return;
        }
        str.push_back(root->val+'0');
        if(root->left!=NULL){
            Traverse(root->left,sum,str);
        }
        if(root->right!=NULL){
            Traverse(root->right,sum,str);
        }
        str.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        int sum=0;
        if(root==NULL)return sum;        
        string str="";
        Traverse(root,sum,str);
        return sum;
    }
};