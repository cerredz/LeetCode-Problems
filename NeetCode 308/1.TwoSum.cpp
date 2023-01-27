class Solution {
public:


/*
    Approach: 
    
    - we will be adding the (target) - (the current Number) to the map, and add the value as the index
    - before doing this, we must check if map[current number] exists, and it is does this means that we have two
        numbers that equal the target

    - declare a result vector, and a map
    - for each integer in nums: 
        - if map[nums[i]] exists
            - add the value of the map[nums[i]] to result
            - add the current index to result
            - return result

        - set the target - nums[i] to the map equal to i

*/

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); i++) {

            if(map.count(nums[i])) {// check if nums[i] is in the map
                res.emplace_back(i);
                res.emplace_back(map[nums[i]]);
                return res;
            }

            map[target - nums[i]] = i; // must declare after checking if map[nums[i]] exists, 
                                        // otherwise we might not get two numbers
        }

        return res;
    }
};
