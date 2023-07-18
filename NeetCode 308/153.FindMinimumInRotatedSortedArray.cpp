class Solution {
public:

/*
    Problem:
      Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
      [4,5,6,7,0,1,2] if it was rotated 4 times. [0,1,2,4,5,6,7] if it was rotated 7 times. Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the
      array [a[n-1], a[0], a[1], a[2], ..., a[n-2]]. Given the sorted rotated array nums of unique elements, return the minimum element of this array.
      You must write an algorithm that runs in O(log n) time.
        
    Approach:
        1. To achieve a runtime of O(log n), we will use the binary search algorithm.
        2. A key observation is that if the vector is rotated, the smallest elements will be located on the right  
            side. Hence, we need to find a way to search for the leftmost element among the sorted numbers on the
            right side of the rotated numbers.
        3. During the binary search, we can compare the number we land on to the first index of the vector. If the 
            number is greater than the first element, it means we haven't reached the smaller numbers on the right
            side yet. In this case, we can eliminate the left side of the numbers in the vector. However, if thenumber
            is smaller than the first element, it means we are at the beginning of the originally sorted array.
            Therefore, we eliminate the numbers to the right of our current index in order to find the smallest element

        4. Additionally, we will maintain a variable called "min" to keep track of the minimum value seen during the 
            binary search. This way, we can continuously update the minimum as we traverse the vector.


*/
    int findMin(vector<int>& nums) {
        

        //declare pointers
        int left = 0, right = nums.size() - 1;
        long long min = 9223372036854775807;
        


        if(nums[0] < nums[nums.size() - 1]) {
            //nums is correctly sorted, just return the first element
            return nums[0];
        }

        //perform the binary search
        while(left <= right) {

            int mid = (left + right) / 2;

            //compare nums[mid] to the first element
            if(nums[mid] >= nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

            //keep track of minimum value seen
            if(nums[mid] < min) {
                min = nums[mid];
            }
        }

        //return lowest value found
        return min;


    }
};
