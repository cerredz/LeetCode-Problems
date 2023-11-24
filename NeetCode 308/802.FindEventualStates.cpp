class Solution {
public:
    /*

    Problem:
      There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i,
      meaning there is an edge from node i to each node in graph[i]. A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a 
      terminal node (or another safe node). Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


*/
    vector<int> state;
    vector<vector<int>> tree;

    bool dfs(int node){

        if(state[node] == 2){
            // terminal node found
            return true;
        }

        if(state[node] == 1){
            // cycle detected
            return false;
        }

        state[node] = 1; // mark node as visited
        for(int neighbor : tree[node]){
            if(!dfs(neighbor)){
                // if even 1 of the neighbors do not lead to a terminal node, it is not a safe node
                return false;
            }
        }
        
        // if control reaches here, a terminal path has been found
        state[node] = 2; 
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        tree = graph;
        state = vector<int>(n, 0); // 0: unvisited, 1: in progress, 2: safe 
        vector<int> res;

        // run dfs on every index, 0 -> n - 1
        for(int i = 0; i < n; i++) {
            if(dfs(i)){
                res.push_back(i);
            }   
        }
        
        return res;
    }
};
