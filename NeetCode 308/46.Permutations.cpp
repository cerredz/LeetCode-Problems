class Solution {
public:

    /*
        Problem:
            Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
            
        Approach:
            1. We can use a backtracking apporach for this problem that uses recursion.
            2. Notice how there is no specified order we have to follow when adding numbers in a 
                permutation. For example, for the list [5,1,6,8,2,4], one of our permutations
                will start with [5,2,...]. In other words, we are going to have to jump 
                around indexes greater than 1
            3. Since there isnt an exact index to jump to in a future iteration, we can use a list
                of bool values to denote whether or not we includes a number in a permutation.
                Also, for every iteration we are going to have to iterate through nums because,
                like i said before, we dont know what indexes have not been added to the current
                permutation
            4. When iterating through nums, if the current number has not been added to the
                permutation, (use bool list to determine this), then add it to the permutation
                and marked that we seen it in the bool list. Then, call our function again
                via recursion. Notice that in this next call the next number will be added to 
                the permutation. 
            5. Now we have to backtrack, after calling the recursive function we want to unmark
                the current number in the list of bools and remove it from our current permutation
            6. We know we have a complete permutation when the size of our current permutation
                is the same size as nums, so when this happens add the current permutation to our result

    */
    void permutations(vector<vector<int>>& res, vector<int> nums, vector<int>& curr_perm, vector<bool>& used) {

        // base case, permutation of nums found
        if(nums.size() == curr_perm.size()) {
            res.push_back(curr_perm);
            return;
        }

        // find the next number that is not in our current permutation
        for(int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                used[i] = true;
                curr_perm.push_back(nums[i]);
                permutations(res, nums, curr_perm, used);

                // backtrack
                used[i] = false;
                curr_perm.pop_back();
            }
        }
    }



    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> curr_perm;
        vector<bool> used(nums.size(), false);
        permutations(res, nums, curr_perm, used);
        return res;


    }
};
