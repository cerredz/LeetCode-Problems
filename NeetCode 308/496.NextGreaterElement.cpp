class Solution {
public:

/*
    Problem:
    The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
    You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
    For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
    If there is no next greater element, then the answer for this query is -1.
    Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
    -------------------------------------------------------------------------------------------
    Approach: 
        - for every number in nums1 we will be doing the following:
            - find where the number in nums2 is equal to nums1[i]
            - if that number has a greater number to the right of it:
                - push that number into the result vector
            - else
                - push -1 onto the result vector

        - return res
    --------------------------------------------------------------------------------------------
*/

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int index = 0;

        while(index < nums1.size()){
            int currElementIndex = 0;//keeps index of where nums1[i] = nums2[j]
            for(int i = 0; i < nums2.size(); i++) {
                if(nums2[i] == nums1[index]) {
                    currElementIndex = i;
                    break;//we have found where the number in nums2 is, no need to keep iterating
                }
            }

            bool greatestNum = false;
            for(int i = currElementIndex + 1; i < nums2.size(); i++) {
                if(nums2[i] > nums2[currElementIndex]) {
                    res.emplace_back(nums2[i]);
                    greatestNum = true;
                    break;
                }
            }

            if(!greatestNum) {
                //control reaches here is there is no number to the right that is greater than 
                    //the number that we are currently looking at
                res.emplace_back(-1);
            }

            index++;
        }

        return res;
    }
};
