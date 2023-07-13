class Solution {
public:

/*
    Problem:
        Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
*/
    vector<int> sortedSquares(vector<int>& nums) {
        
        //we will be using two pointers to build the result vector from largest to smallest, and then reverse the reversal of this vector

        //declare vector and pointers
        vector<int> res;
        int left = 0, right = nums.size() - 1;

        //while pointers do not cross
        while(left <= right) {

            //add the larger number to the back of the vector
            if(abs(nums[left]) <= abs(nums[right])) {
                res.push_back(nums[right] * nums[right]);
                right--;
            } else {
                res.push_back(nums[left] * nums[left]);
                left++;
            }
        }

        //vector = largest -> smallest, we want smallest -> largest so reverse it
        reverse(res.begin(), res.end());
        return res;
        
    }
};
