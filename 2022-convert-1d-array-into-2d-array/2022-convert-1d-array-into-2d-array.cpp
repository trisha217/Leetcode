class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {}; // Return an empty array if dimensions don't match
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        int i=0;
        while(i<m){
            for(int j=0;j<n;j++){
                ans[i][j] = original[i * n + j];
            }
            i++;
        }
        return ans;
    }
};