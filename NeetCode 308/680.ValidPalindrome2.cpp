class Solution {
public:

/*

    Problem:
    - Given a string s, return true if the s can be palindrome after deleting at most one character from it.
---------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer recursive approach, with a left and right pointer
        2. We will have a separate method with three parameters, a string and two pointers, to
            check whether a string, between the two given pointers, is a valid palindrome
        3. In out main method while the left pointer is less than the right pointer we 
            will check is s[left] = s[right], if it is we increment left and decrement right
        4. If is is not we will do the following: Notice how you can only delete one character,
            this means that when s[left] != s[right] you can either delete the left or right
            character. We will use out helper method to simulate deleting the left and 
            right character, and since we can only delete one character we can return 
            what the helper method returns
        5. If you make it past the while loop return true
-----------------------------------------------------------------------------------------------
*/

//helper method, checks whether a string is a palindrome between left -> right
    bool isPalindrome(string str, int left, int right) {

        while(left < right) {
            //returns false if string is not a palindrome
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }

        //returns true if string is a palindrome
        return true;
    }

    bool validPalindrome(string s) {
        
        //initialize pointers
        int left = 0, right = s.length() - 1;

        //while left pointer is less than right pointer
        while(left < right) {
            
            //if pointers are not the same character, simulate a left AND right deletion
            if(s[left] != s[right]) {
                //can return here beacause we can only delete at most one character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }else {
                left++;
                right--;
            }
            
        }

        return true;
        
        

    }

    
};
