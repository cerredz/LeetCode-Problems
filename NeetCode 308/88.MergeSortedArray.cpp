class Solution {
public:

/*
    Problem:
      You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing
      the number of elements in nums1 and nums2 respectively.Merge nums1 and nums2 into a single array sorted in non-decreasing order.
      The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
      To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
      and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
-----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer aproach
        2. Initilize both the left and right pointer = 0
        3. While the left pointer is less than m and the right pointer is less than n, we will
            compare nums1[left] and nums2[right]. Whichever one is less then the other we will
            add it to our res vector and increment the appropriate pointer
        4. At this point we could have some numbers left over, these left over number are 
            automatically greater than the number we have already inputted
        5. While left < m, add nums1[i] to res vector, and while right < n, add nums2[right]
            to the res vector
---------------------------------------------------------------------------------------------
*/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //initialize variables and pointers
        vector<int> res;
        int left = 0, right = 0;

        //while there are less than m and n elements in the res vector
        while(left < m && right < n) {
            
            //if current nums1 element is less than current nums2 element
            if(nums1[left] < nums2[right]) {
                res.emplace_back(nums1[left]);
                left++;
            //if current nums2 element is less than current nums1 element
            }else{
                res.emplace_back(nums2[right]);
                right++;
            }
        }

        //handle left over numbers in nums1
        while(left < m) {
            res.emplace_back(nums1[left]);
            left++;
        }

        //handle left over numbers in nums2
        while(right < n) {
            res.emplace_back(nums2[right]);
            right++;
        }

        nums1 = res;
    }
};
