class Solution {
public:
  /*
   ------------------------------------------------------------------------------------------------------------------------------------------------------------------
   Problem:
   You are given a 0-indexed array of strings words and a 2D array of integers queries.
   Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
   Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
   Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
  -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Approach:
     - we will loop through the string, and map all words with starting and ending vowels to true, and all other words to false
     - for every set of number in query we will count the number of true values in the map, and at the end of the loop add the number of true values to a result vector
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------
  */
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        unordered_map<int, bool> map;//map of words that start and end with a vowel
        char firstLetter = '\0';
        char lastLetter = '\0';
        int index = 0;//used for mapping
        vector<int> res;
        
        for(string s : words) {
            
            firstLetter = tolower(s.front());//first letter in string
            lastLetter = tolower(s.back());///last letter in string
            
            if((firstLetter == 'a' || firstLetter == 'e' || firstLetter == 'i' || firstLetter == 'o' || firstLetter == 'u' ) && (lastLetter == 'a' || lastLetter == 'e' || lastLetter == 'i' || lastLetter == 'o' || lastLetter == 'u' )) {
                //checks for if the first and last leter is a vowel
                map[index] = true;
            }else {
                map[index] = false;
            }
            index++;
            
        }
        int counter = 0;
        
        for(auto query : queries) {//for each set of numbers
            counter = 0;
            for(int i = query[0]; i <= query[1]; i++) {//loops through the specified range
           
                if(map[i] == true) {//checks if word starts and ends with vowel
                    counter++;
                }
            }
            res.emplace_back(counter);
        }
        return res;
    }
};
