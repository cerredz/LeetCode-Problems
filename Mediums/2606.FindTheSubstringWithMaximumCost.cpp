class Solution {
public:
/*
    Problem:
      You are given a string s, a string chars of distinct characters and an integer array vals of the same length as chars.
      The cost of the substring is the sum of the values of each character in the substring. The cost of an empty string is considered 0.
      The value of the character is defined in the following way: If the character is not in the string chars, then its value is its corresponding position (1-indexed) in the alphabet.
      For example, the value of 'a' is 1, the value of 'b' is 2, and so on. The value of 'z' is 26. Otherwise, assuming i is the index where the character occurs in the string chars, then its value is vals[i].
      Return the maximum cost among all substrings of the string s.

*/
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        // store the chars and their corresponding value into a 'hashmap' for constant time lookup
        vector<int> costs(26, -10000);
        for(int i = 0; i < vals.size(); i++) {
            char c = chars[i];
            costs[c -'a'] = vals[i];
            
        }
        for(int i = 0; i < 26; i++) {
            if(costs[i] == -10000) costs[i] = i + 1;
        }

        // implement a sliding window approach 
        int max_cost = 0, curr_cost = 0;
        for(int i = 0; i < s.length(); i++) {
            // add value of current character to out current cost
            char c = s[i];
            curr_cost += costs[c - 'a'];

            if(curr_cost < 0) {
                // empty string has greater cost, reset it to that
                curr_cost = 0;
            } else {
                // account for max cost accordingly
                max_cost = max(max_cost, curr_cost);
            }
        }
        return max_cost;
    }
};
