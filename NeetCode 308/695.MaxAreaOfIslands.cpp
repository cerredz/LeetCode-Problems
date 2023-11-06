class Solution {
public:

    /*
        Problem:
          You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
          You may assume all four edges of the grid are surrounded by water. The area of an island is the number of cells with a value 1 in the island.
          Return the maximum area of an island in grid. If there is no island, return 0.

        Approach:
            1. Traverse through the grid looking for "land", whenever we find a piece of land that we have not yet 
                visited then we can calculate the area of the island
            2. We can calculate the area of an islands using a recursive dfs function, where we look for 
                adjacent cells until we either are out of bounds or run into all 0's
            3. Keep track of the greatest area we find after getting the area of all islands
    
    */

    // helper dfs recursive function to calculate the size of an island
    int getArea(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {

        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || visited[row][col] || grid[row][col] == 0) {
            return 0;
        }

        visited[row][col] = true;
        int area = getArea(grid, row - 1, col, visited);
        area += getArea(grid, row, col - 1, visited);
        area += getArea(grid, row + 1, col, visited);
        area += getArea(grid, row, col + 1, visited);

        return area + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size(), cols = grid[0].size();
        int area = 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        // traverse through grid, running our DFS function whenever we run into land not yet visited
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 1 && !visited[i][j]) {
                    area = max(area, getArea(grid, i, j, visited));
                }
            }
        }

        return area;


        
    }
};
