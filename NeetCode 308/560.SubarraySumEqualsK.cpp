class Solution {
public:

/*
    Problem: 
     Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
     A subarray is a contiguous non-empty sequence of elements within an array.
-------------------------------------------------------------------------------------------------------------------
    Approach: 
        1. Compute the prefix sum of each element, and have a map to store these prefix sums
        2. In the map, if the prefix sum - k exists in the map(adding / subtracting the two prefix sums will
            produce k), then add the value of sum - k in the map to you result
        3. increment the current prefix sum in the map
--------------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare prefixSum map, prefixSum variable(sum), and a result varible
        
        - for each number in nums:
            - add the current number to our sum variable
            - In our map, add the current sum - k to our result varible
            - increment our current sum in the map by 1

        - return result varibale
--------------------------------------------------------------------------------------------------------------------
*/  
    int subarraySum(vector<int>& nums, int k) {
        
        //map to store prefixSums
        unordered_map<int,int> prefixSum;

        int sum = 0, res = 0;

        // prefix sum of first element is 0, so we increment the number of 0's we have in our prefix sum map
        prefixSum[0] = 1;

        for(int i = 0; i < nums.size(); i++ ) {
           //increment prefixSum
           sum += nums[i];
           //ex: if sum - k in the map is 2: this means that we have 2 subarrays, that if added or subtract from
                //the current prefix sum, will equal k, so we can add 2 to the result variable
           res += prefixSum[sum - k];
           //we have a subarray that equals sum, so increment the map[sum] 
           prefixSum[sum]++;
        }
        return res;
    }
};
