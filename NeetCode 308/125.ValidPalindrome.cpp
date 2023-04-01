class Solution {
public:

/*

    Problem:
      A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
      it reads the same forward and backward. Alphanumeric characters include letters and numbers.
      Given a string s, return true if it is a palindrome, or false otherwise.
---------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer approach, left and right pointer
        2. While our left pointer is less than our right pointer we will check the character
            at both the left and right pointer
        3. While either of the characters are not an alphabetic character or number, then
            increment / decrement the correct pointer
        4. Otherwise, check the two characters, if the two characters are not the same then
            return false. If they are the same continue with the while loop with
            incrementing the left pointer and decrementing the right pointer
        5. Return true is control makes it past the while loop
----------------------------------------------------------------------------------------------
    Psuedocode:
    
        - initialize a left pointer = 0,  and a right pointer = s.length - 1

        - while left pointer <= right pointer

            - while s[left pointer] is not a letter or number
                - increment the left pointer

            - while s[right pointer] is not a letter or number
                - increment the right pointer
            
            - if s[left pointer] is not the same as s[right pointer]
                - return false
            
            - else continue with the while loop by incrementing the left pointer and 
                decrementing the right pointer
        
        - return true
----------------------------------------------------------------------------------------------
*/
    bool isPalindrome(string s) {
        
        //initialize pointers
        int left = 0, right = s.length() - 1;

        while(left <= right) {

            //check if left pointer is letter or number (while not going out of bounds)
            while(left < s.length() && !isalnum(s[left])) {
                left++;
            }

            //check if right pointer is letter or number (while not going out of bounds)
            while(right > 0 && !isalnum(s[right])) {
                right--;
            }

            //check if characters are the same
            if(left <= right && tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
      
    }
};
