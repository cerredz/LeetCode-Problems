class Solution {
public:
    /*
      Problem:
        Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
        Each number in candidates may only be used once in the combination.
        Note: The solution set must not contain duplicate combinations.

    */
    // backtracking recursive algorithm
    void getCombinations(vector<vector<int>>& res, vector<int>& candidates, vector<int>& curr, int index, int sum, int target) {

        // step 3: base cases: if sum == target add current subset to res, if index > size of candidates just return
        if (sum == target) {
            res.push_back(curr);
            return;
        }
        if (index >= candidates.size() || sum > target) {
            return;
        }

        // step 4: recrusively get all combinations that sum up to target
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                // skip duplicates
                continue;
            }

            curr.push_back(candidates[i]);
            getCombinations(res, candidates, curr, i + 1, sum + candidates[i], target);
            curr.pop_back(); // backtrack
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> curr;

        // step 1: sort candidates in order to avoid duplicate recursive calls
        sort(candidates.begin(), candidates.end());

        // step 2: implement a recursive backtracking algorithmn
        getCombinations(res, candidates, curr, 0, 0, target);
        return res;

    }
};
