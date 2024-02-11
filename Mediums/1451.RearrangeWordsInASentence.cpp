class Solution {
public:
    /*
      Problem:
        Given a sentence text (A sentence is a string of space-separated words) in the following format: First letter is in upper case. Each word in text are separated by a single space. 
        Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.
        Return the new text following the format shown above
*/
    struct Compare {
        bool operator()(const pair<int, pair<int, string>>& a, const pair<int, pair<int, string>>& b) {
            // Compare the first elements of the pairs
            if (a.first != b.first) {
                // If the first elements are different, return true if a is smaller
                return a.first > b.first; 
            }
            // If the first elements are equal, compare the second elements of the inner pairs
            return a.second.first > b.second.first; // Secondary sort on second pair's first value
        }
    };
    string arrangeWords(string text) {

        // min heap in following format: word length, original index, actual word
        priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, Compare> heap;

        int n = text.length();
        string curr_word = "";
        curr_word += tolower(text[0]);

        // loop through text, adding all words to the heap
        for(int i = 1; i < n; i++) {

            if(text[i] == ' ') {
                heap.push({curr_word.length(), {i, curr_word}});
                curr_word = "";
            } else {
                curr_word += text[i];
            }
        }
        // add last word
        heap.push({curr_word.length(), {n, curr_word}});

        // use the heap to build the output
        string res = "";
        while(!heap.empty()) {
            string word = heap.top().second.second;
            res += word + " ";
            heap.pop();
        }
        res[0] = toupper(res[0]);
        res.pop_back();
        return res;

    }
};
