class Solution {
public:
    /*
        Problem:
          You are given two 2D integer arrays nums1 and nums2.
          nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali
          nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
          Each array contains unique ids and is sorted in ascending order by id.
          Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:
          Only ids that appear in at least one of the two arrays should be included in the resulting array.
          Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays then its value in that array is considered to be 0.
          Return the resulting array. The returned array must be sorted in ascending order by id.


    ----------------------------------------------------------------------------------------------------------------------------------------------------------------
        Approach:
            1. We will loop through all pairs of both vector
            2. At the current pairs, if the first numbers are equal them we will add a vector of the first number, and the second number in
                nums1 + nums2 to a res vector
            3. If the first numbers are not equal then we will push them into the res vector in ascending order
    ------------------------------------------------------------------------------------------------------------------------------------------------------------------
    */
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        
        vector<vector<int>> res;
        int num1 = 0, num2 = 0;
        
        while(num1 < nums1.size() || num2 < nums2.size()) { // must account for different lengthed vectors
            
            int id1 = num1 < nums1.size() ? nums1[num1][0] : INT_MAX;//if out of range of nums1, then id1 will always be bigger than id2
            int id2 = num2 < nums2.size() ? nums2[num2][0] : INT_MAX;//if out of range of num2, then id2 will always be bigger than id1
            
            //check if first numbers are equal to each other
            if (id1 == id2) {
                res.push_back({id1, nums1[num1++][1] + nums2[num2++][1]});
                
            } 
            //now must place them into res in ascending order
            else if (id1 < id2) {
                res.push_back(nums1[num1++]);
            } else {
                res.push_back(nums2[num2++]);
            }

        }
        
        return res;
    }
};
