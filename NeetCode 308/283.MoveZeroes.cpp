class Solution {
public:
/*
--------------------------------------------------------------------------------------------
    Approach:
        1. Swap all the non-zero element to the front of the vector, the 0's will then
            automatically ened up in the back of the vector
----------------------------------------------------------------------------------------------
*/

    void moveZeroes(vector<int>& nums) {
        
        //initialize varibales for swapping
        int front = 0, temp = 0;


        for(int i = 0; i < nums.size(); i++) {

            //if non-zero element is found, swap it with nums[front] and increment front
            if(nums[i] != 0) {
                temp = nums[front];
                nums[front] = nums[i];
                nums[i] = temp;
                front++;
            }
        }
       
    }
};
