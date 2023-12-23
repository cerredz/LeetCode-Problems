class Solution {
public:
    /*
  
        Problem:
          Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
          Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists. Notice that you can return the vertices in any order.


        Approach:
            1. this problem actually doesnt need dfs or bfs at all, all we have to do is find
                the nodes in edges that have no incoming edges, that is a node where nothing points
                to it
            2. After we find all of these nodes with a simple for loop, we can add all of these nodes
                to our result vector
    */
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // find nodes with no incoming edges
        vector<bool> incomingEdge(n, false);    
        for(const auto& edge : edges) {
            int node = edge[1];
            incomingEdge[node] = true;
        }

        // add the nodes with no incoming edges to res
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(!incomingEdge[i]){
                res.push_back(i);
            }

        }
        return res;
        

    }
};
