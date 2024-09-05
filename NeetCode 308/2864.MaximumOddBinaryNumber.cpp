class Solution {
public:
/*
  Problem:
      You are given a binary string s that contains at least one '1'.
      You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
      Return a string representing the maximum odd binary number that can be created from the given combination. Note that the resulting string can have leading zeros.
*/
    string maximumOddBinaryNumber(string s) {
        
        // count the number of ones in s
        int num_ones = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') num_ones++;
        }

        string res = "";
        for(int i = 0; i < num_ones - 1; i++) {
            res += '1';
        }
        for(int i = 0; i < n - num_ones; i++) {
            res += '0';
        }
        if(num_ones > 0) res += '1';
        return res;

    }
};
