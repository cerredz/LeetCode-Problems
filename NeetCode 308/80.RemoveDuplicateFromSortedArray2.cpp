class Solution {
public:

/*
    Problem:
      Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. 
      The relative order of the elements should be kept the same.Since it is impossible to change the length of the array in some languages, 
      you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, 
      then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
      Return k after placing the final result in the first k slots of nums.Do not allocate extra space for another array. 
      You must do this by modifying the input array in-place with O(1) extra memory.
----------------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer approach, one pointer that keeps track of the current index,
            and another pointer that keeps track of where to swap elements
        2. We will iterate through nums, and use our first pointer (i) to keep track of the count
            of each unique number in nums
        3. If the count is either 0 or 1 (2 numbers or less), swap the current number with the index of
            our second pointer (swapIndex), and increment the second pointer
            - this way we are eliminating the numbers that occur more than twice in the vector
        4. Return the index of the second pointer, beacuse the elements up until the next available swap
            are the number of unique elements, up to 2 appearances, in nums
----------------------------------------------------------------------------------------------------------    Psuedocode:

    - intialize second pointer, and count variable

    - for each number in nums:
        - if nums[i] = nums[i - 1]
            - increment count
        - else 
            - reset count back down to 0
        
        - if count is less than 2:
            - swap nums[second pointer] with nums[currentIndex]
            - increment the second pointer
    
    - return the second pointer
----------------------------------------------------------------------------------------------------------
            

*/
    int removeDuplicates(vector<int>& nums) {
        
        //intialize variables
        int swapIndex = 1, count = 0;

        //for-loop index will serve as our first pointer
        for(int i = 1; i < nums.size(); i++) {

            //count occurences of each unique number in nums
            if(nums[i] == nums[i - 1]){
                count++;
            }else {
                count = 0;
            }

            //if the count is less than 2 occurences, swap current index with nums[second pointer]
            if(count <= 1) {
                nums[swapIndex] = nums[i];
                swapIndex++;
            }
        }

        return swapIndex;


    }
};
