class Solution {
public:
/*
Problem:

  Given a string s of '(' , ')' and lowercase English characters. Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is 
  valid and return any valid string. Formally, a parentheses string is valid if and only if: It is the empty string, contains only lowercase characters, or
  It can be written as AB (A concatenated with B), where A and B are valid strings, or It can be written as (A), where A is a valid string
*/
    string minRemoveToMakeValid(string s) {
        string valid_closed = "";
        int n = s.length();
        stack<char> st;
        // we will first build a string that has valid closed parenthesis using a stack
        for(int i = 0; i < n; i++) {
            if(s[i] != '(' && s[i] != ')') {
                valid_closed += s[i];
                continue;
            }
            if(s[i] == '(') {
                st.push(s[i]);
                valid_closed += '(';
            }
            if(s[i] == ')' && !st.empty()) {
                st.pop();
                valid_closed += ")";
            }
        }

        // next, using the valid_closed and open/closed count, return res
        string res = "";
        if(st.empty()) return valid_closed;

        int index = valid_closed.length() - 1;  // Start from the end
        while(index >= 0 && !st.empty()) {
            if(valid_closed[index] == '(' && !st.empty()) {
                st.pop();
                index--;
                continue;
            }
            res = valid_closed[index] + res;  
            index--;
        }

        // Add remaining characters
        if(index >= 0) {
            res = valid_closed.substr(0, index + 1) + res;
        }

        return res;
    }
};
