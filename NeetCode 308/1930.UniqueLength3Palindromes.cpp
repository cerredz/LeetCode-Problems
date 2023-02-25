class Solution {
public:
/*

    Problem:
      Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
      Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
      A palindrome is a string that reads the same forwards and backwards.A subsequence of a string is a new string generated from the original 
     string with some characters (can be none) deleted without changing the relative order of the remaining characters.
     For example, "ace" is a subsequence of "abcde".
------------------------------------------------------------------------------------------------
    Approach:
    1. Keep track of the leftmost and rightmost characters in the string
    2. For every character that appears twice in the string, count the number of unique
        characters in between the two appearances
    3. add the number of unique characters to the result
------------------------------------------------------------------------------------------------
    Psuedocode:
        - have two vectors to keep track of the leftMost and rightMost occurance of each
            character
        - for each character in s:
            - if the character has not been seen yet:
                - set the leftMost[currentChar] = i
            
            - set rightMost[currentChar] = i after every iteration
        
        - for every character in the alphabet
            - if leftMost[char] , rightMost[char]:
                - create a set to store the unique characters
                - from the index of leftMost[char] to rightMost[char], add every character
                - add the size of the set to result
        
        - return result
*/
    int countPalindromicSubsequence(string s) {
        
        vector<int> leftChar (26, -1), rightChar (26, -1);
        int numPalindromes = 0;

        for(int i = 0; i < s.length(); i++) {
            if(leftChar[s[i] - 'a'] == -1) {
                leftChar[s[i] - 'a'] = i;
            }
            rightChar[s[i] - 'a'] = i;
        }

        //time to count the subsequences

        for(int i = 0; i < 26; i++) {
            //check if the string letter has occured at least twice in the string
           if(leftChar[i] < rightChar[i]) {
               //keep track of the unique characters in between leftmost and rightmost
               unordered_set<int> uniqueSubsequences (s.begin() + leftChar[i] + 1, s.begin() + rightChar[i]);
               //add unique characters to our result
               numPalindromes += uniqueSubsequences.size();
           }
        }

        return numPalindromes;


    }
};
