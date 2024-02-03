class Solution {
public:
    /*
        Problem:
        Given an integer array nums, your goal is to make all elements in nums equal. To complete one operation, follow these steps: Find the largest value in nums. Let its index be i (0-indexed) 
        and its value be largest. If there are multiple elements with the largest value, pick the smallest i. Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest. 
        Reduce nums[i] to nextLargest. Return the number of operations to make all elements in nums equal.

        Approach:
            1. we can use a combination of sorting and two pointers to solve this problem
            2. First we want to sort the array, and then have our right pointer look at the biggest (last)
                element. We want to move our left pointer until we get to a number that this not the
                same as our right pointer. We then want to increment our result by however many elements
                are in between our right and left pointers
            3. Continue step 2 until we reach the smallest number (first element) in the array
    */
    int reductionOperations(vector<int>& nums) {
        
        // sort array
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // declare pointers 
        int left = n - 1, right = n - 1;
        int smallest = nums[0];
        int res = 0;

        // decrement left until we reach the smallest number
        while(left > 0 && nums[left] > smallest) {

            while(left > 0 && nums[left] == nums[right]) {
                left--;
            }
            res += right - left;
            nums[right] = nums[left]; // simulates operation to ALL element bigger than left
        }
        return res;
    }
};
