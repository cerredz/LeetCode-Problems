class Solution {
public:
/*
Problem:
    You are given two strings s and t of the same length and an integer maxCost.
    You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
    Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring 
    from s that can be changed to its corresponding substring from t, return 0.

*/
    int equalSubstring(string s, string t, int maxCost) {
        
        int res = 0;
        int curr_cost= 0;

        // implement sliding window appproach
        int left = 0;
        for(int i = 0; i < s.length(); i++) {

            // greedily add cost to current window no matter what
            curr_cost += abs(s[i] - t[i]);

            // window cost too much, shrink it by moving in the left pointer
            while(left <= i && curr_cost > maxCost) {
                curr_cost -= abs(s[left] - t[left]);
                left++;
            }

            // valid window, check if length is greatest so far
            res = max(res, i - left + 1);
        }
        return res;
    }
};
