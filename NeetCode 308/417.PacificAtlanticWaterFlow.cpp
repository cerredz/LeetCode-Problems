class Solution {
public:

      /*

    Problem:
      There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, 
      and the Atlantic Ocean touches the island's right and bottom edges. The island is partitioned into a grid of square cells. You are given an m x n integer 
      matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
      The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west 
      if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
      Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

*/
    // helper dfs recursive function to check if a cell in a 2d array can reach the atlantic OR pacific ocean
    void dfs(vector<vector<int>>& heights, int row, int col, int height, vector<vector<bool>>& ocean) {

        if(row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size() || heights[row][col] < height || ocean[row][col]) {
            return;
        }

        ocean[row][col] = true;

        // check adjacent cells
        dfs(heights, row + 1, col, heights[row][col], ocean);
        dfs(heights, row, col + 1, heights[row][col], ocean);
        dfs(heights, row - 1, col, heights[row][col], ocean);
        dfs(heights, row, col - 1, heights[row][col], ocean);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        

        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> res;
        
        // create 2 bool 2d arrays, one denotes the cells that can make it to the pacific ocean and the other denotes the cells that can make it to the atlantic ocean
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // traverse inward from the left and right
        for(int i = 0; i < n; i++) {
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, m - 1, INT_MIN, atlantic);
        }

        // traverse inward from the top and bottom
        for(int i = 0; i < m; i++) {
            dfs(heights, 0, i, INT_MIN, pacific);
            dfs(heights, n - 1, i, INT_MIN, atlantic);
        }

        
        // if pacific[i][j] and atlantic[i][j] are both true, then the cell[i][j] can travel to the pacific AND atlantic ocean, add all of these cells to a res vector

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;

        

    }
};
