class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negative = 0, min_abs = INT_MAX, zero = 0, n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);
                zero += (matrix[i][j] == 0);
                negative += (matrix[i][j] < 0);
                min_abs = min(min_abs, abs(matrix[i][j]));
            }
        }
        long long subtract = 2LL * min_abs;
        if (zero > 0 || (negative & 1) == 0) 
            subtract = 0;
        return sum - subtract;
    }
};