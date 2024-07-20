class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int check = matrix[i][j];
                bool flag = true;
                
                // Check in row
                for (int k = 0; k < m; ++k) {
                    if (check > matrix[i][k]) {
                        flag = false;
                        break;
                    }
                }
                
                // Check in column if it's the minimum in the row
                if (flag) {
                    for (int k = 0; k < n; ++k) {
                        if (check < matrix[k][j]) {
                            flag = false;
                            break;
                        }
                    }
                }
                
                if (flag) {
                    ans.push_back(check);
                }
            }
        }
        return ans;
    }
};