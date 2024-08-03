class Solution {
public:
/*
    Problem:
      The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
      For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16. Given an integer array nums, choose four distinct indices w, x, y, and z such that the product 
      difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized. Return the maximum such product difference.


*/
    int maxProductDifference(vector<int>& nums) {
        // sorting will essentially find the max product difference for us
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 2] * nums[n - 1]) - (nums[0] * nums[1]);
    }
};
