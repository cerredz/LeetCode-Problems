class Solution {
public:
    /*
        Problem:
          You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
          An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
          You may change 0's to 1's to connect the two islands to form one island. Return the smallest number of 0's you must flip to connect the two islands.
        Approach:
            1. We need to find a way to distintify the two islands
            2. After we can identify the two islands, we need to run a bfs / dfs on all possible 
                bridge paths between the two islands
            3. While running the bfs / dfs, keep track of the shortest bridge
    */

    // helper function to help find and mark the first island found in the grid
    void mark(vector<vector<int>>& grid, int row, int col, queue<pair<int, int>>& q) {

        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1) {
            return;
        }

        // mark the current cell
        grid[row][col] = 2; 
        q.push({row, col});

        // check adjacent cells
        mark(grid, row + 1, col, q);
        mark(grid, row - 1, col, q);
        mark(grid, row, col + 1, q);
        mark(grid, row, col - 1, q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        
        // mark the first island found
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            bool found = false;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    mark(grid, i , j, q);
                    found = true;
                    break;
                }
            }

            if(found) break;
        }

        // using the first island, run bfs until we reach the second island
        int res = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty()){
            int size = q.size();
            // traverse through current level of bfs
            for(int i = 0; i < size; i++) {

                auto[row, col] = q.front();
                q.pop();

                // add next level to q
                for(const auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
                        continue;
                    }

                    if(grid[newRow][newCol] == 0){
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                    } else if (grid[newRow][newCol] == 1){
                        // second island found
                        return res;
                    }
                }
            }

            res++;
        }

        return res;
        
    }
};
