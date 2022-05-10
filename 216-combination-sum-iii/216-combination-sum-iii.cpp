class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        solve(1,n,k,t);
        return ans;
    }
    void solve(int start,int n, int k, vector<int>& temp){
        if(temp.size()==k){
            if(n==0){
                ans.push_back(temp);
                return;
            }
        }
        for(int i= start;i<=9;i++){
            temp.push_back(i);
            solve(i+1,n-i,k,temp);
            temp.pop_back();
        }
    }
};