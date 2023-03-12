class Solution {
public:

/*
    Problem:
        Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
        An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach
        2. Map the letter frequencies in p
        3. We will have a right pointer and left pointer to signify the two ends of out window
        4. Have a separate vector to map the letters frequencies in s between the left and
            right pointers
        5. Iterate through the string, add the right character to the s vector, and if the 
            current window is too big increment left (closing the window)
        6. If the frequencies in each map are the same then we can add the left pointer to 
            out res vector
------------------------------------------------------------------------------------------------
        
*/
    vector<int> findAnagrams(string s, string p) {
        

        vector<int> res;
        //used for mapping letter frequencies
        vector<int> pCharFreq (26, 0), sCharFreq (26, 0);

        //used for closing window
        int left = 0;

        //map p's letter frequencies
        for(auto c : p) {
            pCharFreq[c - 'a']++;
        }

        //count all the anagrams
        for(int right = 0; right < s.length(); right++) {
            sCharFreq[s[right] - 'a']++;
            
            //if the current window is too big, we must close it
            if(right - left + 1 > p.length()) {
                sCharFreq[s[left] - 'a']--;
                left++;
            }

            //if the frequencies are the same
            if(pCharFreq == sCharFreq) {
                res.emplace_back(left);
            }
        }

        //return number of anagrams
        return res;
        
    }
};
