class Solution {
public:

/*
    Problem:
      Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
-----------------------------------------------------------------------------------------------
    Approach:
        1. This problem is pretty simple, all we have to do is reverse the vector several
            times
        2. Start off my reversing the full vector from start to end, now we need to reverse
            two subsets individually to return them to their original order
        3. Reverse the first k elements, this will make the original k-last elements become
            the k-first elements in the vector
        4. Reverse elements k + 1 -> nums.size(), this will correct the order of the remaining
            elements
---------------------------------------------------------------------------------------------- 
*/
    void rotate(vector<int>& nums, int k) {
        
        //edge case, k kis bigger than size of nums
        k %= nums.size();

        //reverse the full vector
        reverse(nums.begin(), nums.end());

        //reverse the first k elements back to their original order
        reverse(nums.begin(), nums.begin() + k);

        //reverse the remaining elements back to their original order
        reverse(nums.begin() + k, nums.end());

    
    }
};
