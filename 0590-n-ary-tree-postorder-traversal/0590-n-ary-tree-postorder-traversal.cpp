class Solution {
public:
    void solve(vector<int>& ans, Node* root){
        if(root == NULL){
            return;
        }
        for(auto it: root->children){
            solve(ans,it);
        }
        ans.push_back(root->val);
        return;
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;  // Return empty vector if root is NULL
        }
        solve(ans,root);
        return ans;
    }
};