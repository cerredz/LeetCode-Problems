class Solution {
public:

/*
    Problem:
      You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
      Return the minimum size of the set so that at least half of the integers of the array are removed.
*/
    int minSetSize(vector<int>& arr) {
        

        // store each number(key) and the number's frequency(values) into a map
        unordered_map<int, int> map;
        for(int i : arr) map[i]++;

        // sort the frequency on numbers using a max heap, this way when we "delete" a number we get the one with the highest number of occurences, in order to sort the frequency of the numbers we need to put the frequency as the key in the heap
        priority_queue<pair<int, int>> heap;
        for(auto entry : map) heap.push({entry.second, entry.first});
        

        // "delete" the most frequent numbers from arr until we have less than half of the integers remaining
        int n = arr.size(), deleted = 0, numsDeleted = 0;
        while(!heap.empty()) {
            deleted += heap.top().first;
            numsDeleted++;
            if(n / 2 <= deleted) return numsDeleted;
            heap.pop();
        } 

        return numsDeleted;
    }
};
