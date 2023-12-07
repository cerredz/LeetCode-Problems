class Solution {
private:
    unordered_map<int, vector<int>> adj_list;
    vector<int> path;
public:
    /*
        Problem:
            There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
            You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
            For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1. 
            Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them.
            If it is impossible to finish all courses, return an empty array.

        Approach:
            - if we find cycle = impossible to finish all courses
            - 
            - convert the graph to an adj_list in order to run a dfs on it
            - as we are iterating through the nodes in the adj_list, if no cycle is found then add it to the current path
            - if at any point we find a cycle, return an empty list
    */

    bool dfs(int node, vector<int>& visited) {

        if(visited[node] == 2){
            // terminal node, no need to visit it again
            return true;
        }

        if(visited[node] == 1) {
            // cycle detected
            return false;
        }

        visited[node] = 1;
        
        for(const int& edge : adj_list[node]) {
            if(!dfs(edge, visited)) {
                return false;
            }
            
        }

        // no cycles detected, add node to path and mark node as visited
        path.push_back(node);
        visited[node] = 2;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // convert the graph into an adjacency list
        for(const auto& entry : prerequisites) {
            int prereq = entry[1];
            int course = entry[0];
            adj_list[course].push_back(prereq);
        }

        // run a dfs on all nodes in the adj_list to make sure there are no cycles, keep track of the path along the way
        
        vector<int> res;
        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        for(int i = 0; i < numCourses; i++) {
            int node = i;
            if(!dfs(node, visited)) {
                return {};
            }
        }
        return path;
        

    }
};
