class Solution {
public:

/*
  Problem:
    Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

*/
    int maxProduct(vector<string>& words) {
        int numWords = words.size();
        int maxProduct = 0;
        
        // Loop through every pair of words
        for (int i = 0; i < numWords; ++i) {
            // Create a frequency array for the first word
            vector<int> wordOneFreq(26, 0);
            for (const char& c : words[i]) {
                wordOneFreq[c - 'a']++;
            }

            for (int j = i + 1; j < numWords; ++j) {
                // Check for common letters between words[i] and words[j]
                bool hasCommonLetters = false;
                for (const char& c : words[j]) {
                    if (wordOneFreq[c - 'a'] > 0) {
                        hasCommonLetters = true;
                        break;
                    }
                }

                // If no common letters, update maxProduct if necessary
                if (!hasCommonLetters) {
                    int product = words[i].length() * words[j].length();
                    if (product > maxProduct) {
                        maxProduct = product;
                    }
                }
            }
        }
        
        return maxProduct;
    }
};
