class Solution {
private:
    unordered_map<int, vector<int>> adj_list;
public:

    /*
      Problem:
          You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
          The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. 
          If there is no outgoing edge from i, then edges[i] == -1. You are also given two integers node1 and node2. Return the index of the node that can be
          reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.
          Note that edges may contain cycles
    
    */
    // helper function to calculate distance of all other nodes starting at inputted node
    void bfs(int node, unordered_map<int, int>& map) {
        queue<pair<int, int>> q;
        q.push({node, 0});
        map[node] = 0;

        while(!q.empty()) {

            int n = q.size();
            int curr = q.front().first, distance = q.front().second;
            q.pop();
            
            // traverse over current node's edges
            for(int i = 0; i < adj_list[curr].size(); i++) {
                int edge = adj_list[curr][i];
                if(!map.count(edge)) {
                    // avoid cycles
                    q.push({edge, distance + 1});
                    map[edge] = distance + 1;
                }
                
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        // convert edges into an adjacency list
        int n = edges.size();
        for(int i = 0; i < n; i++) {
            int edge = edges[i];
            adj_list[i].push_back(edge);
        }

        // run our bfs to find the distance of nodes from node1 AND node2
        unordered_map<int, int> node1_distances;
        unordered_map<int, int> node2_distances;
        bfs(node1, node1_distances);
        bfs(node2, node2_distances);

        int res = -1;
        int distance = INT_MAX;

        // minimize the distances
        for(int i = 0; i < n; i++) {

            if(node1_distances.count(i) && node2_distances.count(i)) {
                int dist = max(node1_distances[i], node2_distances[i]);
                if(dist < distance) {
                    res = i;
                    distance = dist;
                }
            }
            
        }

        return res;


    }
};
