class Solution {
public:

/*
    Problem:
      You are given an array of strings words and a string chars.
      A string is good if it can be formed by characters from chars (each character can only be used once).
      Return the sum of lengths of all good strings in words.

*/
    int countCharacters(vector<string>& words, string chars) {
        // 0 (n * m) solution where m is number of characters
        int length = 0;

        // store the chars and their frequencies into a HashMap
        vector<int> char_freqs(26, 0);
        for(char& c: chars) char_freqs[c - 'a']++;

        // loop though each word, and for each word check that no character has a bigger frequency then the one in chars
        for(string str : words) {
            int letters = str.length();
            bool isValid = true;
            vector<int> temp(26, 0);
            for(char& c : str) {
                // check frequencies
                if(temp[c - 'a'] >= char_freqs[c - 'a']) {
                    isValid = false;
                    break;
                }
                temp[c - 'a']++;
            }
            if(isValid) length += letters;
        }
        return length;
    
    }
};
