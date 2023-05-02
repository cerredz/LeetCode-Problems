class Solution {
public:
/*

    Problem:
      You are given a 0-indexed array nums of distinct integers. You want to rearrange the elements in the array such that every element in the 
      rearranged array is not equal to the average of its neighbors. More formally, the rearranged array should have the property such that for
      every i in the range 1 <= i < nums.length - 1, (nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].
      Return any rearrangement of nums that meets the requirements.
---------------------------------------------------------------------------------------------------------
    Approach:
        1. For this problem there is a trick that we can use that involved sorting the vector
        2. After we sort the vector, we can swap elements in a way that for every index, 
           ( nums[i - 1] + nums[i + 1] ) / 2 will never equal nums[i]
        3. At every iteration, starting at index 1, we will swap the index at i with the index at 
            i - 1. We are swapping instead of creating a whole other vector in order to save time 
            complexity
        4. What this does is it creates either a very small or a very big gap between a number and its
            neighbors
            EX: 
                - consider the sorted array 1,2,3,4,5
                - if we implement our algorithm described above, we will get the vector: 2,1,4,3,5
                - notice that there is a very big gap between index 1 and its neighbors, a very small gap
                    between index 2 and its neighbors, and so on
                - in other words, at evey index it is either the smallest or biggest out of its neighbors
                    and for that reason that algorithm will work
---------------------------------------------------------------------------------------------------------
    Psuedocode:

        - declare a temp variable

        - sort the vector:

            - for every other number in nums starting at index 1:
                - swap nums[i] and nums[i - 1]
                
        - return nums
---------------------------------------------------------------------------------------------------------
*/
    vector<int> rearrangeArray(vector<int>& nums) {
        
        //declare temp variable
        int temp = 0;

        //sort vector
        sort(nums.begin(), nums.end());

        //swap every other numbers
        for(int i = 1; i < nums.size(); i+= 2) {
            temp = nums[i];
            nums[i] = nums[i - 1];
            nums[i - 1] = temp;
        }

        return nums;

       
        
    }
};
