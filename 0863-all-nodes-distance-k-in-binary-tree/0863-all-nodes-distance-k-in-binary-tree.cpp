/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left){
                parent_track[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent_track[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //node,parent
        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(root,parent);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            if(level++ == k){
                break;
            }
            for(int i=0;i<s;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && !vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left] = true;
                }
                if(cur->right && !vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right] = true;
                }
                if(parent[cur] && !vis[parent[cur]]){
                    q.push(parent[cur]);
                    vis[parent[cur]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};