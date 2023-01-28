class Solution {
public:

/*
    Problem: 
    Given two strings s and t, determine if they are isomorphic.
    Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    All occurrences of a character must be replaced with another character while preserving the order of characters. 
    No two characters may map to the same character, but a character may map to itself.
    Approach: 
        - we will have two vectors, and we will be mapping the indexes of the letters in each vector
        - if the letters of s and t do not match each other, then the string are not isomorphic and we can return false
____________________________________________________________________________________________________________________________________
    Psuedocode: 
    
        - declare two vectors: 
        - for each letter in s: 
            - if s[i] != t[i]
                - return false
            
            - set the value of the two vectors to i
        
        - if we reach outside the for loop that means that a letter is not mapped twice,
            and we can return true
        
*/
    bool isIsomorphic(string s, string t) {
        
        vector<int> m1(256, -1);
        vector<int> m2(256, -1);

        for (int i = 0; i < s.size(); ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            //if the values are not the same then one of the characters has been remapped
            
            //now must update the values at each letter
            m1[s[i]] = i; 
            m2[t[i]] = i;
            
        }
        return true;

    }
};
