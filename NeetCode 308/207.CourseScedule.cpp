class Solution {
public:

    /*
        Problem:
          There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates
          that you must take course bi first if you want to take course ai. For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1. Return true if you can finish all courses.
          Otherwise, return false.
          
        Approach:
            1. Notice that we dont have any limits as to how many classes it takes to complete all courses, this means that 
                the only way for us to not be able to take all of the courses is if there is a cycle in prerequisites
            2. Think of prerequisites as a graph, we should first turn it into a adjacentcy list, and then 
                run a dfs on it to see if there are any cycles in the graph 
            3. If there are cyckles, we return false, if there are no cycles, then we return true
    */

    vector<int> visited;
    unordered_map<int, vector<int>> adj_list;
    bool dfs(int node) {
    if(visited[node] == 1) {
        // cycle found, return false
        return false;
    }

    if(visited[node] == 0) {
        visited[node] = 1; // Mark the current node as being visited

        for(int neighbor : adj_list[node]) {
            if(!dfs(neighbor)) {
                return false;
            }
        }

        // all nodes visited and no cycles found, dont want to return false or run dfs on node again, so make it anything that is not 0 or 1
        visited[node] = 2; 
        
    }

    return true;
}


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // convert prerequesites into an adjacency list
        int n = prerequisites.size();
        for(int i = 0; i < n; i++) {
            int node = prerequisites[i][0];
            int edge = prerequisites[i][1];
            adj_list[node].push_back(edge);
        }

        // check for a cycle for every class that has a prerequisite
        visited = vector<int> (numCourses, 0); // 0 = unvisited, 1 = visited
        for(const auto& entry : adj_list) {
            if(!dfs(entry.first)) {
                // cycle found
                return false;
            }
        }

        return true;
    }
};
