class Solution {
public:

/*
    Problem: 
    Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
------------------------------------------------------------------------------------------------------------------------
    Approach: 
        - create a vector the size of the original vector, and fill it with the value -1
        - in this vector keep track of the numbers in nums chronilogically by index
        - if one of the indexes in the vector is still -1, then add the index to the result vector
-------------------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare a vector the size nums, filled with -1 (numbers)
        - declare vector that we will be returning (res)

        - for each integer(i) in nums:
            -  set numbers[i] = nums[i]//could theoretically be any number other than -1
        
        - for each integer(i) in nums:
            - if numbers[i] is not equal to -1
                - add i + 1 to result vector(indexes are 0 - nums.size() - 1) 
        
        - return result vector



*/
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> numbers (nums.size(), -1);
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            numbers[nums[i] - 1] = nums[i];
        }

        for(int i = 0; i < nums.size(); i++) {
            if(numbers[i] == -1) {
                res.emplace_back(i + 1);
            }
        }

        return res;
    }
};
