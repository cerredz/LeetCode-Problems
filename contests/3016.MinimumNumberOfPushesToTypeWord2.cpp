class Solution {
public:
/*
  Problem:
    You are given a string word containing lowercase English letters.
    Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them.
    For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
    It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, 
    but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
    Return the minimum number of pushes needed to type word after remapping the keys.
    An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.
*/
    int minimumPushes(string word) {
        
        unordered_map<char, int> map;
        for(char c : word) map[c]++;
        
        
        priority_queue<int> heap;
        for(const auto& entry : map) {
            heap.push(entry.second);
        }
        
        int res = 0;
        int letters = 0;
        while(!heap.empty()) {
            int increment = letters / 8 + 1;
            int freq = heap.top();
            heap.pop();
            letters++;
            res += (increment * freq);
        }
        return res;
    }
};
