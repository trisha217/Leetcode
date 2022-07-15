class Solution {
public:
    // Returns the area of the island found
    int findIslandArea(vector<vector<int>>& grid, int row, int col) {
        // Base condition
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return 0;
        }
        
        int area = 0;
        if (grid[row][col] == 1) {
            // Update the current cell, as we have already counted it
            grid[row][col] = 0;
            // Recurse on the neighbor cells
            area = 1 + findIslandArea(grid, row + 1, col) + findIslandArea(grid, row - 1, col)
                + findIslandArea(grid, row, col + 1) + findIslandArea(grid, row, col - 1);
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        // Iterate over the entire grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // Check if the current cell is a part of an island
                if (grid[i][j] == 1) {
                    // Update area if found an island with larger area
                    area = max(area, findIslandArea(grid, i, j));
                }
            }
        }
        return area;
    }
};