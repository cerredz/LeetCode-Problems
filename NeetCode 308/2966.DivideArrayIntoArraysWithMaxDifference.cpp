class Solution {
public:

/*
Problem:
    You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
    Divide the array nums into n / 3 arrays of size 3 satisfying the following condition: The difference between any two elements in one array is less than or equal to k.
    Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.
*/
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        // sort nums to get close numbers next to each other
        sort(nums.begin(), nums.end());
        int n = nums.size(), row_index = 0;
        vector<vector<int>> res(n / 3, vector<int>(3, 0));

        // loop through nums in nums 3 at a time, building res
        for(int i = 0; i < n - 2; i+= 3) {
            if(nums[i + 2] - nums[i] > k) return {};
            res[row_index] = {nums[i], nums[i + 1], nums[i + 2]};
            row_index++;
        }
        
        return res;
    }
};
