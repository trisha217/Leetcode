class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int H = matrix.size();
        const int W = matrix[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < W; ++i) {
            vector<int> row;
            row.reserve(W);

            for (int j = 0; j < H; ++j) {
                row.push_back(matrix[j][i]);
            }
            ans.push_back(row);
        }

        return ans;
    }
};