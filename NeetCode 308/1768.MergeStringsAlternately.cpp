class Solution {
public:

/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Problem:
      You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, 
append the additional letters onto the end of the merged string.Return the merged string.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
    string mergeAlternately(string word1, string word2) {
        
        
        string res = "";

        //two pointer approach
        for(int i = 0; i < min(word1.length(), word2.length()); i++){
            
            res += word1[i];
            res += word2[i];
        }

        //add the left over characters from word 1
        for(int i = word2.length(); i < word1.length(); i++) {
            res += word1[i];
        }

        //add the left over characters from word 2
        for(int i = word1.length(); i < word2.length(); i++) {
            res += word2[i];
        }

    
        return res;
    }
};
