class Solution {
public:

/*
    Problem:
        Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or
        equal to threshold
----------------------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach, where we will be looking at all k-lengthed subsets of
            arr
        2. For every k-lengthed subarray:
            - calculate the average of the current subarray
            - if the average is greater than or equal to the threshold, increment the result
        3. Result the subarray who's average is greater than or equal to the threshold
----------------------------------------------------------------------------------------------------------------
    Psuedocode:

        - declare variable to keep track of the sum of the current window, and variable to keep track of the
            count of subarrays
        
        - for the first k elements:
            - add them to the subarray
        //we not have our first k-lengthed subarray, and will be moving the window along the vector

        - for indexes k -> arr.size():

            - calculate the average of the subarray, and if it is bigger than threshold update the count

            - subtract the first index in the current window to the sum, and add the index one to the right 
                of the window to the sum
        
        - return the count
-----------------------------------------------------------------------------------------------------------------
*/
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        //intialize variables
        int sum = 0, subArrayCount = 0;

        //get first k-lengthed subarray
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        //check all other k-lengthed subarrays
        for(int i = k; i < arr.size(); i++) {

            //caculate average
            if(sum / k >= threshold){//do not have to cast to double, floor of the average will still lead to same result
                subArrayCount++;
            }

            //update our current window
            sum -= arr[i - k];
            sum += arr[i];
        }

        //missed last subarray in the for loop, check it
        if(sum / k >= threshold){
            subArrayCount++;
        }

        return subArrayCount;
    }
};
