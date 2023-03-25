class Solution {
public:

/*
    Problem:
      Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
      We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
---------------------------------------------------------------------------------------------
    Approach:
    1. There are two cases for modifying a number, either increasing it or decreasing it
    2. In order to correctly modify a number, we must keep track of the greatest
        number to the left of it
    3. When we run into a decrease in number sequence, check if the greatest number to the
        left of nums[i + 1] is greater
            4. if it is increase the current number to nums[i]
            5. Otherwise we dont have to do anything because we simulate the current number
                decreasing to something less then or equal to nums[i + 1]

            6. If we have already modified something beforehand, return false;
        
    7. Return true if you made it through the for loop
----------------------------------------------------------------------------------------------
Psuedocode:
    - intialize variable for max left number, and a modified count = 0

    - for each number in nums.size() - 1:

        - if nums[i] < nums[i + 1]
            - if max left number > nums[i + 1]
                - set nums[i + 1] = nums[i] (similates a number increase modification)

                - if modified == 1 (this means that we have already modified a number)
                    - return false
                
                - increment modified
            
        - max left number = max (current max left number, nums[i])

    - return true
------------------------------------------------------------------------------------------------


*/
    bool checkPossibility(vector<int>& nums) {
        
        //variables for max left number of total modifications
        int maxNum = -100000, modified = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            //if we run into a decrease number sequence
            if(nums[i] > nums[i + 1]){
                
                //increase modification case
                if(maxNum > nums[i + 1]) {
                    nums[i + 1] = nums[i] + 1;
                }

                //if we have already modified a number beforehand, we return false since we can only modify at most 1 number
                if(modified == 1) {
                    return false;
                }

                //account for modification
                modified++;
            }

            //update max left number if necessary
            maxNum = max(maxNum, nums[i]);
        }

        return true;
    }
};
