class Solution {
public:

/*
  Problem:
    You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.
    The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.
    If multiple creators have the highest popularity, find all of them. If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
    Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.
*/
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, pair<string, pair<int, long long>>> map; // name, smallest id, {highest viewed video, total view count}
        int n = creators.size();
        long long highest_views = LLONG_MIN; // To handle large numbers of views
        for (int i = 0; i < n; i++) {
            if (map.count(creators[i])) {
                // If the new video has more views or the same views but a lexicographically smaller id
                if (views[i] > map[creators[i]].second.first || 
                   (views[i] == map[creators[i]].second.first && ids[i] < map[creators[i]].first)) {
                    map[creators[i]].first = ids[i];
                    map[creators[i]].second.first = views[i];
                }
                // Update total view count
                map[creators[i]].second.second += views[i];

                // Track the highest total views
                highest_views = max(highest_views, map[creators[i]].second.second);
            } else {
                // Initialize new creator with current video details
                map[creators[i]] = {ids[i], {views[i], views[i]}};
                highest_views = max(highest_views, static_cast<long long>(views[i]));
            }
        }

        // Prepare the result based on highest views
        vector<vector<string>> res;
        for (const auto& entry : map) {
            if (entry.second.second.second == highest_views) {
                res.push_back({entry.first, entry.second.first});
            }
        }

        return res;
    }
};
