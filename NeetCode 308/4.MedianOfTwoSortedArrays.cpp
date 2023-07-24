class Solution {
public:

/*
    Problem:

      Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
      The overall run time complexity should be O(log (m+n)).

    Approach:
        1. In ordere to achieve a O(log (m+n)) running time, we have to incorperate binary search into our 
            algorithmn.
        2. Notice how the median is the center of something with a size, this tells us that we are going to have 
            to use the size of both vectors combined in our answer
        3. We will run binary search on one vector, and use the size of both vectors to perform a binary search
            on the second vector. We are not actually running binary search on the second vector though. You see,
            we will compute the mid value in the binary search on the first vector, then we will subtract that mid
            value from half of the total size and use this as the index for the second vector
        4. We will compare the both mid values of each vector to the opposite vector's index to the right, and if
            both mid values are less than the indexes to the right, then this means that we have found our
            median. If the total size is odd, then our median is just the lower of the two mid values, and 
            if it is even then we have to take the average of the greater mid value and the lower mid + 1 value
        5. If the mid value of the first vector is less than the mid + 1 value of the second vector, this means
            that we need a greater mid value for the first vector, so we will set our left to mid + 1
        6. If neither steps 4 or 5 are true, this means that we need a smaller mid value for the first vector
            so set the right value to mid - 1
*/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int m = nums1.size();
        int n = nums2.size();
        
        if (m > n) {
            //need to run the binary search on the bigger vector
            return findMedianSortedArrays(nums2, nums1);
        }

        //declare variables 
        int totalSize = nums1.size() + nums2.size();
        int left = 0, right = nums1.size();

        //perform binary search on nums1
        while (left <= right) {

            //compute both mid values
            int mid = (left + right) / 2;
            int nums2_index = totalSize / 2 - mid;

            //make sure mid and mid+1 are both in bounds
            int nums1_left = (mid > 0) ? nums1[mid - 1] : INT_MIN;
            int nums1_right = (mid < nums1.size()) ? nums1[mid] : INT_MAX;

            int nums2_left = (nums2_index > 0) ? nums2[nums2_index - 1] : INT_MIN;
            int nums2_right = (nums2_index < nums2.size()) ? nums2[nums2_index] : INT_MAX;

            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                //correct mid values, now find the median
                if (totalSize % 2 == 0) {
                    double leftMax = max(nums1_left, nums2_left);
                    double rightMin = min(nums1_right, nums2_right);
                    return (leftMax + rightMin) / 2.0;
                } else {
                    return min(nums1_right, nums2_right);
                }
            } else if (nums1_left > nums2_right) {
                //mid value too big, move left
                right = mid - 1;
            } else {
                //mid value too small, move right
                left = mid + 1;
            }
        }

        return 0.0; // In case of empty input arrays
    }
};
