class Solution {
public:
/*
  Problem:
      Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

*/
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = -1;
        for(int i = 1; i < n; i++) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};
