class NumArray {
public:
/*
    Problem: 
    Given an integer array nums, handle multiple queries of the following type:
    Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
    Implement the NumArray class:
    NumArray(int[] nums) Initializes the object with the integer array nums.
    int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive 
    (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

----------------------------------------------------------------------------------------------------------------
    Approach:
        1. Start with the constructor: When we intialize the constructor we will set a new vector equal to the 
            vector inputted
        2. in the new vector, we will keep the running sum of the vector that was inputted, on other words, each 
            index is the sum of all the numbers of the original vector up until that point
        3. This makes it possible to perform sumRange in constant time. All we have to do is return 
            nums[right] - nums[left - 1]
--------------------------------------------------------------------------------------------------------------
*/
    vector<int> numArray;
    NumArray(vector<int>& nums) {
        numArray = nums;
        for(int i = 1; i < numArray.size(); i++) {
            numArray[i] += numArray[i-1];//keeps running sum in numArray
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) {//edge case, cannot do left - 1 if left is 0
            return numArray[right];
        }

        return numArray[right] - numArray[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
