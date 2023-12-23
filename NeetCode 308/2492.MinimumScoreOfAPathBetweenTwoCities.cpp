class Solution {

private:
unordered_map<int, vector<pair<int, int>>> adj;
unordered_set<int> visited;
int res;


public:

  /*
    Problem:
       You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road
       between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected. The score of a path between two cities is defined as the minimum distance of a road in this path.
       Return the minimum possible score of a path between cities 1 and n.
  */
    // helper function to find lowest weight in the connected component 
    void dfs(int node) {
        if(visited.count(node)) {
            return;
        }

        visited.insert(node);
        for(const auto& entry : adj[node]) {
            int edge = entry.first;
            int weight = entry.second;
            res = min(res, weight);
            dfs(edge);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {

        // convert roads into an adjacency list, also keep track of the weights between an edge
       for(const auto& entry : roads) {
           int node = entry[0];
           int edge = entry[1];
           int weight = entry[2];
           adj[node].push_back({edge, weight});
           adj[edge].push_back({node, weight}); // bidirectional
       }

       // perform the dfs, keep track of the lowest weight found
       res = INT_MAX;
       dfs(1);
       return res;


    }
};
