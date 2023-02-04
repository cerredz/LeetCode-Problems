class Solution {
public:

/*
    Problem:
        Given a pattern and a string s, find if s follows the same pattern.
    ----------------------------------------------------------------------------------------------------------
    Approach:
        - have two maps that have a pattern that corresponds to a word, and vise versa
        - loop through the words of the string and check if the maps correspons to each other
    ----------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare two maps, and split s into words using istringstream
        - while there are still words
            - if the pattern and word do not match
                -return false
            
            - set pattern[i] to currentWord
            - set currentword to pattern[i]
            - increment i
        
        - return i == pattern.length()
*/
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream ss(s);//splits string into separate words
        string word;
        int i = 0;
        
        while(ss >> word) {//while there are still words in s
            if(i >= pattern.length())
                return false;
            
            if(charToWord.count(pattern[i]) && charToWord[pattern[i]] != word)
                return false;
            
            if(wordToChar.count(word) && wordToChar[word] != pattern[i])
                return false;
            
            charToWord[pattern[i]] = word;
            wordToChar[word] = pattern[i];
            i++;
        }
        
        return i == pattern.length();
    }
};
