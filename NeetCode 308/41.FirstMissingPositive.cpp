class Solution {
public:

/*
    Problem:
      Given an unsorted integer array nums, return the smallest missing positive integer.
      You must implement an algorithm that runs in O(n) time and uses constant extra space.
---------------------------------------------------------------------------------------------
    Approach:
    1. if n = length of nums, the first n integers must be in nums (1,2,...,n) to have no
        missing positive values
    2. Given this, we can have a vector of bool values representing the numbers from 1 -> n
        found in nums
    3. We also want to keep track of the greatest number in nums, just in case we are not 
        missing any positive values
    4. Check each number in nums, if the number is greater than 0 and less than or equal to 
        n, mark the bool value at nums[i] = true
    5. After accounting for all numbers, iterate through the vector of bools, if an index is
        false, return that index
    6. If all values in the vector are true this means that we are not missing a positive
        integer, and we can return either the next missing positive integer
----------------------------------------------------------------------------------------------
*/
    int firstMissingPositive(vector<int>& nums) {
        
        //intialize needed variables
        int n = nums.size(), max_num = 0;
        vector<bool> positive_numbers_found(n + 1, false);

        //mark all the numbers found in nums between 1 -> n to true
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 && nums[i] <= n) {
                positive_numbers_found[nums[i]] = true;
            }
            //account for the biggest number in nums
            max_num = max(max_num, nums[i]);
        }

        //check if any number between 1 -> n was not in nums
        for(int i = 1; i <= n; i++) {

            if(!positive_numbers_found[i]){
                return i;
            }
        }

        
        return max(max_num + 1, 1);//if max_num is -2 our algorithm will not work because the first positive integer is 1, so return the max of the two



        
    }
};
