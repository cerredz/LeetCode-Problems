class Solution {
public:
  /*
    Problems:
      You are given an array of integers nums of length n.
      The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
      You need to divide nums into 3 disjoint contiguous subarrays. Return the minimum possible sum of the cost of these subarrays.
  */
    int minimumCost(vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int curr = nums[0] + nums[j] + nums[k];
                    res = min(curr, res);
                }
            }
        }
        return res;


        
    }
};
