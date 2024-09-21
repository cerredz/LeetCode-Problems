class Solution {
private:
    unordered_map<int, vector<int>> adj_list;
public:
    /*
      Problem:
          You are given an integer n and a 2D integer array queries.
          There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.
          queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.
          Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.
    
    */
    // helper function to find shortest path in adjacency list
    int findShortestPath(int start, int end) {

        // implement bfs algorithmn
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        int path = 0;

        while(!q.empty()) {
            int n = q.size();
            path++; // keep track of path length
            for(int i = 0; i < n; i++) {
                int node = q.front();
                q.pop();
                for(const int& end_node : adj_list[node]) {
                    
                    // reached final node, return the path (bfs)
                    if(end_node == end) return path;

                    if(!visited.count(end_node)) {
                        q.push(end_node);
                        visited.insert(end_node);
                    }
                }
            }
        }
        return path;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        // build the default adjacency matrix
        for(int i = 0; i < n - 1; i++) {
            adj_list[i].push_back(i + 1);
        }

        // using queries, find shortest path every time after adding each query to the adjacency matrix
        vector<int> res;
        for(int i = 0; i < queries.size(); i++) {
            int starting_node = queries[i][0];
            int ending_node = queries[i][1];
            adj_list[starting_node].push_back(ending_node);
            int shortest_distance = findShortestPath(0, n - 1);
            res.push_back(shortest_distance);
        }

        return res;
    }
};
