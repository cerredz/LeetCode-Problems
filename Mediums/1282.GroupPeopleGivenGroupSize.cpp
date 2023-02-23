class Solution {
public:

/*
    Problem:
      There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.
      You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. 
      For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.
      Return a list of groups such that each person i is in a group of size groupSizes[i].
      Each person should appear in exactly one group, and every person must be in a group. 
      If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.
-----------------------------------------------------------------------------------------------------------------
    Approach:
        1. Iterate through the list of group sizes, and keep track of the frequecies of eack group
        2. For every group number, map the indexes of the group to a vector inside of the map
        3. When mapped, if the size of the vector is equal to the group number, add the vector to the res vector, and then clear the current vector
-------------------------------------------------------------------------------------------------------------------
    Psuedocode: 
        - declare map to keep track of ALL indexes at a given key, and vector of vector for result
        - for each number in groupSizes:
            - add the index of the the number to the list of all indexes found at that number
            - if the amount of indexes found at that number is equal to the number, then add the list of indexes
                to the vector of the vector
            - clear the list of indexes at the current number

        - return the vector of vectors    
        
*/

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        //list of indexes at a number
        unordered_map<int, vector<int>> map;

        vector<vector<int>> res;

        for(int i = 0; i < groupSizes.size(); i++) 
        {
            // add index to current number we are looking at
            map[groupSizes[i]].emplace_back(i);
            
            //check the amount of indexes at the current Number
            if(map[groupSizes[i]].size() >= groupSizes[i]) {
                res.emplace_back(map[groupSizes[i]]);
                map[groupSizes[i]].clear();
            }

        }

        return res;
    }
};
