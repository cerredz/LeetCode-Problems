class Solution {
private:
    unordered_map<int, vector<int>> adj_list;
    unordered_set<int> visited;
public:

/*
  Problem:
    You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] 
    denotes that there exists an undirected edge connecting nodes ai and bi. Return the number of pairs of different nodes that are unreachable from each other.
*/

    // helper function to get the connected componentes of the graph and return the edges of each connected component
    long dfs(int start) {

        // use stack for dfs
        stack<int> st;
        st.push(start);
        int edges = 0;

        // implement dfs
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            for(const int& num : adj_list[node]) {
                if(visited.count(num)) continue;

                st.push(num);
                visited.insert(num);
                edges++;
            }
        }
        cout << edges << endl;
        return edges;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res = 0, visited_count = n;

        // build the adjacency list
        for(const auto& entry : edges) {
            adj_list[entry[0]].push_back(entry[1]);
            adj_list[entry[1]].push_back(entry[0]);
        }

        for(int i = 0; i < n; i++) {
            if(adj_list[i].size() == 0) adj_list[i].push_back(i);
        }

        // get the total nodes, to later calculate the unreachable nodes
        long long total_nodes = adj_list.size();

        // run a dfs to find connected nodes
        for(const auto& entry : adj_list) {
            long start = entry.first;
            if(!visited.count(start)) {
                long total_connected_nodes = dfs(start); // dfs will return length of each connected component
                res += total_connected_nodes * (visited_count - total_connected_nodes);
                visited_count -= total_connected_nodes;
            }
        }
        return res;
    }

};
