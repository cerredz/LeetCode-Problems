class Solution {
public:
/* 
    Problem:
      There is an integer array nums sorted in ascending order (with distinct values).
      Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
      nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
      Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
      You must write an algorithm with O(log n) runtime complexity.
      
    Approach: 
        1. Since we have to write an algorithmn that runs in 0(log n ) time complexity, we must implement an algorithm that uses binary search 
        2. Notice that unless the array is sorted, there is almost in a way 2 arrays in the singular array. For example in the array: 4,5,6,7,0,1,2, the "two arrays" would be 4,5,6,7 and 0,1,2. Notice that all of the numbers in the first array are larger than all the numbers in the second array, and vise versa. We will using this information in our binary search algorithmn. 
        3. There will be two cases for our modified binary search, and that is what array it is in, denoted as bigger numbers or smaller numbers, we can find this out by comparing the nums[mid] to the the first and last element of the array
        4. If nums[mid] is within the bigger numbers side of the array, then we only want to move it right if the target is less than the last element in the array or greater than nums[mid], otherwise we move our binary search to the right.
        5. If nums[mid] is within the smaller numbers side of the array, then we only want to move it right if the target is greater than nums[mid] and smaller than the last element in the array
        6. Of course, we always want to check if nums[mid] == target in the beginning of the array, and continue
steps 3-6 until the left and right pointers cross

*/
    int search(vector<int>& nums, int target) {
        
        //declare pointers
        int left = 0, right = nums.size() - 1;

        //perform modified binary search
        while(left <= right) {

            //obtain middle element
            int mid = (left + right) / 2;

            //return index if middle element matches target
            if(nums[mid] == target) {
                 return mid;
            }

            //case 1: if nums[mid] > first element then we are in the biggest numbers side of the array
            if(nums[mid] >= nums[0]) {

                //only search to the right if target is greater than nums[mid] or if it is less than the first element
                if(target > nums[mid] || target < nums[0]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            //case 2: nums[mid] < first element so that means we are in the smaller numbers side of the array
            } else {

                //only search to the right if target > nums[mid] and less than or equal to the last element
                if(target > nums[mid] && target <= nums[nums.size() - 1]){
                        left = mid + 1;
                } else {
                        right = mid - 1;
                }
            }      
        }

        //target not found in the array, return -1
        return -1;
        

        


    }
};
