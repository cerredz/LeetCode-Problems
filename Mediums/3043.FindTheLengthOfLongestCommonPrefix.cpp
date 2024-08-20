class Solution {
public:
/*
    Problem:
      You are given two arrays with positive integers arr1 and arr2.
      A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.
      A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have 
      a common prefix. You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.
      Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.
*/
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int res = 0;
        unordered_map<int, pair<int, int>> map; // pair.first = prefix exists in arr1, pair.second = prefix exists in arr2

        // tracking all prefixes for each arr into the map
        getPrefixes(arr1, map, true);
        getPrefixes(arr2, map, false);

        // go through the map, and see which prefixes exist in both lists, returning the longest one
        for(const auto& entry : map) {
            if(entry.second.first == 1 && entry.second.second == 1) {
                int length = to_string(entry.first).length();
                if(length > res) {
                    res = length;
                }
            }
        }
        return res;
    }

    // helper function to store all the prefixes of all numbers in a list into a hashmap
    void getPrefixes(vector<int>& nums, unordered_map<int, pair<int, int>>& map, bool first_list) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int prefix = nums[i];
            while(prefix > 0) {
                (first_list ? map[prefix].first = 1 : map[prefix].second = 1);
                prefix /= 10;
            }
        }
    }
};
