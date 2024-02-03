class Solution {
public:
    /*
      Problem:
        You are given an integer array nums of size n and a positive integer k. Divide the array into one or more arrays of size 3 satisfying the following conditions:
        Each element of nums should be in exactly one array. The difference between any two elements in one array is less than or equal to k.
        Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

*/
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        // sort nums to get numbers with similiar differences closer to each other
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        if (n < 3) return {};

        // iterate over every group of 3
        for(int i = 0; i < n - 2; i += 3){
            if(nums[i + 2] - nums[i] <= k){
                res.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else {
                // even if one group does not satisfy condition we return
                return {};
            }
        }

        if (res.empty()) return {};

        return res;
    }
};
