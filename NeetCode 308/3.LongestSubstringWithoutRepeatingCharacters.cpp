class Solution {
public:

/*
    Problem:
        Given a string s, find the length of the longest substring without repeating characters.
-----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer sliding window apporach, we will use the two pointers
            to dynamically increase and decrease the range of the window
        2. First we need to declare our pointers, max substring variable, and a set to 
            keep track of the characters in our set so far
        3. We start the pointers at the same position, and if the characters at our right 
            pointer is not in the set then add it to the set and increment our right pointer
            by 1. Hence, increasing our window.
        3. If the character at our right pointer is already in the set, then clear the set,
            increment our left pointer to start at a new character, and set the right pointer
            equal to the left pointer. Hence, decreasing our window. Keep doing this
            until our right pointer is out of bounds.
        4. Also, after every iteration calulate the right pointer - left pointer. This value
            represents our window length of non-repeated characters, and update our max 
            substring variable if necessary
        5. Return the max substring we find
-----------------------------------------------------------------------------------------------
    Psuedocode:

    - declare pointers, set, and maxSubstring variable

    - while right pointer is in range of s:

        - if s[right] is not in the set:
            - add s[right] to the set
            - increment right
        - else
            - clear the set
            - increment left
            - set right = left
        
        - update maxSubstring if necessary (right - left = current window length)

    - return maxSubstring
---------------------------------------------------------------------------------------------
*/
    int lengthOfLongestSubstring(string s) {
        
        //initialize pointers, set, and maxSubstring
        int maxSubstring = 0, left = 0, right = 0;
        unordered_set<char> set;

        //implement the algorithm for finding longest substring without repeating characters
        while(right < s.length()) {
            
            //if current char is not in the set, increase window
            if(!set.count(s[right])){
               
               set.insert(s[right]);
               right++;
            //if current char is in the set, decrease window
            } else {
               set.clear();
               left++;
               right = left;
            }

            //see if current window is biggest seen so far
            maxSubstring = max(maxSubstring, right - left);
       }

       return maxSubstring;
    }
};
