class Solution {
public:
    /*
        Problem:
            Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.
            A string is homogenous if all the characters of the string are the same. A substring is a contiguous sequence of characters within a string
        Approach:
            1. use a two pointer approach, where at every iteration the left and right pointer
                represent the starting and ending index of the current homogeneous string that we 
                are looking at
            2. Given the length of the homogenous string, we can calculate the number of homogeneous 
                substrings in constant time ((n * n + 1) / 2)
    */
    int countHomogenous(string s) {
        
        int left = 0, right = 0;
        int n = s.length();
        long long res = 0;

        while(right < n ) {

            // maximize length of current homegenous string
            while(right < n && s[left] == s[right]){
                right++;
            }

            // calculate total number of homogenous substrings
            int length = right - left;
            long long substrings = (static_cast<long long>(length) * (length + 1)) / 2; 
            res += substrings;
            res %= 1000000007; 

            // reset our window
            left = right;
        }
        return res % 1000000007;
    }
};
