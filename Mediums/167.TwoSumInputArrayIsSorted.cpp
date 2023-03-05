class Solution {
public:
/*
    Problem:
        Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
        find two numbers such that they add up to a specific target number.Let these two numbers be numbers[index1] and numbers[index2] 
        where 1 <= index1 < index2 <= numbers.length.Return the indices of the two numbers, index1 and index2, 
        added by one as an integer array [index1, index2] of length 2.The tests are generated such that there is exactly one solution. 
        You may not use the same element twice.Your solution must use only constant extra space.
------------------------------------------------------------------------------------------------------------------
    Approach:
        1. we will have a map to store prefixSums(keys = target - nums[i], value = i)
        2. When looping through the vector, we check if the current number is in the map,
            if it is this means that we have two numbers that add up to the target, so we can 
                add the value at map[currentNumber] + 1 and i + 1 to the map and return
        3. add target - numbers[i] to the map
----------------------------------------------------------------------------------------------------------------
*/  
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        
        vector<int> res;
        
        unordered_map<int,int> map;

        for(int i = 0; i < numbers.size(); i++) {
            
            //check if the number need to equal the target is in the map
            //must check before updating map, or else certain test cases will fail (if target is 6 and nums[i] = 3)
            if(map.count(numbers[i])){
                //insert value in map first (will always be lower)
                res.emplace_back(map[numbers[i]] + 1);
                res.emplace_back(i + 1);
                return res;
            }

            //insert prefixTarget into the map
            map[target - numbers[i]] = i;
        }

        return res;
    }
};
