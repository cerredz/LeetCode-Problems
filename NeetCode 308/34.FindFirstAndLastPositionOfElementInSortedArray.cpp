class Solution {
public:

/*
    Problem:
      Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
      If target is not found in the array, return [-1, -1]. You must write an algorithm with O(log n) runtime complexity.

    Approach:
        1. We will use binary search in our solution
        2. We will perform a standard binary search until we run into the target value. Once we run into the target
            value we will expand the left and right pointers outward until they are no longer equal to the target
            value. Once they are no longer equal to the target value, we will break from the main while loop and return
            the left and right pointers in a vector
        3. Although in the worst case where all the numbers are the same and our algorithmn will run in 0(n) time
            complexity; our algorithm still performs significantly faster on average than a regular iteration through 
            the array
*/
    vector<int> searchRange(vector<int>& nums, int target) {

        //edge case
        if (nums.empty()) {
            return {-1, -1};
        }

        //declare variables
        int left = 0, right = nums.size() - 1;
        bool target_found = false;

        //run a binary search, searching for target
        while (left <= right) {

            int mid = left + (right - left) / 2;

            
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {

                //target found
                target_found = true;
                left = mid;
                right = mid;

                //expand pointers outward
                while (left > 0 && nums[left - 1] == target) {
                    left--;
                }

                while (right < nums.size() - 1 && nums[right + 1] == target) {
                    right++;
                }
                //break from main while loop
                break;
            }
        }

        //if target was in the vector, then the pointers was the window of target, return them
        if (target_found) {
            return {left, right};
        }

        return {-1, -1};
    }
};
