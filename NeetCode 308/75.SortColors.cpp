class Solution {
public:
/*
    Problem:
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
    with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    *You must solve this problem without using the library's sort function.*
----------------------------------------------------------------------------------------------------------------------
    Approach:
        1. Keep track of the frequency of zeros and twos
        2. Loop through the vector 
            3. whenever you encounter a 0, swap that index with the leftmost index that is not a zero
            4. whenever you encounter a 2, swap that index with the rightmost index that is not a two
        - By doing this, not only will the zeros be on the left and twos be on the right, but the 1's will automitically 
            fall into place in the middle
-----------------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - keep track of the indexes of where you next zero or two should go:
            - nextZeroIndex = 0
            - nextTwoIndex = nums.size() - 1

        - while(currentIndex < nextTwoIndex)
            - if the current number is 0
                - swap the current number's index with nextZeroIndex
                - increment nextZeroIndex
            - else if the current number is 2
                - swap the current numbers index with nextTwoIndex
                - decrement nextTwoIndex
            
        
        
*/

    void sortColors(vector<int>& nums) {
        
        int zeroCount = 0, twoCount = nums.size() - 1, index = 0;

        while(index <= twoCount) {//dont want to loop until nums.size() because your 1's and 2's will end up being flipped
            if(nums[index] == 0) //zero case
            {
                swap(nums[index], nums[zeroCount]);
                zeroCount++; 

            }else if(nums[index] == 2){ //two case
                swap(nums[index], nums[twoCount]);
                twoCount--;
                index--;//must decrement index to ensure that no numbers are skipped
            }
            index++; 
        }

       
    }

};
