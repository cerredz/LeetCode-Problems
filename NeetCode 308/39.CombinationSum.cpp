class Solution {
public:
    /*
        Problem:
          Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
          You may return the combinations in any order. The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
          frequency of at least one of the chosen numbers is different.
          The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

        Approach:
            1. we have to form all possible subsets of the numbers in candidates
                and check if the numbers in a given subset sum up to target
            2. We can also combine this with backtracking, if the sum of a given
                subset is > target we can pop from the back of the subset and 
                look at the next number in candidates
            3. In example 1, our subsets would go in this order: 2 -> 2,2 -> 2,2,2 ->
                2,2,2,2. Since our sum is now greater than 7, we pop from the back, 
                increment our index, and now get 2,2,2,3, etc
    */

    void combinations(vector<int> candidates, vector<vector<int>>& res, vector<int>& subset, int index, int sum, int target ) {

        // base cases
        if(index >= candidates.size() || sum > target){
            return;
        }

        if(sum == target) {
            res.push_back(subset);
            return; // avoid duplicate subsets
        }

        // add element at index to the subset and sum
        subset.push_back(candidates[index]);
        combinations(candidates, res, subset, index, sum + candidates[index], target);
        
        // backtrack
        subset.pop_back();
        combinations(candidates, res, subset, index + 1, sum, target);

    
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> subsets;

        combinations(candidates, res, subsets, 0, 0, target);
        return res;
    }
};
