class Solution {
public:
/*
    Problem:
     Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
-----------------------------------------------------------------------------------------------
    Approach:
        1. Store the frequenies of each number in nums into a map
        2. Convert the map to a vector so we can sort the frequencies
        3. Once the vector is sorted, loop until k and add the numbers with the highest 
            frequency
------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare a map to store frequencies(map), and a result vector(res)
        - for each number in nums:
            - increment map[number]
        
        - declare another vector that stores pairs of integers, and fill it with the values 
            in the map(vec)

        - sort the vector by descending values (not keys)

        - for every index up until k:
            - add the second value of vec to res

        return res
*/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        vector<int>res;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        vector<pair<int,int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        for(int i = 0; i < k; i++) {
            res.emplace_back(vec[i].first);
        }

        return res;


    }
};
