class Solution {
private:
vector<vector<int>> g;
public:

/*
    Problem:

      You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
      A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
      Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
    Approach:
        1. we will perform a dfs function where we will be traversing inward
        2. Start the dfs on the border of the grid wherever there is a 1
        3. Turn all of the 1's that connect to the border into 2's
        4. After performing the dfs, count the number of 1's that are left in the grid, these
            are the 1s that are not connected to the border
*/
    // helper function to mark all connecting 1's to the boundary
    void dfs(int row, int col) {
        if(row < 0 || row >= g.size() || col < 0 || col >= g[0].size() || g[row][col] != 1)  {
            return;
        }

        g[row][col] = 2;

        // check neighboring cells
        dfs(row, col + 1);
        dfs(row, col - 1);
        dfs(row + 1, col);
        dfs(row - 1, col);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        g = grid;

        // run dfs on bordering cells
        for(int i = 0; i < n; i++) {
            dfs(i, 0);
            dfs(i, m - 1);
        }

        for(int i = 0; i < m; i++) {
            dfs(0, i);
            dfs(n - 1, i);
        }

        // return the amount of remaining 1's
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j  = 0; j < m; j++) {
                if(g[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;

    }
};
