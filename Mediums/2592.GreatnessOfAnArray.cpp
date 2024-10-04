class Solution {
public:

/*
Problem:
  You are given a 0-indexed integer array nums. You are allowed to permute nums into a new array perm of your choosing.
  We define the greatness of nums be the number of indices 0 <= i < nums.length for which perm[i] > nums[i].
  Return the maximum possible greatness you can achieve after permuting nums.

*/
    int maximizeGreatness(vector<int>& nums) {
        
        // edge case
        if(nums.size() <= 1) return 0;

        // sort array to set up two pointer approach
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int n = nums.size();
        int res = 0;

        // two pointer implementation
        while(left < n && right < n) {
            // always try to find the lowest greater number for our left pointer
            while(right < n && nums[right] <= nums[left]) {
                right++;
            }

           if(right < n) {
            left++;
            right++;
            res++;
           }
        }
        return res;
    }
};
