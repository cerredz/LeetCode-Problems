class Solution {
public:

    /*
        Approach:
            1. we have to implement a solution that is a modification to the algorithmn that 
                generates all the possible combinations to an array
            2. We have to think of the numbers 1->n as an array (if n is 4, think of our array as
            [1,2,3,4]). Knowing this we will implement an algorithm to generate all unique combinations
            3. HOWEVER, the one change we will have is that when our current combination's size 
            is greater than k, we can stop the recursive calls here and return
                 
    */
    void createCombinations(vector<vector<int>>& res, vector<int>& curr_subset, int curr_number, int n, int k) {

        // base cases: size of current subset = n OR current number == n
        if(curr_subset.size() == k) {
            res.push_back(curr_subset);
            return;
        }

        if(curr_number > n) {
            return;
        }
        
        // add current number to current subset
        curr_subset.push_back(curr_number);
        createCombinations(res, curr_subset, curr_number + 1, n, k);

        // backtrack and add next number: (ex: [1,2] -> pop -> [1] -> next iteration will be [1,3])
        curr_subset.pop_back();
        createCombinations(res, curr_subset, curr_number + 1, n, k);
        
    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> curr_subset;
        createCombinations(res, curr_subset, 1, n, k);
        return res;

    }
};
