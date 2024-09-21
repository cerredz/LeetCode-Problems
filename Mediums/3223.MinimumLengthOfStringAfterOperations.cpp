class Solution {
public:

/*
  Problem:
    You are given a string s.
    You can perform the following process on s any number of times: Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], 
    and at least one character to the right that is also equal to s[i]. Delete the closest character to the left of index i that is equal to s[i]. Delete the closest character to the right of index i that is equal to s[i].
    Return the minimum length of the final string s that you can achieve.
*/
    int minimumLength(string s) {
        
        int res = s.length();

        // store frequency on letters into hashmap
        unordered_map<char, int> map; 
        for(char &c : s) map[c]++;

        // using frequencies, calculate the res
        for(auto& entry : map) {
            while(entry.second >= 3) {
                res -= 2;
                entry.second -= 2;
            }
        }

        return res;
    }
};
