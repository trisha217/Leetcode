class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> p(4,true);
        int n = mat.size();
        for(int i = 0; i<n;i++){
            for(int j = 0; j<n;j++){
                if(mat[i][j] != target[i][j]) 
                    p[0] = false; // 0deg
                if(mat[i][j] != target[n-j-1][i]) 
                    p[1] = false; // 90deg
                if(mat[i][j] != target[n-i-1][n-j-1]) 
                    p[2] = false; // 180deg
                if(mat[i][j] != target[j][n-i-1]) 
                    p[3] = false; // 270deg
            }
        }
        return p[0] || p[1] || p[2] || p[3];
    }
};