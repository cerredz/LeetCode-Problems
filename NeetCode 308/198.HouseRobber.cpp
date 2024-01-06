class Solution {
public:
    /*
        Problem:
            You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses
            have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
            Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

        Approach:
            1. Use dynamic programming, every index should represent the maximum AT THAT POINT of the dp 
                array.
            2. EX: if the first number is 15 and the second number is 1, dp[2] should be 15 and NOT 1
            3. Continue this process throughout the entire array
    */
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            cout << dp[i] << endl;
        }
        return dp[n];
    }

};
