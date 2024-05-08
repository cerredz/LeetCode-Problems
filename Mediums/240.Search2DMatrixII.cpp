class Solution {
public:

    /*
    Problem:
        Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
        Integers in each row are sorted in ascending from left to right. Integers in each column are sorted in ascending from top to bottom.
    */
    // helper function, runs a binary search on a list of numbers, returns either true or false if target is found
    bool binarySearch(vector<int>& row, int target) {

        int left = 0, right = row.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;

            if(row[mid] == target) {
                return true;
            } else if(row[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool found = false;
        int n = matrix.size();
        // run binary search on each row, return true or false depending on if we found the target
        for(int i = 0; i < n; i++) {
            if(binarySearch(matrix[i], target)) {
                found = true;
                break;
            }
        }
        return found;
    }
};
