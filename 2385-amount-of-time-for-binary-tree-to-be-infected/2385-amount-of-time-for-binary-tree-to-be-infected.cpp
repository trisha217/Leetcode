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
    TreeNode* mapParentFindTarget(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* targetNode = NULL;
        mp[root] = NULL;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->val == start){
                targetNode = front;
            }
            if(front->left){
                mp[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }
    int burnTree(unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* targetNode){
        unordered_map<TreeNode*,bool> visited;
        visited[targetNode] = true;
        queue<TreeNode*> q;
        q.push(targetNode);
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            int isburnt = false;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL && !visited[node->left]){
                    visited[node->left] = true;
                    isburnt = true;
                    q.push(node->left);
                }
                if(node->right!=NULL && !visited[node->right]){
                    visited[node->right] = true;
                    isburnt = true;
                    q.push(node->right);
                }
                if(mp[node] && !visited[mp[node]]){
                    visited[mp[node]] = true;
                    isburnt = true;
                    q.push(mp[node]);
                }
            }
            if(isburnt){
                time++;
            }
        }
        return time;
    }
        
        
        
    int amountOfTime(TreeNode* root, int start) {
        if(!root){
            return 0;
        }
        unordered_map<TreeNode*,TreeNode*> mp;
        TreeNode* target = mapParentFindTarget(root,mp,start);
        return burnTree(mp,target);
    }
};