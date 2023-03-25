class Solution {
public:

/*
    Problem:
    - Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
------------------------------------------------------------------------------------------------
    Approach:
        1. We wille be using somewhat of a greedy approach
        2. Given k, we know the total unqiue combinations of binary codes that we can 
            generate (2 ^ k)
        3. We can store all the binary codes in a set to keep track of all unique binary codes
            of length k
        4. If the size of the set is equal to  2 ^ k this means that the number of unique 
            binary codes = total amount of possible binary codes lengthed k, so we can return
            true
------------------------------------------------------------------------------------------------
    Psuedocode:
        - initialize a set to keep track of the binary codes, and a totalBinaryCodes variable
        (2 ^ k)

        - for each charcter in s:
            - add the current substring of length k into the set 

        - if the set is equal to totalBinaryCodes
            - return true
        
        - return false
-------------------------------------------------------------------------------------------------

*/
    bool hasAllCodes(string s, int k) {
        
        //edge case
        if(s.length() < k) {
            return false;
        }

        //total amount of every binary code of length k
        int totalPossibleCodes = pow(2, k);

        //used for storing unique binary codes in s
        unordered_set<string> set;

        //insert unqiue binary codes into the set 
        for(int i = 0; i <= s.length() - k; i++) {
            set.insert(s.substr(i,k));
        }

        return set.size() == totalPossibleCodes;
    }
};
