class Solution {
public:

/*
  Problem:
    You are given a 0-indexed integer array nums of length n. nums contains a valid split at index i if the following are true:
    The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements. There is at least one element to the right of i. That is, 0 <= i < n - 1.
    Return the number of valid splits in nums.

*/
    int waysToSplitArray(vector<int>& nums) {
        
        long long sum = 0;
        int n = nums.size(), res = 0;

        // compute the prefix sum of nums
        vector<long> prefix(n, 0);
        for(int i = 0; i < n; i++) {
            prefix[i] = sum;
            sum += nums[i];
        }

        // reset the sum, iterate backwards, and compare the new sum to the prefix sum
        sum = 0;
        for(int i = n - 1; i > 0; i--) {
            sum += nums[i];
            if(prefix[i] >= sum) {
                res++;
            }
        }
        return res;
    }
};
