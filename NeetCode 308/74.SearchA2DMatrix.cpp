class Solution {
public:

/*

    Problem:
        You are given an m x n integer matrix matrix with the following two properties: Each row is sorted in non-decreasing order. The first integer of each row is greater 
        than the last integer of the previous row. Given an integer target, return true if target is in matrix or false otherwise.
        You must write a solution in O(log(m * n)) time complexity.
    Approach:
        1. This problem is pretty straightforward, we will simple just treat the vector of a vector as a singular 
            vector of numbers with length (m * n). For example, if the 2d vector has 4 rows and 3 columns then 
            we will simple just run a binary search on the 2d vector were the lower bound is = 0, and the 
            upper bound is = 11 ((m * n) - 1). By doing the problem this way we will be able to achieve the 
            0(log (m * n)) time complexity that is required for this problem
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        //obtain number of rows and cols
        int rows = matrix.size(), cols = matrix[0].size(); 

        //declare our lower and upper bound
        int left = 0, right = (rows * cols) - 1; 


        //perform a binary search on the 2d vector
        while(left <= right) {

            int mid = (left + right) / 2;

            //calculate the exact row and column index of the 2d vector
            int row_index = (mid / cols);
            int column_index = mid % cols;


            //compare value to target
            if(matrix[row_index][column_index] == target) {
                //target found
                return true;
            } else if (matrix[row_index][column_index] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }
        
        //if control reaches here, target is not in the 2d vector
        return false;
    }
};
