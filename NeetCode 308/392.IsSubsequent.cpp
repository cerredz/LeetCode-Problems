class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        /*
        
            Problem: Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
            A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
            without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

            Approach: 
            - declare an index variable
            - declare an lettersFound variable

            - while the index is in range of t's length
                - if s[lettersFound] == t[index]
                    - increment lettersFound
                    - increment index
                - else 
                    - only increment index

            //this way we are looking for the letters in S in the correct order

            - if the lettersFound != the length of S
                - this means that either the letters are out of order
                - or that t does not contain all the letter in t
                - we can return false
                
            - otherwise, return true

        */
        int index = 0;
        int lettersFound = 0;

        while(index < t.length()){

            if(s[lettersFound] == t[index]){
                lettersFound++;
                index++;
            }else {
                index++;
            }
        }

        return lettersFound == s.length();

        


    }
};
