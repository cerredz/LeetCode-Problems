class Solution {
public:

/*
  Problem:
      Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. 
      Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
      However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
      Return the least number of units of times that the CPU will take to finish all the given tasks.

*/
    int leastInterval(vector<char>& tasks, int n) {
        
       // store the frequency of each character in tasks into a HashMap
       unordered_map<char, int> map;
       for(char c : tasks) {
           map[c]++;
       }

       // sort the frequencies of the tasks into desending order using a max heap
       priority_queue<int> pq;
       for(auto entry : map) {
           pq.push(entry.second);
       }

       // simulate the task sceduler using a queue, the max heap, n, and a time counter
       queue<pair<int, int>> q; // first parameter is the "task / letter", second parameter is when to add it back into the heap
       int time = 0;

       while(!pq.empty() || !q.empty()) {

            // increment time
            time++;
            // get current most frequenct task from the heap
            if(!pq.empty()) {
                int currTask = pq.top() - 1;
                pq.pop();

                // add it into the q 
                if(currTask > 0) {
                    q.push({currTask, time + n });
                }
                
            }

            // check if first element from q needs to be added back into the max heap
            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        
       }

       return time;
    }
};
