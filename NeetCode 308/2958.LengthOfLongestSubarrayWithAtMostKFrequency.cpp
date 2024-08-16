class Solution {
public:
/*
    Problem:
      You are given an integer array nums and an integer k. The frequency of an element x is the number of times it occurs in an array.
      An array is called good if the frequency of each element in this array is less than or equal to k. Return the length of the longest good subarray of nums.
      A subarray is a contiguous non-empty sequence of elements within an array.
*/
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int max_subarray = 0, n = nums.size();
        // use left and right pointer for our sliding window approach, starting at leftmost indexes
        int left = 0, right = 1;
        // use map to store number freqencies in our window
        unordered_map<int, int> map; 
        if(n < 2) return n;
        map[nums[left]]++;

        // implement out sliding window approach, growing the window to the right
        while(right < n) {
            map[nums[right]]++;
            if(map[nums[right]] > k) {
                // too mcuh frequency of number on the right, start chopping from the left of our window 
                while(left < right && map[nums[right]] > k){
                    map[nums[left]]--;
                    left++;
                }
            }
            // calculate window size
            max_subarray = max(max_subarray, right - left + 1);
            right++;
        }
        return max_subarray;
    }
};
