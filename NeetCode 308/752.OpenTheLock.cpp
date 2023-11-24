class Solution {
public:

/*

    Problem:
      You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn
      '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
      The lock initially starts at '0000', a string representing the state of the 4 wheels. You are given a list of deadends dead ends, meaning if the lock displays any of these codes,
      the wheels of the lock will stop turning and you will be unable to open it.   Given a target representing the value of the wheels that will unlock the lock, return the minimum total number 
      of turns required to open the lock, or -1 if it is impossible.

*/
    int openLock(vector<string>& deadends, string target) {
        

        unordered_set<string> visited;
        queue<pair<string, int>> q;
        int res = INT_MAX;

        // add deadends to visited set
        for(string str : deadends) visited.insert(str);

        if(visited.count("0000")){
            //edge case
            return -1;
        }

        q.push({"0000", 0});

        // use queue to perform bfs
        while(!q.empty()) {

            string str = q.front().first;
            int path = q.front().second;
            q.pop();

            if(str == target) {
                return path;
            }
            // build the new strings
            for (int i = 0; i < str.length(); i++) {
                string new_string = str;

                // Increment 
                int increment = (str[i] - '0' + 1) % 10;
                new_string[i] = static_cast<char>(increment + '0');
                if (!visited.count(new_string)) {
                    visited.insert(new_string);
                    q.push({new_string, path + 1});
                }   
                
                // Decrement 
                int decrement = (str[i] - '0' + 9) % 10;
                new_string[i] = static_cast<char>(decrement + '0');
                if (!visited.count(new_string)) {
                    visited.insert(new_string);
                    q.push({new_string, path + 1});
                } 
            }


        }

        return -1;
    }
};
