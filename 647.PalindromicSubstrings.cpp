class Solution {
public:
    int countSubstrings(string s) {

        /*
            Approach / Psuedocode:
            --------------------------------------------------------------------
            - we will inplement a expanding sliding window approach at every index, if the window satsifies the
                requirements of a palindrome then we will increment out total number of palindromes
            --------------------------------------------------------------------

            - initialize our total palindomes counter, a left pointer, and a right pointer
            - for every letter in string s
                // we must handle an odd and even length palindrome

                //odd case
                - set both pointers to i
                - if left and right are the same letter
                    - increment left, right, and total Palindromes

                //even case
                - set left to i, and right to i + 1
                    - if left and right are the same letter
                        - increment, left, right, and total palindromes
            
            return our totalPalindromes counter
        */
        int totalPalindromes = 0; // counter

        int left = 0, right = 0; // pointers

        for(int i  = 0; i < s.length(); i++){

            //first lets handle the odd lengthed palindrome case
            left = i;
            right = i;

            while(left >= 0 && right < s.length() && s.at(left) == s.at(right)){
                //if we reach here then the window left->right is a palindrome
                left--;
                right++;//increment pointers
                totalPalindromes++; //increment counter
            }

            //now we must handle the even lengthed palindrome case
            left = i;
            right = i + 1;

            //now its just the same process as the odd lengthed case
            while(left >= 0 && right < s.length() && s.at(left) == s.at(right)){
                left--;
                right++;
                totalPalindromes++;
            }


        }

        return totalPalindromes;


    }
};
