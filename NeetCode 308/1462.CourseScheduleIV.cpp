class Solution {

    /*
        Problem:
        There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
        You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first
        if you want to take course bi. For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
        Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, 
        then course a is a prerequisite of course c. You are also given an array queries where queries[j] = [uj, vj]. For the jth query, 
        you should answer whether course uj is a prerequisite of course vj or not. Return a boolean array answer, where answer[j]
        is the answer to the jth query.


        Approach:
            - build adjacency list using the prereq
            - course = node, prereq = edge
            - have our dfs keep track of starting node, ending node, and visited nodes
                - if we run into a cycle or do not make it to the ending node, we return false for our dfs

            - run this dfs function on each of the queries, where the starting node is the 0-th index, and the ending node is the first index
                
    */
private:
unordered_map<int, vector<int>> adj_list;

public:

    bool dfs(int start, int end, vector<bool>& visited) {

        if(start == end){
            return true;
        }

        if(visited[start] == 1){
            // cycle detected
            return false;
        }

        visited[start] = true;
        for(const int& num : adj_list[start]){
            if (dfs(num, end, visited)) {
                return true;  
            }
        }

        return false;
    }


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        // convert prereqs into adj_list
        for(const auto& entry : prerequisites) {
            int node = entry[0];
            int edge = entry[1];
            adj_list[node].push_back(edge);
        }

        // run dfs of all the queries
        int n = queries.size(), i = 0;
        vector<bool> res(n, false);
        vector<bool> visited(numCourses, 0);
        for(const auto& entry : queries) {
            int start = entry[0];
            int end = entry[1];
            vector<bool> visited(numCourses, 0); // 0 = unvisited, 1 = visited
            if(dfs(start, end, visited)){
                res[i] = true;
            }
            i++;
        }

        return res;
    }

};
