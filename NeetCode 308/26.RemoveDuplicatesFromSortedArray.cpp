class Solution {
public:
/*
    Problem:
        Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
        The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
        Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
        Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
        The remaining elements of nums are not important as well as the size of nums.Return k.

--------------------------------------------------------------------------------------------------------
    Approach:
        1. Intialize a separate vector that will be used for changing the order of nums, and an int
            counter variable that will be used for returning the number of unique numbers in nums
        2. For every number in nums we want to look at the previous number, if they are not the same
            then we can increment our counter varible and add the number to our new vector
        3. Change the first k-unqiue numbers in nums to the corresponding value in our other vector
        4. Return the counter varible
----------------------------------------------------------------------------------------------------------
*/
    int removeDuplicates(vector<int>& nums) {
        
        //declare variables
        vector<int> correctOrder;
        int count = 1;
        //must account for first number
        correctOrder.emplace_back(nums[0]);

        //count distinct numbers in nums
        for(int i = 1; i < nums.size(); i++) {
            
            //look at previous element
            if(nums[i] != nums[i - 1]){
                correctOrder.emplace_back(nums[i]);
                count++;
            }
        }

        //fix the order of first count-numbers in nums
        for(int i = 0; i < correctOrder.size(); i++) {
            nums[i] = correctOrder[i];
        }

        return count;

    }   

};
