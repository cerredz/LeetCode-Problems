class Solution {
public:
    /*
        Problem:
          You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
          That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
          Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


         Approach:
            1. given an 0-indexes array of length n, split the array into 0 -> n - 1, and 1 -> n
            2. Once you have the two arrays, run the dp algorithm that solves House Robber 1, and return 
                the one with the bigger result
    */
    
    // helper dp function
    int steal(vector<int>& nums, int start, int end) {

        int n = (end - start) + 1;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = nums[start];
        for(int i = start + 2; i <= end + 1; i++) {
            dp[i - start] = max(dp[i - 1 - start], dp[i - 2 - start] + nums[i - 1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        // split array into two pieces, and run dp on the 2 subsets, returning the bigger one
        return max(steal(nums, 0, n - 2), steal(nums, 1, n - 1));
    }
};
