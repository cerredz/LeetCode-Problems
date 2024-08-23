class Solution {
public:
/*
    Problem:
      Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
      Note: You can only move either down or right at any point in time.
*/
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        res[0][0] = grid[0][0];
        // fill in first row of dp 2d-array
        for(int i = 1; i < m; i++) {
            res[0][i] = grid[0][i] + res[0][i - 1];
        }

        // fill in first colum of dp 2d-array
        for(int i = 1; i < n; i++) {
            res[i][0] = grid[i][0] + res[i - 1][0];
        }

        // using res, find the minimum path
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                res[i][j] = min(res[i - 1][j] + grid[i][j], res[i][j - 1] + grid[i][j]);
            }
        }

        return res[n - 1][m - 1];
    }
};
