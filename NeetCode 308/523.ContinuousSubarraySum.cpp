class Solution {
public:

/*
    Problem:
        Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.A good subarray is a subarray where:
        its length is at least two, and the sum of the elements of the subarray is a multiple of k.
        Note that:
          A subarray is a contiguous part of the array.
          An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

----------------------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a prefix sum approach, storing these prefix sums into a map
        2. Have a running sum, and store the remainder of the running sum into a hashMap. Input the remainder 
            as the keys and the indexes as the values
        3. When we input a key into that map, if that key already exists in the map that means that there is a 
            multiple of k that is present in the list
        4. If the key is already in the map, we also have to check if the subarray is big enough, which is why
            we store the indexes as the values
        5. Return false if we do not find a subarray after iterating through the list
-----------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - initialize a map and a variable to keep track of the running sum

        - for each number in nums:
            - add current number to runningSum

            - if the remainder of runningSum exists in the map:
                - if the current index - index[runningSum % k] is greater than 1
                    //this means the subarray is at least 2 numbers long
                    - return true
            - else
                - add the remainder of the runningSum to the map, set its value to the current index

        - if we make it outside the for loop, this means that we do not have a subarray of at least 2 numbers
            and can return false
------------------------------------------------------------------------------------------------------------------
        
*/
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int runningSum = 0;
        unordered_map<int,int> map;

        //must set map at 0, otherwise there will be edge cases that fail ([0])
        map[0] = -1;

        
        for(int i = 0; i < nums.size(); i++) {

            //add current number to the runnning sum
            runningSum += nums[i];

            //if the remainder of the running sum is in the map
            if(map.count(runningSum % k)) {
                //check for at least 2 number subarray
                if(i - map[runningSum % k] > 1) {
                    return true;
                }
            //if the remainder of the runnning sum is not in the map, put it in the map
            }else {
                map[runningSum % k] = i;
            }

            
        }

        //no subarray of at least length 2 have been found
        return false;
       
    }
};
