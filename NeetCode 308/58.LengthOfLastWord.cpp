class Solution {
public:
    int lengthOfLastWord(string s) {
        

        /*
        
            Problem: 
            
            Given a string s consisting of words and spaces, return the length of the last word in the string.
            A word is a maximal substring consisting of non-space characters only.
            
            Approach: 


            - declare a variable at the end of the string's length called index
            - decrement index until you reach a letter

            - while index is greater than 0
                -  if s[index] is not equal to a space
                    - increment result variable
                - otherwise, return result (this means that you have reached a space)

            - after while loop we have to return result, because if a string has no spaces then result will not 
            be returned yet
        
        */
        int lastWordEnd = s.length() - 1;
        int res = 0;

        while(lastWordEnd >= 0 && s[lastWordEnd] == ' ' ) {
            lastWordEnd--;
        }
        //after while loop we are currently at the last letter of the last word in the string
       

        while(lastWordEnd >= 0) {

            if(s[lastWordEnd] != ' ') {
                //if control reaches here this means that we have found a non-space, so we increment result
                res++;
            }else {
                //if control reaches here this means that we have found a space, so we return the result
                return res;
            }

            lastWordEnd--;
        }

        return res;
    }
};
