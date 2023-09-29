class Solution {
public:

/*
    Problem:
        You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
        You should rearrange the elements of nums such that the modified array follows the given conditions: Every consecutive pair of integers have opposite signs.
        For all integers with the same sign, the order in which they were present in nums is preserved. The rearranged array begins with a positive integer.
        Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
  
*/
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> res(nums.size(), 0);
        int positiveIndex = 0, negativeIndex = 1;

        // place the numbers in nums into res according to the pos and neg index
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                // positive number found, place at positiveIndex
                res[positiveIndex] = nums[i];
                positiveIndex+= 2;
            } else {
                // negative number found, place at negativeIndex
                res[negativeIndex] = nums[i];
                negativeIndex+= 2;
            }
        }

        return res;

       
    }
};
