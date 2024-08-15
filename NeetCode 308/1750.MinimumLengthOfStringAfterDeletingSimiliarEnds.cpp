class Solution {
public:
/*
    Problem:
      Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
      Pick a non-empty prefix from the string s where all the characters in the prefix are equal. Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
      The prefix and the suffix should not intersect at any index. The characters from the prefix and suffix must be the same.
      Delete both the prefix and the suffix. Return the minimum length of s after performing the above operation any number of times (possibly zero times).

*/
    int minimumLength(string s) {
        int n = s.length();
        int res = n;
        int left = 0, right = n - 1;
        // sliding window approach, start with the outmost window and work out way in
        while(left < right && s[left] == s[right]) {
            // same prefix and suffix found, get to innermost index of each prefix and suffix
            res -= 2;
            while(left < right - 1 && s[left] == s[left + 1]) {
                left++;
                res--;
            }
            while(right > left + 1 && s[right] == s[right - 1]) {
                right--;
                res--;
            }
            left++;
            right--;
        }
        
        return res;
    }
};
