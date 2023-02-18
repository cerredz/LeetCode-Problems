class Solution {
public:
/*
    Problem: 
    There is a rectangular brick wall in front of you with n rows of bricks. 
    The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. 
    The total width of each row is the same.Draw a vertical line from the top to the bottom and cross the least bricks. 
    If your line goes through the edge of a brick, then the brick is not considered as crossed. 
    You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
    Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.
----------------------------------------------------------------------------------------------------------------
    Approach: 
    1. We will create a hashMap, this hashmap will store how many gaps we have in each column
    2. The keys in our hashmap will be the index where we find a gap, and the value will be how many gaps
        we find at that index
    3. We will loop through the entire vector of vector and update out map appropiately
    4. We will then loop thrugh out map to find which index has the highest number of gaps(numGaps) (if they have the 
        highest number of gaps they will have the lower number of croseed bridges)
    5. return the number of rows - numGaps to find the least amount of crossed bricks drawing a straight line
---------------------------------------------------------------------------------------------------------------
    Psuedocode:
    
    - declare a map variable (map),  a leftSum variable (leftSum), and a variable to keep track of the greatest 
        number of gaps in a row (largestGaps)
    - for every row in map:
        - reset the leftSum  = 0
        - for every column in the current row:
             - increment leftSum by the current number we are looking at
             - increment map[leftsum] by 1
    - for every entry in map:
        - if that entry's value is bigger than largestGaps then update largestGaps
    
    - return the number of rows in wall - largestGaps
--------------------------------------------------------------------------------------------------------------

*/

    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int, int> map;
        int leftSum = 0, largestGap = 0;

        //step 1: count gaps in the wall
        for(int row = 0; row < wall.size(); row ++)
        {
            leftSum = 0;
            for(int col = 0; col < wall[row].size() - 1; col++)//can't draw a line on the right of the last brick, so we stop 1 index short 
            {
                leftSum += wall[row][col];//increment leftSum before incrementing map[leftSum] because we cant draw a line on the left of the first index
                map[leftSum] ++;
            }
        }

        //step 2: find the index with the largest amount of gaps
        for(auto entry : map) {
            largestGap = max(entry.second, largestGap);
        }

    
        return wall.size() - largestGap;
    }
};
