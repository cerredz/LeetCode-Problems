class Solution {
public:

/*
    Problem: 
      You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.
      A string is called balanced if and only if:It is the empty string, or It can be written as AB, where both A and B are balanced strings, or
      It can be written as [C], where C is a balanced string. You may swap the brackets at any two indices any number of times.
      Return the minimum number of swaps to make s balanced.
--------------------------------------------------------------------------------------------------------------------
    Approach:
        1. Loop through the characters of the string, and keep track of the order of the open and closed brackets
        2. If we encounter a closed bracket before an open bracket (when it is not supposed to be before it), 
            then we can increment the amount of swaps we need
--------------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare two variables: 
            - 1 to keep track of the number of swaps (swaps)
            - 1 to keep track of the number of open and closed brackets (numOpen)
        - for every character in s:

            - if we encounter a closed bracket:
                - if numOpens is greater than 0 (this means that we encountered a closed bracket but the closed
                                                bracket belongs there since there is more open brackets)
                    - decrement numOpens to account for the closed bracket

                - else if numsOpen is less than 0 (this means that we can encountered a closed bracket in the wrong
                                                    position, before an open bracket)
                    - increment swaps
                    - increment numsOpen (simulating a swap)

            - else if we encounter a open bracket: 
                - increment numOpen to account for an open bracket
        
        - return swaps
--------------------------------------------------------------------------------------------------------------------
        
*/
    int minSwaps(string s) {
        
        
        
        int swaps = 0, numOpen = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == ']') 
            {
                //if we encounter a closed bracket
                if(numOpen > 0) {
                    numOpen--;

                }
                //if we encounter a closed bracket before an open bracket
                else {
                    numOpen++;
                    swaps++;
                }
                
            }else {
                //keeps track of open brackets
                numOpen++;
            }
        }
        return swaps;

       

    }
};
