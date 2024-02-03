class Solution {
public:
    /*
        Problem:
          You are given a positive integer array nums. Partition nums into two arrays, nums1 and nums2, such that: Each element of the array nums belongs to either the array nums1 or the array nums2. 
          Both arrays are non-empty. The value of the partition is minimized. The value of the partition is |max(nums1) - min(nums2)|. Here, max(nums1) denotes the maximum element of the array nums1, 
          and min(nums2) denotes the minimum element of the array nums2. Return the integer denoting the value of such partition.

        Approach:
            1. the solution is very straighforward, all we have to do is to find the minimum difference
                between two elements in the array
    */
    int findValueOfPartition(vector<int>& nums) {

        // sort to minimize difference between adjacent numbers
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MAX;
        // find minimum difference
        for(int i = 0; i < n - 1; i++) {
            res = min(res, nums[i + 1] - nums[i]);
        } 
        return res;
    }
};
