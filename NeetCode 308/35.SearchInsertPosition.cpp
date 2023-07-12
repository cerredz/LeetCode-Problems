class Solution {
public:

/*
    Problem: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were
    inserted in order. You must write an algorithm with O(log n) runtime complexity.


*/
    int searchInsert(vector<int>& nums, int target) {

        //delcare pointers
        int left = 0, right = nums.size() - 1;

        //perform a binary search
        while(left <= right) {
            int mid = (left + right) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right= mid - 1;
            }
        }

        //if target not found, left pointer will be in the position the target should be in
        return left;
    }
};
