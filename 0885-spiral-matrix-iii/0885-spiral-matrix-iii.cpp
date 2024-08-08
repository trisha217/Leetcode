class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        int visitedCount = 1, steps = 0;
        int totalCells = rows * cols;
        int currentRow = rStart, currentCol = cStart;

        if(rows == 0 || cols == 0)  // Handle edge case where rows or cols is 0
            return {};

        while(visitedCount < totalCells) {
            // Move right
            steps++;
            for(int i = 0; i < steps; i++) {
                currentCol++;
                if(currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols) {
                    result.push_back({currentRow, currentCol});
                    visitedCount++;
                }
            }

            // Move down
            for(int i = 0; i < steps; i++) {
                currentRow++;
                if(currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols) {
                    result.push_back({currentRow, currentCol});
                    visitedCount++;
                }
            }

            // Move left
            steps++;
            for(int i = 0; i < steps; i++) {
                currentCol--;
                if(currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols) {
                    result.push_back({currentRow, currentCol});
                    visitedCount++;
                }
            }

            // Move up
            for(int i = 0; i < steps; i++) {
                currentRow--;
                if(currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols) {
                    result.push_back({currentRow, currentCol});
                    visitedCount++;
                }
            }
        }

        return result;
    }
};