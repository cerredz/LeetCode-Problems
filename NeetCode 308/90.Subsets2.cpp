class Solution {
public:

    /*

        Problem:
            Given an integer array nums that may contain duplicates, return all possible 
            subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
        Approach:
            1. we need to implement an algorithmn that generates all subsets on a list, but in the
                case of having duplicate numbers we only want to generate all subsets as if there 
                was 1 of this number
            2. For example, if we have the list 1,4,5,6,6, we want to generate all subsets of 1,4,5,6
            3. In order to achieve this, we can set all duplicate numbers next to each other 
                by sorting nums, and then when we increment our index make sure that we 
                increment it until we reach a different number
    */
    void createSubsets(vector<vector<int>>& res, vector<int> nums, vector<int>& subset, int index ) {

        // base case: add current subset to list of subsets
        if(index == nums.size()) {
            res.push_back(subset);
            return;
        }
        
        // add current number to subset
        subset.push_back(nums[index]);
        createSubsets(res, nums, subset, index + 1);


        // backtrack
        subset.pop_back();

        // skip all duplicate numbers
        while(index + 1< nums.size() && nums[index] == nums[index + 1]){
            index++;
        }
        createSubsets(res, nums, subset, index + 1);
        
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> subset;
        
        // sort nums to get duplicate numbers next to each other
        sort(nums.begin(), nums.end());

        // generate subsets
        createSubsets(res, nums, subset, 0);
        return res;
    }
};
