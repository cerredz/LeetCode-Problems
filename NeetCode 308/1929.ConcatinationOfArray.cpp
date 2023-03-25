class Solution {
public:
  
  /*
    Problem: Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for
    0 <= i < n (0-indexed).Specifically, ans is the concatenation of two nums arrays.Return the array ans.


  */
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n = nums.size();
        //must get size before we add elements to the back of nums, otherwise we will
        //be stuck in an infinite loop
        for(int i = 0; i < n; i++) {
            nums.emplace_back(nums[i]);
        }
        return nums;


    }
};
