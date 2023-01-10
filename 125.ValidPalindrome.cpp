class Solution {
public:
    bool isPalindrome(string s) {
        

        /*
            Approach / Psuedocode

            - we will be taking a two pointer approach, and continue to check if the left pointer is equal to the right pointer at every character
            - if they are an alphabetical character and not equal then we will return false

            - initialize a left pointer = 0
            - initialize a right pointer = s.length() - 1

            - while the left pointer is less than the right pointer
                - while the left pointer is not an alphabetical character
                    - increment the left pointer
                - while the right pointer is not an alphabetical character
                    - increment the right pointer

                - if the lowercase version of the characters are not equal to each other
                    - return false

                increment left and right pointer

            if we reach outside of the while loop then we can return true, the string is a valid palindrone
            
        */
        
        int leftChar = 0, rightChar = s.length() - 1;

        while(leftChar < rightChar){


            while( leftChar < rightChar && !isalnum(s.at(leftChar)) ) {
                leftChar++;
            }

            while(leftChar < rightChar && !isalnum(s.at(rightChar))){
                rightChar--;
            }

            if(tolower(s.at(leftChar)) != tolower(s.at(rightChar))){
                return false;
            }
            leftChar++;
            rightChar--;
        }

        return true;
    }
};
