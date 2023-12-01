class Solution {
public:

/*
  Problem:
  Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the 
  integers that appears twice. You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            if (nums[index] < 0) {
                res.push_back(index + 1);
            } else {
                nums[index] = -nums[index]; // "marking" the number at index since nums can never have negative number
            }
        }

        return res;

    }
};
