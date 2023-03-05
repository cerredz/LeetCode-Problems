class Solution {
public:

/*
    Problem:
      Given an integer array nums, find the subarray with the largest sum, and return its sum.
------------------------------------------------------------------------------------------------------------------
    Approach:
        1. We will have a maxSum(keeps track of maximum subarray), and a currentSum(keep track of the sum of the
            current subarray)
        2. Loop through the vector
            3.  Increment the current running sum by the the current number
            4.  If the current running sum is greater than the maximum sum, update the maximum sum
            5.  If the current running sum is less than 0, set the current running sum back equal to 0
                (shortening window of subarray)
        6. return the maxSum
---------------------------------------------------------------------------------------------------------------
*/
    int maxSubArray(vector<int>& nums) {

    
        //declare maxSum and currentSum
        int maxSum = INT_MIN, currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            //add current number to currentSum
            currentSum += nums[i];
            //update maxSum if maxSum < currentSum
            maxSum = max(maxSum, currentSum);
            //shorten window is currentSum is negative
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
};
