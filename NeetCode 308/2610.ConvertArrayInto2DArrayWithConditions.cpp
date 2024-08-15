class Solution {
public:

/*
  Problem:
    You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
    The 2D array should contain only the elements of the array nums. Each row in the 2D array contains distinct integers.
    The number of rows in the 2D array should be minimal. Return the resulting array. If there are multiple answers, return any of them.
    Note that the 2D array can have a different number of elements on each row.

*/
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        // store the frequencies of each num in nums into a hashmap
        unordered_map<int, int> map;
        for(int& i : nums) map[i]++;

        // build res using the freqencies in the map
        for(const auto& entry : map) {
            int num = entry.first;
            int freq = entry.second;
        
            for(int i = 0; i < freq; i++) {
                if(i >= res.size()) {
                    res.push_back(vector<int>());
                }
                res[i].push_back(num);
            }
        }
        return res;
        
    }
};
