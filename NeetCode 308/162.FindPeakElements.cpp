class Solution {
public:

/*
    Problem:
      A peak element is an element that is strictly greater than its neighbors.
      Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
      You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
      You must write an algorithm that runs in O(log n) time.
    
    Approach:
        1. In order for our solution to run in 0(log n ) we must implement a solution using binary search. Our lower
            and upper bounds are going to be the same as always (0, and 1 less than the size of the vector)
        2. We must find a way to eliminate half of the array in every iteration since we are utilizing binary search,
            one way to do this is to check if the mid element is less than the element to the right of it. By doing 
            this we find out two things:
                - if nums[mid] < nums[mid + 1], we know that there greater number on the right side of our mid value,
                    and if not we know that there is a greater number on the left side of our mid value

                - in more simpler terms, the solution is either on the left side of mid or the right side of mid
        3. If we continue to check this case every iteration then we will cut the number of options in half after every
            iteration. We want to STOP the iteration when left == right, when the while loop end both left and right
            wil be at the position of a peak element, so return either one
*/  
    int findPeakElement(vector<int>& nums) {

        //declare bounds for binary search
        int left = 0, right = nums.size() - 1;

        //perform a modified binary search
        while (left < right) {

            int mid = (left + right) / 2;

            //determine wether peak is on left or right side of vector
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
