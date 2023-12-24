class Solution {
public:
    /*
      Problem:
          A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
          Every adjacent pair of words differs by a single letter. Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList. sk == endWord
          Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
  
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // keep a set of the words in wordList for instant lookup
        unordered_set<string> dictionary;
        for(string& str : wordList) {
            dictionary.insert(str);
        }

        // declare queue for bfs
        queue<string> q;
        q.push(beginWord);
        int result = 1;
        while(!q.empty()) {
            int n = q.size();
            // traverse over eliments in q
            for(int i = 0; i < n; i++) {

                string curr = q.front();
                q.pop();
                if(curr == endWord) {
                    return result;
                }
                dictionary.erase(curr);

                // traverse over every letter in current word, and add every combination to the q that is in the dictionary
                for(int i = 0; i < curr.size(); i++) {
                    char letter = curr[i];
                    for(int j = 0; j < 26; j++) {
                        curr[i] = j + 'a';
                        if(dictionary.count(curr)) {
                            q.push(curr);
                            dictionary.erase(curr); // dont want to visit same word twice
                        }
                        curr[i] = letter;
                    }
                }
            }
            result++;
        }

        return 0;
    }
};
