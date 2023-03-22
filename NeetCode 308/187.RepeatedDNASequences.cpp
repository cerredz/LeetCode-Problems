class Solution {
public:
/*

    Problem:
      The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
      For example, "ACGAATTCCG" is a DNA sequence.When studying DNA, it is useful to identify repeated sequences within the DNA.
      Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. 
      You may return the answer in any order.
----------------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach, and be using 2 sets to keep track of the 
            duplicate DNA sequences
        2. We will iterate through the string, and look each 10 letter DNA sequence
        3. If the current DNA sequence is in the first set(set for all DNA subsequences), insert it into
            the second set(set of all UNIQUE duplicates)
        4. Otherwise, insert it into the first set
        // The reason why we need another set is so that we dont have duplicates in our actual answer
        5. Loop through the second set and add each DNA sequence to a list of DNA sequences, and
            return that list
---------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare 2 sets, a list of strings, and a string

        - for each letter in s:
            - get the current 10 letter DNA sequence

            - if the sequence is in the first set
                - add it to the second set
            - else 
                - add the sequence to the first set
        
        - for each sequence in the second set
            - add it to the list of sequences
        
        - return the list of sequences
------------------------------------------------------------------------------------------------------
*/
    vector<string> findRepeatedDnaSequences(string s) {
        

        
        //list of duplicate sequences
        vector<string> res;
        //list of all sequences
        unordered_set<string> allSubsequences;
        //list of all duplicate sequences
        unordered_set<string> duplicateSubsequences;

        //edge case
        if(s.length() < 10) {
            return res;
        }
        
        //used for storing current DNA sequence
        string currSequence = "";

        for(int i = 0; i <= s.length() - 10; i++){

            currSequence = s.substr(i, 10);

            //look for sequence in first set
            if(allSubsequences.count(currSequence)) {
                duplicateSubsequences.insert(currSequence);
            //otherwise, add to second set
            }else {
                allSubsequences.insert(currSequence);
            }
        }

        //convert set of all duplicate sequences to a vector
        for(auto c : duplicateSubsequences) {
            res.emplace_back(c);
        }

        return res;

    }
};
