class Solution {
public:

/* 

    Problem:
      You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. 
      Two robots are playing a game on this matrix.Both robots initially start at (0, 0) and want to reach (1, n-1). 
      Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).At the start of the game, the first robot moves from 
      (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. 
      Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.
      The first robot wants to minimize the number of points collected by the second robot. 
      In contrast, the second robot wants to maximize the number of points it collects. 
      If both robots play optimally, return the number of points collected by the second robot.
-----------------------------------------------------------------------------------------------------------------
    Approach: 
        1. We will be using a greedy approach, and first we will be computing the running sum of the top row
            as the prefix sum.
        // rememeber, there are only 2 rows so this makes it easy to compute all possible   
            paths for the robot to travel
        2. We will looper through each columna and will use our top prefix sum to 
            calculate the sum for the SECOND robot:

            3. At each iteration we will change the path the second robot is taking, since there is only 2 rows 
                we can increment the top row's running sum and decrement the bottom row's running sum
            4. Keep track of the path with the lowest score

        5. Return the path with the lowest score
-----------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - have a varibales to keep track of the top running sum (topScore), bottom running sum (bottomScore),
            and the second robot's score (secondRobot)

        - calculate the running sum of the top row in grid (topScore)

        - for each column in grid:

            - simulate the path moving down, (it can only move down one and never come back up), and 
                calculate the second robot's path sum using topScore and bottomScore

        - return the second robot's current score (will be the lowest)
*/
    long long gridGame(vector<vector<int>>& grid) {

        //top and bottom prefix scores
        long long topScore = grid[0][0], bottomScore = 0;
        long long secondRobot = LLONG_MAX;

        //top row running sum
        for(int i = 1; i < grid[0].size(); i++) {
            topScore += grid[0][i];
        }

        //compute all possible paths for robot to travel and set second robot to the minimum path
        for(int i = 0; i < grid[0].size(); i++) {
            topScore -= grid[0][i]; 
            //simulates the numbers from grid[0][0] -> grid[0][i] all being 0

            secondRobot = min(secondRobot, max(topScore, bottomScore));
            
            bottomScore += grid[1][i];
            //simulates the numbers from grid[1][N] -> grid[1][i] being 0, where N is # of columns
        }

        return secondRobot;



        
        
    }
};
