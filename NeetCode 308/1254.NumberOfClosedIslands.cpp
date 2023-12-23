class Solution {
private:
    vector<vector<bool>> visited; 
public:

    /*
      Problem:
          Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
          Return the number of closed islands.
    */
    // helper function: given an island, determine if it is a closed island or not
    bool dfs(vector<vector<int>>& grid, int row, int col) {

        // base cases
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return false;
        }

        if(visited[row][col] || grid[row][col] == 1) {
            return true;
        }

        visited[row][col] = true;

        // check neighboring cells, only if ALL of them are 1's we can know we have a closed island
        bool left = dfs(grid, row, col - 1);
        bool right = dfs(grid, row, col + 1);
        bool up = dfs(grid, row - 1, col);
        bool down = dfs(grid, row + 1, col);

        return left && right && up && down;
    }


    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        int res = 0;

        // traverse through the grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int row = i;
                int col = j;
                if(grid[row][col] == 0 && !visited[row][col]) {
                    // island has not been visited
                    res += dfs(grid, row, col) ? 1 : 0;
                }
            }
        }

        return res;
    }
};
