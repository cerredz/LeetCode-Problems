class Solution {
public:

/*

    Problem:
      Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
---------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach
        2. At each iteration, look at a substring of the haystack equal to the length of
            the needle
        3. Keep shifting the window one index to the right, and if the substring if
            equal to needle then return the index of the left pointer
        4. If no such substring is found, return -1
---------------------------------------------------------------------------------------------
    Pseudocode:
        - have a string variable for the curent window
        - for every letter in haystack - needle.length:
            - get the current substring
            - if the current substring = needle
                - return the current index
        
        - return -1
--------------------------------------------------------------------------------------------
*/
    int strStr(string haystack, string needle) {
        
        //edge case
        if(needle.length() > haystack.length()) {
            return -1;
        }
        
        //used for storing substrings
        string currentString = "";
        int N = needle.length();

        //implement sliding window approach
        for(int i = 0; i <= haystack.length() - needle.length(); i++ ) {
            currentString = haystack.substr(i, N);
            //if current window = needle
            if(currentString == needle) {
                return i;
            }
        }

        return -1;
    }
};
