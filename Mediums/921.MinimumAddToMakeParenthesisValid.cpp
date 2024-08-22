class Solution {
public:
/*
    Problem:
      A parentheses string is valid if and only if: It is the empty string, It can be written as AB (A concatenated with B), where A and B are valid strings, or
      It can be written as (A), where A is a valid string. You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
      For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))". Return the minimum number of moves required to make s valid.
*/

    int minAddToMakeValid(string s) {
        int res = 0;
        stack<char> st; // use track for previous parenthesis
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                // push all open brackets onto stack
                st.push(s[i]); 
            } else if (s[i] == ')' && !st.empty()) {
                // matching open bracket for the found closed bracket
                st.pop();
            } else if(st.empty() && s[i] == ')') {
                // either too many closed brackets or closed bracket before open brackets
                res++;
            } 
        }
        return res + st.size();
    }
};
