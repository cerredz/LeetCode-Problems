class Solution {
public:
/*
  Problem:

    You are given a string s, which contains stars *. In one operation, you can: Choose a star in s. Remove the closest non-star character to its
     left, as well as remove the star itself. Return the string after all stars have been removed. Note: The input will be generated such that the
      operation is always possible. It can be shown that the resulting string will always be unique.

*/
    string removeStars(string s) {
        
        //this is a stack-like problem, but he do not actually need to use a stack. Instead we 
        //can use the pop_back() function for strings to simulate popping from a stack. By not using a stack this will save us memory

        //declare string
        string res = "";
        
        
        for(char c : s) {

            //if c is an asterick, then we have to remove the last element in the string
            if(c == '*') {

                if(res != ""){
                    res.pop_back();//same thing as popping from a stack
                }
            //if c is not an asterick, then we add it to the string
            } else {
                res += c;
            }
        }

        return res;

        
    }
};
