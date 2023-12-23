class Solution {
public:
/*
    Problem:
      You are climbing a staircase. It takes n steps to reach the top.
      Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Approach:
        1. use dynamic programming, the result of the nth step is simply just the sum of the 
            previous two n steps
        2. Fill in our base cases for first and second step, then fill in the rest of the array up until n
*/
    int climbStairs(int n) {
        
        vector<unsigned int>dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};
