class Solution {
public:
  /*
    Problem:
        The distance of a pair of integers a and b is defined as the absolute difference between a and b.
        Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
  */
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n = nums.size();
        // sort for binary search
        sort(nums.begin(), nums.end());

        // define initial window for binary search
        int left = 0;
        int right = nums[n - 1] - nums[0];

        // perform binary search
        while(left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            int j = 0;

            // count the pairs with distance less than mid
            for(int i = 0; i < n; i++) {
                while(j < n && nums[j] - nums[i] <= mid) {
                    j++;
                }
                count += j - i - 1;
            }

            // update the binary search window based on k
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }

        }

        return left;
    }
};
