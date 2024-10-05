class Solution {
public:
/*
Problem:
  Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
  A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true: 0 <= i, j < nums.length i != j |nums[i] - nums[j]| == k Notice that |val| denotes the absolute value of val.
*/
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        int res = 0;
        int left = 0, right = 1;
        // sort array to setup two-pointer approach
        sort(nums.begin(), nums.end());

        while(left < n && right < n) {
            // case 1: found valid pair
            if(nums[right] - nums[left] == k) {
                res++;
                // avoid duplicates
                while(right < n - 1 && nums[right] == nums[right + 1]) {
                    right++;
                }
                while(left < right - 1 && nums[left] == nums[left + 1]) {
                    left++;
                }
                right++;
            } else if (left < right - 1 && nums[right] - nums[left] > k) {
                // case 2: pairs too big, increment left pointer
                left++;
            } else {
                // case 3: pairs too smaller, increment right pointer
                right++;
            } 
        }

        return res;
    }
};
