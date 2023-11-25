class Solution {
public:

    /*
        Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
        A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
        All the visited cells of the path are 0. All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
        The length of a clear path is the number of visited cells of this path.
        
        Approach:
        1. Start at the top left cell and run a bfs on the grid
        2. Starting at the top left cell, check the 8 adjacent neighbors and only if they are a 0 add them to the q
        3. Every time we go through out q, increment our result variable by 1
        4. If we ever reach the bottom right of the grid then we can return out result that we found using the bfs
    */


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if (grid[0][0] == 1 || grid.size() == 1 && grid[0].size() == 1) {
            // If the starting cell is blocked or the grid has only one cell and it is 0, return the appropriate value
            return grid[0][0] == 0 ? 1 : -1;
        }

        int n = grid.size(), m = grid[0].size(), res = 1;
        bool skipped = false;
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}}; // 8-directionally connected
        q.push({0, 0});

        // perform the bfs using the coordinates in the grid
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                // add 8 adjcent cells to the next level of the bfs 
                for(const auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m){
                        continue;
                    }

                    if(grid[newRow][newCol] == 0){
                        if(newRow == n - 1 && newCol == m - 1){
                            // reached bottom right cell
                            return res + 1;
                        }
                        grid[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            res++;

        }


        return -1;

    }


};


