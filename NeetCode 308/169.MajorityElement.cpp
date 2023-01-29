class Solution {
public:

/*
    Problem:
    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times. 
    You may assume that the majority element always exists in the array.
    -------------------------------------------------------------------------------------------
    Approach: 
        - we will be looping through the vector and recording the frequency of each element
        - we will then return the element with the greatest frquency
    -------------------------------------------------------------------------------------------
    Psuedocode: 
        - declare a map, maxElement, and result variables

        - for every number in nums: 
            - increment map[nums[i]]
        
        - for every entry in the map:
            - if the entry has the greatest frequency
                - update result to entry->first
                - update maxElement to entry->second
        
        - return res

*/
    int majorityElement(vector<int>& nums) {
        int maxElement = 0;//keeps track of greatest frequency
        int res = 0;//keeps track of the actual number with the greatest frequency
        
        unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;//mapping the frequency of each number
        }

        for(auto entry : map) {
            if(entry.second > maxElement){
                res = entry.first;
                maxElement = entry.second;
            }
        }

        return res;
    }
};
