class Solution {
public:

/*
problem:
    Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

*/
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> map; // {number, frequency of number}
        for(int i = 0; i < arr.size(); i++) map[arr[i]]++;

        // use heap to sort the frequencies
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(const auto& entry : map) min_heap.push(entry.second);

        // remove the least frequency numbers until we run out of numbers to remove
        while(!min_heap.empty() && k > 0) {
            int frequency = min_heap.top();
            if(k < frequency) {
                break;
            }
            min_heap.pop();
            k -= frequency;
        }

        // the size of the heap is how many unique numbers are left
        return min_heap.size();

    }
};
