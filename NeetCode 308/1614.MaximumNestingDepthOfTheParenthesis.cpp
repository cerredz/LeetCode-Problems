class Solution {
public:
/*
    Problem:
        Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
*/
    int maxDepth(string s) {
        int res = 0;
        stack<char> st;
        int n = s.length();

        // add open parenthesis to st, pop when we see closed parenthesis, use the size of the stack to calculate res
        for(int i = 0; i < n; i++){
            char curr = s[i];
            if(curr != '(' && curr != ')'){
                continue;
            }

            if(curr == '(') {
                st.push(curr);
            } else if (curr == ')' && !st.empty()){
                st.pop();
            }

            int depth = st.size();
            res = max(res, depth);
        }   

        return res;
    }
};
