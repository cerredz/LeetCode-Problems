class Solution {
public:
    /*
      Problem:
        You have n processors each having 4 cores and n * 4 tasks that need to be executed such that each core should perform only one task.
        Given a 0-indexed integer array processorTime representing the time at which each processor becomes available for the first time and a 0-indexed integer array tasks representing the time it takes to execute 
        each task, return the minimum time when all of the tasks have been executed by the processors.
        Note: Each core executes the task independently of the others.

*/
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        
        // sort the tasks and times
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        int res = INT_MIN, time_index = processorTime.size() - 1, task_index = 0, n = tasks.size();
        // use the sorted list and iterate in groups of 4 to simulate the each processor having 4 cores
        // start at the highest processing time combined with the lower tasks time, then move the pointers inward
        while(task_index < n - 3) {
            int curr_max = INT_MIN;
            for(int i = 0; i < 4; i++) {
                curr_max = max(curr_max, processorTime[time_index] + tasks[task_index]);
                task_index++;
            }
            time_index--;
            res = max(res, curr_max);
        }

        return res;

    }
};
