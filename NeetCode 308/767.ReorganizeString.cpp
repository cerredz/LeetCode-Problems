class Solution {
public:
    /*
        Problem:
            Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
            Return any possible rearrangement of s or return "" if not possible
            
        Approach:
            1. Sort character frequency into descending order (max heap) beacuse we want to start with the most freuqent character when buiding the string  
            2. using the most frequent element and the size of s, calculate whether or not building a string is possible
            3. If building a string is possible, then build it using the heap that we created. At every iteration add two characters, and then decrement the count of those two characters until the heap is empty. 
    */

    string reorganizeString(string s) {
        

        // store the frequency of each character in s into a HashMap
        int n = s.length();
        unordered_map<char, int> map;
        for(char c : s) {
            map[c]++;
        }

        // sort the frequencies (not characters) into descending order using a max heap
        priority_queue<pair<int, char>> max_heap;
        for(auto entry : map) {
            max_heap.push({entry.second, entry.first});
        }

        // calculate whether or not building a string is possible
        int mostFrequent = max_heap.top().first;
        if((n % 2 == 0 && mostFrequent > n / 2) || (n % 2 == 1 && mostFrequent > n / 2 + 1)) {
            
            return "";
        }

        // reorganize the string using the max heap
        string res = "";
        while(!max_heap.empty()) {

            pair<int, char> mostFrequentChar = max_heap.top();
            max_heap.pop();

            if(!res.empty() && res.back() == mostFrequentChar.second) {
                cout << res << ", " << mostFrequentChar.second << endl;
                return "";
            }

            res += mostFrequentChar.second;
            mostFrequentChar.first--;
            
            if(!max_heap.empty()) {
                
                pair<int, char> secondMostFrequentChar = max_heap.top();
                max_heap.pop();
                res += secondMostFrequentChar.second;
                secondMostFrequentChar.first--;

                if(mostFrequentChar.first > 0) {
                    // wait to add most frequent back into heap after adding second most frequent to res
                    max_heap.push(mostFrequentChar);
                }
                if(secondMostFrequentChar.first > 0) {
                    max_heap.push(secondMostFrequentChar);
                }
            }
        }

        return res;
    }
};
