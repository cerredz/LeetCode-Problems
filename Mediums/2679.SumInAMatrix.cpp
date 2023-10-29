
class Solution {
public:

  /*
    Problem:
      You are given a 0-indexed 2D integer array nums. Initially, your score is 0. Perform the following operations until the matrix becomes empty:
      From each row in the matrix, select the largest number and remove it. In the case of a tie, it does not matter which number is chosen.
      Identify the highest number amongst all those removed in step 1. Add that number to your score.
      Return the final score.
*/
    int matrixSum(vector<vector<int>>& nums) {
        

        // sort the individual rows in nums
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sort(nums[i].begin(), nums[i].end());
        }

        // for every column in each row, keep track of the max number seen and add it to the result variable
        int res = 0;
        for(int i = 0; i < nums[0].size(); i++) {
            int max_num = INT_MIN;
            for(int j = 0; j < n; j++) {
                max_num = max(max_num, nums[j][i]);
            }

            res += max_num;
        }

        return res;


    }
};
