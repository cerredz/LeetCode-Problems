class Solution {
public:
/*

Problem:
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
    You must write an algorithm that runs in O(n) time and without using the division operation.
------------------------------------------------------------------------------------------------
Approach:
    1. declare a res vector
    2. Loop through the numbers in nums and add the left product to each of the indexes
    3. Loop through the numbers in nums again, this time in reverse order, and multiply the
        right product to the current index
------------------------------------------------------------------------------------------------
Psuedocode:
    - declare result vector(res) the size of nums, and set each index's value to 1

    - for each number in nums:
        - set res[i] equal to the product of (previous index of res and the previous
            index's value of nums)

    - declare variable to keep track of the right product
    - for each number in nums(in the reverse order)
        - set res[i] equal to the current value multiplied by the right value
        - update the right product by multiplying it by nums[currentIndex]

    - return res
        
*/
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
       vector<int>res (nums.size(), 1);

       for(int i = 1; i < nums.size(); i++) {//starts at index 1 because the left product of index 0 is the same as nums[0] * 1
           res[i] = res[i - 1] * nums[i - 1];//calculates left product of each index
       }

       int rightProduct = 1;//no right product of last index, so we start right product off as 1

       for(int i = nums.size() - 1; i >= 0; i--) {
           res[i] *= rightProduct;//must update res before updating rightProduct, because the last element does not have a right product
           rightProduct *= nums[i]; 
       }

        return res;
        
    }
};
