class Solution {
public:

/* 
  Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
  
  Approach: 
  - create a map
  - for each number in nums: 
    - if map[number] > 0
      - this means that number appears more than once
      - return true
      
    - increment map[number]
  
  - if control reaches outside of the for loop, we can return false
      
*/ 
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i : nums) {
            if(map[i] > 0) {
                return true;
            }

            map[i]++;
        }
        return false;
        
    }
};
