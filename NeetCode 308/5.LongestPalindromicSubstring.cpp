class Solution {
public:
    /*
        Approach:
            1. at every index we will have a left and right pointer, we will expand these pointers
                outward if the characters they are pointing to are the same
            2. After expanding outwards, check if the length between the pointers is the greatest length
                out of all palindromes that we have found, if so update the longest palindrome
                substring
            3. Make sure to check all possible substrings (even vs odd lengthed)
    */
    string longestPalindrome(string s) {
        string res = "";
        int n = s.length();

        for(int i = 0; i < n; i++) {
            // odd-lengthed
            int left = i;
            int right = i;
            
            // expand pointers outward
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            } 

            left++;
            right--;
            if(right - left + 1 > res.length()){
                res = s.substr(left, right - left + 1);
            }

            // even lengthed
            left = i;
            right = i + 1;
            
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            } 

            left++;
            right--;
            if(right - left + 1 > res.length()){
                res = s.substr(left, right - left + 1);
            }
        }

        return res;
        
    }
};
