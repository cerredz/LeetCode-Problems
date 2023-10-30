class Solution {
public:

    /*

        Problem:
          You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.
          Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.
          Note that an integer x divides y if y % x == 0.

        Approach:
            1. We will be using a combination of a hashMap and a min heap to solve this problem
            2. store the frequencies of the numbers in nums into a hashMap
            3. sort the numbers and their frequencies in nums using a min heap
            4. traverse through the min heap, and check if the smallest number can divide all of the elements in numsDivide, make sure to keep track of the deletions so far. If the current smallest number cannot divide all of the numbers in numsDivide, make sure to add the frequency of that number to the res. (this is why we are using the hashMap in the first place, in order to avoid repeated work)
    
    */
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        // store frequencies into hashMap
        unordered_map<int, int> map;
        for(int i : nums) map[i]++;

        // sort the frequencies using min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        for(auto entry : map) min_heap.push({entry.first, entry.second});

        // use min heap to find minimum number of deletions
        int num_deletions = 0;
        while(!min_heap.empty()) {

            int curr_smallest = min_heap.top().first;
            int curr_smallest_frequency = min_heap.top().second;
            min_heap.pop();

            bool divides_all = true;
            for(int i : numsDivide) {
                if(i % curr_smallest != 0) {
                    divides_all = false;
                    break;
                }
            }

            if(divides_all == true) {
                return num_deletions;
            }
            num_deletions += curr_smallest_frequency;
        }

        return -1;


    }
};
