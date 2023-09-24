
class Solution {
public:

/* 
  Problem:
      You are given a binary string s that contains at least one '1'.
      You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
      Return a string representing the maximum odd binary number that can be created from the given combination. Note that the resulting string can have leading zeros.

*/
    string maximumOddBinaryNumber(string s) {


        // create a string that has the 1's in s at the front of the res string, and leave an extra 1 at the back of the res string to make the number odd
        unordered_map<char, int> map;
        
        for(char c : s) {
            map[c]++;
        }
        string res = "";
        int numOnes = map['1'], numZeros = map['0'];
        
        for(int i = 0; i < numOnes - 1; i++) {
            res += '1';
        }
        
        for(int i = 0; i < numZeros; i++) {
            res += '0';
        }
        
        res += '1';
        return res;
        
    }
};
