class Solution {
public:

/*
    Problem:
        Given a string s, find the length of the longest 
-----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach, with a left and a right pointer
        2. Have a set to keep track of the characters in the current window
        3. Start the left and right pointer at the same position, if the right pointer is
            not in the set then we add it to the set and increment the right pointer
        4. If the right pointer is already in the set, update the result if
            necessary, update the left pointer, and clear the set
        5. Return the longest substring without repeating characters
-----------------------------------------------------------------------------------------------
    Psuedocode:
        - have a set to store the charcters in the current window, and left and right pointers,
            and res to store the biggest substring

        - while the right pointer is not out of bounds:
            - if the current character is not in the set
                - add it to the set 
                - increment right
            
            - else if the character is in the set
                - the current window is right - left 
                - clear the set
                - reset the window at left + 1

            - res = right - left, update it if necessary

            

        - return res 
-----------------------------------------------------------------------------------------------
        
*/
    int lengthOfLongestSubstring(string s) {
        

        int longestSubstring = 0, left = 0, right = 0, res = 0;
        unordered_set<char> set;
       
        //while out window is not out of bounds
        while(right < s.length()) {
            //current letter
            char currentChar = s[right];

            //if the current letter is not in the set we add it to the set and increment our right pointer
            if(!set.count(currentChar)) {
                set.insert(currentChar);
                right++;
            //if the current letters is not in the set we clear the set, and reset out window
            }else {
                set.clear();
                left++;
                right = left;
            }
            //update res if right - left is bigger than it
            res = max(res, right - left);
        }

        return res;

    }
};
