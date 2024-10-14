class Solution {
public:

/*
problem:
    You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract 
    its value from x. Note that this modifies the array for future operations. Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

*/
    int minOperations(vector<int>& nums, int x) {
        
        // create the target for our max subarray sliding window approach
        int target = 0, total_sum = 0;
        for(int &i : nums) total_sum += i;
        target = total_sum - x;

        int res = INT_MAX, n = nums.size(), left = 0, right = 0, curr_sum = 0;

        // implement sliding window approach
        while(right < n) {
            // look for a window where target = curr_sum, this means that the rest of the element in the array will add up to x
            curr_sum += nums[right];

            // window sum too big, shrink it
            while(left <= right && curr_sum > target) {
                curr_sum -= nums[left];
                left++;
            }

            // found possible subarray
            if(curr_sum == target) res = min(res, n - (right - left + 1));
            right++;
        }

        if(res == INT_MAX) return -1;

        return res;
        
    }
};
