class Solution {
public:

/*
    Problem: Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

*/
    void rotate(vector<int>& nums, int k) {
        
        //find how many element you have to rotate(if k > size of nums)
        k %= nums.size();

        //reverse the whole vector
        reverse(nums.begin(), nums.end());
        //reverse number of element you need to rotate (reverts back to original order of last k elements)
        reverse(nums.begin(), nums.begin() + k);
        //reverse the rest of the elements
        reverse(nums.begin() + k, nums.end()); (reverts back to original order of first n-k elements


    
    }
};
