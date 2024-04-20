class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>v;
        int n = land.size(), m = land[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1 && ((i == 0 || land[i-1][j] == 0) && (j == 0 || land[i][j-1] == 0))){
                    int I = i, J = j;
                    while(I < n && land[I][J] == 1) I++;

                    I--;
                    while(J < m && land[I][J] == 1) J++;

                    J--;
                    v.push_back({i, j, I, J});
                    j = J;
                }
            }
        }
        return v;
    }
};