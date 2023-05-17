class Solution {
public:
/*

    Problem:
        Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
        whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach where we will be expanding and 
            shrinking the window
        2. We will have a left and right pointer, we will start at the leftmost index be
            incrementing the right pointer
        3. We want to keep the sum of the numbers in our window, and keep expanding our
            window if this sum is less than the target
        4. once this sum is greater than the target, we want to update the variable keeping 
            track of the minimal subarray if necessary, we also want to shrink our window 
            from the left side until the sum is less than the target. This will ensure
            that the smallest window where the sum > target is checked.
        5. Continue this process until our right pointer is out of bounds of the vector.
---------------------------------------------------------------------------------------------
*/
    int minSubArrayLen(int target, vector<int>& nums) {
        

        //declare variables
        int res = 100000000, left = 0, sum = 0;

        //implement sliding window approach
        
        for(int i = 0; i < nums.size(); i++) {//i simulates the right pointer

            //keep track of the sum of our window
            sum += nums[i];

            //shrink window if sum > target
            while(sum >= target) {
                //update window if it is lowest seen so far
                res = min(res, i - left + 1);

                //here is where we actually shrink the window
                sum -= nums[left];
                left++;
                
            }
            

            
        }

        //if no window is found return 0
        if(res == 100000000){
            return 0;
        }

        //otherwise return the smallest window found
        return res;
    }
};
