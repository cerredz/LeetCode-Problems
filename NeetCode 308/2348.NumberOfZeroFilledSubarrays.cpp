class Solution {
public:
/*
    Problem:
        Given an integer array nums, return the number of subarrays filled with 0. 
        A subarray is a contiguous non-empty sequence of elements within an array. 
*/
    long long zeroFilledSubarray(vector<int>& nums) {
        
        //declare result variables, and variable to keep track of the number of zeros we have in a continguous subarray
        long long res = 0;
        int numZeros = 0;


        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0) {
                //if the current number is a 0, we simply just add the length of the contiguous number of zeros to the result, this will give us the total number of subarrays filled with 0
                res += numZeros + 1;
                numZeros += 1;
                
            } else {
                //result the length of the contiguous zeros if the current number is not a zero
                numZeros = 0;
            }
        }

        return res;


    }
};
