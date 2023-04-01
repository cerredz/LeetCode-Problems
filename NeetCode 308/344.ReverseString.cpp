class Solution {
public:
/*
    Problem:
      Write a function that reverses a string. The input string is given as an array of characters s.
      You must do this by modifying the input array in-place with O(1) extra memory.
------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer approach 
        2. Initialize the left pointer = 0, and right pointer = last index of s
        3. While the left is less than the right pointer, swap the two characters at each 
            pointer with one another
        4. Increment the left pointer and decrement the right pointer after every iteration
------------------------------------------------------------------------------------------------

*/
    void reverseString(vector<char>& s) {
        
        //initalize pointers
        int left= 0, right = s.size() - 1;
        char temp = '\0';//used for swapping

        
        while(left < right) {
            //swap s[left] and s[right]
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            //update pointers
            left++;
            right--;
        }


    }
};
