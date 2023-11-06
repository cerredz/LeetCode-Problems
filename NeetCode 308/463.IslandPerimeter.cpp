class Solution {
public:

  /*
      Problem:
          You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
          Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., 
          one or more connected land cells). The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. 
          One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island
  
  */
    // helper dfs function to help calculate perimeter
    int getPerimeter(vector<vector<int>>&grid, int row, int col, vector<vector<bool>>& visited ) {

        // either out of bounds or hit water, add 1 to the perimeter
        if(row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == 0){
            return 1;
        }
        if(visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;
        // traverse in all 4 directions looking for more land
        int perimeter = getPerimeter(grid, row, col - 1, visited);
        perimeter += getPerimeter(grid, row, col + 1, visited);
        perimeter += getPerimeter(grid, row - 1, col, visited);
        perimeter += getPerimeter(grid, row + 1, col, visited);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited_islands(rows, vector<bool>(cols, false));

        // first find an island in the grid, then call the dfs function on that piece of land
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    return getPerimeter(grid, i, j, visited_islands);
                }
            }
        } 
 
        return 0;

    }
};
