class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        bool a = false, b = false;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i =-0;i<n;i++){
            for(int j=0;j<m;j++){

                int min_ele_row = *min_element(matrix[i].begin(),matrix[i].end());
                if(matrix[i][j] == min_ele_row) a = true;

                int max_ele_col = INT_MIN;
                for(int k=0;k<n;k++){
                    if(matrix[k][j] > max_ele_col) max_ele_col = matrix[k][j];
                }

                if(max_ele_col == matrix[i][j]) b = true;

                if(a && b) ans.push_back(matrix[i][j]);

                a = false, b= false;
            }
            
        }
        return ans;
        
    }
};