class Solution {
public:

    /*
    
      Problem:
        You are given two strings s and t. In one step, you can append any character to either s or t.
        Return the minimum number of steps to make s and t anagrams of each other.
        An anagram of a string is a string that contains the same characters with a different (or the same) ordering.
    */
    int minSteps(string s, string t) {
        
        vector<int> sChars(26, 0);
        vector<int> tChars(26,0);
        
        int res = 0;

        // Count characters in string s
        for(char c : s) sChars[c - 'a']++;

        // Count characters in string t and check for an existing count in s
        for(char c : t) {
            tChars[c - 'a']++;
            if(tChars[c - 'a'] > sChars[c - 'a']) {
                res++;
            }
        }

        // Calculate the number of extra characters in s that are not in t
        for(int i = 0; i < 26; i++) {
            if(sChars[i] > tChars[i]) {
                res += sChars[i] - tChars[i];
            }
        }

        return res;

    }
};
