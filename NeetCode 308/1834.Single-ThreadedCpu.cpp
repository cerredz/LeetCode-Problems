class Solution {
public:

    /*
      Problem:
        You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be 
        available to process at enqueueTimei and will take processingTimei to finish processing.You have a single-threaded CPU that can process at most one task at a time and will 
        act in the following way: If the CPU is idle and there are no available tasks to process, the CPU remains idle. If the CPU is idle and there are available tasks, 
        the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
        Once a task is started, the CPU will process the entire task without stopping. The CPU can finish a task then start a new one instantly.
        Return the order in which the CPU will process the tasks.
    */

    // helper function to sort pairs into ascending order based off of first parameter
    static bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        vector<int> res;

        // sort the tasks into ascending order based on their enqueueTime
        vector<pair<int, int>> pairs(tasks.size());
        for(int i = 0 ; i < n; i++) {
            pairs[i] = {tasks[i][0], i};
        }
        sort(pairs.begin(), pairs.end(), comparePairs);


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        long long enqueueTime = pairs[0].first;
        int index = 0;

        while(index < pairs.size() || !minHeap.empty()) {

            // add all of the tasks within the enqueue time into the min heap
            while(index < n && pairs[index].first <= enqueueTime) {
                int processingTime = tasks[pairs[index].second][1];
                int originalIndex = pairs[index].second;
                minHeap.push({processingTime, originalIndex}); // sort based off of processing time
                index++;
            }


            if(minHeap.empty()) {
                // cpu is idle, fast forward "enqueueTime" to the actual next enqueueTime
                enqueueTime = pairs[index].first; 
                continue;
            }

            if(!minHeap.empty()) {
                // tasks ready for cpu to complete
                pair<int, int> nextTask = minHeap.top();
                res.push_back(nextTask.second); // least processing time of available tasks
                enqueueTime += nextTask.first; // increase time
                minHeap.pop();
                
            }
        }
        return res;


    }
};
