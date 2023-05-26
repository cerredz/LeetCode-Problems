class Solution {
public:


/*

    Problem:
      Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
      The result should also be sorted in ascending order. An integer a is closer to x than an integer b if:
      |a - x| < |b - x|, or |a - x| == |b - x| and a < b.
-----------------------------------------------------------------------------------------------------------------
    Approach: 
        1. Since the vector is in sorted order, we can combine our sliding window approach with binary search
        2. Have two pointers, starting the left pointer at 0, and the right pointer at the index of the last
            element
        3. find the middle index of the two pointers. if arr[mid] is not closer to x than arr[mid + k]
            this means that that the element at the last index of our k-element window is closer to x than the 
            first element, so we must increment our left pointer to mid + 1 (same as in binary search). 
            if arr[mid] is closer (or equal to ) x than arr[mid + k] this means that the first element in our 
            k-lengthed window is closer to x than the last element, so we will try to find an even lower element
            by setting our right pointer = mid (same as binary search)
        4. continue step 3 until the left pointer is greater than the right pointer
        5. The intuition is tricky to fully understand, but think of it as finding the lowest possible starting
            element to a k-lengthed window that we can return so that the k-closest elements are returned
        6. After completing step 4, return a vector that is k-elements long that starts at the left pointer
-----------------------------------------------------------------------------------------------------------------
*/
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        //declare pointers
        int left = 0, right = arr.size() - k;

        //implement sliding window approach that utilizes a binary search
        while(left < right) {
            //find middle index
            int mid = (left + right) / 2;

            //case 1: last element in window is closer to x than first element
            if(x - arr[mid] > arr[mid + k] - x){
                left = mid + 1;
            //case 2: first element in window is closer to x than last element
            } else {
                right = mid;
            }
        }


        //start at the left pointer and return the next k-elements
        vector<int> res (arr.begin() + left, arr.begin() + left + k);
        return res;
    }
};
