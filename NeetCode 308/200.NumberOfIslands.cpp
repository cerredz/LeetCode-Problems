class Solution {
public:

    /*

        Problem:
          Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
          An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
          You may assume all four edges of the grid are all surrounded by water.

        Approach:
            1. We will iterate through the grid and have a corrsponding bool grid that tells using the
                cells that we have visited
            2. While iterating through the grid, if we have not visited a cell and that cell is == 1,
                then we will call a recursive function that "marks" all adjacent cells == 1. In other
                words,  the recursive function will "find" and island and "mark" it
            3. Whenever we have to call the recursive function, add 1 to our result, and when we are
                dont iterating through the grid we can return our result
    
    */

    // helper dfs function to "find" islands
    void findAdjacentIslands(vector<vector<char>>&grid, int row, int col, vector<vector<bool>>& visited) {
        
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || visited[row][col] || grid[row][col] == '0') {
            return;
        }

        visited[row][col] = true;
        findAdjacentIslands(grid, row + 1, col, visited);
        findAdjacentIslands(grid, row, col + 1, visited);
        findAdjacentIslands(grid, row - 1, col, visited);
        findAdjacentIslands(grid, row, col - 1, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    cout << "entered" << endl;
                    // piece of land not visited found, now find the island
                    findAdjacentIslands(grid, i, j, visited);
                    islands++;
                }
            }
        }

        return islands;
    }
};
