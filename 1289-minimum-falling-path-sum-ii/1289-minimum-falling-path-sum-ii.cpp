class Solution {
public:
    int n;
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& t){
        if(row == n-1){
            return matrix[row][col];
        }
        if(t[row][col] != INT_MAX){
            return t[row][col];
        }
        int curr = matrix[row][col];
        int minSum = INT_MAX;

        for(int j=0; j<n; j++){ // Iterate over the entire column
            if(j != col) { // Skip the current column
                minSum = min(minSum, solve(matrix, row+1, j, t));
            }
        }

        return t[row][col] = curr+minSum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int row = 0;
        int minSum = INT_MAX;
        
        // Dynamically allocate memory for t based on grid size
        vector<vector<int>> t(n, vector<int>(n, INT_MAX));

        for(int col = 0; col<n; col++){
            minSum = min(minSum, solve(grid, row, col, t));
        }
        return minSum;
    }
};