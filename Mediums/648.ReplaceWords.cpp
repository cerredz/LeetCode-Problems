class Solution {
public:
/*
    Problem:
        
  In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. 
  For example, when the root "an" is followed by the successor word "other", we can form a new word "another". Given a dictionary consisting of 
  many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it.
  If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
  Return the sentence after the replacement.


*/
    string replaceWords(vector<string>& dictionary, string sentence) {
        

        // store all of the words in the dictionary into a set for constant time lookup
        unordered_set<string> st;
        for(const string& word : dictionary) {
            st.insert(word);
        }

        // store the words in the sentence into an array
        vector<string> words;
        string curr = "";
        int n = sentence.length();
        for(int i = 0; i < n; i++) {
            char letter = sentence[i];
            if(letter == ' '){
                words.push_back(curr);
                curr = "";
                continue;
            }
            curr += letter;
        }
        // add last word in the sentence
        words.push_back(curr);

        // go through each letter in each word and see if we can reduce the length using the dictionary
        string res = "";
        for(int i = 0; i < words.size(); i++) {
            string substr = "";
            for(int j = 0; j < words[i].length(); j++) {
                substr += words[i][j];
                if(st.count(substr)){
                    break;
                }
            }

            res += substr + ' ';
        }
        res.pop_back();
        return res;


    }
};
