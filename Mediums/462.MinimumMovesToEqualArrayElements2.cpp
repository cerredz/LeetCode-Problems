class Solution {
public:
/*
Problem:
    Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.In one move, you can increment or decrement an element of the array by 1.
    Test cases are designed so that the answer will fit in a 32-bit integer.

*/
    int minMoves2(vector<int>& nums) {
        
        long long res = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            long long moves = 0;
            for(int j = 0; j < n; j++) {
                moves += abs(nums[i] - nums[j]);
            }
            res = min(res, moves);
        }
        return res;
    }
};
