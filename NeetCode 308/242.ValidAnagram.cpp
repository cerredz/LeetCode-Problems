class Solution {
public:
  
  /* 
   Problem: Given two strings s and t, return true if t is an anagram of s, and false otherwise. An Anagram is a word or phrase formed by rearranging the letters 
   of a different word or phrase, typically using all the original letters exactly once.
   
   Approach: 
   - have a map to store the frequencies of the string
   - for each letter of the string
      - increment the counter for the first string at letter c
      - decrement the counter for the second string at letter t
      
  //after this for loop, if the two string are an anagram then all the value in the map will be 0
  
  - iterate through the map
    - if the value of the entry is not 0  
        -return false
  
  
  - if we reach here the two string are anagrams
    - return true;
   


  */
    bool isAnagram(string s, string t) {
        
        if(t.length() != s.length() ) {
            return false; //if the length of the strings are not the same it is impossible for them to be anagrams, so we can return false
        }
    
        unordered_map<char, int> charFrequencies;

        for(int i = 0; i < s.length(); i++){
            charFrequencies[s[i]]++;//increment letter at s[i]
            charFrequencies[t[i]]--;//decrement letter at t[i]
            
            
        }

        for(auto entry = charFrequencies.begin(); entry != charFrequencies.end(); entry++){//iterates through the map of frequencies
            if(entry->second != 0){
                return false;
            }
        }


       return true;
    }
};
