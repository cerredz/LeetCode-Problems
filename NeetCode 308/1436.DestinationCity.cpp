class Solution {
public:
/*
    Problem:
      You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, 
      that is, the city without any path outgoing to another city. It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
*/
    string destCity(vector<vector<string>>& paths) {
        // store the cityA and cityB counts of the paths into a map
        unordered_map<string, pair<int, int>> paths_freq;
        
        // first value in pair represents cityA, second represents cityB
        for(const auto& path : paths) {
            paths_freq[path[0]].first++;
            paths_freq[path[1]].second++;
        } 

        // return the path with only 1 cityB value and 0 cityA values, this is the destination city
        for(const auto& freq : paths_freq) {
            if(freq.second.second == 1 && freq.second.first == 0) return freq.first;
        }

        // will never reach here
        return "";
    }
};
