class Solution {
public:
    /*
      Problem:
        Given an array of strings words and an integer k, return the k most frequent strings.
        Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
        
    */
    vector<string> topKFrequent(vector<string>& words, int k) {
        

        // Step 1: store the frequency of each word
        unordered_map<string, int> word_frequency;
        for(string str : words) {
            word_frequency[str]++;
        }

        // Step 2: sort the frequency of each word by adding them to a max heap
        // custom comparison function for the max heap
        auto compare = [](pair<int, string> a, pair<int, string> b) {
            if (a.first != b.first) {
                return a.first < b.first; 
            } else {
                return a.second > b.second; 
            }
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> sorted_word_frequency(compare);

        for(auto entry : word_frequency) {
            sorted_word_frequency.push({entry.second, entry.first});
        }

        // Step 3: pop k-1 times from the max heap, each time adding the string to list of strings that we will return
        vector<string> res(k);
        int index = 0;
        while(k > 0) {
            cout << sorted_word_frequency.top().second << endl;
            res[index] = sorted_word_frequency.top().second;
            sorted_word_frequency.pop();
            index++;
            k--;
        }



        return res;
    }
};
