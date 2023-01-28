class Solution {
public:

/*
    Problem: 
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

    Approach:
    - we will be looping through the letters of each string, and checking if each index is the same
    - if all letters are the same we can add it to a result varible, if not we can return the result variable

*/
    string longestCommonPrefix(vector<string>& strs) {
        
       string res = "";
        for(int i = 0; i < strs[0].length(); i++)//the prefex can only be as long as the  shortest word
        {
            for(int j = 1; j < strs.size(); j++)//loop through every word in the vector
            {
                if(strs[0][i] != strs[j][i]) {//check if the letters are the same at the same index
                    return res;
                }
            }
            res += strs[0][i];//if control reaches here, all letters are the same and we can add to res
        }

        return res;
    }
};
