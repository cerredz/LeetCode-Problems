class Solution {
public:
/*
    Problem:
        Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] 
        and abs(i - j) <= k.
-----------------------------------------------------------------------------------------------------------------
    Approach:
        1. We wil be using a sliding window approach that incorperated hashing the most recent index of a number
        2. In our map we will store the number in nums as the keys, and the indexes as our values. 
        3. We want the gap between indexes found to be as small as they can, so whenever we find a number
            that is already in the map, update the index to the larger one. This will simulate moving the 
            current window of that number to the right
        4. If we already find a number in the map, see if the absolute value of the difference of the two
            numbers is less than or equal to k, if it is return true
        5. If we do not return true by the end of iterating through each number in nums, then return false
-----------------------------------------------------------------------------------------------------------------
    Psuedocode:

        - declare a map for our sliding window approach

        - for each number in nums:

            - if the number is in nums, then calculate the absolute value of the two indexes that the number was 
                found
                - if this number is less than or equal to k, then return false

            - set / update map[currentNumber] = the current index
        
        - return false
----------------------------------------------------------------------------------------------------------------
*/
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        //initialize map
        unordered_map<int, int> map;

        //implement our sliding window approach
        for(int i = 0; i < nums.size(); i++) {
            
            //if we find duplicate, caluculate difference
            if(map.count(nums[i])){
                if(abs(i - map[nums[i]]) <= k){
                    return true;
                }
            }

            //decrease the window for the current number
            map[nums[i]] = i;
            
        }

        return false;
    }
};
