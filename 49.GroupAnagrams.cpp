class Solution {
public:

    /*
        Approach / Puedocode
        - initialize a vector<vector<string>>
        - initialize a map where the key is a string, and the value is a vector of strings
        - loop through Strs
            - keep track of the current word
            - sort the current word
            - insert into the map like this: map[sortedWord] = sts[i];
            //if anagrams are sorted, they will have the same sorted word, thus inputting them into the ssame vector

        - loop through the map
            - add the vectors of string to result

        //return vector of vector
    */



    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result; 
        unordered_map<string, vector<string>> map; // map of vector of string
        string currentString; // our temp string

        for(int i = 0; i < strs.size(); i++){
            currentString = strs.at(i); // keep track of the current string
            sort(currentString.begin(), currentString.end()); // sort the string
            map[currentString].emplace_back(strs[i]); // insert it into the map
        }

        for(auto i = map.begin(); i != map.end(); i++){
            result.emplace_back(i->second); // add the vectors to the final vector of vectors
        }
        
        return result;// return vector of vectors
    }
};
