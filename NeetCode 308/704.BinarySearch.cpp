class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //declare  our variables / pointers
        int left = 0, right = nums.size() - 1;


        //check mid point until pointers cross
        while(left < right) {
            int mid = (left + right) / 2;

            //case 1: number found
            if(nums[mid] == target) {
                return mid;

            //case 2: number too small, increment left pointer
            } else if (nums[mid] < target) {
                left = mid + 1;

            ///case 3: number too big, decrement right pointer
            } else {
                right = mid - 1;
            }
        }

        //number not found, return -1
        return -1;
    }
};
