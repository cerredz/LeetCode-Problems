class Solution {
public:
    /*
      Problem:
        You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected
        4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells. An island in grid2 is considered a sub-island if there is an island 
        in grid1 that contains all the cells that make up this island in grid2. Return the number of islands in grid2 that are considered sub-islands.

*/
    // helper dfs function
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int& m, int& n, int row, int col, bool& result) {
        int directions[][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // left, up, right, down

        if (grid1[row][col] != 1) result = false; 
        grid2[row][col] = -1; // mark as visited

        // traverse through adjacent cells
        for (int i = 0; i < 4; i++) {
            int nr = row + directions[i][0], nc = col + directions[i][1];
            if (nr < 0 || nc < 0 || nr == m || nc == n || grid2[nr][nc] != 1)
                continue;
            dfs(grid1, grid2, visited, m, n, nr, nc, result);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size(), cols = grid1[0].size();
        int numSubIslands = 0;

        // traverse through the grid 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bool isSubIsland = true; 
                if (grid2[i][j] == 1 && !visited[i][j]) { // 1 in grid2 not yet visited
                    dfs(grid1, grid2, visited, rows, cols, i, j, isSubIsland); // determine if island is a subisland
                    if (isSubIsland) numSubIslands++; // if subisland, increment res
                }
            }
        }

        return numSubIslands;
    }
};
