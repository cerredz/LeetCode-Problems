class Solution {
public:

/*

    Problem:
    
      You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
      Find two lines that together with the x-axis form a container, such that the container contains the most water.
      Return the maximum amount of water a container can store.Notice that you may not slant the container.
------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer approach starting at the first and last index
        2. Find the current lower height between height[left pointer] and height[right pointer]
        3. The current height * (right - left) is the amount of water in the container from 
            left -> right
        4. Make sure to keep track of the greatest amount of water seen so far, and
            update accordingly
        5. Whichever index at each pointer is lower than the other, then move that pointer
            inwards until the pointers cross each other
-----------------------------------------------------------------------------------------------
    Psuedocode:
        - declare variables

        - while left pointer <= right pointer:
            - find the minimum height between the two pointers

            - if the min height * (right - left) > current greatest max area
                - up current greatest max area
            
            - if height[left pointer] < height[right pointer]
                - increment left pointer
            - else
                - decrement the right pointer
        
        - return the greatest amount of water found at any given index
----------------------------------------------------------------------------------------------
*/
    int maxArea(vector<int>& height) {
        
        //declare pointers, max water variable, and min height variable
        int left = 0, right = height.size()-1, maxArea = 0, minHeight = 10000000;

        //while pointers do not cross
        while(left <= right) {
            
            //find lower height between two pointers
            minHeight = min(height[left], height[right]);

            //if more water then previous max, update current max
            maxArea = max(maxArea, minHeight * (right - left));

            //move the smaller pointer inwards
            if(height[left] < height[right]){
                left++;
            }else {
                right--;
            }
            
        }

        //return most water found 
        return maxArea;
    }
};
