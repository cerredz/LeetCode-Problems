class Solution {
public:
/*

  Problem:
    Given an integer array nums, find the subarray with the largest sum, and return its sum.


*/
    int maxSubArray(vector<int>& nums) {
        
        int res = INT_MIN, curr_sum = nums[0];
        int n = nums.size();

        // keep track of subarray sum
        for(int i = 1; i < n; i++) {
            // keep track of maximum subarray sum found
            res = max(res, curr_sum);
            if(curr_sum < 0){
                // if sum dips below 0, reset it to the current number
                curr_sum = nums[i];
            } else {
                curr_sum += nums[i];
            }
        }
        res = max(res, curr_sum); // acount for last subarray sum
        return res;
    }
};
