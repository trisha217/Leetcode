class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowsum, vector<int>& colsum) {
        int n = rowsum.size();
        int m = colsum.size();
        vector<vector<int>> ans(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rowsum[i]<= colsum[j]){
                    ans[i][j] = rowsum[i];
                    rowsum[i] = 0;
                    colsum[j] -= ans[i][j];
                }
                else{
                    ans[i][j] = colsum[j];
                    colsum[j] = 0;
                    rowsum[i] -= ans[i][j];
                }
            }
        }
        return ans;
    }
};