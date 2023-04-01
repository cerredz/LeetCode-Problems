class Solution {
public:

/*

    Problem:
      You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
      Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
      Return the minimum possible difference.
---------------------------------------------------------------------------------------------
    Approach:
        1. We will start by sorting the list of numbers, this will give us the ability to 
            use a two pointer approach because numbers with the least
            difference will be align next to each other
        2. Initialize out left pointer to 0, and the right pointer to k - 1
        3.  While the right pointer is less than the size of nums, calcualte the nums[right]
            minus nums[left]. This is our current window with respect to k numbers, and if
            the different is less then our answer variable then update answer
        4. Increment both left and right after every iteration of the while loop
------------------------------------------------------------------------------------------------

*/
    int minimumDifference(vector<int>& nums, int k) {
        
        //edge case
        if(nums.size() == 1) {
            return 0;
        }
        //start off by sorting nums to align numbers correctly in order to be able to use a two pointer approach
        sort(nums.begin(), nums.end());

        //initialize pointers
        int left = 0, right = k-1, ans = nums[k-1] - nums[0];

        //calcualte the differences of the values at each pointer and update answer accorindly
        while(right < nums.size() - 1) {
            //increment pointers
            left++;
            right++;
            //calculate differences
            ans = min(ans, nums[right] - nums[left]);
            
        }

        return ans;
        
        
    }
};
