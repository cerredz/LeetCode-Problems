class Solution {
public:
/*
  Problem:
    You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it satisfies these conditions: The value of the first element in arr must be 1.
      The absolute difference between any 2 adjacent elements must be less than or equal to 1. In other words, abs(arr[i] - arr[i - 1]) <= 1 for each i where 1 <= i < arr.length (0-indexed). 
      abs(x) is the absolute value of x. There are 2 types of operations that you can perform any number of times: Decrease the value of any element of arr to a smaller positive integer. 
      Rearrange the elements of arr to be in any order. Return the maximum possible value of an element in arr after performing the operations to satisfy the conditions.
  
*/
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // first sort to reduce absolute different of adjacent elements
        sort(arr.begin(), arr.end());
        int res = 0; // simulates starting the first element at 1
        int n = arr.size();

        // make sure that different of adjacent elements are less than or equal to 1
        for(int i = 0; i < n; i++ ) {
            if(arr[i] > res + 1) {
                res = res + 1; // simulates decreasing current index to res + 1
            } else if (arr[i] > res) {
                res = arr[i]; // res + 1
            }
        }
        return res;

    }
};
