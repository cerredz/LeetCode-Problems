class Solution {
public:

    /*
        Problem:
            Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to
            the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
            The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
        Approach:
            1. Run a bfs on the LAND cells, marking all water cells and turning them into land 
                (turning '0's into '1's)
            2. Keep track of the distance we while traversing all cells in the graph
            3. After we reach the last '0' cell and the bfs has ended, return the distance we got up to 
    */

    int maxDistance(vector<vector<int>>& grid) {
        
        
        int n = grid.size(), m = grid[0].size();
        int distance = 1;
        queue<pair<int, int>> q;
        
        // add the land cells to the q for the bfs
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                bool land = grid[i][j] == 1;
                if(land) q.push({i, j});
            }
        }

        if(q.empty() || q.size() == n * m) {
            // either all water or all land
            return -1;
        }

        // perform the bfs, keeping track of the distance
        while(!q.empty()) {

            int n = q.size();

            for(int i = 0; i < n; i++) {

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 2) {
                    continue;
                }

                grid[row][col] = 2; // "mark" current cell as visited

                q.push({row + 1, col});
                q.push({row - 1, col});
                q.push({row, col + 1});
                q.push({row, col - 1});
            }
            distance++;

        }

       // exclude iteration where we counted the distance of the final '0'
        return distance - 1;
    }
};
