class Solution {
public:

/*

Problem:

    You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
    Return the single element that appears only once.

Approach: 
    1. we can use two pointers to solve this problem, starting at the leftmost and rightmost
        indexes
    2. Even with using two pointers, we can skip about half of the index we check since 
        there are only n / 2 numbers in an n-lengthed vector 
    3. If the number next to our left pointer and right pointer is equal to it it, then we 
        will move both the left pointer and right pointer inward by 2 indexes since we
        already checked the next index;
    4. If the number next to the left or right pointer is not equal to the left / right 
        pointer we want to return the number at the left / right pointer. We dont want to 
        return the number next to it because our pointers will always be positioned at the 
        first index of a number
    

*/
    int singleNonDuplicate(vector<int>& nums) {
        

        //declare pointers
        int left = 0, right = nums.size() - 1;

        //edge case
        if(nums.size() == 1) {
            return nums[0];
        }

        //perform two pointer algorithmn
        while(left <= right) {

            //check adjacent number to our pointers, if not the same then return the pointer
            
            if(nums[left] != nums[left + 1]) {
                return nums[left];
            }

            if(nums[right] != nums[right - 1]) {
                return nums[right];
            }

            //move pointers inward
            left += 2;
            right -= 2;
        }

        //control will never reach here, return anything
        return -1;
    }

};
