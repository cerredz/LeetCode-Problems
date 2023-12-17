class Solution {
public:
    /*
    
        Problem:
          Given a binary array nums, you should delete one element from it.
          Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
          Return 0 if there is no such subarray.
    */
    int longestSubarray(vector<int>& nums) {
        
        
        int res = INT_MIN;
        int left = 0, right = 0, zero_index = -1;

        // sliding window approach
        while(right < nums.size()) {

            if(nums[right] == 0 && zero_index != -1) {
                // if zero_index is not -1, this means that there is already 1 zero in our window, so we have to decrement our window
                left = zero_index + 1;
            }

            if(nums[right] == 0) {
                zero_index = right;
            }

            // right - left represents current window of 1's with at most 1 deletion
            res = max(res, right - left);
            right++;
        }

        return res;

    }
};
