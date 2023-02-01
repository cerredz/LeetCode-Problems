class Solution {
public:


/*
    Problem: 
     Given an array of integers nums, calculate the pivot index of this array.
     The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of 
     all the numbers strictly to the index's right.If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left.
     This also applies to the right edge of the array.Return the leftmost pivot index. If no such index exists, return -1.
---------------------------------------------------------------------------------------------------------------------
    Approach:
        - we will go through the element in the vector and keep track of the sum of all element
        - we will also have a leftSum, that is the sum of all element to the left of the current element
        - we will loop through the vector and see if the leftSum is equal to the rightSum of the index
----------------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare a sum and leftSum variable
        
        - for each number in nums:
            - add number to sum
        
        - for each number in nums:  
            - if the leftSum = sum - leftSum - nums[i]//calculates the right sum
                - return i
            
            - increment leftSum by nums[i]

        - return -1

*/
    int pivotIndex(vector<int>& nums) {
        
        int sum = 0, leftSum = 0;

        for(int i : nums) {
            sum += i;//sum of all elements in nums
        }

        for(int i = 0; i < nums.size(); i++) {
            
            if(leftSum == sum - leftSum - nums[i]){//check if leftSum and rightSum are equal to each other
                return i;
            }
            leftSum += nums[i];//increment leftSum
        }

        return -1;
       
    }
};
