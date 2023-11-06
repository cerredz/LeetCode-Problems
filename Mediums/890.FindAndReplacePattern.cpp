class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for (string s : words) {
            if (matchPattern(s, pattern)) {
                res.push_back(s);
            }
        }
        
        return res;
    }
    
private:
    bool matchPattern(const string& word, const string& pattern) {
        // create a bijection of letter to letter mapping between each character in each word
        unordered_map<char, char> word_mapping;
        unordered_map<char, char> pattern_mapping;
        
        for (int i = 0; i < word.length(); i++) {
            char w = word[i];
            char p = pattern[i];
            
            if (word_mapping.count(p) && word_mapping[p] != w) {
                return false;
            }
            
            if (pattern_mapping.count(w) && pattern_mapping[w] != p) {
                return false;
            }
            
            word_mapping[p] = w;
            pattern_mapping[w] = p;
        }
        
        return true;
    }
};
