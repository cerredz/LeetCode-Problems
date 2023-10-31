class Solution {
public:

    /*
      Problem:
          Given an integer array nums of unique elements, return all possible 
          subsets (the power set).
          The solution set must not contain duplicate subsets. Return the solution in any order.
    */
    void createSubsets(vector<int> nums, vector<vector<int>>& res, vector<int>& currSubset, int index) {

        if( index >= nums.size()) {
            res.push_back(currSubset);
            return;
        }

        // add next element
        currSubset.push_back(nums[index]);
        createSubsets(nums, res, currSubset, index + 1);

        // backtrack
        currSubset.pop_back();
        createSubsets(nums, res, currSubset, index + 1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> subset;
        createSubsets(nums, res, subset, 0);
        return res;

    }
};
