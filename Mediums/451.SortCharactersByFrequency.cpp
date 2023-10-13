class Solution {
public:
/*
  Problem:
    Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
    Return the sorted string. If there are multiple answers, return any of them.
*/
    string frequencySort(string s) {
        
        // first store the character and character frequency into a HashMap
        unordered_map<char, int> map;
        for(char c : s) map[c]++;

        // convert the map into a max heap in order to sort the character frequency
        priority_queue<pair<int, char>> heap;
        for(auto entry : map) heap.push({entry.second, entry.first}); 
        // in order to sort characters, we need to have their frequency as the key and not the actual character
        
        // build the result string using the max heap
        string res = "";
        while(!heap.empty()) {
            for(int i = 0; i < heap.top().first; i++) res += heap.top().second;
            heap.pop();
        }

        return res;



    }
};
