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
    TreeNode * LCA(TreeNode *root,int p ,int q){
        if(root==NULL||root->val==p||root->val==q){
            return root;
        }
        TreeNode *left = LCA(root->left,p,q);
        TreeNode *right = LCA(root->right,p,q);
        if(left && right){
            return root;
        }
        return left == NULL ? right : left;
    }
    bool search(string &res,TreeNode *node,int end){
        if(node==NULL) return false;
        if(node->val==end){
            return true;;
        }
        res.push_back('L');
        if(search(res,node->left,end)) return true;
        res.pop_back();
        res.push_back('R');
        if(search(res,node->right,end)) return true;;
        res.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int start, int end) {
        TreeNode *node = LCA(root,start,end);
        string result="";
        if(node->val==start){
            string res="";
            search(res,node,end);
            result = res;
        }else if(node->val==end){
            string res="";
            search(res,node,start);
            int size = res.size();
            while(size--){
                result += 'U';
            }
        }else{
            string res="",res1="";
            search(res,node,start);
            int size = res.size();
            while(size--){
                result += 'U';
            }
            search(res1,node,end);
            result += res1;
        }
        return result;
    }
};