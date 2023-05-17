class Solution {
public:
/*
    Problem:
        Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
        In other words, return true if one of s1's permutations is the substring of s2.
----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach that also uses a vector to store letter 
            frequencies
        2. First store the character frequencies, of the first s1.size() characters, of each
            string into two separate vectors
        3. If the vectors store the same value then return true
        4. If the vector do not store the same value, this is when we will start to implement
            the sliding window algorithmn
        5. We must iterate through every element in s2 starting at the size of s1, chop off
            the left size of the window (current index - s1.size()) by decrementing the count
            of that character in the s2 vector. Increment the character at the currrent index
            to the s2 vector, and check if the two vectors are the same again. Continue this
            process for every element in s2
        6. If nothing is returned after iterating through every element in s2, this means 
            that there are no permutations of s1 in s2 and we can return false
----------------------------------------------------------------------------------------------
    Psuedocode:

        - declare vectors

        - for every character(c) in s1:
            - increment frequency of s1Freq[c]
            - increment frequency of s2Freq[c]

        - if s1Freq == s2Freq then retun true

        - for every character(c) in s2 starting at s1.length():

            - decrement frequency of s2Freqs[current index - s1.length()]
            - increment frequency of s2Freqs[current index]

            - if s1Freq == s2Freq then retun true

        - return false
----------------------------------------------------------------------------------------------

*/
    bool checkInclusion(string s1, string s2) {
        
        //edge case, s2 cannot have permutation of s1 if s1 is bigger
        if(s1.length() > s2.length()){
            return false;
        }

        //declare vectors
        vector<int> s1Freqs(26, 0);
        vector<int> s2Freqs(26, 0);

        //store frequency of first s1.length() characters
        for(int i = 0; i < s1.length(); i++) {
            s1Freqs[s1[i] - 'a']++;
            s2Freqs[s2[i] - 'a']++;
        }

        if(s1Freqs == s2Freqs) {
            return true;
        }

        //implement sliding window approach
        for(int i = s1.length(); i < s2.length(); i++) {

            //slide the window
            s2Freqs[s2[i - s1.length()] - 'a']--;
            s2Freqs[s2[i] - 'a']++;

            //if character frequencies are the same, return true
            if(s1Freqs == s2Freqs) {
                return true;
            }
        }

        //no permutations found if control reaches here, return false
        return false;

    }
};
