class Solution {
public:
/*
  Problem:
    An array is monotonic if it is either monotone increasing or monotone decreasing.
    An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
    Given an integer array nums, return true if the given array is monotonic, or false otherwise.
*/
    bool isMonotonic(vector<int>& nums) {
        // have 2 bolean varibales one to track mono inc, and mono decre
        bool isMonotonicIncreasing = true, isMonotonicDecreasing = true;
        int n = nums.size();

        // update the variables as we loop through the array, can be done in 1 for-loop
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) isMonotonicIncreasing = false;
            if(nums[i] < nums[i + 1]) isMonotonicDecreasing = false;
        }
        return isMonotonicIncreasing || isMonotonicDecreasing;
    }
};
